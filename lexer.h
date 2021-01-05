#include "parser.tab.hpp"
#include <string>
#include <string.h>

namespace Bool
{
  class Lexer
  {
  public:
    Lexer(const std::string& data);

    Parser::token_type lex(Parser::semantic_type*);

  private:
    std::string data;
      // input start
    char const* p;
      // input end
    char const* const pe;
    char const* const eof;
    int cs;
    char const* ts;
    char const* te;
    int act;
  };
}
