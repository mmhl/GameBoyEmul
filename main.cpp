#include <iostream>
#include "mem.h"

using namespace std;

int main() {
    mem myMem(65536, 0x00);
    //mem::dump(myMem);

    try {
        auto testRom = Rom::loadFromFile("/home/mhl/Sources/GameBoyEmul/resources/TetrisWorld.gb");
        if(testRom.verify()) {
            myMem.loadRom(testRom);
            mem::dump(myMem);
            std::cout << "Rom Loaded succesfully" << std::endl;
        } else {
            std::cout << "Failed to load ROM! Malformed/Not supported" << std::endl;
        }
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}