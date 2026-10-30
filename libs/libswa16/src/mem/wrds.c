//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  wrds.c
//
//  https://github.com/reallukee/swa
//

#include <mem/wrds.h>

#include "isaint.h"
#include "cpuint.h"
#include "memint.h"

const swa16_addr_t SWA16_MEM_WRDS_ENTRYPOINT = 0x0001;

bool swa16_mem_wrds_init(swa16_mem_t* mem)
{
    if (mem == NULL)
    {
        return false;
    }

    if (mem->wrds_init)
    {
        return true;
    }

    memset(mem->wrds, 0, sizeof(mem->wrds));

    mem->wrds_init = true;

    return true;
}

bool swa16_mem_wrds_isInit(const swa16_mem_t* mem)
{
    if (mem == NULL)
    {
        return false;
    }

    return mem->wrds_init;
}



bool swa16_mem_wrds_get(const swa16_mem_t* mem, swa16_addr_t addr, swa16_word_t* out)
{
    if (mem == NULL || out == NULL)
    {
        return false;
    }

    if (!swa16_mem_wrds_isGp(addr))
    {
        return false;
    }

    *out = mem->wrds[addr];

    return true;
}

bool swa16_mem_wrds_getlo(const swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t* out)
{
    swa16_word_t word_out = 0;

    if (!swa16_mem_wrds_get(mem, addr, &word_out))
    {
        return false;
    }

    *out = swa16_binint_gwlo(word_out);

    return true;
}

bool swa16_mem_wrds_gethi(const swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t* out)
{
    swa16_word_t word_out = 0;

    if (!swa16_mem_wrds_get(mem, addr, &word_out))
    {
        return false;
    }

    *out = swa16_binint_gwhi(word_out);

    return true;
}



bool swa16_mem_wrds_set(swa16_mem_t* mem, swa16_addr_t addr, swa16_word_t in)
{
    if (mem == NULL)
    {
        return false;
    }

    if (!swa16_mem_wrds_isGp(addr))
    {
        return false;
    }

    mem->wrds[addr] = in;

    return true;
}

bool swa16_mem_wrds_setlo(swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t in)
{
    swa16_word_t word_in = 0;

    word_in = swa16_binint_swlo(word_in, in);

    return swa16_mem_wrds_set(mem, addr, word_in);
}

bool swa16_mem_wrds_sethi(swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t in)
{
    swa16_word_t word_in = 0;

    word_in = swa16_binint_swhi(word_in, in);

    return swa16_mem_wrds_set(mem, addr, word_in);
}



bool swa16_mem_wrds_isGp(swa16_addr_t addr)
{
    return swa16_mem_wrds_isNull(addr) && swa16_mem_wrds_isNone(addr);
}

bool swa16_mem_wrds_isNull(swa16_addr_t addr)
{
    return addr == SWA16_MEM_WRDS_NULL;
}

bool swa16_mem_wrds_isNone(swa16_addr_t addr)
{
    return addr == SWA16_MEM_WRDS_NONE;
}



swa16_word_t swa16_mem_wrds_to(swa16_addr_t wrds)
{
    return (swa16_word_t)wrds;
}

swa16_addr_t swa16_mem_wrds_from(swa16_word_t value)
{
    if (value > SWA16_MEM_WRDS_END)
    {
        return SWA16_MEM_WRDS_NONE;
    }

    return (swa16_addr_t)value;
}



const char* swa16_mem_wrds_to_name(swa16_addr_t wrds)
{
    char* wrds_str = calloc(
        18, sizeof(char)
    );

    snprintf(
        wrds_str, 18, "WRDS_ADDR_0x%04X", wrds
    );

    return wrds_str;
}

swa16_addr_t swa16_mem_wrds_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_MEM_WRDS_NONE;
    }

    swa16_addr_t addr = SWA16_MEM_WRDS_NONE;

    if (sscanf(name, "WRDS_ADDR_0x%hx", &addr) != 1)
    {
        return SWA16_MEM_WRDS_NONE;
    }

    return addr;
}



static void printex_callback(swa16_addr_t wrds, swa16_word_t value)
{
    printf("%d: %d\n", wrds, value);
}

bool swa16_mem_wrds_print(
    const swa16_mem_t* mem,
    swa16_addr_t       start,
    swa16_addr_t       count)
{
    return swa16_mem_wrds_exprint(
        mem, start, count, printex_callback
    );
}

bool swa16_mem_wrds_exprint(
    const swa16_mem_t* mem,
    swa16_addr_t       start,
    swa16_addr_t       count,
    void               (*callback)(swa16_addr_t wrds, swa16_word_t value))
{
    if (mem == NULL || callback == NULL)
    {
        return false;
    }

    for (swa16_word_t i = start; i < start + count + 1; ++i)
    {
        swa16_word_t out;

        if (!swa16_mem_wrds_get(mem, i, &out))
        {
            continue;
        }

        callback(i, out);
    }

    return true;
}



bool swa16_mem_wrds_load(swa16_mem_t* mem, const char* path)
{
    if (mem == NULL || path == NULL)
    {
        return false;
    }

    FILE* in = fopen(path, "rb");

    if (in == NULL)
    {
        return false;
    }

    fread(mem->wrds, sizeof(mem->wrds), SWA16_MEM_WRDS_SIZE, in);

    fclose(in);

    return true;
}

bool swa16_mem_wrds_unload(const swa16_mem_t* mem, const char* path)
{
    if (mem == NULL || path == NULL)
    {
        return false;
    }

    FILE* out = fopen(path, "wb");

    if (out == NULL)
    {
        return false;
    }

    fwrite(mem->wrds, sizeof(mem->wrds), SWA16_MEM_WRDS_SIZE, out);

    fclose(out);

    return true;
}
