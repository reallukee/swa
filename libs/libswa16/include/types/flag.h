//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  flag.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_TYPES_FLAG_H
#define LIBSWA16_TYPES_FLAG_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/binint.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_FLAG_START 0x0000
#define SWA16_FLAG_END   0x0001
#define SWA16_FLAG_SIZE  (SWA16_FLAG_END + 1)

typedef enum swa16_flag : swa16_word_t
{
    SWA16_FLAG_LO   = 0x0000, // 0x0000 --- LO
    SWA16_FLAG_HI   = 0x0001, // 0x0001 --- HI

    SWA16_FLAG_NONE = 0xFFFF, // 0xFFFF --- Fallback Value
} swa16_flag_t;

LIBSWA16_API swa16_word_t swa16_flag_to  (swa16_flag_t flag);
LIBSWA16_API swa16_flag_t swa16_flag_from(swa16_word_t value);

LIBSWA16_API const char*  swa16_flag_to_name  (swa16_flag_t flag);
LIBSWA16_API swa16_flag_t swa16_flag_from_name(const char* name);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_TYPES_FLAG_H
