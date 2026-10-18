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

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <mac.h>

#include <isa.h>
#include <cpu.h>
#include <mem.h>

SWA16_NAMESPACE_BEGIN

#define LIBSWA16_VERSION_H     200
#define LIBSWA16_MIN_VERSION_H 200

LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_VERSION;
LIBSWA16_EXTERN LIBSWA16_DLL const uint64_t LIBSWA16_MIN_VERSION;

SWA16_NAMESPACE_END

#endif // !LIBSWA16_LIBSWA16_H
