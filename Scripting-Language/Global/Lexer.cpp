#include "Lexer.hpp"

Lexer::Lexer(std::string file) {
    this->mFile = file;
    
    fstream code(mFile);
    if (!code.is_open())
        throw "Lexer Error: Unable to Open File";
    string line = "";
    while (getline(code, line)) {
        string tmp = "";
        string current = "";
        for (unsigned int i = 0; i < line.size()+1; i++){
            
            if (line[i] == ' ' || i == line.size()) {
                // Compile TMP
                if (current == "") {
                    if (tmp == "print") {
                        current = "print";
                        tmp = "";
                    }
                } else {
                    if (current == "print") {
                        cout << tmp << endl;
                        tmp = "";
                    }
                }
            } else {
                tmp += line[i];
            }
        }
    }
}
Lexer::~Lexer() {
}
