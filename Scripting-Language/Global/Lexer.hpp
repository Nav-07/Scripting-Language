#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Lexer {
private:
    std::string mFile;
    
    vector<vector<pair<string, string>>> mLines;
public:
    Lexer(std::string file);
    ~Lexer();
    
    vector<vector<pair<string, string>>> getLines();
};
