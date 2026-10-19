//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  flgs.c
//
//  https://github.com/reallukee/swa
//

#include <cpu/flgs.h>

#include "isaint.h"
#include "cpuint.h"
#include "memint.h"

bool swa16_cpu_flgs_init(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->flgs_init)
    {
        return true;
    }

    memset(cpu->flgs, 0, sizeof(cpu->flgs));

    cpu->flgs_init = true;

    return true;
}

bool swa16_cpu_flgs_isInit(const swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    return cpu->flgs_init;
}



bool swa16_cpu_flgs_get(
    const swa16_cpu_t* cpu,
    swa16_cpu_flgs_t   flg,
    swa16_flag_t*      out)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (flg < SWA16_CPU_FLGS_START ||
        flg > SWA16_CPU_FLGS_END)
    {
        return false;
    }

    *out = cpu->flgs[flg];

    return true;
}

bool swa16_cpu_flgs_islo(
    const swa16_cpu_t* cpu,
    swa16_cpu_flgs_t   flg,
    bool*              out)
{
    swa16_flag_t temp_out;

    if (!swa16_cpu_flgs_get(cpu, flg, &temp_out))
    {
        return false;
    }

    *out = (temp_out == false);

    return true;
}

bool swa16_cpu_flgs_ishi(
    const swa16_cpu_t* cpu,
    swa16_cpu_flgs_t   flg,
    bool*              out)
{
    swa16_flag_t temp_out;

    if (!swa16_cpu_flgs_get(cpu, flg, &temp_out))
    {
        return false;
    }

    *out = (temp_out == true);

    return true;
}



bool swa16_cpu_flgs_set(
    swa16_cpu_t*     cpu,
    swa16_cpu_flgs_t flg,
    swa16_flag_t     in)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (flg < SWA16_CPU_FLGS_START ||
        flg > SWA16_CPU_FLGS_END)
    {
        return false;
    }

    cpu->flgs[flg] = in;

    return true;
}

bool swa16_cpu_flgs_tolo(
    swa16_cpu_t*     cpu,
    swa16_cpu_flgs_t flg)
{
    if (!swa16_cpu_flgs_set(cpu, flg, false))
    {
        return false;
    }

    return true;
}

bool swa16_cpu_flgs_tohi(
    swa16_cpu_t*     cpu,
    swa16_cpu_flgs_t flg)
{
    if (!swa16_cpu_flgs_set(cpu, flg, true))
    {
        return false;
    }

    return true;
}



swa16_word_t swa16_cpu_flgs_to(swa16_cpu_flgs_t flg)
{
    return (swa16_word_t)flg;
}

swa16_cpu_flgs_t swa16_cpu_flgs_from(swa16_word_t value)
{
    if (value > SWA16_CPU_FLGS_END)
    {
        return SWA16_CPU_FLGS_NONE;
    }

    return (swa16_cpu_flgs_t)value;
}



const char* swa16_cpu_flgs_to_name(swa16_cpu_flgs_t flg)
{
    switch (flg)
    {
    case 0x0000: return "ZERO";
    case 0x0001: return "BORROW";
    case 0x0002: return "NEGATIVE";
    case 0x0003: return "OVERFLOW";
    case 0x0004: return "UPDATE";
    case 0x0005: return "EVALUATE";

    case 0xFFFF: return "NONE";

    default:     return "NONE";
    }
}

swa16_cpu_flgs_t swa16_cpu_flgs_from_name(const char* name)
{
    if (strcmp(name,     "ZERO") == 0) return SWA16_CPU_FLGS_ZERO;
    if (strcmp(name,   "BORROW") == 0) return SWA16_CPU_FLGS_BORROW;
    if (strcmp(name, "NEGATIVE") == 0) return SWA16_CPU_FLGS_NEGATIVE;
    if (strcmp(name, "OVERFLOW") == 0) return SWA16_CPU_FLGS_OVERFLOW;
    if (strcmp(name,   "UPDATE") == 0) return SWA16_CPU_FLGS_UPDATE;
    if (strcmp(name, "EVALUATE") == 0) return SWA16_CPU_FLGS_EVALUATE;

    if (strcmp(name,     "NONE") == 0) return SWA16_CPU_FLGS_NONE;

    return SWA16_CPU_FLGS_NONE;
}



static void printex_callback(swa16_cpu_flgs_t flg, swa16_flag_t value)
{
    printf("%d: %d\n", flg, value);
}

bool swa16_cpu_flgs_print(
    const swa16_cpu_t* cpu)
{
    return swa16_cpu_flgs_exprint(
        cpu, printex_callback
    );
}

bool swa16_cpu_flgs_exprint(
    const swa16_cpu_t* cpu,
    void               (*callback)(swa16_cpu_flgs_t flg, swa16_flag_t value))
{
    if (cpu == NULL || callback == NULL)
    {
        return false;
    }

    for (swa16_word_t i = SWA16_CPU_FLGS_START; i < SWA16_CPU_FLGS_SIZE; ++i)
    {
        swa16_flag_t out;

        if (!swa16_cpu_flgs_get(cpu, i, &out))
        {
            continue;
        }

        callback(i, out);
    }

    return true;
}



bool swa16_cpu_flgs_load(swa16_cpu_t* cpu, const char* path)
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

    fread(cpu->flgs, sizeof(cpu->flgs), SWA16_CPU_FLGS_SIZE, in);

    fclose(in);

    return true;
}

bool swa16_cpu_flgs_unload(const swa16_cpu_t* cpu, const char* path)
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

    fwrite(cpu->flgs, sizeof(cpu->flgs), SWA16_CPU_FLGS_SIZE, out);

    fclose(out);

    return true;
}
