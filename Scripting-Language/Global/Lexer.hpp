#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Lexer {
private:
    std::string mFile;
public:
    Lexer(std::string file);
    ~Lexer();
};
