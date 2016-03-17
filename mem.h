//
// Created by mhl on 14.03.16.
//

#ifndef GAMEBOYEMUL_MEM_H
#define GAMEBOYEMUL_MEM_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include "Rom.h"

class mem {
public:
    mem(int size, int pattern = 0x00);
    void loadRom(const Rom &rom);

    static void dump(const mem &memory) {
        std::cout << "memdump" << std::endl;
        std::stringstream ss;

        ss << "  ";
        for(int i = 0; i <= 0xF; ++i) {
            ss << std::hex << std::setw(6) << i;
        }

        int row = 0;
        for(int i = 0; i < memory.mPhysMem.size(); ++i) {
            if(i % 16 == 0) {
                ss << std::endl << std::setw(3) << row;
                row += 16;
            }
            ss << std::hex << std::setw(6) << static_cast<int>(memory.mPhysMem[i]);
        }

        std::cout << ss.str() << std::endl;
    }
private:
    std::vector<uint8_t> mPhysMem;
};


#endif //GAMEBOYEMUL_MEM_H
