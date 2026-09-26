#include <iostream>
#include <vector>
#include "util/hex_utils.h"
#include "rar/rar_reader.h"

int main() {
    std::string dosya_yolu;
    std::cout << "RAR dosya yolu: ";
    std::cin >> dosya_yolu;

    auto baytlar = ilk_baytlari_oku(dosya_yolu, RAR_IMZA_UZUNLUGU);
    if (baytlar.empty()) {
        std::cout << "Dosya okunamadi!\n";
        return 1;
    }

    std::cout << "Ilk baytlar: ";
    hex_yazdir(baytlar);

    auto surum = rar_surumu_tespit(baytlar);

    switch (surum) {
    case rar_surumu::Rar3:
        std::cout << "Bu bir RAR3 dosyasi\n";
        break;
    case rar_surumu::Rar5:
        std::cout << "Bu bir RAR5 dosyasi\n";
        break;
    default:
        std::cout << "Bu bir RAR dosyasi degil\n";
        break;
    }
}