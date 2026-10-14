//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  cond.c
//
//  https://github.com/reallukee/swa
//

#include <isa/cond.h>

swa16_word_t swa16_isa_cond_to(swa16_isa_cond_t cond)
{
    return (swa16_word_t)cond;
}

swa16_isa_cond_t swa16_isa_cond_from(swa16_word_t value)
{
    if (value > SWA16_ISA_COND_END)
    {
        return SWA16_ISA_COND_NONE;
    }

    return (swa16_isa_cond_t)value;
}



const char* swa16_isa_cond_to_name(swa16_isa_cond_t cond)
{
    switch (cond)
    {
    case SWA16_ISA_COND_ALWAYS:            return "ALWAYS";
    case SWA16_ISA_COND_NOT_ALWAYS:        return "NOT ALWAYS";
    case SWA16_ISA_COND_EQUAL:             return "EQUAL";
    case SWA16_ISA_COND_NOT_EQUAL:         return "NOT EQUAL";
    case SWA16_ISA_COND_SIGNED_LESS:       return "SIGNED LESS";
    case SWA16_ISA_COND_SIGNED_NOT_LESS:   return "SIGNED NOT LESS";
    case SWA16_ISA_COND_UNSIGNED_LESS:     return "UNSIGNED LESS";
    case SWA16_ISA_COND_UNSIGNED_NOT_LESS: return "UNSIGNED NOT LESS";

    case SWA16_ISA_COND_NONE:              return "NONE";

    default:                               return "NONE";
    }
}

swa16_isa_cond_t swa16_isa_cond_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_ISA_COND_NONE;
    }

    if (strcmp(name,            "ALWAYS") == 0) return SWA16_ISA_COND_ALWAYS;
    if (strcmp(name,        "NOT ALWAYS") == 0) return SWA16_ISA_COND_NOT_ALWAYS;
    if (strcmp(name,             "EQUAL") == 0) return SWA16_ISA_COND_EQUAL;
    if (strcmp(name,         "NOT EQUAL") == 0) return SWA16_ISA_COND_NOT_EQUAL;
    if (strcmp(name,       "SIGNED LESS") == 0) return SWA16_ISA_COND_SIGNED_LESS;
    if (strcmp(name,   "SIGNED NOT LESS") == 0) return SWA16_ISA_COND_SIGNED_NOT_LESS;
    if (strcmp(name,     "UNSIGNED LESS") == 0) return SWA16_ISA_COND_UNSIGNED_LESS;
    if (strcmp(name, "UNSIGNED NOT LESS") == 0) return SWA16_ISA_COND_UNSIGNED_NOT_LESS;

    if (strcmp(name,              "NONE") == 0) return SWA16_ISA_COND_NONE;

    return SWA16_ISA_COND_NONE;
}
