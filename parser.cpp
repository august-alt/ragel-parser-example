
#line 1 "parser.rl"
#include "custom_struct.h"
#include <cstdint>
#include <cassert>
#include <memory>


#line 71 "parser.rl"




#line 15 "parser.cpp"
static const int parser_start = 1;
static const int parser_first_final = 14;
static const int parser_error = 0;

static const int parser_en_main = 1;


#line 75 "parser.rl"

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

    
#line 38 "parser.cpp"
	{
	cs = parser_start;
	}

#line 43 "parser.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	goto tr0;
tr0:
#line 10 "parser.rl"
	{
         structs.push_back({});
    }
#line 14 "parser.rl"
	{
        // Initialize the type buffer
        type = 0;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 66 "parser.cpp"
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	goto tr3;
tr3:
#line 19 "parser.rl"
	{
        // Append the byte to the type buffer
        type = (type << 8) | (*p);
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 89 "parser.cpp"
	goto tr4;
tr4:
#line 24 "parser.rl"
	{
        // Store the type value in the current struct
        structs.back().type = type;
    }
#line 29 "parser.rl"
	{
        // Initialize the size buffer
        size = 0;
    }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 107 "parser.cpp"
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	goto tr7;
tr7:
#line 34 "parser.rl"
	{
        // Append the byte to the size buffer
        size = (size << 8) | (*p);
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 130 "parser.cpp"
	goto tr8;
tr8:
#line 39 "parser.rl"
	{
        // Store the size value in the current struct
        structs.back().size = size;
    }
#line 44 "parser.rl"
	{
        // Initialize the data buffer
        counter = 0;
        data = new char[size + 1];
        structs.back().data = data;
        structs.back().data[size] = 0;
    }
#line 52 "parser.rl"
	{
        // Append the byte to the data buffer
        data[counter++] = (*p);
    }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 156 "parser.cpp"
	goto tr9;
tr9:
#line 57 "parser.rl"
	{
        // Verify the data is the correct size
        counter <= structs.back().size
                ? (cs = parser_error)
                : (cs = cs);
        data = nullptr;
    }
#line 29 "parser.rl"
	{
        // Initialize the size buffer
        size = 0;
    }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 177 "parser.cpp"
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	goto tr12;
tr12:
#line 34 "parser.rl"
	{
        // Append the byte to the size buffer
        size = (size << 8) | (*p);
    }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 200 "parser.cpp"
	goto st0;
st0:
cs = 0;
	goto _out;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 14: 
#line 39 "parser.rl"
	{
        // Store the size value in the current struct
        structs.back().size = size;
    }
	break;
#line 231 "parser.cpp"
	}
	}

	_out: {}
	}

#line 91 "parser.rl"


    return cs != parser_error;
}
