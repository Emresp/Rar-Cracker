#include "bruteforce.h"
#include <cstdlib>

//Şifre bulunursa erken durudamk için flag
static bool bulundu = false;
static std::string bulunan_sifre = "";

std::string karakter_seti_olustur(int secim) {
    switch (secim) {
        case 1:
            return "0123456789";
        case 2:
            return "abcdefghijklmnopqrstuvwxyz";
        case 3:
            return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        case 4:
            return "abcdefghijklmnopqrstuvwxyz"
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "0123456789";
        case 5:
            return "abcdefghijklmnopqrstuvwxyz"
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "0123456789"
                   "!@#$%^&*()_+-=";
        default:
            return "0123456789";
    }
}


static bool sifre_dene(const std::string& dosya_yolu, const std::string& aday)
{
    //unrar.exe programına ürettiğimiz şifreleri denemesi için veren cmd komutu
    std::string komut = "\"\"C:\\Program Files\\WinRAR\\unrar.exe\" t -p"
                    + aday
                    + " \"" + dosya_yolu + "\"\" > nul 2>&1";
    //Ekrana gereksiz mesajlar yazmaması için nul ekledim

    //Komudu çalıştıran system kodu
    int sonuc=system(komut.c_str());

    return sonuc ==0;
}

//Yinilenen fonksiyon
static void brute_force_rec(std::string& aday, const std::string& karakter_seti, int kalan, const std::string& dosya_yolu) {

    if (bulundu) {
        return;
    }


    if (kalan == 0) {



        if (sifre_dene(dosya_yolu, aday)) {
            bulundu = true;
            bulunan_sifre = aday;
        }

        return;
    }


    for (char c : karakter_seti) {
        aday += c;
        brute_force_rec(aday, karakter_seti, kalan - 1, dosya_yolu);
        aday.pop_back();
    }
}


std::string brute_force(const std::string& dosya_yolu,const std::string& karakter_seti,int maks_uzunluk) {

    bulundu = false;
    bulunan_sifre = "";


    for (int uzunluk = 1; uzunluk <= maks_uzunluk; uzunluk++) {
        std::string aday = "";
        brute_force_rec(aday, karakter_seti, uzunluk, dosya_yolu);

        if (bulundu) {
            break;
        }
    }

    return bulunan_sifre;
}