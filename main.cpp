#include "lexer.h" 
#include "custom_define.h"


namespace Bool{


void Parser::error(const std::string&msg){
  std::cout<<"parse error:"<<msg<<std::endl;
}
class ASTParse : public Bool::Parser{
public:
  using Parser::Parser;
  virtual void error(const std::string& msg) override{
    std::cout<<"ast parse error:"<<msg<<std::endl;
  } 
};
}
int main()
{
  srand(::time(nullptr));
  CustomContext custom_context;
  custom_context.media_index = 30;
  custom_context.app_version.major = 10;
  custom_context.app_version.minor = 6;
  custom_context.src_id = "308";
  custom_context.random = rand()%100;
  std::cout<<"random:"<<custom_context.random<<std::endl;

  Bool::Context& context = custom_context;

  std::string formular = R"(media_index == 30 && (src_id == "308" || app_version == "10.5") && random < 50 xxx)";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  std::cout<<"final result:"<<expression->GetResult(custom_context)<<std::endl;
  std::cout<<"parse result:"<<res<<std::endl;
}
