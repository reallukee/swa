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

swa16_word_t swa16_isa_mode_to(swa16_isa_mode_t mode)
{
    return (swa16_word_t)mode;
}

swa16_isa_mode_t swa16_isa_mode_from(swa16_word_t value)
{
    if (value > SWA16_ISA_MODE_END)
    {
        return SWA16_ISA_MODE_NONE;
    }

    return (swa16_isa_mode_t)value;
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
    if (name == NULL)
    {
        return SWA16_ISA_MODE_NONE;
    }

    if (strcmp(name,  "REG") == 0) return SWA16_ISA_MODE_REG;
    if (strcmp(name,  "IMM") == 0) return SWA16_ISA_MODE_IMM;

    if (strcmp(name, "NONE") == 0) return SWA16_ISA_MODE_NONE;

    return SWA16_ISA_MODE_NONE;
}
