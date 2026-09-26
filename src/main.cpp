#include <iostream>
#include <vector>
#include "util/hex_utils.h"

int main() {
    //TEST KODU
    std::vector<uint8_t> rar3Imzasi = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00};

    std::cout << "Test cikti: ";
    hex_yazdir(rar3Imzasi);

    return 0;
}