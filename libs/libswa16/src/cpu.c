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

#include "cpu.h"

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

    cpu->regs = (swa16_word_t*)calloc(
        SWA16_CPU_REGS_SIZE, sizeof(cpu->regs)
    );

    cpu->pc = (swa16_word_t*)calloc(
        SWA16_CPU_PC_SIZE, sizeof(cpu->pc)
    );

    cpu->flgs = (swa16_word_t*)calloc(
        SWA16_CPU_FLGS_SIZE, sizeof(cpu->flgs)
    );

    if (cpu->regs == NULL ||
        cpu->pc   == NULL ||
        cpu->flgs == NULL )
    {
        swa16_cpu_free(cpu);

        return NULL;
    }

    memset(cpu->regs, 0, SWA16_CPU_REGS_SIZE * sizeof(cpu->regs));
    memset(cpu->pc,   0,     SWA16_CPU_PC_SIZE * sizeof(cpu->pc));
    memset(cpu->flgs, 0, SWA16_CPU_FLGS_SIZE * sizeof(cpu->flgs));

    cpu->regs_init = false;
    cpu->pc_init   = false;
    cpu->flgs_init = false;

    return cpu;
}

void swa16_cpu_free(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return;
    }

    free(cpu->regs);
    free(cpu->pc);
    free(cpu->flgs);

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
