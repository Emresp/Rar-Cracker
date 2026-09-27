#include <iostream>
#include <string>
#include "attack/bruteforce.h"

int main() {
    std::cout << "=== RarCracker Brute-Force Testi ===\n\n";


    std::cout << "Karakter seti sec:\n";
    std::cout << "  1) Sadece rakam (0-9)\n";
    std::cout << "  2) Sadece kucuk harf (a-z)\n";
    std::cout << "  3) Sadece buyuk harf (A-Z)\n";
    std::cout << "  4) Harf + rakam\n";
    std::cout << "  5) Her sey (harf + rakam + ozel)\n";
    std::cout << "Secim: ";

    int secim;
    std::cin >> secim;

    std::string karakter_seti = karakter_seti_olustur(secim);
    std::cout << "Karakter seti: \"" << karakter_seti << "\"\n\n";

    // 2. Maksimum uzunluk
    std::cout << "Maksimum uzunluk (ornek: 3): ";
    int maks;
    std::cin >> maks;


    std::cout << "\n--- Brute-force basliyor ---\n\n";

    std::string sonuc = brute_force("test_data/test_sifreli.rar", karakter_seti, maks);


    std::cout << "\n--- Sonuc ---\n";
    if (!sonuc.empty()) {
        std::cout << "*** SIFRE BULUNDU: " << sonuc << " ***\n";
    } else {
        std::cout << "Sifre bulunamadi.\n";
    }

    return 0;
}