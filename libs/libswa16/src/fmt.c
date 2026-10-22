//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  fmt.c
//
//  https://github.com/reallukee/swa
//

#include <fmt.h>

#include "isaint.h"

bool swa16_fmt_inst_to_argn(const swa16_cpu_t*      cpu,
                            const swa16_isa_inst_t* inst,
                            swa16_fmt_argn_t*       fmt_argn)
{
    if (cpu == NULL || inst == NULL || fmt_argn == NULL)
    {
        return false;
    }

    swa16_cpu_regs_t dest = swa16_cpu_regs_from(inst->arg0);

    swa16_word_t arg0 = 0;

    if (!swa16_cpu_regs_isGp(dest))
    {
        return false;
    }

    arg0 = inst->arg0;

    if (!swa16_cpu_regs_get(cpu, dest, &arg0))
    {
        return false;
    }

    if (inst->mode == SWA16_ISA_MODE_REG)
    {
        swa16_cpu_regs_t reop = swa16_cpu_regs_from(inst->arg1);

        swa16_word_t arg1 = 0;

        if (!swa16_cpu_regs_isGp(reop))
        {
            return false;
        }

        arg1 = inst->arg1;

        if (!swa16_cpu_regs_get(cpu, reop, &arg1))
        {
            return false;
        }

        fmt_argn->dest = dest;
        fmt_argn->arg0 = arg0;
        fmt_argn->arg1 = arg1;
    }
    else
    {
        swa16_word_t arg1 = 0;

        arg1 = inst->arg1;

        fmt_argn->dest = dest;
        fmt_argn->arg0 = arg0;
        fmt_argn->arg1 = arg1;
    }

    return true;
}

bool swa16_fmt_inst_to_argf(const swa16_cpu_t*      cpu,
                            const swa16_isa_inst_t* inst,
                            swa16_fmt_argf_t*       fmt_argf)
{
    if (cpu == NULL || inst == NULL || fmt_argf == NULL)
    {
        return false;
    }

    if (inst->mode == SWA16_ISA_MODE_REG)
    {
        swa16_cpu_regs_t reop = swa16_cpu_regs_from(inst->argf);

        swa16_word_t argf = 0;

        if (!swa16_cpu_regs_isGp(reop))
        {
            return false;
        }

        argf = inst->argf;

        if (!swa16_cpu_regs_get(cpu, reop, &argf))
        {
            return false;
        }

        fmt_argf->argf = argf;
    }
    else
    {
        swa16_word_t argf = 0;

        argf = inst->argf;

        fmt_argf->argf = argf;
    }

    return true;
}

bool swa16_fmt_inst_to_argfm(const swa16_cpu_t*      cpu,
                             const swa16_isa_inst_t* inst,
                             swa16_fmt_argfm_t*      fmt_argfm)
{
    if (cpu == NULL || inst == NULL || fmt_argfm == NULL)
    {
        return false;
    }

    swa16_cpu_regs_t dest = swa16_cpu_regs_from(inst->arg0);

    swa16_addr_t addr = 0;

    if (!swa16_cpu_regs_isGp(dest))
    {
        return false;
    }

    addr = inst->arg1;

    swa16_cpu_regs_t srce = swa16_cpu_regs_from(addr);

    if (!swa16_cpu_regs_isGp(srce))
    {
        return false;
    }

    if (!swa16_cpu_regs_get(cpu, srce, &addr))
    {
        return false;
    }

    fmt_argfm->dest = dest;
    fmt_argfm->srce = addr;

    return true;
}

bool swa16_fmt_inst_to_argtm(const swa16_cpu_t*      cpu,
                             const swa16_isa_inst_t* inst,
                             swa16_fmt_argtm_t*      fmt_argtm)
{
    if (cpu == NULL || inst == NULL || fmt_argtm == NULL)
    {
        return false;
    }

    swa16_cpu_regs_t srce = swa16_cpu_regs_from(inst->arg0);

    swa16_addr_t addr = 0;

    if (!swa16_cpu_regs_isGp(srce))
    {
        return false;
    }

    addr = inst->arg0;

    swa16_cpu_regs_t dest = swa16_cpu_regs_from(addr);

    if (!swa16_cpu_regs_isGp(dest))
    {
        return false;
    }

    fmt_argtm->dest = addr;
    fmt_argtm->srce = srce;

    return true;
}
