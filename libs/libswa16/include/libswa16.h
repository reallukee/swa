//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  libswa16.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_LIBSWA16_H
#define LIBSWA16_LIBSWA16_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/binint.h>

#include <mac.h>

#include <isa.h>
#include <cpu.h>
#include <mem.h>

SWA16_NAMESPACE_BEGIN

#define LIBSWA16_VERSION_H     200
#define LIBSWA16_MIN_VERSION_H 200
#define LIBSWA16_API_VERSION_H 200
#define LIBSWA16_ISA_VERSION_H 100

LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_VERSION;
LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_MIN_VERSION;
LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_API_VERSION;
LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_ISA_VERSION;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_LIBSWA16_H
