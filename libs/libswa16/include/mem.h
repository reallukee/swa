//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mem.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_MEM_H
#define LIBSWA16_MEM_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <mem/wrds.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_mem swa16_mem_t;

typedef swa16_mem_t swa16_nvm_t;
typedef swa16_mem_t swa16_ram_t;
typedef swa16_mem_t swa16_rom_t;

LIBSWA16_API swa16_mem_t* swa16_mem_alloc();
LIBSWA16_API void         swa16_mem_free (swa16_mem_t* mem);

LIBSWA16_API bool swa16_mem_init  (swa16_mem_t* mem);
LIBSWA16_API bool swa16_mem_isInit(const swa16_mem_t* mem);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_MEM_H
