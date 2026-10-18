//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  sign.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_SIGN_H
#define LIBSWA16_ISA_SIGN_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_ISA_SIGN_START 0x0000
#define SWA16_ISA_SIGN_END   0x0007
#define SWA16_ISA_SIGN_SIZE  (SWA16_ISA_SIGN_END + 1)

typedef enum swa16_sign : swa16_word_t
{
    SWA16_ISA_SIGN_NEXT           = 0x0000, // 0x0000 --- NEXT
    SWA16_ISA_SIGN_JUMP           = 0x0001, // 0x0001 --- JUMP
    SWA16_ISA_SIGN_END_OF_PROGRAM = 0x0002, // 0x0002 --- END_OF_PROGRAM
    SWA16_ISA_SIGN_SHUTDOWN       = 0x0003, // 0x0003 --- SHUTDOWN
    SWA16_ISA_SIGN_STOP           = 0x0004, // 0x0004 --- STOP
    SWA16_ISA_SIGN_RESUME         = 0x0005, // 0x0005 --- RESUME
    SWA16_ISA_SIGN_OK             = 0x0006, // 0x0006 --- OK
    SWA16_ISA_SIGN_DANGER         = 0x0007, // 0x0007 --- DANGER
    SWA16_ISA_SIGN_FAIL           = 0x0008, // 0x0008 --- FAIL
    SWA16_ISA_SIGN_CRITICAL       = 0x0009, // 0x0009 --- CRITICAL

    SWA16_ISA_SIGN_NONE           = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_isa_sign_t;

LIBSWA16_API swa16_word_t     swa16_isa_sign_to  (swa16_isa_sign_t sign);
LIBSWA16_API swa16_isa_sign_t swa16_isa_sign_from(swa16_word_t value);

LIBSWA16_API const char*      swa16_isa_sign_to_name  (swa16_isa_sign_t sign);
LIBSWA16_API swa16_isa_sign_t swa16_isa_sign_from_name(const char* name);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_SIGN_H
