current_path=$(pwd)
echo $current_path/lua/lib
export LD_LIBRARY_PATH=${current_path}/lua/lib
bison parser.ypp
ragel lexer.rl -o lexer.cpp
#g++ -g -std=c++17 lexer.c main.cpp -I. -I/home/fanglc/mycode/IBool/lua/include parser.tab.cpp -L/home/fanglc/mycode/IBool/lua/lib/ -llua 
g++ -g -std=c++17 lexer.cpp main.cpp -I. -I./lua/include parser.tab.cpp -L./lua/lib/ -llua 
