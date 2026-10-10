//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mode.c
//
//  https://github.com/reallukee/swa
//

#include <isa/mode.h>

swa16_isa_mode_t swa16_isa_mode_from(swa16_word_t value)
{
    switch (value)
    {
    case 0x0000: return SWA16_ISA_MODE_REG;
    case 0x0001: return SWA16_ISA_MODE_IMM;

    case 0xFFFF: return SWA16_ISA_MODE_NONE;

    default:     return SWA16_ISA_MODE_NONE;
    }
}

const char* swa16_isa_mode_to_name(swa16_isa_mode_t mode)
{
    switch (mode)
    {
    case SWA16_ISA_MODE_REG:  return "REG";
    case SWA16_ISA_MODE_IMM:  return "IMM";

    case SWA16_ISA_MODE_NONE: return "NONE";

    default:                  return "NONE";
    }
}

swa16_isa_mode_t swa16_isa_mode_from_name(const char* name)
{
    if (strcmp(name,  "REG") == 0) return SWA16_ISA_MODE_REG;
    if (strcmp(name,  "IMM") == 0) return SWA16_ISA_MODE_IMM;

    if (strcmp(name, "NONE") == 0) return SWA16_ISA_MODE_NONE;

    return SWA16_ISA_MODE_NONE;
}
