# IBool

根据上下文，计算布尔表达式的值。 词发分析由ragel完成，语法分析由bison完成，计算由表达式树完成。  
目前只支持 ==, !=(<>), <, <=, >, >=, ||, && 操作符  
自定义类型比较需要重载相应操作符。  

示例:  
  srand(::time(nullptr));  
  CustomContext custom_context;  
  custom_context.media_index = 30;  
  custom_context.app_version.major = 10;  
  custom_context.app_version.minor = 6;  
  custom_context.src_id = "308";  
  custom_context.random = rand()%100;  

  Bool::Context& context = custom_context;  

  std::string formular = R"(media_index == 30 && (src_id == "308" || app_version == "10.5") && random < 50)";  
  Bool::Lexer lexer(formular);  
  Bool::Expression* expression;  
  Bool::ASTParse parser(lexer, &expression);  
  int res = parser.parse();  
  
  std::cout<<"print:"<<expression->Print()<<std::endl;  
  std::cout<<"final result:"<<expression->GetResult(custom_context)<<std::endl;  
  std::cout<<"parse result:"<<res<<std::endl;  

参考文档:  
https://www.gnu.org/software/bison/manual/bison.html#Bison-Parser  
http://www.colm.net/files/ragel/ragel-guide-6.10.pdf  
https://github.com/cucumber-attic/bool  
https://archive.codeplex.com/?p=ragelbison  