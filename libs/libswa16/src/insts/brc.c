//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  brc.c
//
//  https://github.com/reallukee/swa
//

#include <insts/brc.h>

#include "macint.h"

static swa16_isa_sign_t swa16_isa_insts_brc(const swa16_mac_t*      mac,
                                            const swa16_isa_inst_t* inst)
{
    swa16_fmt_argf_t fmt_argf;

    if (!swa16_fmt_inst_to_argf(mac->cpu, inst, &fmt_argf))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_word_t argf = fmt_argf.argf;

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
        case SWA16_ISA_OPCODE_JMPR:
            if (inst->mode == SWA16_ISA_MODE_REG)
            {
                argf &= 0xFFFF;

                if ((swa16_sword_t)argf >= 0x0000)
                {
                    if (!swa16_cpu_pc_add(mac->cpu, argf))
                    {
                        return SWA16_ISA_SIGN_CRITICAL;
                    }
                }
                else
                {
                    if (!swa16_cpu_pc_sub(mac->cpu, argf))
                    {
                        return SWA16_ISA_SIGN_CRITICAL;
                    }
                }
            }
            else
            {
                argf &= 0x00FF;

                if ((swa16_sbyte_t)argf >= 0x0000)
                {
                    if (!swa16_cpu_pc_add(mac->cpu, argf))
                    {
                        return SWA16_ISA_SIGN_CRITICAL;
                    }
                }
                else
                {
                    if (!swa16_cpu_pc_sub(mac->cpu, argf))
                    {
                        return SWA16_ISA_SIGN_CRITICAL;
                    }
                }
            }

            return SWA16_ISA_SIGN_JUMP;

        case SWA16_ISA_OPCODE_JMPA:
            if (!swa16_cpu_pc_set(mac->cpu, SWA16_CPU_PC_ENTRYPOINT + argf))
            {
                return SWA16_ISA_SIGN_CRITICAL;
            }

            return SWA16_ISA_SIGN_JUMP;

        case SWA16_ISA_OPCODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

        default:                    return SWA16_ISA_SIGN_CRITICAL;
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}

swa16_isa_sign_t swa16_isa_insts_jmpr(const swa16_mac_t*      mac,
                                      const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_brc(mac, inst);
}

swa16_isa_sign_t swa16_isa_insts_jmpa(const swa16_mac_t*      mac,
                                      const swa16_isa_inst_t* inst)
{
    return swa16_isa_insts_brc(mac, inst);
}
