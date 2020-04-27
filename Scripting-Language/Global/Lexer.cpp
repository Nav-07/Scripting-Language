#include "Lexer.hpp"

#include <map>
#include <utility>

vector<string> inbuild_funcs = {
    "print"
};

Lexer::Lexer(std::string file) {
    this->mFile = file;
    
    fstream code(mFile);
    if (!code.is_open())
        throw "Lexer Error: Unable to Open File";
    string line = "";
    while (getline(code, line)) {
        string tmp = "";
        string current = "";
        
        vector<pair<string, string>> lines;
        for (unsigned int i = 0; i < line.size()+1; i++){
            
            if (line[i] == ' ' || i == line.size()) {
                // Compile TMP
                for (unsigned int j = 0; j < inbuild_funcs.size(); j++) {
                    if (tmp == inbuild_funcs[j]) {
                        lines.push_back(make_pair("cmd", tmp));
                        tmp = "";
                    }
                    else
                        continue;
                }
                if (tmp != "") {
                    lines.push_back(make_pair("identifier", tmp));
                }
            } else {
                tmp += line[i];
            }
        }
        
        mLines.push_back(lines);
    }
}
Lexer::~Lexer() {
}

vector<vector<pair<string, string>>> Lexer::getLines() {
    return mLines;
}
