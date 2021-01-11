#include "lexer.h" 
#include "custom_define.h"
#include <fstream>
#include <sstream>
#include "sol/sol.hpp"
#include <chrono>


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


int test_lua() {
	sol::state lua;
	lua.open_libraries(sol::lib::base);

	lua.set("media_index", 30);
	lua["src_id"] = "308";
	lua["app_version"] = "10.5";
	lua["random"] = 30;

        /*
        std::ifstream f("luac.out", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << f.rdbuf();
        std::string buff = ss.str();
        */
        
        std::string formular = R"(return media_index == 30 and (src_id == "308" or app_version == "10.5") and (random < 50 or not(random < 50)))";
        auto s = std::chrono::steady_clock::now();
        for (int i = 0; i < 100; i ++){
          bool res = lua.script(formular);
        }
        std::cout<<"time lua:"<<std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - s).count()<<std::endl;
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

  Bool::Context& context = custom_context;
  {
  std::string formular = R"(media_index == 30 && (src_id == "308" || app_version == "10.5") && (random < 50 || !random < 50) && src_id in ["309", "400" ])";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == false);
  }

  {
  std::string formular = R"(media_index == 30 && (src_id == "308" || app_version == "10.5") && (random < 50 || !random < 50) && src_id in ["308", "309", "400" ])";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == true);
  }

  {
  std::string formular = R"(media_index == 30 && (src_id == "308" || app_version == "10.5") && (random < 50 || !random < 50) || src_id in ["309", "400" ])";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == true);
  }

  {
  custom_context.tags = {"game", "30-40"};
  custom_context.loc_codes = {110000, 110001};
  custom_context.levels = {88, 99};
  custom_context.taichi = "AAA,BBB,CCC";
  std::string formular = R"(tags contains "game" && loc_codes contains 110000 && !levels contains 100 && taichi contains "AAA" && !taichi contains "AAAA")";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == true);
  }

  {
  custom_context.tags = {"game", "30-40"};
  custom_context.loc_codes = {110000, 110001};
  custom_context.levels = {88, 99};
  custom_context.taichi = "AAA,BBB,CCC";
  std::string formular = R"(tags contains "game" && loc_codes contains 110000 && !levels contains 100 && taichi contains "AAAA")";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == false);
  }

  {
  std::string formular = R"(src_id == "308" && app_version == "10.6")";
  std::cout<<formular<<std::endl;
  Bool::Lexer lexer(formular);
  Bool::Expression* expression;
  Bool::ASTParse parser(lexer, &expression);
  int res = parser.parse();
  std::cout<<"print:"<<expression->Print()<<std::endl;
  assert(expression->GetResult(custom_context) == true);
  }

/*
  auto s = std::chrono::steady_clock::now();
  for (int i = 0; i < 100; i ++){
    bool res = expression->GetResult(custom_context);
  }
  std::cout<<"time express tree:"<<std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - s).count()<<std::endl;
  test_lua();
*/
}
