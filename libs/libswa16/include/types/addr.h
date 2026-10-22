//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  addr.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_TYPES_ADDR_H
#define LIBSWA16_TYPES_ADDR_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/binint.h>

LIBSWA16_NAMESPACE_BEGIN

#define SWA16_ADDR_START 0x0001
#define SWA16_ADDR_END   0xFFFE
#define SWA16_ADDR_SIZE  (SWA16_ADDR_END + 1)

#define SWA16_ADDR_GP
#define SWA16_ADDR_NULL  0x0000
#define SWA16_ADDR_NONE  0xFFFF

LIBSWA16_EXTERN const swa16_word_t SWA16_ADDR_ENTRYPOINT;

typedef swa16_word_t swa16_addr_t;

LIBSWA16_API bool swa16_addr_isGp  (swa16_addr_t addr);
LIBSWA16_API bool swa16_addr_isNull(swa16_addr_t addr);
LIBSWA16_API bool swa16_addr_isNone(swa16_addr_t addr);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_TYPES_ADDR_H
