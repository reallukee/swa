//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  prgm.c
//
//  https://github.com/reallukee/swa
//

#include "prgm.h"

#include "prgmint.h"

const swa16_addr_t SWA16_PRGM_MAGIC_NUMBER   = 0x3792;
const swa16_addr_t SWA16_PRGM_ARCH_VERSION   = 0x1002;
const swa16_addr_t SWA16_PRGM_FORMAT_VERSION = 0x0004;

swa16_prgm_t* swa16_prgm_alloc()
{
    swa16_prgm_t* prgm = (swa16_prgm_t*)calloc(
        1, sizeof(swa16_prgm_t)
    );

    if (prgm == NULL)
    {
        return NULL;
    }

    prgm->init = false;

    prgm->lookup = (swa16_word_t*)calloc(
        1, sizeof(prgm->lookup)
    );

    if (prgm->lookup == NULL)
    {
        swa16_prgm_free(prgm);

        return NULL;
    }

    return prgm;
}

void swa16_prgm_free(swa16_prgm_t* prgm)
{
    if (prgm == NULL)
    {
        return;
    }

    free(prgm->lookup);

    free(prgm);
}



bool swa16_prgm_init(swa16_prgm_t* prgm)
{
    if (prgm == NULL)
    {
        return false;
    }

    if (prgm->init)
    {
        return true;
    }

    prgm->header.magic_number   = SWA16_PRGM_MAGIC_NUMBER;
    prgm->header.arch_version   = SWA16_PRGM_ARCH_VERSION;
    prgm->header.format_version = SWA16_PRGM_FORMAT_VERSION;

    prgm->body.metadata_length  = 0;
    prgm->body.data_length      = 0;
    prgm->body.text_length      = 0;

    memset(prgm->lookup, 0, 1 * sizeof(prgm->lookup));

    prgm->init = true;

    return true;
}

bool swa16_prgm_isInit(const swa16_prgm_t* prgm)
{
    if (prgm == NULL)
    {
        return false;
    }

    return prgm->init;
}



static bool swa16_prgm_load_section(
    FILE*              file,
    const swa16_mac_t* mac,
    size_t             section_length,
    size_t             section_max_length,
    size_t             section_start)
{
    if (section_length == 0)
    {
        return true;
    }

    if (file           == NULL ||
        section_length >  section_max_length)
    {
        return false;
    }

    swa16_word_t* buffer = (swa16_word_t*)calloc(
        section_max_length, sizeof(swa16_word_t)
    );

    if (buffer == NULL)
    {
        return false;
    }

    size_t result = fread(
        buffer,
        sizeof(swa16_word_t),
        section_length,
        file
    );

    if (result != section_length)
    {
        free(buffer);

        return false;
    }

    const swa16_nvm_t* nvm = swa16_mac_get_nvm(mac);

    for (size_t i = 0; i < section_length; ++i)
    {
        if (!swa16_mem_wrds_set(nvm, section_start + i, buffer[i]))
        {
            return false;
        }
    }

    free(buffer);

    return true;
}

static bool swa16_prgm_unload_section(
    FILE*              file,
    const swa16_mac_t* mac,
    size_t             section_length,
    size_t             section_max_length,
    size_t             section_start)
{
    if (section_length == 0)
    {
        return true;
    }

    if (file           == NULL ||
        section_length >  section_max_length)
    {
        return false;
    }

    swa16_word_t* buffer = (swa16_word_t*)calloc(
        section_max_length, sizeof(swa16_word_t)
    );

    if (buffer == NULL)
    {
        return false;
    }

    const swa16_nvm_t* nvm = swa16_mac_get_nvm(mac);

    for (size_t i = 0; i < section_length; ++i)
    {
        if (!swa16_mem_wrds_get(nvm, section_start + i, &buffer[i]))
        {
            return false;
        }
    }

    size_t result = fwrite(
        buffer,
        sizeof(swa16_word_t),
        section_length,
        file
    );

    if (result != section_length)
    {
        free(buffer);

        return false;
    }

    free(buffer);

    return true;
}



bool swa16_prgm_load(const char* path, swa16_prgm_t* prgm, const swa16_mac_t* mac)
{
    if (path == NULL || prgm == NULL || mac == NULL)
    {
        return false;
    }

    FILE* file = fopen(path, "rb");

    if (file == NULL)
    {
        return false;
    }

    bool fail = false;

    fail |= !(fread(&prgm->header.magic_number,   sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fread(&prgm->header.arch_version,   sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fread(&prgm->header.format_version, sizeof(swa16_word_t), 1, file) == 1);

    if (fail ||
        prgm->header.magic_number   != SWA16_PRGM_MAGIC_NUMBER ||
        prgm->header.arch_version   != SWA16_PRGM_ARCH_VERSION ||
        prgm->header.format_version != SWA16_PRGM_FORMAT_VERSION)
    {
        goto error;
    }

    fail |= !(fread(&prgm->body.metadata_length, sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fread(&prgm->body.data_length,     sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fread(&prgm->body.text_length,     sizeof(swa16_word_t), 1, file) == 1);

    if (fail)
    {
        goto error;
    }

    if (prgm->body.metadata_length > SWA16_PRGM_METADATA_LENGTH ||
        prgm->body.data_length     > SWA16_PRGM_DATA_LENGTH     ||
        prgm->body.text_length     > SWA16_PRGM_TEXT_LENGTH)
    {
        goto error;
    }

    fail |= !(swa16_prgm_load_section(
        file, mac, prgm->body.metadata_length, SWA16_PRGM_METADATA_LENGTH, SWA16_PRGM_METADATA_START
    ));

    fail |= !(swa16_prgm_load_section(
        file, mac, prgm->body.data_length, SWA16_PRGM_DATA_LENGTH, SWA16_PRGM_DATA_START
    ));

    fail |= !(swa16_prgm_load_section(
        file, mac, prgm->body.text_length, SWA16_PRGM_TEXT_LENGTH, SWA16_PRGM_TEXT_START
    ));

    if (fail)
    {
        goto error;
    }

    fclose(file);

    return true;

error:

    fclose(file);

    return false;
}

bool swa16_prgm_unload(const char* path, swa16_prgm_t* prgm, const swa16_mac_t* mac)
{
    if (path == NULL || prgm == NULL || mac == NULL)
    {
        return false;
    }

    FILE* file = fopen(path, "wb");

    if (file == NULL)
    {
        return false;
    }

    bool fail = false;

    fail |= !(fwrite(&prgm->header.magic_number,   sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fwrite(&prgm->header.arch_version,   sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fwrite(&prgm->header.format_version, sizeof(swa16_word_t), 1, file) == 1);

    if (fail ||
        prgm->header.magic_number   != SWA16_PRGM_MAGIC_NUMBER ||
        prgm->header.arch_version   != SWA16_PRGM_ARCH_VERSION ||
        prgm->header.format_version != SWA16_PRGM_FORMAT_VERSION)
    {
        goto error;
    }

    fail |= !(fwrite(&prgm->body.metadata_length, sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fwrite(&prgm->body.data_length,     sizeof(swa16_word_t), 1, file) == 1);
    fail |= !(fwrite(&prgm->body.text_length,     sizeof(swa16_word_t), 1, file) == 1);

    if (fail)
    {
        goto error;
    }

    if (prgm->body.metadata_length > SWA16_PRGM_METADATA_LENGTH ||
        prgm->body.data_length     > SWA16_PRGM_DATA_LENGTH     ||
        prgm->body.text_length     > SWA16_PRGM_TEXT_LENGTH)
    {
        goto error;
    }

    fail |= !(swa16_prgm_unload_section(
        file, mac, prgm->body.metadata_length, SWA16_PRGM_METADATA_LENGTH, SWA16_PRGM_METADATA_START
    ));

    fail |= !(swa16_prgm_unload_section(
        file, mac, prgm->body.data_length, SWA16_PRGM_DATA_LENGTH, SWA16_PRGM_DATA_START
    ));

    fail |= !(swa16_prgm_unload_section(
        file, mac, prgm->body.text_length, SWA16_PRGM_TEXT_LENGTH, SWA16_PRGM_TEXT_START
    ));

    if (fail)
    {
        goto error;
    }

    fclose(file);

    return true;

error:

    fclose(file);

    return false;
}
