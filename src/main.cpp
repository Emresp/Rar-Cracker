#include <iostream>
#include <vector>
#include "util/hex_utils.h"
#include "rar/rar_reader.h"

int main() {
    // Test 1: RAR3 imzasi
    std::vector<uint8_t> rar3 = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00};
    std::cout << "RAR3 testi: ";
    auto s1 = rar_surumu_tespit(rar3);
    if (s1 == rar_surumu::Rar3) std::cout << "Rar3 tespit edildi\n";
    else std::cout << "HATA\n";

    // Test 2: RAR5 imzasi
    std::vector<uint8_t> rar5 = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x01, 0x00};
    std::cout << "RAR5 testi: ";
    auto s2 = rar_surumu_tespit(rar5);
    if (s2 == rar_surumu::Rar5) std::cout << "Rar5 tespit edildi\n";
    else std::cout << "HATA\n";

    // Test 3: RAR degil
    std::vector<uint8_t> pdf = {0x25, 0x50, 0x44, 0x46, 0x2D, 0x31, 0x2E};
    std::cout << "PDF testi: ";
    auto s3 = rar_surumu_tespit(pdf);
    if (s3 == rar_surumu::Bilinmiyor) std::cout << "Rar degil, dogru\n";
    else std::cout << "HATA\n";

    // Test 4: Bos vector
    std::vector<uint8_t> bos;
    std::cout << "Bos testi: ";
    auto s4 = rar_surumu_tespit(bos);
    if (s4 == rar_surumu::Bilinmiyor) std::cout << "Bos, dogru\n";
    else std::cout << "HATA\n";

    return 0;
}