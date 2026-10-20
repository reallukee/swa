//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  fmt.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_FMT_H
#define LIBSWA16_FMT_H

#include <utils/header.h>
#include <utils/export.h>
#include <utils/macros.h>

#include <types/addr.h>
#include <types/binint.h>
#include <types/flag.h>

#include <isa.h>
#include <cpu.h>
#include <mem.h>

SWA16_NAMESPACE_BEGIN

typedef struct swa16_fmt_argn
{
    swa16_cpu_regs_t dest;
    swa16_word_t     arg0;
    swa16_word_t     arg1;
} swa16_fmt_argn_t;

LIBSWA16_API bool swa16_fmt_inst_to_argn(
    const swa16_cpu_t*      cpu,
    const swa16_isa_inst_t* inst,
    swa16_fmt_argn_t*       fmt_argn);



typedef struct swa16_fmt_argf
{
    swa16_word_t argf;
} swa16_fmt_argf_t;

LIBSWA16_API bool swa16_fmt_inst_to_argf(
    const swa16_cpu_t*      cpu,
    const swa16_isa_inst_t* inst,
    swa16_fmt_argf_t*       fmt_argf);



typedef struct swa16_fmt_argfm
{
    swa16_cpu_regs_t dest;
    swa16_word_t     srce;
} swa16_fmt_argfm_t;

LIBSWA16_API bool swa16_fmt_inst_to_argfm(
    const swa16_cpu_t*      cpu,
    const swa16_isa_inst_t* inst,
    swa16_fmt_argfm_t*      fmt_argfm);



typedef struct swa16_fmt_argtm
{
    swa16_word_t     dest;
    swa16_cpu_regs_t srce;
} swa16_fmt_argtm_t;

LIBSWA16_API bool swa16_fmt_inst_to_argtm(
    const swa16_cpu_t*      cpu,
    const swa16_isa_inst_t* inst,
    swa16_fmt_argtm_t*      fmt_argtm);

SWA16_NAMESPACE_END

#endif // !LIBSWA16_FMT_H
