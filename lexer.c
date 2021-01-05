
#line 1 "lexer.rl"
#include "lexer.h"
#include <cstdlib>
#include <string>



#line 10 "lexer.c"
static const char _Lexer_actions[] = {
	0, 1, 0, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 7, 1, 
	8, 1, 9, 1, 10, 1, 11, 1, 
	12, 1, 13, 1, 14, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 2, 
	1, 15, 3, 0, 1, 15
};

static const char _Lexer_key_offsets[] = {
	0, 0, 1, 2, 4, 5, 6, 29, 
	30, 33, 35, 37, 38, 45, 52, 61, 
	70, 79, 86, 95
};

static const char _Lexer_trans_keys[] = {
	34, 38, 48, 57, 61, 124, 32, 33, 
	34, 38, 40, 41, 60, 61, 62, 70, 
	84, 95, 102, 116, 124, 9, 10, 48, 
	57, 65, 90, 97, 122, 61, 46, 48, 
	57, 48, 57, 61, 62, 61, 95, 48, 
	57, 65, 90, 97, 122, 95, 48, 57, 
	65, 90, 97, 122, 65, 95, 97, 48, 
	57, 66, 90, 98, 122, 76, 95, 108, 
	48, 57, 65, 90, 97, 122, 83, 95, 
	115, 48, 57, 65, 90, 97, 122, 95, 
	48, 57, 65, 90, 97, 122, 82, 95, 
	114, 48, 57, 65, 90, 97, 122, 85, 
	95, 117, 48, 57, 65, 90, 97, 122, 
	0
};

static const char _Lexer_single_lengths[] = {
	0, 1, 1, 0, 1, 1, 15, 1, 
	1, 0, 2, 1, 1, 1, 3, 3, 
	3, 1, 3, 3
};

static const char _Lexer_range_lengths[] = {
	0, 0, 0, 1, 0, 0, 4, 0, 
	1, 1, 0, 0, 3, 3, 3, 3, 
	3, 3, 3, 3
};

static const char _Lexer_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 30, 
	32, 35, 37, 40, 42, 47, 52, 59, 
	66, 73, 78, 85
};

static const char _Lexer_indicies[] = {
	1, 0, 2, 3, 5, 4, 6, 3, 
	7, 3, 8, 9, 0, 10, 11, 12, 
	14, 15, 16, 18, 19, 17, 18, 19, 
	20, 8, 13, 17, 17, 3, 22, 21, 
	24, 13, 23, 5, 23, 26, 22, 25, 
	28, 27, 30, 30, 30, 30, 29, 32, 
	32, 32, 32, 31, 33, 30, 33, 30, 
	30, 30, 29, 34, 32, 34, 32, 32, 
	32, 31, 35, 32, 35, 32, 32, 32, 
	31, 32, 32, 32, 32, 31, 36, 30, 
	36, 30, 30, 30, 29, 35, 32, 35, 
	32, 32, 32, 31, 0
};

static const char _Lexer_trans_targs[] = {
	1, 6, 6, 0, 6, 9, 6, 6, 
	6, 7, 2, 6, 6, 8, 10, 4, 
	11, 12, 14, 18, 5, 6, 6, 6, 
	3, 6, 6, 6, 6, 6, 13, 6, 
	13, 15, 16, 17, 19
};

static const char _Lexer_trans_actions[] = {
	0, 9, 11, 0, 37, 0, 15, 13, 
	27, 0, 0, 23, 25, 7, 0, 0, 
	0, 0, 0, 0, 0, 31, 17, 29, 
	0, 35, 21, 33, 19, 42, 1, 39, 
	0, 1, 0, 0, 1
};

static const char _Lexer_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _Lexer_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 5, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _Lexer_eof_trans[] = {
	0, 0, 0, 5, 0, 0, 0, 22, 
	24, 24, 26, 28, 30, 32, 30, 32, 
	32, 32, 30, 32
};

static const int Lexer_start = 6;
static const int Lexer_first_final = 6;
static const int Lexer_error = 0;

static const int Lexer_en_main = 6;


#line 137 "lexer.rl"


Bool::Lexer::Lexer(const std::string& input):data(input), p(data.data()), pe(data.data() + data.length()), eof(data.data() + data.length()){
  if (data.empty()){
    return;
  }
  
#line 125 "lexer.c"
	{
	cs = Lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 144 "lexer.rl"
}



Bool::Parser::token_type Bool::Lexer::lex(Parser::semantic_type* val)
{
  std::cout<<"in lexer.lex"<<std::endl;
  Parser::token_type ret = Parser::token::TOKEN_END;

  if (p == eof) {
    std::cout<<"eof"<<std::endl;
    return ret;
  }

  
#line 149 "lexer.c"
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
#line 170 "lexer.c"
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
#line 49 "lexer.rl"
	{te = p+1;{
    std::cout<<"CONST_STR_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_STR_VAR;
    {p++; goto _out; }
  }}
	break;
	case 6:
#line 59 "lexer.rl"
	{te = p+1;{
    std::cout<<"LOGIC_OP_AND_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_AND;
    {p++; goto _out; }
  }}
	break;
	case 7:
#line 64 "lexer.rl"
	{te = p+1;{
    std::cout<<"LOGIC_OP_OR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_OR;
    {p++; goto _out; }
  }}
	break;
	case 8:
#line 74 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_EQ_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_EQ;
    {p++; goto _out; }
  }}
	break;
	case 9:
#line 79 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_NE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_NE;
    {p++; goto _out; }
  }}
	break;
	case 10:
#line 89 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_GTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GTE;
    {p++; goto _out; }
  }}
	break;
	case 11:
#line 99 "lexer.rl"
	{te = p+1;{
    std::cout<<"RELATION_OP_LTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LTE;
    {p++; goto _out; }
  }}
	break;
	case 12:
#line 104 "lexer.rl"
	{te = p+1;{
    std::cout<<"LPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LPAREN;
    {p++; goto _out; }
  }}
	break;
	case 13:
#line 109 "lexer.rl"
	{te = p+1;{
    std::cout<<"RPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RPAREN;
    {p++; goto _out; }
  }}
	break;
	case 14:
#line 114 "lexer.rl"
	{te = p+1;{
    std::cout<<"SPACE_ACTION"<<std::endl;
  }}
	break;
	case 15:
#line 44 "lexer.rl"
	{te = p;p--;{
    std::cout<<"DYNAMIC_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_DYNAMIC_VAR;
    {p++; goto _out; }
  }}
	break;
	case 16:
#line 54 "lexer.rl"
	{te = p;p--;{
    std::cout<<"CONST_NUM_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_NUM_VAR;
    {p++; goto _out; }
  }}
	break;
	case 17:
#line 69 "lexer.rl"
	{te = p;p--;{
    std::cout<<"LOGIC_OP_NOT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_NOT;
    {p++; goto _out; }
  }}
	break;
	case 18:
#line 84 "lexer.rl"
	{te = p;p--;{
    std::cout<<"RELATION_OP_GT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GT;
    {p++; goto _out; }
  }}
	break;
	case 19:
#line 94 "lexer.rl"
	{te = p;p--;{
    std::cout<<"RELATION_OP_LT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LT;
    {p++; goto _out; }
  }}
	break;
	case 20:
#line 54 "lexer.rl"
	{{p = ((te))-1;}{
    std::cout<<"CONST_NUM_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_NUM_VAR;
    {p++; goto _out; }
  }}
	break;
#line 378 "lexer.c"
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
#line 391 "lexer.c"
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

#line 159 "lexer.rl"

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
