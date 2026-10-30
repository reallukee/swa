//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  pc.c
//
//  https://github.com/reallukee/swa
//

#include <cpu/pc.h>

#include "isaint.h"
#include "cpuint.h"
#include "memint.h"

const swa16_addr_t SWA16_CPU_PC_ENTRYPOINT = 0x0001;

bool swa16_cpu_pc_init(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->pc_init)
    {
        return true;
    }

    cpu->pc = SWA16_CPU_PC_ENTRYPOINT;

    cpu->pc_init = true;

    return true;
}

bool swa16_cpu_pc_isInit(const swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    return cpu->pc_init;
}



bool swa16_cpu_pc_get(const swa16_cpu_t* cpu, swa16_word_t* out)
{
    if (cpu == NULL || out == NULL)
    {
        return false;
    }

    *out = cpu->pc;

    return true;
}

bool swa16_cpu_pc_getra(const swa16_cpu_t* cpu, swa16_word_t* out)
{
    if (!swa16_cpu_pc_get(cpu, out))
    {
        return false;
    }

    *out = *out + 1;

    return true;
}



bool swa16_cpu_pc_set(swa16_cpu_t* cpu, swa16_word_t in)
{
    if (cpu == NULL)
    {
        return false;
    }

    cpu->pc = in;

    return true;
}

bool swa16_cpu_pc_setra(swa16_cpu_t* cpu, swa16_word_t in)
{
    in = in + 1;

    if (!swa16_cpu_pc_set(cpu, in))
    {
        return false;
    }

    return true;
}



bool swa16_cpu_pc_inc(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (!swa16_cpu_pc_isGp(cpu->pc + 1))
    {
        return false;
    }

    cpu->pc++;

    return true;
}

bool swa16_cpu_pc_dec(swa16_cpu_t* cpu)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (!swa16_cpu_pc_isGp(cpu->pc - 1))
    {
        return false;
    }

    cpu->pc--;

    return true;
}



bool swa16_cpu_pc_add(swa16_cpu_t* cpu, swa16_word_t value)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->pc + value < cpu->pc)
    {
        return false;
    }

    cpu->pc += value;

    return true;
}

bool swa16_cpu_pc_sub(swa16_cpu_t* cpu, swa16_word_t value)
{
    if (cpu == NULL)
    {
        return false;
    }

    if (cpu->pc - value > cpu->pc)
    {
        return false;
    }

    cpu->pc -= value;

    return true;
}



bool swa16_cpu_pc_isGp(swa16_addr_t addr)
{
    return swa16_cpu_pc_isNull(addr) && swa16_cpu_pc_isNone(addr);
}

bool swa16_cpu_pc_isNull(swa16_addr_t addr)
{
    return addr == SWA16_CPU_PC_NULL;
}

bool swa16_cpu_pc_isNone(swa16_addr_t addr)
{
    return addr == SWA16_CPU_PC_NONE;
}



swa16_word_t swa16_cpu_pc_to(swa16_addr_t pc)
{
    return (swa16_word_t)pc;
}

swa16_addr_t swa16_cpu_pc_from(swa16_word_t value)
{
    if (value > SWA16_CPU_PC_END)
    {
        return SWA16_CPU_PC_NONE;
    }

    return (swa16_addr_t)value;
}



const char* swa16_cpu_pc_to_name(swa16_addr_t pc)
{
    char* pc_str = calloc(
        16, sizeof(char)
    );

    snprintf(
        pc_str, 16, "PC_ADDR_0x%04X", pc
    );

    return pc_str;
}

swa16_addr_t swa16_cpu_pc_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_CPU_PC_NONE;
    }

    swa16_addr_t addr = SWA16_CPU_PC_NONE;

    if (sscanf(name, "PC_ADDR_0x%hx", &addr) != 1)
    {
        return SWA16_CPU_PC_NONE;
    }

    return addr;
}



static void printex_callback(swa16_addr_t pc, swa16_word_t value)
{
    printf("%d: %d\n", pc, value);
}

bool swa16_cpu_pc_print(
    const swa16_cpu_t* cpu)
{
    return swa16_cpu_pc_exprint(
        cpu, printex_callback
    );
}

bool swa16_cpu_pc_exprint(
    const swa16_cpu_t* cpu,
    void  (*callback)(swa16_addr_t pc, swa16_word_t value))
{
    if (cpu == NULL || callback == NULL)
    {
        return false;
    }

    if (true)
    {
        swa16_word_t out;

        if (!swa16_cpu_pc_get(cpu, &out))
        {
            true;
        }

        callback(0, out);
    }

    return true;
}



bool swa16_cpu_pc_load(swa16_cpu_t* cpu, const char* path)
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

    fread(&cpu->pc, sizeof(cpu->pc), 1, in);

    fclose(in);

    return true;
}

bool swa16_cpu_pc_unload(const swa16_cpu_t* cpu, const char* path)
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

    fwrite(&cpu->pc, sizeof(cpu->pc), 1, out);

    fclose(out);

    return true;
}
