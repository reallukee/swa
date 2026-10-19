//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  regs.c
//
//  https://github.com/reallukee/swa
//

#include <cpu/regs.h>

#include "isaint.h"
#include "cpuint.h"
#include "memint.h"

bool swa16_cpu_regs_init(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->regs_init)
    {
        return true;
    }

    memset(cpu->regs, 0, sizeof(cpu->regs));

    cpu->regs_init = true;

    return true;
}

bool swa16_cpu_regs_isInit(const swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    return cpu->regs_init;
}



bool swa16_cpu_regs_get(
    const swa16_cpu_t* cpu,
    swa16_cpu_regs_t   reg,
    swa16_word_t*      out)
{
    if (cpu == NULL || out == NULL)
    {
        return false;
    }

    if (reg < SWA16_CPU_REGS_START ||
        reg > SWA16_CPU_REGS_END)
    {
        return false;
    }

    *out = cpu->regs[reg];

    return true;
}

bool swa16_cpu_regs_getlo(
    const swa16_cpu_t* cpu,
    swa16_cpu_regs_t   reg,
    swa16_byte_t*      out)
{
    swa16_word_t word_out = 0;

    if (!swa16_cpu_regs_get(cpu, reg, &word_out))
    {
        return false;
    }

    *out = swa16_binint_gwlo(word_out);

    return true;
}

bool swa16_cpu_regs_gethi(
    const swa16_cpu_t* cpu,
    swa16_cpu_regs_t   reg,
    swa16_byte_t*      out)
{
    swa16_word_t word_out = 0;

    if (!swa16_cpu_regs_get(cpu, reg, &word_out))
    {
        return false;
    }

    *out = swa16_binint_gwhi(word_out);

    return true;
}



bool swa16_cpu_regs_set(
    swa16_cpu_t*     cpu,
    swa16_cpu_regs_t reg,
    swa16_word_t     in)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (reg < SWA16_CPU_REGS_START ||
        reg > SWA16_CPU_REGS_END)
    {
        return false;
    }

    cpu->regs[reg] = in;

    return true;
}

bool swa16_cpu_regs_setlo(
    swa16_cpu_t*     cpu,
    swa16_cpu_regs_t reg,
    swa16_byte_t     in)
{
    swa16_word_t word_in = 0;

    word_in = swa16_binint_swlo(word_in, in);

    return swa16_cpu_regs_set(cpu, reg, word_in);
}

bool swa16_cpu_regs_sethi(
    swa16_cpu_t*     cpu,
    swa16_cpu_regs_t reg,
    swa16_byte_t     in)
{
    swa16_word_t word_in = 0;

    word_in = swa16_binint_swhi(word_in, in);

    return swa16_cpu_regs_set(cpu, reg, word_in);
}



swa16_word_t swa16_cpu_regs_to(swa16_cpu_regs_t reg)
{
    return (swa16_word_t)reg;
}

swa16_cpu_regs_t swa16_cpu_regs_from(swa16_word_t value)
{
    if (value > SWA16_CPU_REGS_END)
    {
        return SWA16_CPU_REGS_NONE;
    }

    return (swa16_cpu_regs_t)value;
}



const char* swa16_cpu_regs_to_name(swa16_cpu_regs_t reg)
{
    switch (reg)
    {
    case 0x0000: return "RA";
    case 0x0001: return "RV";
    case 0x0002: return "A0";
    case 0x0003: return "A1";
    case 0x0004: return "A2";
    case 0x0005: return "A3";
    case 0x0006: return "T0";
    case 0x0007: return "T1";
    case 0x0008: return "S0";
    case 0x0009: return "S1";
    case 0x000A: return "S2";
    case 0x000B: return "S3";
    case 0x000C: return "S4";
    case 0x000D: return "S5";
    case 0x000E: return "FP";
    case 0x000F: return "SP";

    case 0xFFFF: return "NONE";

    default:     return "NONE";
    }
}

swa16_cpu_regs_t swa16_cpu_regs_from_name(const char* name)
{
    if (strcmp(name,   "RA") == 0) return SWA16_CPU_REGS_RA;
    if (strcmp(name,   "RV") == 0) return SWA16_CPU_REGS_RV;
    if (strcmp(name,   "A0") == 0) return SWA16_CPU_REGS_A0;
    if (strcmp(name,   "A1") == 0) return SWA16_CPU_REGS_A1;
    if (strcmp(name,   "A2") == 0) return SWA16_CPU_REGS_A2;
    if (strcmp(name,   "A3") == 0) return SWA16_CPU_REGS_A3;
    if (strcmp(name,   "T0") == 0) return SWA16_CPU_REGS_T0;
    if (strcmp(name,   "T1") == 0) return SWA16_CPU_REGS_T1;
    if (strcmp(name,   "S0") == 0) return SWA16_CPU_REGS_S0;
    if (strcmp(name,   "S1") == 0) return SWA16_CPU_REGS_S1;
    if (strcmp(name,   "S2") == 0) return SWA16_CPU_REGS_S2;
    if (strcmp(name,   "S3") == 0) return SWA16_CPU_REGS_S3;
    if (strcmp(name,   "S4") == 0) return SWA16_CPU_REGS_S4;
    if (strcmp(name,   "S5") == 0) return SWA16_CPU_REGS_S5;
    if (strcmp(name,   "FP") == 0) return SWA16_CPU_REGS_FP;
    if (strcmp(name,   "SP") == 0) return SWA16_CPU_REGS_SP;

    if (strcmp(name, "NONE") == 0) return SWA16_CPU_REGS_NONE;

    return SWA16_CPU_REGS_NONE;
}



static void printex_callback(swa16_cpu_regs_t reg, swa16_word_t value)
{
    printf("%d: %d\n", reg, value);
}

bool swa16_cpu_regs_print(
    const swa16_cpu_t* cpu)
{
    return swa16_cpu_regs_exprint(
        cpu, printex_callback
    );
}

bool swa16_cpu_regs_exprint(
    const swa16_cpu_t* cpu,
    void               (*callback)(swa16_cpu_regs_t reg, swa16_word_t value))
{
    if (cpu == NULL || callback == NULL)
    {
        return false;
    }

    for (swa16_word_t i = SWA16_CPU_REGS_START; i < SWA16_CPU_REGS_SIZE; ++i)
    {
        swa16_word_t out;

        if (!swa16_cpu_regs_get(cpu, i, &out))
        {
            continue;
        }

        callback(i, out);
    }

    return true;
}



bool swa16_cpu_regs_load(swa16_cpu_t* cpu, const char* path)
{
    if (cpu == NULL || path == NULL)
    {
        return false;
    }

    FILE* in = fopen(path, "rb");

    if (in == NULL)
    {
        return false;
    }

    fread(cpu->regs, sizeof(cpu->regs), SWA16_CPU_REGS_SIZE, in);

    fclose(in);

    return true;
}

bool swa16_cpu_regs_unload(const swa16_cpu_t* cpu, const char* path)
{
    if (cpu == NULL || path == NULL)
    {
        return false;
    }

    FILE* out = fopen(path, "wb");

    if (out == NULL)
    {
        return false;
    }

    fwrite(cpu->regs, sizeof(cpu->regs), SWA16_CPU_REGS_SIZE, out);

    fclose(out);

    return true;
}
