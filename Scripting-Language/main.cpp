#include <iostream>
#include <string>
using namespace std;
#include "Global/Lexer.hpp"
#include "Global/Parser.hpp"

int main() {
    Lexer lexer("test.txt");
    Parser parser(lexer);
    
    parser.OnOutput();
    return 0;
}
