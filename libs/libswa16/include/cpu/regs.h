//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  regs.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CPU_REGS_H
#define LIBSWA16_CPU_REGS_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_cpu swa16_cpu_t;

#define SWA16_CPU_REGS_START 0x0000
#define SWA16_CPU_REGS_END   0x000F
#define SWA16_CPU_REGS_SIZE  (SWA16_CPU_REGS_END + 1)

typedef enum swa16_cpu_regs : swa16_word_t
{
    SWA16_CPU_REGS_RA   = 0x0000, // 0x0000 --- Return Address
    SWA16_CPU_REGS_RV   = 0x0001, // 0x0001 --- Return Value
    SWA16_CPU_REGS_A0   = 0x0002, // 0x0002 --- Argument 0
    SWA16_CPU_REGS_A1   = 0x0003, // 0x0003 --- Argument 1
    SWA16_CPU_REGS_A2   = 0x0004, // 0x0004 --- Argument 2
    SWA16_CPU_REGS_A3   = 0x0005, // 0x0005 --- Argument 3
    SWA16_CPU_REGS_T0   = 0x0006, // 0x0006 --- Temp 0
    SWA16_CPU_REGS_T1   = 0x0007, // 0x0007 --- Temp 1
    SWA16_CPU_REGS_S0   = 0x0008, // 0x0008 --- Saved 0
    SWA16_CPU_REGS_S1   = 0x0009, // 0x0009 --- Saved 1
    SWA16_CPU_REGS_S2   = 0x000A, // 0x000A --- Saved 2
    SWA16_CPU_REGS_S3   = 0x000B, // 0x000B --- Saved 3
    SWA16_CPU_REGS_S4   = 0x000C, // 0x000C --- Saved 4
    SWA16_CPU_REGS_S5   = 0x000D, // 0x000D --- Saved 5
    SWA16_CPU_REGS_FP   = 0x000E, // 0x000E --- Frame Pointer
    SWA16_CPU_REGS_SP   = 0x000F, // 0x000F --- Stack Pointer

    SWA16_CPU_REGS_NONE = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_cpu_regs_t;

LIBSWA16_API bool swa16_cpu_regs_init  (swa16_cpu_t* cpu);
LIBSWA16_API bool swa16_cpu_regs_isInit(const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_regs_get  (const swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_word_t* out);
LIBSWA16_API bool swa16_cpu_regs_getlo(const swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_byte_t* out);
LIBSWA16_API bool swa16_cpu_regs_gethi(const swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_byte_t* out);
LIBSWA16_API bool swa16_cpu_regs_set  (swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_word_t in);
LIBSWA16_API bool swa16_cpu_regs_setlo(swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_byte_t in);
LIBSWA16_API bool swa16_cpu_regs_sethi(swa16_cpu_t* cpu, swa16_cpu_regs_t reg, swa16_byte_t in);

LIBSWA16_API swa16_word_t     swa16_cpu_regs_to  (swa16_cpu_regs_t reg);
LIBSWA16_API swa16_cpu_regs_t swa16_cpu_regs_from(swa16_word_t value);

LIBSWA16_API const char*      swa16_cpu_regs_to_name  (swa16_cpu_regs_t reg);
LIBSWA16_API swa16_cpu_regs_t swa16_cpu_regs_from_name(const char* name);

LIBSWA16_API bool swa16_cpu_regs_print(
    const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_regs_exprint(
    const swa16_cpu_t* cpu,
    void               (*callback)(swa16_cpu_regs_t reg, swa16_word_t value));

LIBSWA16_API bool swa16_cpu_regs_load  (swa16_cpu_t* cpu, const char* path);
LIBSWA16_API bool swa16_cpu_regs_unload(const swa16_cpu_t* cpu, const char* path);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_CPU_REGS_H
