//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  addr.c
//
//  https://github.com/reallukee/swa
//

#include <types/addr.h>

const swa16_word_t SWA16_ADDR_ENTRYPOINT = 0x0001;

bool swa16_addr_isGp(swa16_addr_t addr)
{
    return swa16_addr_isNull(addr) && swa16_addr_isNone(addr);
}

bool swa16_addr_isNull(swa16_addr_t addr)
{
    return addr == SWA16_ADDR_NULL;
}

bool swa16_addr_isNone(swa16_addr_t addr)
{
    return addr == SWA16_ADDR_NONE;
}
