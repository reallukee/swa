//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mode.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_ISA_MODE_H
#define LIBSWA16_ISA_MODE_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/binint.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_ISA_MODE_START 0x0000
#define SWA16_ISA_MODE_END   0x0001
#define SWA16_ISA_MODE_SIZE  (SWA16_ISA_MODE_END + 1)

typedef enum swa16_isa_mode
{
    SWA16_ISA_MODE_REG      = 0x0000, // 0x0000 --- REG
    SWA16_ISA_MODE_IMM      = 0x0001, // 0x0001 --- IMM
    SWA16_ISA_MODE_NEXT     = 0x0000, // 0x0000 --- NEXT
    SWA16_ISA_MODE_SHUTDOWN = 0x0001, // 0x0001 --- SHUTDOWN
    SWA16_ISA_MODE_EMULATOR = 0x0000, // 0x0000 --- EMULATOR
    SWA16_ISA_MODE_SYSTEM   = 0x0001, // 0x0001 --- SYSTEM
    SWA16_ISA_MODE_WORD     = 0x0000, // 0x0000 --- WORD
    SWA16_ISA_MODE_BYTE     = 0x0001, // 0x0001 --- BYTE

    SWA16_ISA_MODE_NONE     = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_isa_mode_t;

LIBSWA16_API swa16_isa_mode_t swa16_isa_mode_from     (swa16_word_t value);
LIBSWA16_API const char*      swa16_isa_mode_to_name  (swa16_isa_mode_t mode);
LIBSWA16_API swa16_isa_mode_t swa16_isa_mode_from_name(const char* name);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_MODE_H
