//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  prgmint.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA_PRGMINT_H
#define LIBSWA_PRGMINT_H

#include "utils/header.h"
#include "utils/export.h"
#include "utils/macros.h"

#include "types/addr.h"
#include "types/binint.h"
#include "types/flag.h"

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_prgm
{
    bool init;

    struct
    {
        swa16_word_t magic_number;
        swa16_word_t arch_version;
        swa16_word_t format_version;
    } header;

    struct
    {
        swa16_word_t metadata_length;
        swa16_word_t data_length;
        swa16_word_t text_length;
    } body;

    swa16_word_t* lookup;
} swa16_prgm_t;

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA_PRGMINT_H
