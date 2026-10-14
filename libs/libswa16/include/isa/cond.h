//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cond.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_COND_H
#define LIBSWA16_ISA_COND_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_ISA_COND_START 0x0000
#define SWA16_ISA_COND_END   0x0007
#define SWA16_ISA_COND_SIZE  (SWA16_ISA_COND_END + 1)

typedef enum swa16_isa_cond : swa16_word_t
{
    SWA16_ISA_COND_ALWAYS            = 0x0000, // 0x0000 --- ALWAYS
    SWA16_ISA_COND_NOT_ALWAYS        = 0x0001, // 0x0001 --- NOT ALWAYS
    SWA16_ISA_COND_EQUAL             = 0x0002, // 0x0002 --- EQUAL
    SWA16_ISA_COND_NOT_EQUAL         = 0x0003, // 0x0003 --- NOT EQUAL
    SWA16_ISA_COND_SIGNED_LESS       = 0x0004, // 0x0004 --- SIGNED LESS
    SWA16_ISA_COND_SIGNED_NOT_LESS   = 0x0005, // 0x0005 --- SIGNED NOT LESS
    SWA16_ISA_COND_UNSIGNED_LESS     = 0x0006, // 0x0006 --- UNSIGNED LESS
    SWA16_ISA_COND_UNSIGNED_NOT_LESS = 0x0007, // 0x0007 --- UNSIGNED NOT LESS

    SWA16_ISA_COND_NONE              = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_isa_cond_t;

LIBSWA16_API swa16_word_t     swa16_isa_cond_to  (swa16_isa_cond_t cond);
LIBSWA16_API swa16_isa_cond_t swa16_isa_cond_from(swa16_word_t value);

LIBSWA16_API const char*      swa16_isa_cond_to_name  (swa16_isa_cond_t cond);
LIBSWA16_API swa16_isa_cond_t swa16_isa_cond_from_name(const char* name);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_COND_H
