//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  wrds.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_MEM_WRDS_H
#define LIBSWA16_MEM_WRDS_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mem swa16_mem_t;

#define SWA16_MEM_WRDS_START 0x0001
#define SWA16_MEM_WRDS_END   0xFFFE
#define SWA16_MEM_WRDS_SIZE  (SWA16_MEM_WRDS_END + 1)

#define SWA16_MEM_WRDS_GP
#define SWA16_MEM_WRDS_NULL  0x0000
#define SWA16_MEM_WRDS_NONE  0xFFFF

LIBSWA16_EXTERN LIBSWA16_DLL const swa16_addr_t SWA16_MEM_WRDS_ENTRYPOINT;

LIBSWA16_API bool swa16_mem_wrds_init  (swa16_mem_t* mem);
LIBSWA16_API bool swa16_mem_wrds_isInit(const swa16_mem_t* mem);

LIBSWA16_API bool swa16_mem_wrds_get  (const swa16_mem_t* mem, swa16_addr_t addr, swa16_word_t* out);
LIBSWA16_API bool swa16_mem_wrds_getlo(const swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t* out);
LIBSWA16_API bool swa16_mem_wrds_gethi(const swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t* out);
LIBSWA16_API bool swa16_mem_wrds_set  (swa16_mem_t* mem, swa16_addr_t addr, swa16_word_t in);
LIBSWA16_API bool swa16_mem_wrds_setlo(swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t in);
LIBSWA16_API bool swa16_mem_wrds_sethi(swa16_mem_t* mem, swa16_addr_t addr, swa16_byte_t in);

LIBSWA16_API bool swa16_mem_wrds_isGp  (swa16_addr_t addr);
LIBSWA16_API bool swa16_mem_wrds_isNull(swa16_addr_t addr);
LIBSWA16_API bool swa16_mem_wrds_isNone(swa16_addr_t addr);

LIBSWA16_API swa16_word_t swa16_mem_wrds_to  (swa16_addr_t wrds);
LIBSWA16_API swa16_addr_t swa16_mem_wrds_from(swa16_word_t value);

LIBSWA16_API const char*  swa16_mem_wrds_to_name  (swa16_addr_t wrds);
LIBSWA16_API swa16_addr_t swa16_mem_wrds_from_name(const char* name);

LIBSWA16_API bool swa16_mem_wrds_print(const swa16_mem_t* mem,
                                       swa16_addr_t       start,
                                       swa16_addr_t       count);

LIBSWA16_API bool swa16_mem_wrds_exprint(const swa16_mem_t* mem,
                                         swa16_addr_t       start,
                                         swa16_addr_t       count,
                                         void               (*callback)(swa16_addr_t wrds, swa16_word_t value));

LIBSWA16_API bool swa16_mem_wrds_load  (swa16_mem_t* mem, const char* path);
LIBSWA16_API bool swa16_mem_wrds_unload(const swa16_mem_t* mem, const char* path);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_MEM_WRDS_H
