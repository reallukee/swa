//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  memint.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_MEMINT_H
#define LIBSWA16_MEMINT_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <mem/wrds.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_mem
{
    bool init;

    bool wrds_init;

    swa16_word_t wrds[SWA16_MEM_WRDS_SIZE];
} swa16_mem_t;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_MEMINT_H
