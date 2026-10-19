//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cpu.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CPU_H
#define LIBSWA16_CPU_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <cpu/regs.h>
#include <cpu/pc.h>
#include <cpu/flgs.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_cpu swa16_cpu_t;

LIBSWA16_API swa16_cpu_t* swa16_cpu_alloc();
LIBSWA16_API void         swa16_cpu_free (swa16_cpu_t* cpu);

LIBSWA16_API bool swa16_cpu_init  (swa16_cpu_t* cpu);
LIBSWA16_API bool swa16_cpu_isInit(const swa16_cpu_t* cpu);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_CPU_H
