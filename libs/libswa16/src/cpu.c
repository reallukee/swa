//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cpu.c
//
//  https://github.com/reallukee/swa
//

#include <cpu.h>

#include "cpuint.h"

swa16_cpu_t* swa16_cpu_alloc()
{
    swa16_cpu_t* cpu = (swa16_cpu_t*)calloc(
        1, sizeof(swa16_cpu_t)
    );

    if (cpu == NULL)
    {
        return NULL;
    }

    cpu->init = false;

    cpu->regs_init = false;
    cpu->pc_init   = false;
    cpu->flgs_init = false;

    memset(cpu->regs, 0, sizeof(cpu->regs));
    cpu->pc = 0;
    memset(cpu->flgs, 0, sizeof(cpu->flgs));

    return cpu;
}

void swa16_cpu_free(swa16_cpu_t* cpu)
{
    free(cpu);
}



bool swa16_cpu_init(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->init)
    {
        return true;
    }

    if (!swa16_cpu_regs_init(cpu) ||
        !swa16_cpu_pc_init  (cpu) ||
        !swa16_cpu_flgs_init(cpu))
    {
        return false;
    }

    cpu->init = true;

    return true;
}

bool swa16_cpu_isInit(const swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    return !swa16_cpu_regs_isInit(cpu) ||
           !swa16_cpu_pc_isInit  (cpu) ||
           !swa16_cpu_flgs_isInit(cpu);
}
