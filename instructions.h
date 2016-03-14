//
// Created by mhl on 12.03.16.
//

#ifndef GAMEBOYEMUL_INSTRUCTIONS_H
#define GAMEBOYEMUL_INSTRUCTIONS_H

#include <cstdint>
#include <functional>
#include <unordered_map>

#include "cpu.h"
class cpu;

const std::tuple<uint8_t, const char *, int, std::function<int(cpu &)>> instruction_set[]  {
        {std::make_tuple(0x00, "NOP", 0, [](cpu &mach) {return 0;})},// Only make_tuple works like this. Tuple - explicit
};
#endif //GAMEBOYEMUL_INSTRUCTIONS_H
