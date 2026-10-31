//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  macint.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_MACINT_H
#define LIBSWA16_MACINT_H

#include <isa.h>
#include <cpu.h>
#include <mem.h>

#include <insts.h>

#include "isaint.h"
#include "cpuint.h"
#include "memint.h"

#include "instsint.h"

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mac
{
    bool init;

    swa16_cpu_t* cpu;

    swa16_ram_t* ram;
    swa16_rom_t* rom;
    swa16_nvm_t* nvm;
} swa16_mac_t;

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_MACINT_H
