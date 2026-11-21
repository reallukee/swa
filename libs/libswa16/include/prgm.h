//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  prgm.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_PRGM_H
#define LIBSWA16_PRGM_H

#include "utils/header.h"
#include "utils/export.h"
#include "utils/macros.h"

#include "types/addr.h"
#include "types/binint.h"
#include "types/flag.h"

#include "mac.h"

#include "isa.h"
#include "cpu.h"
#include "mem.h"

LIBSWA16_NAMESPACE_BEGIN

LIBSWA16_EXTERN LIBSWA16_DLL const swa16_addr_t SWA16_PRGM_MAGIC_NUMBER;
LIBSWA16_EXTERN LIBSWA16_DLL const swa16_addr_t SWA16_PRGM_ARCH_VERSION;
LIBSWA16_EXTERN LIBSWA16_DLL const swa16_addr_t SWA16_PRGM_FORMAT_VERSION;

typedef struct swa16_prgm swa16_prgm_t;

#define SWA16_PRGM_METADATA_START  0x0001
#define SWA16_PRGM_METADATA_END    0x1000
#define SWA16_PRGM_METADATA_LENGTH (SWA16_PRGM_METADATA_END - SWA16_PRGM_METADATA_START + 1)

#define SWA16_PRGM_DATA_START      0x1001
#define SWA16_PRGM_DATA_END        0x4000
#define SWA16_PRGM_DATA_LENGTH     (SWA16_PRGM_DATA_END - SWA16_PRGM_DATA_START + 1)

#define SWA16_PRGM_TEXT_START      0x4001
#define SWA16_PRGM_TEXT_END        0xFFFE
#define SWA16_PRGM_TEXT_LENGTH     (SWA16_PRGM_TEXT_END - SWA16_PRGM_TEXT_START + 1)

LIBSWA16_API swa16_prgm_t* swa16_prgm_alloc();
LIBSWA16_API void          swa16_prgm_free (swa16_prgm_t* prgm);

LIBSWA16_API bool swa16_prgm_init  (swa16_prgm_t* prgm);
LIBSWA16_API bool swa16_prgm_isInit(const swa16_prgm_t* prgm);

LIBSWA16_API bool swa16_prgm_load  (const char* path, swa16_prgm_t* prgm, const swa16_mac_t* mac);
LIBSWA16_API bool swa16_prgm_unload(const char* path, swa16_prgm_t* prgm, const swa16_mac_t* mac);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_PRGM_H
