//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  flag.c
//
//  https://github.com/reallukee/swa
//

#include <types/flag.h>

swa16_word_t swa16_flag_to(swa16_flag_t flag)
{
    return (swa16_word_t)flag;
}

swa16_flag_t swa16_flag_from(swa16_word_t value)
{
    if (value > SWA16_FLAG_END)
    {
        return SWA16_FLAG_NONE;
    }

    return (swa16_flag_t)value;
}



const char* swa16_flag_to_name(swa16_flag_t flag)
{
    switch (flag)
    {
    case SWA16_FLAG_LO:   return "LO";
    case SWA16_FLAG_HI:   return "HI";

    case SWA16_FLAG_NONE: return "NONE";

    default:              return "NONE";
    }
}

swa16_flag_t swa16_flag_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_FLAG_NONE;
    }

    if (strcmp(name,   "LO") == 0) return SWA16_FLAG_LO;
    if (strcmp(name,   "HI") == 0) return SWA16_FLAG_HI;

    if (strcmp(name, "NONE") == 0) return SWA16_FLAG_NONE;

    return SWA16_FLAG_NONE;
}
