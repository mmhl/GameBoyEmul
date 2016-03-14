//
// Created by mhl on 12.03.16.
//

#include "cpu.h"

int cpu::powerUp() {
    // Initialize registers into known values
    mCpuRegs.af = 0x0;
    mCpuRegs.bc = 0x0;
    mCpuRegs.de = 0x0;
    mCpuRegs.hl = 0x0;
    mCpuRegs.pc = 0x100;
    mCpuRegs.sp = 0xFFFE;
}

