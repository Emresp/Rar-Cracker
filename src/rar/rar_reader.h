#ifndef RARCRACKER_RAR_READER_H
#define RARCRACKER_RAR_READER_H

#include <vector>
#include <cstdint>
#include <cstddef>
#include <string>

// Enum'u class olarak kullaniyorum ki baska kutuphaneler ile karismasin.
// Enum kullanmamin sebebi ise enum'un otomatik deger siralmasidir.
enum class rar_surumu
{
    Bilinmiyor,  // 0
    Rar3,        // 1
    Rar5         // 2
};

//Rar sürümünü tespit etmek okunması gereken minimum bayt sayısı
constexpr size_t RAR_IMZA_UZUNLUGU = 8;

// Ilk baytlari okumak icin tasarlanan 2 parametreli fonksiyon.
// Ilk parametre dosya yolunu referans olarak tutar.
// Ikinci parametre ise okunmasi gereken bayt sayisini tutar.
std::vector<uint8_t> ilk_baytlari_oku(const std::string& dosya_yolu, size_t bayt_sayisi);

// RAR surumunu tespit etmek icin kullanilan tek parametreli fonksiyon.
// Parametre olarak baytlarin referansini alir.
rar_surumu rar_surumu_tespit(const std::vector<uint8_t>& baytlar);

#endif //RARCRACKER_RAR_READER_H