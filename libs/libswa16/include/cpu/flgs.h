//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  flgs.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CPU_FLGS_H
#define LIBSWA16_CPU_FLGS_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_cpu swa16_cpu_t;

#define SWA16_CPU_FLGS_START 0x0000
#define SWA16_CPU_FLGS_END   0x0005
#define SWA16_CPU_FLGS_SIZE  (SWA16_CPU_FLGS_END + 1)

typedef enum swa16_cpu_flgs : swa16_word_t
{
    SWA16_CPU_FLGS_ZERO     = 0x0000, // 0x0000 --- Zero
    SWA16_CPU_FLGS_BORROW   = 0x0001, // 0x0001 --- Borrow
    SWA16_CPU_FLGS_NEGATIVE = 0x0002, // 0x0002 --- Negative
    SWA16_CPU_FLGS_OVERFLOW = 0x0003, // 0x0003 --- Overflow
    SWA16_CPU_FLGS_UPDATE   = 0x0004, // 0x0004 --- Update
    SWA16_CPU_FLGS_EVALUATE = 0x0005, // 0x0005 --- Evaluate

    SWA16_CPU_FLGS_NULL     = 0xFFFE, // 0xFFFE --- Null
    SWA16_CPU_FLGS_NONE     = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_cpu_flgs_t;

LIBSWA16_API bool swa16_cpu_flgs_init  (swa16_cpu_t* cpu);
LIBSWA16_API bool swa16_cpu_flgs_isInit(const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_flgs_get (const swa16_cpu_t* cpu, swa16_cpu_flgs_t flg, swa16_flag_t* out);
LIBSWA16_API bool swa16_cpu_flgs_islo(const swa16_cpu_t* cpu, swa16_cpu_flgs_t flg, bool* out);
LIBSWA16_API bool swa16_cpu_flgs_ishi(const swa16_cpu_t* cpu, swa16_cpu_flgs_t flg, bool* out);
LIBSWA16_API bool swa16_cpu_flgs_set (swa16_cpu_t* cpu, swa16_cpu_flgs_t flg, swa16_flag_t in);
LIBSWA16_API bool swa16_cpu_flgs_tolo(swa16_cpu_t* cpu, swa16_cpu_flgs_t flg);
LIBSWA16_API bool swa16_cpu_flgs_tohi(swa16_cpu_t* cpu, swa16_cpu_flgs_t flg);

LIBSWA16_API bool swa16_cpu_flgs_isGp  (swa16_cpu_flgs_t flg);
LIBSWA16_API bool swa16_cpu_flgs_isNull(swa16_cpu_flgs_t flg);
LIBSWA16_API bool swa16_cpu_flgs_isNone(swa16_cpu_flgs_t flg);

LIBSWA16_API swa16_word_t     swa16_cpu_flgs_to  (swa16_cpu_flgs_t flg);
LIBSWA16_API swa16_cpu_flgs_t swa16_cpu_flgs_from(swa16_word_t value);

LIBSWA16_API const char*      swa16_cpu_flgs_to_name  (swa16_cpu_flgs_t flg);
LIBSWA16_API swa16_cpu_flgs_t swa16_cpu_flgs_from_name(const char* name);

LIBSWA16_API bool swa16_cpu_flgs_print(const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_flgs_exprint(
    const swa16_cpu_t* cpu,
    void  (*callback)(swa16_cpu_flgs_t flg, swa16_flag_t value));

LIBSWA16_API bool swa16_cpu_flgs_load  (swa16_cpu_t* cpu, const char* path);
LIBSWA16_API bool swa16_cpu_flgs_unload(const swa16_cpu_t* cpu, const char* path);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_CPU_FLGS_H
