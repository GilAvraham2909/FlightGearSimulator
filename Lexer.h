//
// Created by zvi on 12/19/19.
//

#ifndef FLIGHTGEAR_LEXER_H
#define FLIGHTGEAR_LEXER_H

#include <vector>
#include <string>
#include "OpenServerCommand.h"
#include "ConnectClientCommand.h"
#include <vector>
#include <unordered_map>


using namespace std;

class Lexer {
public:
    Lexer();
    vector<vector<string>> read(string fileName);
    double interpret(string s);
};


#endif //FLIGHTGEAR_LEXER_H