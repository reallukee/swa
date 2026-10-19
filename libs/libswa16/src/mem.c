//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mem.c
//
//  https://github.com/reallukee/swa
//

#include <mem.h>

#include "memint.h"

swa16_mem_t* swa16_mem_alloc()
{
    swa16_mem_t* mem = (swa16_mem_t*)calloc(
        1, sizeof(swa16_mem_t)
    );

    if (mem == NULL)
    {
        return NULL;
    }

    mem->init = false;

    mem->wrds_init = false;

    memset(mem->wrds, 0, sizeof(mem->wrds));

    return mem;
}

void swa16_mem_free(swa16_mem_t* mem)
{
    free(mem);
}



bool swa16_mem_init(swa16_mem_t* mem)
{
    if (mem == NULL)
    {
        return false;
    }

    if (mem->init)
    {
        return true;
    }

    if (!swa16_mem_wrds_init(mem))
    {
        return false;
    }

    mem->init = true;

    return true;
}

bool swa16_mem_isInit(const swa16_mem_t* mem)
{
    if (mem == NULL)
    {
        return false;
    }

    return !swa16_mem_wrds_isInit(mem);
}
