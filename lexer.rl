#include "lexer.h"
#include <cstdlib>
#include <string>


%%{
  machine Lexer;
  alphtype char;
  write data;



  action enter_dynamic_expr {
    std::cout<<"enter_dynamic_expr:"<<std::endl;
  }
  action leave_dynamic_expr {
    std::cout<<"leave_dynamic_expr:"<<std::endl;
  }
  SPACE             = [ \t];
  KEY_WORDS         = 'in'i | 'nin'i;

  CONST_STR_VAR    = '"' . (any - '"')* . '"';
  INTEGER_VAR      = digit+;
  FLOAT_VAR        = digit+ ('.' digit+)?;
  BOOL_VAR         = 'true'i | 'false'i;
  CONST_NUM_VAR    = INTEGER_VAR | FLOAT_VAR | BOOL_VAR;
  CONST_VAR        = CONST_STR_VAR | CONST_NUM_VAR;
  CONST_LIST       = '[' . SPACE? CONST_VAR (SPACE? ',' SPACE? CONST_VAR)* SPACE? . ']';
  DYNAMIC_VAR      = ([_A-Za-z][_A-Za-z0-9]* - (KEY_WORDS | BOOL_VAR)) >enter_dynamic_expr %leave_dynamic_expr;

  LOGIC_OP_AND     = '&&';
  LOGIC_OP_OR      = '||';
  LOGIC_OP_NOT     = '!';

  RELATION_OP_EQ   = '==';
  RELATION_OP_NE   = '!=' | '<>';
  RELATION_OP_GT   = '>';
  RELATION_OP_GTE  = '>=';
  RELATION_OP_LT   = '<';
  RELATION_OP_LTE  = '<=';
  RELATION_OP_IN   = 'in'i;
  RELATION_OP_NIN  = 'nin'i;

  LPAREN           = '(';
  RPAREN           = ')';
    
    
  WS = [ \t\n];

  action DYNAMIC_VAR_ACTION {
    std::cout<<"DYNAMIC_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_DYNAMIC_VAR;
    fbreak;
  }
  action CONST_VAR_ACTION {
    std::cout<<"CONST_VAR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_VAR;
    fbreak;
  }
  action CONST_LIST_ACTION {
    std::cout<<"CONST_LIST_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_CONST_LIST;
    fbreak;
  }
  action LOGIC_OP_AND_ACTION {
    std::cout<<"LOGIC_OP_AND_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_AND;
    fbreak;
  }
  action LOGIC_OP_OR_ACTION {
    std::cout<<"LOGIC_OP_OR_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_OR;
    fbreak;
  }
  action LOGIC_OP_NOT_ACTION {
    std::cout<<"LOGIC_OP_NOT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LOGIC_OP_NOT;
    fbreak;
  }
  action RELATION_OP_EQ_ACTION {
    std::cout<<"RELATION_OP_EQ_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_EQ;
    fbreak;
  }
  action RELATION_OP_NE_ACTION {
    std::cout<<"RELATION_OP_NE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_NE;
    fbreak;
  }
  action RELATION_OP_GT_ACTION {
    std::cout<<"RELATION_OP_GT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GT;
    fbreak;
  }
  action RELATION_OP_GTE_ACTION {
    std::cout<<"RELATION_OP_GTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_GTE;
    fbreak;
  }
  action RELATION_OP_LT_ACTION {
    std::cout<<"RELATION_OP_LT_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LT;
    fbreak;
  }
  action RELATION_OP_LTE_ACTION {
    std::cout<<"RELATION_OP_LTE_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_LTE;
    fbreak;
  }
  action RELATION_OP_IN_ACTION {
    std::cout<<"RELATION_OP_IN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_IN;
    fbreak;
  }
  action RELATION_OP_NIN_ACTION {
    std::cout<<"RELATION_OP_NIN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RELATION_OP_NIN;
    fbreak;
  }
  action LPAREN_ACTION {
    std::cout<<"LPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_LPAREN;
    fbreak;
  }
  action RPAREN_ACTION {
    std::cout<<"RPAREN_ACTION"<<std::endl;
    ret = Parser::token::TOKEN_RPAREN;
    fbreak;
  }
  action SPACE_ACTION {
    std::cout<<"SPACE_ACTION"<<std::endl;
  }
    
  main := |*

    DYNAMIC_VAR     => DYNAMIC_VAR_ACTION;
    CONST_VAR       => CONST_VAR_ACTION;
    CONST_LIST      => CONST_LIST_ACTION;
    LOGIC_OP_AND    => LOGIC_OP_AND_ACTION;
    LOGIC_OP_OR     => LOGIC_OP_OR_ACTION;
    LOGIC_OP_NOT    => LOGIC_OP_NOT_ACTION;
    RELATION_OP_EQ  => RELATION_OP_EQ_ACTION;
    RELATION_OP_NE  => RELATION_OP_NE_ACTION;
    RELATION_OP_GT  => RELATION_OP_GT_ACTION;
    RELATION_OP_GTE => RELATION_OP_GTE_ACTION;
    RELATION_OP_LT  => RELATION_OP_LT_ACTION;
    RELATION_OP_LTE => RELATION_OP_LTE_ACTION;
    RELATION_OP_IN  => RELATION_OP_IN_ACTION;
    RELATION_OP_NIN => RELATION_OP_NIN_ACTION;
    LPAREN          => LPAREN_ACTION;
    RPAREN          => RPAREN_ACTION;
    WS              => SPACE_ACTION;

  *|;
}%%

Bool::Lexer::Lexer(const std::string& input):data(input), p(data.data()), pe(data.data() + data.length()), eof(data.data() + data.length()){
  if (data.empty()){
    return;
  }
  %% write init;
}



Bool::Parser::token_type Bool::Lexer::lex(Parser::semantic_type* val)
{
  std::cout<<"in lexer.lex"<<std::endl;
  Parser::token_type ret = Parser::token::TOKEN_END;

  if (p == eof) {
    std::cout<<"eof"<<std::endl;
    return ret;
  }

  %% write exec;

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
