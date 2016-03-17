#include <iostream>
#include "mem.h"
#include "Rom.h"

using namespace std;

int main() {
    mem myMem(1024, 0x0F);
    //mem::dump(myMem);

    try {
        auto testRom = Rom::loadFromFile("/home/mhl/Sources/GameBoyEmul/resources/TetrisWorld.gb");
        if(testRom.verify() == true) {
            std::cout << "Rom Loaded succesfully" << std::endl;
        } else {
            std::cout << "Failed to load ROM! Malformed/Not supported" << std::endl;
        }
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}