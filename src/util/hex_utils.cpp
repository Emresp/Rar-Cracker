#include "hex_utils.h"
#include <iostream>
#include <iomanip>

void hex_yazdir(const std::vector<uint8_t>& baytlar)
{

    for (uint8_t byte : baytlar)
    {
        //Okunan rar dosyalarıdaki baytları  hex formatında düzgün bir şekilde görebilmek
        std::cout<<std::hex<< std::setw(2)<<std::setfill('0')<<static_cast<int>(byte) <<" ";
    }

    //hexe aldığımız tipi tekrardan decimal'a döndürdük
    std::cout<<std::dec<<std::endl;

}
