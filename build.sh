export LD_LIBRARY_PATH=./lua/lib
bison parser.ypp
ragel lexer.rl
#g++ -g -std=c++17 lexer.c main.cpp -I. -I/home/fanglc/mycode/IBool/lua/include parser.tab.cpp -L/home/fanglc/mycode/IBool/lua/lib/ -llua 
g++ -g -std=c++17 lexer.c main.cpp -I. -I./lua/include parser.tab.cpp -L./lua/lib/ -llua 
