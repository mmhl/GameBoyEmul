//
// Created by mhl on 12.03.16.
//

#ifndef GAMEBOYEMUL_CPU_H
#define GAMEBOYEMUL_CPU_H


#include <stdint-gcc.h>
#include "instructions.h"

// http://gameboy.mongenel.com/dmg/opcodes.html
// http://imrannazar.com/Gameboy-Z80-Opcode-Map
// http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf

struct registers {
    union {
        struct {
            uint8_t a;
            uint8_t f;
        };
        uint16_t af;
    };
    union {
        struct {
            uint8_t b;
            uint8_t c;
        };
        uint16_t bc;
    };
    union {
        struct {
            uint8_t d;
            uint8_t e;
        };
        uint16_t de;
    };
    union {
        struct {
            uint8_t h;
            uint8_t l;
        };
        uint16_t hl;
    };

    uint16_t pc;
    uint16_t sp;

    registers() {
        af = 0;
        bc = 0;
        de = 0;
        hl = 0;
        pc = 0;
        sp = 0;
    }
};

class cpu {
public:
    int powerUp();
    struct registers mCpuRegs;
};


#endif //GAMEBOYEMUL_CPU_H
