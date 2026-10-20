//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  pc.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CPU_PC_H
#define LIBSWA16_CPU_PC_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_cpu swa16_cpu_t;

#define SWA16_CPU_PC_START 0x0001
#define SWA16_CPU_PC_END   0xFFFE
#define SWA16_CPU_PC_SIZE  (SWA16_CPU_PC_END + 1)

#define SWA16_CPU_PC_GP
#define SWA16_CPU_PC_NULL  0x0000
#define SWA16_CPU_PC_NONE  0xFFFF

LIBSWA16_EXTERN LIBSWA16_DLL const swa16_addr_t SWA16_CPU_PC_ENTRYPOINT;

LIBSWA16_API bool swa16_cpu_pc_init  (swa16_cpu_t* cpu);
LIBSWA16_API bool swa16_cpu_pc_isInit(const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_pc_get  (const swa16_cpu_t* cpu, swa16_word_t* out);
LIBSWA16_API bool swa16_cpu_pc_getra(const swa16_cpu_t* cpu, swa16_word_t* out);
LIBSWA16_API bool swa16_cpu_pc_set  (swa16_cpu_t* cpu, swa16_word_t in);
LIBSWA16_API bool swa16_cpu_pc_setra(swa16_cpu_t* cpu, swa16_word_t in);

LIBSWA16_API bool swa16_cpu_pc_add(swa16_cpu_t* cpu, swa16_word_t value);
LIBSWA16_API bool swa16_cpu_pc_sub(swa16_cpu_t* cpu, swa16_word_t value);

LIBSWA16_API bool swa16_cpu_pc_inc(swa16_cpu_t* cpu);
LIBSWA16_API bool swa16_cpu_pc_dec(swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_pc_isGp  (swa16_addr_t addr);
LIBSWA16_API bool swa16_cpu_pc_isNull(swa16_addr_t addr);
LIBSWA16_API bool swa16_cpu_pc_isNone(swa16_addr_t addr);

LIBSWA16_API swa16_word_t swa16_cpu_pc_to  (swa16_addr_t pc);
LIBSWA16_API swa16_addr_t swa16_cpu_pc_from(swa16_word_t value);

LIBSWA16_API const char*  swa16_cpu_pc_to_name  (swa16_addr_t pc);
LIBSWA16_API swa16_addr_t swa16_cpu_pc_from_name(const char* name);

LIBSWA16_API bool swa16_cpu_pc_print(
    const swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_pc_exprint(
    const swa16_cpu_t* cpu,
    void               (*callback)(swa16_addr_t pc, swa16_word_t value));

LIBSWA16_API bool swa16_cpu_pc_load  (swa16_cpu_t* cpu, const char* path);
LIBSWA16_API bool swa16_cpu_pc_unload(const swa16_cpu_t* cpu, const char* path);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_CPU_PC_H
