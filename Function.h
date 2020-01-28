//
// Created by zvi on 12/26/19.
//

#ifndef FLIGHTGEAR_FUNCTION_H
#define FLIGHTGEAR_FUNCTION_H

#include <vector>
#include "Command.h"
#include "Interpreter.h"

class Function {
    vector<vector<string>> CommandVector;
    vector<string> Vars;
public:
    Function(vector<vector<string>> CommandVector, vector<string> vars);
    int execute() ;
    void setVariables(vector<string> num);
};


#endif //FLIGHTGEAR_FUNCTION_H
