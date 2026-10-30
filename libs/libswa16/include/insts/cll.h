//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cll.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_INSTS_CLL_H
#define LIBSWA16_INSTS_CLL_H

#include <isa.h>
#include <fmt.h>
#include <ctx.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mac swa16_mac_t;

typedef enum swa16_ecll_code
{
    SWA16_ECALL_CODE_EVALUATE = 0x0000, // 0x0000 --- EVALUATE
    SWA16_ECALL_CODE_UPDATE   = 0x0001, // 0x0001 --- UPDATE

    SWA16_ECALL_CODE_NONE     = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_ecll_code_t;

typedef enum swa16_scll_code
{
    SWA16_SCALL_CODE_INP  = 0x0000, // 0x0000 --- INP
    SWA16_SCALL_CODE_OUT  = 0x0001, // 0x0001 --- OUT

    SWA16_SCALL_CODE_NONE = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_scll_code_t;

LIBSWA16_API swa16_isa_sign_t swa16_insts_cll(
    const swa16_mac_t*      mac,
    const swa16_isa_inst_t* inst);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_INSTS_CLL_H
