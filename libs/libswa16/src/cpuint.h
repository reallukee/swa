//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cpuint.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CPUINT_H
#define LIBSWA16_CPUINT_H

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

typedef struct swa16_cpu
{
    bool init;

    bool regs_init;
    bool pc_init;
    bool flgs_init;

    swa16_word_t regs[SWA16_CPU_REGS_SIZE];
    swa16_word_t pc;
    swa16_word_t flgs[SWA16_CPU_FLGS_SIZE];
} swa16_cpu_t;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_CPUINT_H
