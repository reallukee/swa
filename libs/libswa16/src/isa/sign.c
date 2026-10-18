//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  sign.c
//
//  https://github.com/reallukee/swa
//

#include <isa/sign.h>

swa16_word_t swa16_isa_sign_to(swa16_isa_sign_t sign)
{
    return (swa16_word_t)sign;
}

swa16_isa_sign_t swa16_isa_sign_from(swa16_word_t value)
{
    if (value > SWA16_ISA_SIGN_END)
    {
        return SWA16_ISA_SIGN_NONE;
    }

    return (swa16_isa_sign_t)value;
}



const char* swa16_isa_sign_to_name(swa16_isa_sign_t sign)
{
    switch (sign)
    {
    case SWA16_ISA_SIGN_NEXT:           return "NEXT";
    case SWA16_ISA_SIGN_JUMP:           return "JUMP";
    case SWA16_ISA_SIGN_END_OF_PROGRAM: return "END OF PROGRAM";
    case SWA16_ISA_SIGN_SHUTDOWN:       return "SHUTDOWN";
    case SWA16_ISA_SIGN_STOP:           return "STOP";
    case SWA16_ISA_SIGN_RESUME:         return "RESUME";
    case SWA16_ISA_SIGN_OK:             return "OK";
    case SWA16_ISA_SIGN_DANGER:         return "DANGER";
    case SWA16_ISA_SIGN_FAIL:           return "FAIL";
    case SWA16_ISA_SIGN_CRITICAL:       return "CRITICAL";

    case SWA16_ISA_SIGN_NONE:           return "NONE";

    default:                            return "NONE";
    }
}

swa16_isa_sign_t swa16_isa_sign_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_ISA_SIGN_NONE;
    }

    if (strcmp(name,           "NEXT") == 0) return SWA16_ISA_SIGN_NEXT;
    if (strcmp(name,           "JUMP") == 0) return SWA16_ISA_SIGN_JUMP;
    if (strcmp(name, "END OF PROGRAM") == 0) return SWA16_ISA_SIGN_END_OF_PROGRAM;
    if (strcmp(name,       "SHUTDOWN") == 0) return SWA16_ISA_SIGN_SHUTDOWN;
    if (strcmp(name,           "STOP") == 0) return SWA16_ISA_SIGN_STOP;
    if (strcmp(name,         "RESUME") == 0) return SWA16_ISA_SIGN_RESUME;
    if (strcmp(name,             "OK") == 0) return SWA16_ISA_SIGN_OK;
    if (strcmp(name,         "DANGER") == 0) return SWA16_ISA_SIGN_DANGER;
    if (strcmp(name,           "FAIL") == 0) return SWA16_ISA_SIGN_FAIL;
    if (strcmp(name,       "CRITICAL") == 0) return SWA16_ISA_SIGN_CRITICAL;

    if (strcmp(name,           "NONE") == 0) return SWA16_ISA_SIGN_NONE;

    return SWA16_ISA_SIGN_NONE;
}
