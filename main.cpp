#include <iostream>
#include "custom_struct.h"
#include "parser.h"

StructList structs;

using namespace std;

int main()
{
    // Read the file into a buffer
    FILE* file = fopen("file.bin", "rb");
    if (file == NULL)
    {
        std::cout << "Failed to open a file!" << std::endl;
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);
    char* buffer = new char[fileSize];
    fread(buffer, 1, fileSize, file);
    fclose(file);

    // Parse the buffer
    structs.clear();
    bool success = parse_custom_struct(const_cast<const char*>(buffer), fileSize);
    delete[] buffer;

    if (!success)
    {
        std::cout << "Parsing was not successful!" << std::endl;
    }

    // Print the results
    for (const auto& s : structs)
    {
        std::cout << "Type: " << s.type << std::endl;
        std::cout << "Size: " << s.size << std::endl;

        for (int i = 0; i < s.size; i++)
        {
            std::cout << std::hex << std::uppercase << (uint8_t)s.data[i] << std::endl;
        }
        delete [] s.data;
    }

    return 0;
}
