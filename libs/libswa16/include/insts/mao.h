//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mao.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_INSTS_MAO_H
#define LIBSWA16_ISA_INSTS_MAO_H

#include <isa.h>
#include <fmt.h>
#include <ctx.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mac swa16_mac_t;

LIBSWA16_API swa16_isa_sign_t swa16_isa_insts_ldd(const swa16_mac_t*      mac,
                                                  const swa16_isa_inst_t* inst);

LIBSWA16_API swa16_isa_sign_t swa16_isa_insts_std(const swa16_mac_t*      mac,
                                                  const swa16_isa_inst_t* inst);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_INSTS_MAO_H
