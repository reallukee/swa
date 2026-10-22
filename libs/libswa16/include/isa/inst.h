//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  inst.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_INST_H
#define LIBSWA16_ISA_INST_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_isa_inst
{
    unsigned opcode : 4;
    unsigned mode   : 1;
    unsigned cond   : 3;

    union
    {
        unsigned argf : 8;

        struct
        {
            unsigned arg0 : 4;
            unsigned arg1 : 4;
        };
    };
} swa16_isa_inst_t;

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_INST_H
