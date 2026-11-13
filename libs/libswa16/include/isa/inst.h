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

#include "utils/header.h"
#include "utils/export.h"
#include "utils/macros.h"

#include "types/addr.h"
#include "types/binint.h"
#include "types/flag.h"

LIBSWA16_NAMESPACE_BEGIN

typedef enum swa16_isa_inst_fmt : swa16_word_t
{
    SWA16_ISA_INST_FMT_ARGN  = 0x0000, // 0x0000 --- ARGN
    SWA16_ISA_INST_FMT_ARGF  = 0x0001, // 0x0001 --- ARGF
    SWA16_ISA_INST_FMT_ARGFM = 0x0002, // 0x0002 --- ARGFM
    SWA16_ISA_INST_FMT_ARGTM = 0x0003, // 0x0003 --- ARGTM

    SWA16_ISA_INST_FMT_NONE  = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_isa_inst_fmt_t;

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
