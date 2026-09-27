#ifndef RARCRACKER_BRUTEFORCE_H
#define RARCRACKER_BRUTEFORCE_H

#include <string>
#include <vector>

//Kullanıcının isteklerine göre karakter denemek için
std::string karakter_seti_olustur(int secim);


std::string brute_force(const std::string& dosya_yolu, const std::string& karakter_seti, int maks_uzunluk);

#endif //RARCRACKER_BRUTEFORCE_H