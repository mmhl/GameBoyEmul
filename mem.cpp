//
// Created by mhl on 14.03.16.
//

#include "mem.h"
#include <iostream>

mem::mem(int size, int pattern) : mPhysMem(size) {
    std::cout << "Initialized memory of size " << size  << " bytes" << std::endl;
    for (auto cell : mPhysMem) {
        cell = (uint8_t) (pattern & 0xFF);
    }
}

