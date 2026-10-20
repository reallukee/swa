//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  ctx.c
//
//  https://github.com/reallukee/swa
//

#include <ctx.h>

#include "isaint.h"

bool swa16_ctx_evaluate(
    const swa16_cpu_t*      cpu,
    const swa16_isa_inst_t* inst)
{
    if (cpu == NULL || inst == NULL)
    {
        return false;
    }

    swa16_flag_t zero     = SWA16_FLAG_LO;
    swa16_flag_t borrow   = SWA16_FLAG_LO;
    swa16_flag_t negative = SWA16_FLAG_LO;
    swa16_flag_t overflow = SWA16_FLAG_LO;

    swa16_cpu_flgs_get(cpu, SWA16_CPU_FLGS_ZERO,         &zero);
    swa16_cpu_flgs_get(cpu, SWA16_CPU_FLGS_BORROW,     &borrow);
    swa16_cpu_flgs_get(cpu, SWA16_CPU_FLGS_NEGATIVE, &negative);
    swa16_cpu_flgs_get(cpu, SWA16_CPU_FLGS_OVERFLOW, &overflow);

    swa16_isa_cond_t cond = inst->cond;

    switch (cond)
    {
    case SWA16_ISA_COND_ALWAYS:            return true;
    case SWA16_ISA_COND_NOT_ALWAYS:        return !true;
    case SWA16_ISA_COND_EQUAL:             return zero;
    case SWA16_ISA_COND_NOT_EQUAL:         return !zero;
    case SWA16_ISA_COND_SIGNED_LESS:       return (negative != overflow);
    case SWA16_ISA_COND_SIGNED_NOT_LESS:   return (negative == overflow);
    case SWA16_ISA_COND_UNSIGNED_LESS:     return borrow;
    case SWA16_ISA_COND_UNSIGNED_NOT_LESS: return !borrow;

    case SWA16_ISA_COND_NONE:              return true;

    default:                               return true;
    }

    return true;
}



swa16_flag_t swa16_ctx_compute_zero(swa16_long_t result)
{
    return ((swa16_long_t)result & SWA16_WORD_MAX) == 0;
}

swa16_flag_t swa16_ctx_compute_borrow(swa16_long_t result)
{
    return ((swa16_long_t)result > SWA16_WORD_MAX ||
            (swa16_long_t)result < SWA16_WORD_MIN);
}

swa16_flag_t swa16_ctx_compute_negative(swa16_long_t result)
{
    return ((swa16_long_t)result & SSWA16_WORD_MAX) != 0;
}

swa16_flag_t swa16_ctx_compute_overflow(swa16_long_t result)
{
    return ((swa16_long_t)result > SSWA16_WORD_MAX ||
            (swa16_long_t)result < SSWA16_WORD_MIN);
}



bool swa16_ctx_update(
    swa16_cpu_t* cpu,
    swa16_long_t result)
{
    if (cpu == NULL)
    {
        return false;
    }

    swa16_flag_t zero     = swa16_ctx_compute_zero    (result);
    swa16_flag_t borrow   = swa16_ctx_compute_borrow  (result);
    swa16_flag_t negative = swa16_ctx_compute_negative(result);
    swa16_flag_t overflow = swa16_ctx_compute_overflow(result);

    swa16_cpu_flgs_set(cpu, SWA16_CPU_FLGS_ZERO,         zero);
    swa16_cpu_flgs_set(cpu, SWA16_CPU_FLGS_BORROW,     borrow);
    swa16_cpu_flgs_set(cpu, SWA16_CPU_FLGS_NEGATIVE, negative);
    swa16_cpu_flgs_set(cpu, SWA16_CPU_FLGS_OVERFLOW, overflow);

    return true;
}
