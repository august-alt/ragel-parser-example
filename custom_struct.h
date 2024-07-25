#pragma once

#include <vector>
#include <cstdint>

struct CustomStruct
{
    uint32_t type;
    uint32_t size;
    char*    data; // Must be the size of `size` member variable.

    CustomStruct()
        : type(0)
        , size(0)
        , data(nullptr)
    {}
};

typedef std::vector<CustomStruct> StructList;

extern StructList structs;
