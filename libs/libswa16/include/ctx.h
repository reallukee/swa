//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  ctx.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_CTX_H
#define LIBSWA16_CTX_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <isa.h>
#include <cpu.h>
#include <mem.h>

SWA16_NAMESPACE_BEGIN

LIBSWA16_API bool swa16_ctx_evaluate(const swa16_cpu_t*      cpu,
                                     const swa16_isa_inst_t* inst);

LIBSWA16_API swa16_flag_t swa16_ctx_compute_zero    (swa16_long_t result);
LIBSWA16_API swa16_flag_t swa16_ctx_compute_borrow  (swa16_long_t result);
LIBSWA16_API swa16_flag_t swa16_ctx_compute_negative(swa16_long_t result);
LIBSWA16_API swa16_flag_t swa16_ctx_compute_overflow(swa16_long_t result);

LIBSWA16_API bool swa16_ctx_update(swa16_cpu_t* cpu,
                                   swa16_long_t result);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_CTX_H
