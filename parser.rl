#include "custom_struct.h"
#include <cstdint>
#include <cassert>
#include <memory>

%%{
    machine parser;

    action struct_start
    {
         structs.push_back({});
    }

    action type_start {
        // Initialize the type buffer
        type = 0;
    }

    action type_parse {
        // Append the byte to the type buffer
        type = (type << 8) | fc;
    }

    action type_end {
        // Store the type value in the current struct
        structs.back().type = type;
    }

    action size_start {
        // Initialize the size buffer
        size = 0;
    }

    action size_parse {
        // Append the byte to the size buffer
        size = (size << 8) | fc;
    }

    action size_end {
        // Store the size value in the current struct
        structs.back().size = size;
    }

    action data_start {
        // Initialize the data buffer
        counter = 0;
        data = new char[size + 1];
        structs.back().data = data;
        structs.back().data[size] = 0;
    }

    action data_parse {
        // Append the byte to the data buffer
        data[counter++] = fc;
    }

    action data_end {
        // Verify the data is the correct size
        counter <= structs.back().size
                ? (cs = parser_error)
                : (cs = cs);
        data = nullptr;
    }

    UINT32_T = extend{4};
    type = (UINT32_T >type_start @type_parse %type_end);
    size = (UINT32_T >size_start @size_parse %size_end);
    data = (extend >data_start @data_parse %data_end);
    record = (type size data(size)) >struct_start;
    main := record;
}%%


%%write data;

bool parse_custom_struct(const char *const in, const size_t len)
{
    const char *p = in;
    const char *const pe = in + len;
    const char *eof = pe;
    int cs;

    uint32_t type = 0;
    uint32_t size = 0;
    char* data = nullptr;
    size_t counter = 0;

    %%{
        write init;
        write exec;
    }%%

    return cs != parser_error;
}
