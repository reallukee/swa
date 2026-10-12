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

swa16_byte_t swa16_binint_gwlo(swa16_word_t wordv)
{
    return (swa16_byte_t)((wordv >> 0) & 0x00FF);
}

swa16_byte_t swa16_binint_gwhi(swa16_word_t wordv)
{
    return (swa16_byte_t)((wordv >> 8) & 0x00FF);
}

swa16_word_t swa16_binint_swlo(swa16_word_t wordv, swa16_byte_t bytev)
{
    return (swa16_word_t)((wordv & 0xFF00) |
           ((swa16_word_t)bytev << 0));
}

swa16_word_t swa16_binint_swhi(swa16_word_t wordv, swa16_byte_t bytev)
{
    return (swa16_word_t)((wordv & 0x00FF) |
           ((swa16_word_t)bytev << 8));
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



swa16_word_t swa16_binint_gllo(swa16_long_t longv)
{
    return (swa16_word_t)((longv >> 0) & 0x0000FFFF);
}

swa16_word_t swa16_binint_glhi(swa16_long_t longv)
{
    return (swa16_word_t)((longv >> 8) & 0x0000FFFF);
}

swa16_long_t swa16_binint_sllo(swa16_long_t longv, swa16_word_t wordv)
{
    return (swa16_long_t)((longv & 0xFFFF0000)) |
           ((swa16_word_t)wordv << 0);
}

swa16_long_t swa16_binint_slhi(swa16_long_t longv, swa16_word_t wordv)
{
    return (swa16_long_t)((longv & 0x0000FFFF)) |
           ((swa16_word_t)wordv << 8);
}
