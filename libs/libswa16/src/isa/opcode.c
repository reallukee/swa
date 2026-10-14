//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  opcode.c
//
//  https://github.com/reallukee/swa
//

#include <isa/opcode.h>

swa16_word_t swa16_isa_opcode_to(swa16_isa_opcode_t opcode)
{
    return (swa16_word_t)opcode;
}

swa16_isa_opcode_t swa16_isa_opcode_from(swa16_word_t value)
{
    if (value > SWA16_ISA_OPCODE_END)
    {
        return SWA16_ISA_OPCODE_NONE;
    }

    return (swa16_isa_opcode_t)value;
}



const char* swa16_isa_opcode_to_name(swa16_isa_opcode_t opcode)
{
    switch (opcode)
    {
    case SWA16_ISA_OPCODE_FLW:  return "FLW";
    case SWA16_ISA_OPCODE_MOV:  return "MOV";
    case SWA16_ISA_OPCODE_ADD:  return "ADD";
    case SWA16_ISA_OPCODE_SUB:  return "SUB";
    case SWA16_ISA_OPCODE_AND:  return "AND";
    case SWA16_ISA_OPCODE_IOR:  return "IOR";
    case SWA16_ISA_OPCODE_XOR:  return "XOR";
    case SWA16_ISA_OPCODE_SHL:  return "SHL";
    case SWA16_ISA_OPCODE_SHR:  return "SHR";
    case SWA16_ISA_OPCODE_SAR:  return "SAR";
    case SWA16_ISA_OPCODE_CMP:  return "CMP";
    case SWA16_ISA_OPCODE_CLL:  return "CLL";
    case SWA16_ISA_OPCODE_JMPR: return "JMPR";
    case SWA16_ISA_OPCODE_JMPA: return "JMPA";
    case SWA16_ISA_OPCODE_LDD:  return "LDD";
    case SWA16_ISA_OPCODE_STD:  return "STD";

    case SWA16_ISA_OPCODE_NONE: return "NONE";

    default:                    return "NONE";
    }
}

swa16_isa_opcode_t swa16_isa_opcode_from_name(const char* name)
{
    if (name == NULL)
    {
        return SWA16_ISA_OPCODE_NONE;
    }

    if (strcmp(name,  "FLW") == 0) return SWA16_ISA_OPCODE_FLW;
    if (strcmp(name,  "MOV") == 0) return SWA16_ISA_OPCODE_MOV;
    if (strcmp(name,  "ADD") == 0) return SWA16_ISA_OPCODE_ADD;
    if (strcmp(name,  "SUB") == 0) return SWA16_ISA_OPCODE_SUB;
    if (strcmp(name,  "AND") == 0) return SWA16_ISA_OPCODE_AND;
    if (strcmp(name,  "IOR") == 0) return SWA16_ISA_OPCODE_IOR;
    if (strcmp(name,  "XOR") == 0) return SWA16_ISA_OPCODE_XOR;
    if (strcmp(name,  "SHL") == 0) return SWA16_ISA_OPCODE_SHL;
    if (strcmp(name,  "SHR") == 0) return SWA16_ISA_OPCODE_SHR;
    if (strcmp(name,  "SAR") == 0) return SWA16_ISA_OPCODE_SAR;
    if (strcmp(name,  "CMP") == 0) return SWA16_ISA_OPCODE_CMP;
    if (strcmp(name,  "CLL") == 0) return SWA16_ISA_OPCODE_CLL;
    if (strcmp(name, "JMPR") == 0) return SWA16_ISA_OPCODE_JMPR;
    if (strcmp(name, "JMPA") == 0) return SWA16_ISA_OPCODE_JMPA;
    if (strcmp(name,  "LDD") == 0) return SWA16_ISA_OPCODE_LDD;
    if (strcmp(name,  "STD") == 0) return SWA16_ISA_OPCODE_STD;

    if (strcmp(name, "NONE") == 0) return SWA16_ISA_OPCODE_NONE;

    return SWA16_ISA_OPCODE_NONE;
}
