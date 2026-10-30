//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  flw.c
//
//  https://github.com/reallukee/swa
//

#include <insts/flw.h>

#include "macint.h"

swa16_isa_sign_t swa16_isa_insts_flw(const swa16_mac_t*      mac,
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

    if (execute)
    {
        switch (inst->mode)
        {
        case SWA16_ISA_MODE_NEXT:     return SWA16_ISA_SIGN_NEXT;
        case SWA16_ISA_MODE_SHUTDOWN: return SWA16_ISA_SIGN_SHUTDOWN;

        case SWA16_ISA_MODE_NONE:     return SWA16_ISA_SIGN_CRITICAL;

        default:                      return SWA16_ISA_SIGN_CRITICAL;
        }
    }

    return SWA16_ISA_SIGN_NEXT;
}
