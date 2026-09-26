#include "hex_utils.h"
#include <iostream>
#include <iomanip>

void hex_yazdir(const std::vector<uint8_t>& baytlar)
{
    for (uint8_t byte : baytlar)
    {
        std::cout<<std::hex<< std::setw(2)<<std::setfill('0')<<static_cast<int>(byte) <<" ";
    }

    std::cout<<std::dec<<std::endl;

}
