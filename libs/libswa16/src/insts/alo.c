//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  alo.c
//
//  https://github.com/reallukee/swa
//

#include <insts/alo.h>

#include "macint.h"

static swa16_isa_sign_t swa16_isa_insts_alo(const swa16_mac_t*      mac,
                                            const swa16_isa_inst_t* inst)
{
    swa16_fmt_argn_t fmt_argn;

    if (!swa16_fmt_inst_to_argn(mac->cpu, inst, &fmt_argn))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_cpu_regs_t dest = fmt_argn.dest;
    swa16_word_t     arg0 = fmt_argn.arg0;
    swa16_word_t     arg1 = fmt_argn.arg1;

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

    swa16_long_t result;

    if (execute)
    {
        switch (inst->opcode)
        {
        case SWA16_ISA_OPCODE_ADD:  result = arg0 +  arg1; break;
        case SWA16_ISA_OPCODE_SUB:  result = arg0 -  arg1; break;
        case SWA16_ISA_OPCODE_AND:  result = arg0 &  arg1; break;
        case SWA16_ISA_OPCODE_IOR:  result = arg0 |  arg1; break;
        case SWA16_ISA_OPCODE_XOR:  result = arg0 ^  arg1; break;
        case SWA16_ISA_OPCODE_SHL:  result = arg0 << arg1; break;
        case SWA16_ISA_OPCODE_SHR:  result = arg0 >> arg1; break;
        case SWA16_ISA_OPCODE_SAR:  result = arg0 >> arg1; break;

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

        if (!swa16_cpu_regs_set(mac->cpu, dest, result))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}

swa16_isa_sign_t swa16_isa_insts_add(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_sub(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_and(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_ior(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_xor(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_shl(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_shr(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_sar(const swa16_mac_t*      mac,
                                     const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_alo(mac, inst);
}
