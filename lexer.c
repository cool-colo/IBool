
#line 1 "lexer.rl"
#include "lexer.h"
#include <cstdlib>
#include <string>



#line 10 "lexer.c"
static const char _Lexer_actions[] = {
	0, 1, 0, 1, 2, 1, 3, 1, 
	4, 1, 9, 1, 10, 1, 11, 1, 
	12, 1, 13, 1, 14, 1, 15, 1, 
	16, 1, 17, 1, 18, 1, 19, 1, 
	21, 1, 22, 1, 23, 1, 24, 1, 
	25, 1, 26, 1, 27, 2, 1, 20, 
	2, 4, 5, 2, 4, 6, 2, 4, 
	7, 2, 4, 8
};

static const unsigned char _Lexer_key_offsets[] = {
	0, 0, 1, 2, 4, 5, 14, 21, 
	22, 26, 28, 35, 37, 43, 45, 47, 
	49, 51, 53, 55, 56, 86, 87, 90, 
	92, 94, 95, 102, 111, 120, 129, 138, 
	147, 156, 165, 172, 181, 190, 199, 208, 
	217, 226, 235, 244
};

static const char _Lexer_trans_keys[] = {
	34, 38, 48, 57, 61, 9, 32, 34, 
	70, 84, 102, 116, 48, 57, 34, 70, 
	84, 102, 116, 48, 57, 34, 9, 32, 
	44, 93, 44, 93, 9, 32, 44, 46, 
	93, 48, 57, 48, 57, 9, 32, 44, 
	93, 48, 57, 65, 97, 76, 108, 83, 
	115, 69, 101, 82, 114, 85, 117, 124, 
	32, 33, 34, 38, 40, 41, 60, 61, 
	62, 67, 70, 73, 78, 84, 91, 95, 
	99, 102, 105, 110, 116, 124, 9, 10, 
	48, 57, 65, 90, 97, 122, 61, 46, 
	48, 57, 48, 57, 61, 62, 61, 95, 
	48, 57, 65, 90, 97, 122, 79, 95, 
	111, 48, 57, 65, 90, 97, 122, 78, 
	95, 110, 48, 57, 65, 90, 97, 122, 
	84, 95, 116, 48, 57, 65, 90, 97, 
	122, 65, 95, 97, 48, 57, 66, 90, 
	98, 122, 73, 95, 105, 48, 57, 65, 
	90, 97, 122, 78, 95, 110, 48, 57, 
	65, 90, 97, 122, 83, 95, 115, 48, 
	57, 65, 90, 97, 122, 95, 48, 57, 
	65, 90, 97, 122, 65, 95, 97, 48, 
	57, 66, 90, 98, 122, 76, 95, 108, 
	48, 57, 65, 90, 97, 122, 83, 95, 
	115, 48, 57, 65, 90, 97, 122, 69, 
	95, 101, 48, 57, 65, 90, 97, 122, 
	78, 95, 110, 48, 57, 65, 90, 97, 
	122, 73, 95, 105, 48, 57, 65, 90, 
	97, 122, 78, 95, 110, 48, 57, 65, 
	90, 97, 122, 82, 95, 114, 48, 57, 
	65, 90, 97, 122, 85, 95, 117, 48, 
	57, 65, 90, 97, 122, 0
};

static const char _Lexer_single_lengths[] = {
	0, 1, 1, 0, 1, 7, 5, 1, 
	4, 2, 5, 0, 4, 2, 2, 2, 
	2, 2, 2, 1, 22, 1, 1, 0, 
	2, 1, 1, 3, 3, 3, 3, 3, 
	3, 3, 1, 3, 3, 3, 3, 3, 
	3, 3, 3, 3
};

static const char _Lexer_range_lengths[] = {
	0, 0, 0, 1, 0, 1, 1, 0, 
	0, 0, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 4, 0, 1, 1, 
	0, 0, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3
};

static const short _Lexer_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 17, 24, 
	26, 31, 34, 41, 43, 49, 52, 55, 
	58, 61, 64, 67, 69, 96, 98, 101, 
	103, 106, 108, 113, 120, 127, 134, 141, 
	148, 155, 162, 167, 174, 181, 188, 195, 
	202, 209, 216, 223
};

static const char _Lexer_indicies[] = {
	1, 0, 2, 3, 5, 4, 6, 3, 
	7, 7, 8, 10, 11, 10, 11, 9, 
	3, 8, 10, 11, 10, 11, 9, 3, 
	12, 8, 13, 13, 14, 15, 3, 14, 
	15, 3, 13, 13, 14, 16, 15, 9, 
	3, 17, 3, 13, 13, 14, 15, 17, 
	3, 18, 18, 3, 19, 19, 3, 20, 
	20, 3, 12, 12, 3, 21, 21, 3, 
	20, 20, 3, 22, 3, 23, 24, 0, 
	25, 26, 27, 29, 30, 31, 33, 34, 
	35, 36, 37, 14, 32, 33, 34, 35, 
	36, 37, 38, 23, 28, 32, 32, 3, 
	40, 39, 42, 28, 41, 5, 41, 44, 
	40, 43, 46, 45, 48, 48, 48, 48, 
	47, 49, 48, 49, 48, 48, 48, 47, 
	50, 48, 50, 48, 48, 48, 47, 51, 
	48, 51, 48, 48, 48, 47, 52, 48, 
	52, 48, 48, 48, 47, 53, 48, 53, 
	48, 48, 48, 47, 54, 48, 54, 48, 
	48, 48, 47, 56, 48, 56, 48, 48, 
	48, 55, 48, 48, 48, 48, 57, 58, 
	48, 58, 48, 48, 48, 47, 59, 48, 
	59, 48, 48, 48, 47, 60, 48, 60, 
	48, 48, 48, 47, 61, 48, 61, 48, 
	48, 48, 47, 62, 48, 62, 48, 48, 
	48, 47, 63, 48, 63, 48, 48, 48, 
	47, 64, 48, 64, 48, 48, 48, 47, 
	65, 48, 65, 48, 48, 48, 47, 60, 
	48, 60, 48, 48, 48, 47, 0
};

static const char _Lexer_trans_targs[] = {
	1, 20, 20, 0, 20, 23, 20, 6, 
	7, 10, 13, 17, 8, 9, 5, 20, 
	11, 12, 14, 15, 16, 18, 20, 20, 
	21, 2, 20, 20, 22, 24, 4, 25, 
	26, 27, 35, 39, 40, 42, 19, 20, 
	20, 20, 3, 20, 20, 20, 20, 20, 
	26, 28, 29, 30, 31, 32, 33, 20, 
	34, 20, 36, 37, 38, 34, 34, 41, 
	34, 43
};

static const char _Lexer_trans_actions[] = {
	0, 9, 13, 0, 41, 0, 17, 0, 
	0, 0, 0, 0, 0, 0, 0, 11, 
	0, 0, 0, 0, 0, 0, 15, 29, 
	0, 0, 25, 27, 7, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 0, 33, 
	19, 31, 0, 37, 23, 35, 21, 45, 
	0, 0, 0, 0, 0, 0, 0, 39, 
	51, 43, 0, 0, 0, 48, 54, 0, 
	57, 0
};

static const char _Lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _Lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const short _Lexer_eof_trans[] = {
	0, 0, 0, 5, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 40, 42, 42, 
	44, 46, 48, 48, 48, 48, 48, 48, 
	48, 56, 58, 48, 48, 48, 48, 48, 
	48, 48, 48, 48
};

static const int Lexer_start = 20;
static const int Lexer_first_final = 20;
static const int Lexer_error = 0;

static const int Lexer_en_main = 20;


#line 162 "lexer.rl"


Bool::Lexer::Lexer(const std::string& input):data(input), p(data.data()), pe(data.data() + data.length()), eof(data.data() + data.length()){
  if (data.empty()){
    return;
  }
  
#line 191 "lexer.c"
	{
	cs = Lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 169 "lexer.rl"
}



Bool::Parser::token_type Bool::Lexer::lex(Parser::semantic_type* val)
{
  Parser::token_type ret = Parser::token::TOKEN_END;

  if (p == eof) {
    std::cout<<"eof"<<std::endl;
    return ret;
  }

  
#line 214 "lexer.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _Lexer_actions + _Lexer_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 3:
#line 1 "NONE"
	{ts = p;}
	break;
#line 235 "lexer.c"
		}
	}

	_keys = _Lexer_trans_keys + _Lexer_key_offsets[cs];
	_trans = _Lexer_index_offsets[cs];

	_klen = _Lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _Lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _Lexer_indicies[_trans];
_eof_trans:
	cs = _Lexer_trans_targs[_trans];

	if ( _Lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _Lexer_actions + _Lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 13 "lexer.rl"
	{
    std::cout<<"enter_dynamic_expr:"<<std::endl;
  }
	break;
	case 1:
#line 16 "lexer.rl"
	{
    std::cout<<"leave_dynamic_expr:"<<std::endl;
  }
	break;
	case 4:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 5:
#line 56 "lexer.rl"
	{act = 2;}
	break;
	case 6:
#line 111 "lexer.rl"
	{act = 13;}
	break;
	case 7:
#line 116 "lexer.rl"
	{act = 14;}
	break;
	case 8:
#line 121 "lexer.rl"
	{act = 15;}
	break;
	case 9:
#line 56 "lexer.rl"
	{te = p+1;{
    std::cout<<"CONST_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_VAR;
    {p++; goto _out; }
  }}
	break;
	case 10:
#line 61 "lexer.rl"
	{te = p+1;{
    std::cout<<"CONST_LIST_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_LIST;
    {p++; goto _out; }
  }}
	break;
	case 11:
#line 66 "lexer.rl"
	{te = p+1;{
    std::cout<<"LOGIC_OP_AND_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_AND;
    {p++; goto _out; }
  }}
	break;
	case 12:
#line 71 "lexer.rl"
	{te = p+1;{
    std::cout<<"LOGIC_OP_OR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_OR;
    {p++; goto _out; }
  }}
	break;
	case 13:
#line 81 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_EQ_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_EQ;
    {p++; goto _out; }
  }}
	break;
	case 14:
#line 86 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_NE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_NE;
    {p++; goto _out; }
  }}
	break;
	case 15:
#line 96 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_GTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GTE;
    {p++; goto _out; }
  }}
	break;
	case 16:
#line 106 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_LTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LTE;
    {p++; goto _out; }
  }}
	break;
	case 17:
#line 126 "lexer.rl"
	{te = p+1;{
    std::cout<<"LPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LPAREN;
    {p++; goto _out; }
  }}
	break;
	case 18:
#line 131 "lexer.rl"
	{te = p+1;{
    std::cout<<"RPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RPAREN;
    {p++; goto _out; }
  }}
	break;
	case 19:
#line 136 "lexer.rl"
	{te = p+1;{
    //std::cout<<"SPACE_ACTION"<<std::endl;
  }}
	break;
	case 20:
#line 51 "lexer.rl"
	{te = p;p--;{
    std::cout<<"DYNAMIC_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_DYNAMIC_VAR;
    {p++; goto _out; }
  }}
	break;
	case 21:
#line 56 "lexer.rl"
	{te = p;p--;{
    std::cout<<"CONST_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_VAR;
    {p++; goto _out; }
  }}
	break;
	case 22:
#line 76 "lexer.rl"
	{te = p;p--;{
    std::cout<<"LOGIC_OP_NOT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_NOT;
    {p++; goto _out; }
  }}
	break;
	case 23:
#line 91 "lexer.rl"
	{te = p;p--;{
    std::cout<<"RELATION_OP_GT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GT;
    {p++; goto _out; }
  }}
	break;
	case 24:
#line 101 "lexer.rl"
	{te = p;p--;{
    std::cout<<"RELATION_OP_LT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LT;
    {p++; goto _out; }
  }}
	break;
	case 25:
#line 111 "lexer.rl"
	{te = p;p--;{
    std::cout<<"RELATION_OP_CTN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_CTN;
    {p++; goto _out; }
  }}
	break;
	case 26:
#line 56 "lexer.rl"
	{{p = ((te))-1;}{
    std::cout<<"CONST_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_VAR;
    {p++; goto _out; }
  }}
	break;
	case 27:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;}
    std::cout<<"CONST_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_VAR;
    {p++; goto _out; }
  }
	break;
	case 13:
	{{p = ((te))-1;}
    std::cout<<"RELATION_OP_CTN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_CTN;
    {p++; goto _out; }
  }
	break;
	case 14:
	{{p = ((te))-1;}
    std::cout<<"RELATION_OP_IN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_IN;
    {p++; goto _out; }
  }
	break;
	case 15:
	{{p = ((te))-1;}
    std::cout<<"RELATION_OP_NIN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_NIN;
    {p++; goto _out; }
  }
	break;
	}
	}
	break;
#line 509 "lexer.c"
		}
	}

_again:
	_acts = _Lexer_actions + _Lexer_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 522 "lexer.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _Lexer_eof_trans[cs] > 0 ) {
		_trans = _Lexer_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 183 "lexer.rl"

  if (ret == Parser::token::TOKEN_END){
    const char* prefix = "syntax error:";
    char* message = (char*)malloc(sizeof(char) * (strlen(prefix) + pe - p + 1));
    strcpy(message, prefix);
    strcpy(message + strlen(prefix), p);
    std::cout<<"parse syntax error:" << message << std::endl;
  } else {
    std::cout<<ret<<std::endl;
    val->token = (char*)(malloc(sizeof(char) * (te - ts + 1)));
    strncpy(val->token, ts, te - ts);
    val->token[te - ts] = '\0';
  }
  return ret;
}
