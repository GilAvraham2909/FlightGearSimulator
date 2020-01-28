//
// Created by zvi on 12/26/19.
//

#include "Function.h"
#include "Parser.h"

extern Interpreter I;

Function :: Function(vector<vector<string>> CommandVector, vector<string> vars) {
    this->Vars = vars;
    this->CommandVector = CommandVector;
}

void Function :: setVariables(vector<string> num) {
    I.setVariables(this->Vars, num);
}

int Function :: execute() {
    Parser par = Parser();
    par.parse(this->CommandVector);
}