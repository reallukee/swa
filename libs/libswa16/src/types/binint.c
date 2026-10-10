//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  binint.c
//
//  https://github.com/reallukee/swa
//

#include <types/binint.h>

swa16_byte_t swa16_binint_gwlo(swa16_word_t word)
{
    return (swa16_byte_t)((word >> 0) & 0x00FF);
}

swa16_byte_t swa16_binint_gwhi(swa16_word_t word)
{
    return (swa16_byte_t)((word >> 8) & 0x00FF);
}

swa16_word_t swa16_binint_swlo(swa16_word_t word, swa16_byte_t byte)
{
    return (swa16_word_t)((word & 0xFF00) |
           ((swa16_word_t)byte << 0));
}

swa16_word_t swa16_binint_swhi(swa16_word_t word, swa16_byte_t byte)
{
    return (swa16_word_t)((word & 0x00FF) |
           ((swa16_word_t)byte << 8));
}



bool swa16_binint_addwof(swa16_word_t op1, swa16_word_t op2)
{
    return (~(op1 ^ op2) & (op1 ^ (op1 + op2)) & 0x8000) != 0;
}

bool swa16_binint_addswof(swa16_sword_t op1, swa16_sword_t op2)
{
    return (op1 + op2) < op1;
}

bool swa16_binint_subwof(swa16_word_t op1, swa16_word_t op2)
{
    return ((op1 ^ op2) & (op1 ^ (op1 - op2)) & 0x8000) != 0;
}

bool swa16_binint_subswof(swa16_sword_t op1, swa16_sword_t op2)
{
    return (op1 - op2) > op1;
}
