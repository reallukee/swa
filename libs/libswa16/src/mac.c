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

#include "mac.h"

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

    if (mac->cpu == NULL ||
        mac->ram == NULL ||
        mac->rom == NULL ||
        mac->nvm == NULL)
    {
        swa16_mac_free(mac);

        return NULL;
    }

    return mac;
}

void swa16_mac_free(swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return;
    }

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
        !swa16_mem_wrds_get(mac->nvm, pc, word) ||
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
        !swa16_mem_wrds_get(mac->nvm, pc, word) ||
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



const swa16_cpu_t* swa16_mac_get_cpu(const swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return NULL;
    }

    return mac->cpu;
}



const swa16_nvm_t* swa16_mac_get_nvm(const swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return NULL;
    }

    return mac->nvm;
}

const swa16_ram_t* swa16_mac_get_ram(const swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return NULL;
    }

    return mac->ram;
}

const swa16_rom_t* swa16_mac_get_rom(const swa16_mac_t* mac)
{
    if (mac == NULL)
    {
        return NULL;
    }

    return mac->rom;
}



static bool swa16_mac_handler(swa16_isa_sign_t sign)
{
    switch (sign)
    {
    case SWA16_ISA_SIGN_NEXT:           return true;
    case SWA16_ISA_SIGN_JUMP:           return true;
    case SWA16_ISA_SIGN_END_OF_PROGRAM: return false;
    case SWA16_ISA_SIGN_SHUTDOWN:       return false;
    case SWA16_ISA_SIGN_STOP:           return true;
    case SWA16_ISA_SIGN_RESUME:         return true;
    case SWA16_ISA_SIGN_OK:             return true;
    case SWA16_ISA_SIGN_DANGER:         return true;
    case SWA16_ISA_SIGN_FAIL:           return false;
    case SWA16_ISA_SIGN_CRITICAL:       return false;

    case SWA16_ISA_SIGN_NONE:           return false;

    default:                            return false;
    }
}



static bool swa16_mac_eom(const swa16_mac_t* mac, const swa16_prgm_t* prgm, bool* eom)
{
    if (mac == NULL || eom == NULL)
    {
        return false;
    }

    const swa16_cpu_t* cpu = swa16_mac_get_cpu(mac);

    if (cpu == NULL)
    {
        return false;
    }

    swa16_word_t pc;

    if (!swa16_cpu_pc_get(cpu, &pc))
    {
        return false;
    }

    *eom = (pc == SWA16_PRGM_METADATA_START + prgm->body.metadata_length + 1);

    return true;
}

static bool swa16_mac_eod(const swa16_mac_t* mac, const swa16_prgm_t* prgm, bool* eod)
{
    if (mac == NULL || eod == NULL)
    {
        return false;
    }

    const swa16_cpu_t* cpu = swa16_mac_get_cpu(mac);

    if (cpu == NULL)
    {
        return false;
    }

    swa16_word_t pc;

    if (!swa16_cpu_pc_get(cpu, &pc))
    {
        return false;
    }

    *eod = (pc == SWA16_PRGM_DATA_START + prgm->body.data_length + 1);

    return true;
}

static bool swa16_mac_eot(const swa16_mac_t* mac, const swa16_prgm_t* prgm, bool* eot)
{
    if (mac == NULL || eot == NULL)
    {
        return false;
    }

    const swa16_cpu_t* cpu = swa16_mac_get_cpu(mac);

    if (cpu == NULL)
    {
        return false;
    }

    swa16_word_t pc;

    if (!swa16_cpu_pc_get(cpu, &pc))
    {
        return false;
    }

    *eot = (pc == SWA16_PRGM_TEXT_START + prgm->body.text_length + 1);

    return true;
}



static bool swa16_mac_eop(const swa16_mac_t* mac, const swa16_prgm_t* prgm, bool* eop)
{
    return swa16_mac_eot(mac, prgm, eop);
}

swa16_isa_sign_t swa16_mac_run(const swa16_mac_t* mac, const swa16_prgm_t* prgm)
{
    if (mac == NULL || prgm == NULL)
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    bool eop              = true;

    swa16_word_t     word = 0x0000;
    swa16_isa_inst_t inst = {};
    swa16_isa_sign_t sign = SWA16_ISA_SIGN_NONE;

    bool execute          = true;

    const swa16_cpu_t* cpu = swa16_mac_get_cpu(mac);

    if (cpu == NULL)
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    if (!swa16_cpu_pc_set(cpu, SWA16_PRGM_TEXT_START))
    {
        return SWA16_ISA_SIGN_CRITICAL;
    }

    while (execute)
    {
        sign = swa16_mac_fetch  (mac,   &word);
        sign = swa16_mac_decode (&word, &inst);
        sign = swa16_mac_execute(mac,   &inst);

        if (!swa16_mac_eop(mac, prgm, &eop))
        {
            return SWA16_ISA_SIGN_CRITICAL;
        }

        if (eop)
        {
            sign = SWA16_ISA_SIGN_END_OF_PROGRAM;
        }

        execute = swa16_mac_handler(sign);
    }

    return SWA16_ISA_SIGN_OK;
}
