//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  binint.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_TYPES_BININT_H
#define LIBSWA16_TYPES_BININT_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

SWA16_NAMESPACE_BEGIN

typedef uint8_t  swa16_byte_t;
typedef int8_t   swa16_sbyte_t;

#define SWA16_BYTE_MIN  0x0000
#define SWA16_BYTE_MAX  0x00FF
#define SWA16_SBYTE_MIN 0x0080
#define SWA16_SBYTE_MAX 0x007F

typedef uint16_t swa16_word_t;
typedef int16_t  swa16_sword_t;

#define SWA16_WORD_MIN  0x0000
#define SWA16_WORD_MAX  0xFFFF
#define SSWA16_WORD_MIN 0x8000
#define SSWA16_WORD_MAX 0x7FFF

LIBSWA16_API swa16_byte_t swa16_binint_gwlo(swa16_word_t word);
LIBSWA16_API swa16_byte_t swa16_binint_gwhi(swa16_word_t word);
LIBSWA16_API swa16_word_t swa16_binint_swlo(swa16_word_t word, swa16_byte_t byte);
LIBSWA16_API swa16_word_t swa16_binint_swhi(swa16_word_t word, swa16_byte_t byte);

LIBSWA16_API bool swa16_binint_addwof (swa16_word_t op1, swa16_word_t op2);
LIBSWA16_API bool swa16_binint_addswof(swa16_sword_t op1, swa16_sword_t op2);
LIBSWA16_API bool swa16_binint_subwof (swa16_word_t op1, swa16_word_t op2);
LIBSWA16_API bool swa16_binint_subswof(swa16_sword_t op1, swa16_sword_t op2);

typedef uint32_t swa16_long_t;
typedef uint32_t swa16_slong_t;

#define SWA16_LONG_MIN  0x00000000
#define SWA16_LONG_MAX  0xFFFFFFFF
#define SWA16_SLONG_MIN 0x80000000
#define SWA16_SLONG_MAX 0x7FFFFFFF

SWA16_NAMESPACE_END

#endif // !LIBSWA16_TYPES_BININT_H
