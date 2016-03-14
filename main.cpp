#include <iostream>
#include "mem.h"
using namespace std;

int main() {
    mem myMem(1024, 0x00);
    mem::dump(myMem);
    return 0;
}