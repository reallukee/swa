//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  isaint.h
//
//  https://github.com/reallukee/swa
//

#ifndef SWA16_ISAINT_H
#define SWA16_ISAINT_H

typedef struct swa16_inst
{
    bool init;

    unsigned opcode : 4;
    unsigned mode   : 1;
    unsigned cond   : 3;

    union
    {
        unsigned argf : 8;

        struct
        {
            unsigned arg0 : 4;
            unsigned arg1 : 4;
        };
    };
} swa16_inst_t;

#endif // !SWA16_ISAINT_H
