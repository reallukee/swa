//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mov.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_INSTS_MOV_H
#define LIBSWA16_ISA_INSTS_MOV_H

#include <isa.h>
#include <fmt.h>
#include <ctx.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mac swa16_mac_t;

LIBSWA16_API swa16_isa_sign_t swa16_isa_insts_mov(const swa16_mac_t*      mac,
                                                  const swa16_isa_inst_t* inst);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_INSTS_MOV_H
