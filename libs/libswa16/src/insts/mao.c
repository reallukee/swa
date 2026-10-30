//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mao.c
//
//  https://github.com/reallukee/swa
//

#include <insts/mao.h>

#include "macint.h"

static swa16_isa_sign_t swa16_insts_ld(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst,
    swa16_cpu_regs_t        dest,
    swa16_word_t            srce,
    swa16_word_t*           result)
{
    switch (inst->mode)
    {
    case SWA16_ISA_MODE_WORD:
        if (!swa16_mem_wrds_get(mac->ram, srce, result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        break;

    case SWA16_ISA_MODE_BYTE:
        swa16_byte_t loresult;

        if (!swa16_mem_wrds_getlo(mac->ram, srce, &loresult))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        *result = (swa16_word_t)loresult;

        break;

    case SWA16_ISA_MODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

    default:                  return SWA16_ISA_SIGN_CRITICAL;
    }

    if (!swa16_cpu_regs_set(mac->cpu, dest, *result))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}

static swa16_isa_sign_t swa16_insts_sd(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst,
    swa16_word_t            dest,
    swa16_cpu_regs_t        srce,
    swa16_word_t*           result)
{
    switch (inst->mode)
    {
    case SWA16_ISA_MODE_WORD:
        if (!swa16_cpu_regs_get(mac->cpu, srce, result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        break;

    case SWA16_ISA_MODE_BYTE:
        swa16_byte_t loresult;

        if (!swa16_cpu_regs_getlo(mac->cpu, srce, &loresult))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        *result = (swa16_word_t)loresult;

        break;

    case SWA16_ISA_MODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

    default:                  return SWA16_ISA_SIGN_CRITICAL;
    }

    if (!swa16_mem_wrds_set(mac->ram, dest, *result))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}

static swa16_isa_sign_t swa16_insts_mao(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst,
    void*                   dest,
    void*                   srce)
{
    swa16_flag_t evaluate_result;

    if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_EVALUATE, &evaluate_result))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    bool execute = true;

    if (evaluate_result)
    {
        execute = swa16_ctx_evaluate(mac->cpu, inst);
    }

    swa16_word_t result;

    if (execute)
    {
        switch (inst->opcode)
        {
        case SWA16_ISA_OPCODE_LDD:
            if (swa16_insts_ld(
                    mac, inst, *(swa16_cpu_regs_t*)dest, *(swa16_word_t*)srce, &result
               ) == SWA16_ISA_SIGN_CRITICAL)
            {
                return SWA16_ISA_SIGN_CRITICAL;
            }

        case SWA16_ISA_OPCODE_STD:
            if (swa16_insts_sd(
                    mac, inst, *(swa16_word_t*)dest, *(swa16_cpu_regs_t*)srce, &result
               ) == SWA16_ISA_SIGN_CRITICAL)
            {
                return SWA16_ISA_SIGN_CRITICAL;
            }

        case SWA16_ISA_OPCODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

        default:                    return SWA16_ISA_SIGN_CRITICAL;
        }

        swa16_flag_t update_result;

        if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_UPDATE, &update_result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }
        else
        {
            if (update_result)
            {
                swa16_ctx_update(mac->cpu, result);
            }
        }

        if (!swa16_cpu_regs_set(mac->cpu, *(swa16_cpu_regs_t*)dest, result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}

swa16_isa_sign_t swa16_insts_ldd(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst)
{
    swa16_fmt_argfm_t fmt_argfm;

    if (!swa16_fmt_inst_to_argfm(mac->cpu, inst, &fmt_argfm))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_cpu_regs_t dest = fmt_argfm.dest;
    swa16_word_t     srce = fmt_argfm.srce;

#ifdef LIBSWA16_EXPERIMENTAL
    return swa16_insts_mao(mac, inst, &dest, &srce);
#endif

    swa16_flag_t evaluate_result;

    if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_EVALUATE, &evaluate_result))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    bool execute = true;

    if (evaluate_result)
    {
        execute = swa16_ctx_evaluate(mac->cpu, inst);
    }

    swa16_word_t result;

    if (execute)
    {
        if (swa16_insts_ld(mac, inst, dest, srce, &result) == SWA16_ISA_SIGN_CRITICAL)
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        swa16_flag_t update_result;

        if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_UPDATE, &update_result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }
        else
        {
            if (update_result)
            {
                swa16_ctx_update(mac->cpu, result);
            }
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}

swa16_isa_sign_t swa16_insts_std(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst)
{
    swa16_fmt_argtm_t fmt_argtm;

    if (!swa16_fmt_inst_to_argtm(mac->cpu, inst, &fmt_argtm))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_word_t     dest = fmt_argtm.dest;
    swa16_cpu_regs_t srce = fmt_argtm.srce;

#ifdef LIBSWA16_EXPERIMENTAL
    return swa16_insts_mao(mac, inst, &dest, &srce);
#endif

    swa16_flag_t evaluate_result;

    if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_EVALUATE, &evaluate_result))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    bool execute = true;

    if (evaluate_result)
    {
        execute = swa16_ctx_evaluate(mac->cpu, inst);
    }

    swa16_word_t result;

    if (execute)
    {
        if (swa16_insts_sd(mac, inst, dest, srce, &result) == SWA16_ISA_SIGN_CRITICAL)
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        swa16_flag_t update_result;

        if (!swa16_cpu_flgs_get(mac->cpu, SWA16_CPU_FLGS_UPDATE, &update_result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }
        else
        {
            if (update_result)
            {
                swa16_ctx_update(mac->cpu, result);
            }
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}
