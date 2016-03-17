//
// Created by mhl on 14.03.16.
//

#include "mem.h"

mem::mem(int size, int pattern) : mPhysMem(size) {
    std::cout << "Initialized memory of size " << mPhysMem.size() << " bytes" << std::endl;
    for (auto &cell : mPhysMem) {
        cell = (uint8_t) (pattern & 0xFF);
    }
}

void mem::loadRom(const Rom &rom) {
    if(!rom.verify()) {
       throw RomException(RomError::ROM_INVALID, rom);
    }

    auto program = rom.getBytes();
    auto romSize = program.size();
    std::vector<uint8_t>::iterator rom_begin = program.begin();
    std::vector<uint8_t>::iterator rom_end = program.end();
    std::copy(rom_begin, rom_end, mPhysMem.begin());
}



