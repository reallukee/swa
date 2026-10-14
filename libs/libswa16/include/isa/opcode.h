//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  opcode.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_OPCODE_H
#define LIBSWA16_ISA_OPCODE_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_ISA_OPCODE_START 0x0000
#define SWA16_ISA_OPCODE_END   0x000F
#define SWA16_ISA_OPCODE_SIZE  (SWA16_ISA_OPCODE_END + 1)

typedef enum swa16_isa_opcode : swa16_word_t
{
    SWA16_ISA_OPCODE_FLW  = 0x0000, // 0x0000 --- FLW
    SWA16_ISA_OPCODE_MOV  = 0x0001, // 0x0001 --- MOV
    SWA16_ISA_OPCODE_ADD  = 0x0002, // 0x0002 --- ADD
    SWA16_ISA_OPCODE_SUB  = 0x0003, // 0x0003 --- SUB
    SWA16_ISA_OPCODE_AND  = 0x0004, // 0x0004 --- AND
    SWA16_ISA_OPCODE_IOR  = 0x0005, // 0x0005 --- IOR
    SWA16_ISA_OPCODE_XOR  = 0x0006, // 0x0006 --- XOR
    SWA16_ISA_OPCODE_SHL  = 0x0007, // 0x0007 --- SHL
    SWA16_ISA_OPCODE_SHR  = 0x0008, // 0x0008 --- SHR
    SWA16_ISA_OPCODE_SAR  = 0x0009, // 0x0009 --- SAR
    SWA16_ISA_OPCODE_CMP  = 0x000A, // 0x000A --- CMP
    SWA16_ISA_OPCODE_CLL  = 0x000B, // 0x000B --- CLL
    SWA16_ISA_OPCODE_JMPR = 0x000C, // 0x000C --- JMPR
    SWA16_ISA_OPCODE_JMPA = 0x000D, // 0x000D --- JMPA
    SWA16_ISA_OPCODE_LDD  = 0x000E, // 0x000E --- LDD
    SWA16_ISA_OPCODE_STD  = 0x000F, // 0x000F --- STD

    SWA16_ISA_OPCODE_NONE = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_isa_opcode_t;

LIBSWA16_API swa16_word_t       swa16_isa_opcode_to  (swa16_isa_opcode_t opcode);
LIBSWA16_API swa16_isa_opcode_t swa16_isa_opcode_from(swa16_word_t value);

LIBSWA16_API const char*        swa16_isa_opcode_to_name  (swa16_isa_opcode_t opcode);
LIBSWA16_API swa16_isa_opcode_t swa16_isa_opcode_from_name(const char* name);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_OPCODE_H
