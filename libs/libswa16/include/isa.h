//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  isa.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_H
#define LIBSWA16_ISA_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/binint.h>

#include <isa/opcode.h>
#include <isa/mode.h>
#include <isa/cond.h>

SWA16_NAMESPACE_BEGIN

typedef enum swa16_sign
{
    SWA16_SIGN_NEXT           = 0x0000, // 0x0000 --- NEXT
    SWA16_SIGN_JUMP           = 0x0001, // 0x0001 --- JUMP
    SWA16_SIGN_END_OF_PROGRAM = 0x0002, // 0x0002 --- END_OF_PROGRAM
    SWA16_SIGN_SHUTDOWN       = 0x0003, // 0x0003 --- SHUTDOWN
    SWA16_SIGN_STOP           = 0x0004, // 0x0004 --- STOP
    SWA16_SIGN_RESUME         = 0x0005, // 0x0005 --- RESUME
    SWA16_SIGN_OK             = 0x0006, // 0x0006 --- OK
    SWA16_SIGN_DANGER         = 0x0007, // 0x0007 --- DANGER
    SWA16_SIGN_FAIL           = 0x0008, // 0x0008 --- FAIL
    SWA16_SIGN_CRITICAL       = 0x0009, // 0x0009 --- CRITICAL

    SWA16_SIGN_NONE           = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_sign_t;

typedef struct swa16_inst swa16_inst_t;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_H
