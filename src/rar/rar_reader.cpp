#include "rar_reader.h"
#include <fstream>

//Rar sürümü fark etmeksizin rarların ilk 6 baytu bu şekildedir ilerde kolay kontrol için tanımladık
const std::vector<uint8_t> RAR_ORTAK_IMZA = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07};

std::vector<uint8_t> ilk_baytlari_oku(const std::string& dosya_yolu, size_t bayt_sayisi)
{
    //dosyayı binary okuncak şekilde açtık
    std::ifstream dosya(dosya_yolu,std::ios::binary);

    //Dosya kontrolü
    if (!dosya.is_open())
    {
        return {};
    }

    //bayt sayısı büyüklüğünde buffer adında bir vecctor oluşturduk ki baytları yazabilelim
    std::vector<uint8_t> buffer(bayt_sayisi);

    //Dosyayı okuma işlemi yapıyoruz .read fonksiyonu char bekler ama bizim bufferımız uint8_t tipinde bundan dolayı cast işlemi tip dönüşümü yapıyoruz
    //.data ise buffer'ın ilk adrsini verir
    //bayt_sayisi ise kaç bayt okuncağını söyler
    dosya.read(reinterpret_cast<char*>(buffer.data()), bayt_sayisi);

    //.gcount fonksiyonu ile kaçt bayt okunmuş hesaplanır ve vectörün boyutu ona göre yeniden yapılandırılır
    std::streamsize okunan = dosya.gcount();
    buffer.resize(okunan);

    return buffer;
}

rar_surumu rar_surumu_tespit(const std::vector<uint8_t>& baytlar)
{
    //Okunan baytlar 6'dan küçükse zaten rar dosyası olamaz bunun için ilk başta konrtol yaptım
    if (baytlar.size() < 6)
    {
        return rar_surumu::Bilinmiyor;
    }

    //equal donksiyonun özelliği sayesinde ortak imza değişkenin başından başlar ortak imzanın sonuna tek tek kontrol eder
    //Tanımlamış olduğumuz ortak imza 6 bayt olduğu için okuduğumuz bayt vektörününde sadece ilk 6 baytına kadar
    if (!std::equal(RAR_ORTAK_IMZA.begin(), RAR_ORTAK_IMZA.end(), baytlar.begin())) {
        return rar_surumu::Bilinmiyor;
    }

    //Bir rar dosyası en az 7 bayt olabileceği için 7 den küçüksede Bilinmiyor döndrücez
    if (baytlar.size() < 7)
    {
        return rar_surumu::Bilinmiyor;
    }
    //Geriye kalan baytları spesifik olarak tek tek kontrol ederek rar3 mü rar5 yada bozuk bir dosya mı tek tek kontrolünü sağladım
    if (baytlar[6]==0x00)
    {
        return rar_surumu::Rar3;
    }
    else if (baytlar[6]==0x01)
    {
        if (baytlar.size() < 8)
        {
            return rar_surumu::Bilinmiyor;
        }
        if (baytlar[7]==0x00)
        {
            return rar_surumu::Rar5;
        }
        else
        {
            return rar_surumu::Bilinmiyor;
        }
    }
    else
    {
        return rar_surumu::Bilinmiyor;
    }
}