//
// Created by mhl on 14.03.16.
//

#ifndef GAMEBOYEMUL_MEM_H
#define GAMEBOYEMUL_MEM_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>

class mem {
public:
    mem(int size, int pattern = 0x00);

    static void dump(const mem &memory) {
        std::cout << "memdump" << std::endl;
        int column = 0;
        for(auto bte : memory.mPhysMem) {
            std::cout << std::hex << std::setfill('0') << std::setw(2) << bte;
            if(++column % 15 == 0) {
                std::cout << std::endl;
            }
            else std::cout << " ";
        }
    }
private:
    std::vector<uint8_t> mPhysMem;
};


#endif //GAMEBOYEMUL_MEM_H
