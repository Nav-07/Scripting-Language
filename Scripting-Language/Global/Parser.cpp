#include "Parser.hpp"

vector<string> outputs;
Parser::Parser(Lexer lexer) {
    for (unsigned int i = 0; i < lexer.getLines().size(); i++) {
        
        string current = "";
        for (unsigned int j = 0; j < lexer.getLines()[i].size(); j++) {
            
            if (current == "") {
                if (lexer.getLines()[i][j].first == "cmd") {
                    current = lexer.getLines()[i][j].second;
                }
            } else {
                if (current == "print") {
                    if (lexer.getLines()[i][j].first == "identifier") {
                        outputs.push_back(lexer.getLines()[i][j].second);
                    }
                }
            }
            
            
        }
    }
}

void Parser::OnOutput() {
    for (unsigned int i = 0; i < outputs.size(); i++) {
        cout << "[Output] " << outputs[i] << endl;
    }
}

Parser::~Parser() {
    
}
