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

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <isa/sign.h>
#include <isa/opcode.h>
#include <isa/mode.h>
#include <isa/cond.h>
#include <isa/inst.h>

SWA16_NAMESPACE_BEGIN

#define SWA16_ISA_IDENTIFIER_H 1600
#define SWA16_ISA_VERSION_H    1000

LIBSWA16_EXTERN LIBSWA16_DLL const swa16_word_t SWA16_ISA_IDENTIFIER;
LIBSWA16_EXTERN LIBSWA16_DLL const swa16_word_t SWA16_ISA_VERSION;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_ISA_H
