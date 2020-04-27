#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "Lexer.hpp"

class Parser {
private:
public:
    Parser(Lexer lexer);
    void OnOutput();
    ~Parser();
};
