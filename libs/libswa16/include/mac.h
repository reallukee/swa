//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  mac.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_MAC_H
#define LIBSWA16_MAC_H

#include <isa.h>
#include <cpu.h>
#include <mem.h>

#include <insts.h>

LIBSWA16_NAMESPACE_BEGIN

typedef struct swa16_mac swa16_mac_t;

LIBSWA16_API swa16_mac_t* swa16_mac_alloc();
LIBSWA16_API void         swa16_mac_free (swa16_mac_t* mac);

LIBSWA16_API bool swa16_mac_init  (swa16_mac_t* mac);
LIBSWA16_API bool swa16_mac_isInit(const swa16_mac_t* mac);

LIBSWA16_API swa16_isa_sign_t swa16_mac_fetch  (const swa16_mac_t* mac, swa16_word_t* word);
LIBSWA16_API swa16_isa_sign_t swa16_mac_defetch(const swa16_mac_t* mac, swa16_word_t* word);

LIBSWA16_API swa16_isa_sign_t swa16_mac_decode(const swa16_word_t* word, swa16_isa_inst_t* inst);
LIBSWA16_API swa16_isa_sign_t swa16_mac_encode(const swa16_isa_inst_t* inst, swa16_word_t* word);

LIBSWA16_API swa16_isa_sign_t swa16_mac_execute(const swa16_mac_t* mac, const swa16_isa_inst_t* inst);

LIBSWA16_API const swa16_cpu_t* swa16_mac_get_cpu(const swa16_mac_t* mac);

LIBSWA16_API const swa16_nvm_t* swa16_mac_get_nvm(const swa16_mac_t* mac);
LIBSWA16_API const swa16_ram_t* swa16_mac_get_ram(const swa16_mac_t* mac);
LIBSWA16_API const swa16_rom_t* swa16_mac_get_rom(const swa16_mac_t* mac);

LIBSWA16_NAMESPACE_END

#endif // !LIBSWA16_MAC_H
