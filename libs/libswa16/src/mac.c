//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mac.c
//
//  https://github.com/reallukee/swa
//

#include <mac.h>

#include "macint.h"

swa16_mac_t* swa16_mac_alloc()
{
    swa16_mac_t* mac = (swa16_mac_t*)calloc(
        1, sizeof(swa16_mac_t)
    );

    if (mac == NULL)
    {
        return NULL;
    }

    mac->init = false;

    mac->cpu = swa16_cpu_alloc();
    mac->ram = swa16_mem_alloc();
    mac->rom = swa16_mem_alloc();
    mac->nvm = swa16_mem_alloc();

    return mac;
}

void swa16_mac_free(swa16_mac_t* mac)
{
    swa16_cpu_free(mac->cpu);
    swa16_mem_free(mac->ram);
    swa16_mem_free(mac->rom);
    swa16_mem_free(mac->nvm);

    free(mac);
}



bool swa16_mac_init(swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return false;
    }

    if (mac->init)
    {
        return true;
    }

    if (!swa16_cpu_init(mac->cpu) ||
        !swa16_mem_init(mac->ram) ||
        !swa16_mem_init(mac->rom) ||
        !swa16_mem_init(mac->nvm))
    {
        return false;
    }

    mac->init = true;

    return true;
}

bool swa16_mac_isInit(const swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return false;
    }

    return !swa16_cpu_isInit(mac->cpu) ||
           !swa16_mem_isInit(mac->ram) ||
           !swa16_mem_isInit(mac->rom) ||
           !swa16_mem_isInit(mac->nvm);
}



swa16_isa_sign_t swa16_mac_fetch(const swa16_mac_t* mac, swa16_word_t* word)
{
    if (mac == NULL)
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_word_t pc = SWA16_CPU_PC_NULL;

    if (!swa16_cpu_pc_get  (mac->cpu, &pc)      ||
        !swa16_mem_wrds_get(mac->rom, pc, word) ||
        !swa16_cpu_pc_inc  (mac->cpu))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}

swa16_isa_sign_t swa16_mac_defetch(const swa16_mac_t* mac, swa16_word_t* word)
{
    if (mac == NULL)
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    swa16_word_t pc = SWA16_CPU_PC_NULL;

    if (!swa16_cpu_pc_get  (mac->cpu, &pc)      ||
        !swa16_mem_wrds_get(mac->rom, pc, word) ||
        !swa16_cpu_pc_dec  (mac->cpu))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}



swa16_isa_sign_t swa16_mac_decode(const swa16_word_t* word, swa16_isa_inst_t* inst)
{
    if (inst == NULL || word == NULL)
    {
        return false;
    }

    inst->opcode = (*word >> 0x0C) & 0x0F;
    inst->mode   = (*word >> 0x0B) & 0x01;
    inst->cond   = (*word >> 0x08) & 0x07;

    switch (inst->opcode)
    {
    case SWA16_ISA_OPCODE_FLW:
    case SWA16_ISA_OPCODE_CLL:
    case SWA16_ISA_OPCODE_JMPR:
    case SWA16_ISA_OPCODE_JMPA:
        inst->argf = *word & 0xFF;

        break;

    case SWA16_ISA_OPCODE_MOV:
    case SWA16_ISA_OPCODE_ADD:
    case SWA16_ISA_OPCODE_SUB:
    case SWA16_ISA_OPCODE_AND:
    case SWA16_ISA_OPCODE_IOR:
    case SWA16_ISA_OPCODE_XOR:
    case SWA16_ISA_OPCODE_SHL:
    case SWA16_ISA_OPCODE_SHR:
    case SWA16_ISA_OPCODE_SAR:
    case SWA16_ISA_OPCODE_CMP:
    case SWA16_ISA_OPCODE_LDD:
    case SWA16_ISA_OPCODE_STD:
        inst->arg0 = ((*word & 0xFF) >> 4) & 0x0F;
        inst->arg1 = ((*word & 0xFF) >> 0) & 0x0F;

        break;

    case SWA16_ISA_OPCODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

    default:                    return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}

swa16_isa_sign_t swa16_mac_encode(const swa16_isa_inst_t* inst, swa16_word_t* word)
{
    if (inst == NULL || word == NULL)
    {
        return false;
    }

    *word |= (inst->opcode & 0x0F) << 0x0C;
    *word |= (inst->mode   & 0x01) << 0x0B;
    *word |= (inst->cond   & 0x07) << 0x08;

    switch (inst->opcode)
    {
    case SWA16_ISA_OPCODE_FLW:
    case SWA16_ISA_OPCODE_CLL:
    case SWA16_ISA_OPCODE_JMPR:
    case SWA16_ISA_OPCODE_JMPA:
        *word |= (inst->argf & 0xFF);

        break;

    case SWA16_ISA_OPCODE_MOV:
    case SWA16_ISA_OPCODE_ADD:
    case SWA16_ISA_OPCODE_SUB:
    case SWA16_ISA_OPCODE_AND:
    case SWA16_ISA_OPCODE_IOR:
    case SWA16_ISA_OPCODE_XOR:
    case SWA16_ISA_OPCODE_SHL:
    case SWA16_ISA_OPCODE_SHR:
    case SWA16_ISA_OPCODE_SAR:
    case SWA16_ISA_OPCODE_CMP:
    case SWA16_ISA_OPCODE_LDD:
    case SWA16_ISA_OPCODE_STD:
        *word |= (inst->arg0 & 0x0F) << 4;
        *word |= (inst->arg1 & 0x0F) << 0;

        break;

    case SWA16_ISA_OPCODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

    default:                    return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_OK;
}



swa16_isa_sign_t swa16_mac_execute(const swa16_mac_t* mac, const swa16_isa_inst_t* inst)
{
    if (mac == NULL || inst == NULL)
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    switch (inst->opcode)
    {
    case SWA16_ISA_OPCODE_FLW:  return swa16_insts_flw (mac, inst);
    case SWA16_ISA_OPCODE_MOV:  return swa16_insts_mov (mac, inst);
    case SWA16_ISA_OPCODE_ADD:  return swa16_insts_add (mac, inst);
    case SWA16_ISA_OPCODE_SUB:  return swa16_insts_sub (mac, inst);
    case SWA16_ISA_OPCODE_AND:  return swa16_insts_and (mac, inst);
    case SWA16_ISA_OPCODE_IOR:  return swa16_insts_ior (mac, inst);
    case SWA16_ISA_OPCODE_XOR:  return swa16_insts_xor (mac, inst);
    case SWA16_ISA_OPCODE_SHL:  return swa16_insts_shl (mac, inst);
    case SWA16_ISA_OPCODE_SHR:  return swa16_insts_shr (mac, inst);
    case SWA16_ISA_OPCODE_SAR:  return swa16_insts_sar (mac, inst);
    case SWA16_ISA_OPCODE_CMP:  return swa16_insts_cmp (mac, inst);
    case SWA16_ISA_OPCODE_CLL:  return swa16_insts_cll (mac, inst);
    case SWA16_ISA_OPCODE_JMPR: return swa16_insts_jmpr(mac, inst);
    case SWA16_ISA_OPCODE_JMPA: return swa16_insts_jmpa(mac, inst);
    case SWA16_ISA_OPCODE_LDD:  return swa16_insts_ldd (mac, inst);
    case SWA16_ISA_OPCODE_STD:  return swa16_insts_std (mac, inst);

    case SWA16_ISA_OPCODE_NONE: return SWA16_ISA_SIGN_CRITICAL;

    default:                    return SWA16_ISA_SIGN_CRITICAL;
    }

    return SWA16_ISA_SIGN_DANGER;
}
