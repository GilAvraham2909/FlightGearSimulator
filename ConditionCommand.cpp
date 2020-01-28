//
// Created by zvi on 12/25/19.
//

#include "ConditionCommand.h"
#include "Parser.h"

extern Interpreter I;

//constractor
ConditionCommand :: ConditionCommand(vector<vector<string>> CommandVector, string command,  string left, string sign, string right){
    this->CommandVector = CommandVector;
    this->Command = command;
    this->Left = left;
    this->Sign = sign;
    this->Right = right;
}

//this function check if condition is true or false.
bool ConditionCommand ::condition() {
    if (Sign == "=" && I.interpret(Left) == I.interpret(Right)) {
        return true;
    } else if (Sign == "==" && I.interpret(Left) == I.interpret(Right)) {
        return true;
    } else if (Sign == ">" && I.interpret(Left) > I.interpret(Right)) {
        return true;
    } else if(Sign == "<" && I.interpret(Left) < I.interpret(Right)) {
        return true;
    } else if(Sign == ">=" && I.interpret(Left) >= I.interpret(Right)) {
        return true;
    } else if(Sign == "<=" && I.interpret(Left) <= I.interpret(Right)) {
        return true;
    } else if(Sign == "!=" && I.interpret(Left) != I.interpret(Right)) {
        return true;
    }
    //the condition is false.
    return false;
}

//this function execute if or while command
void ConditionCommand :: execute() {
    Parser par = Parser();
    if (this->Command == "if" && this->condition()) {
        par.parse(this->CommandVector);
    } else if (this->Command == "while") {
        while (this->condition()) {
            par.parse(this->CommandVector);
        }
    }
    return;
}