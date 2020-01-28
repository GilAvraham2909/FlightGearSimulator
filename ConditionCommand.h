//
// Created by zvi on 12/25/19.
//

#ifndef FLIGHTGEAR_CONDITIONCOMMAND_H
#define FLIGHTGEAR_CONDITIONCOMMAND_H

#include <vector>
#include "Command.h"
#include "Interpreter.h"

class ConditionCommand {
    string Command;
    string Left;
    string Sign;
    string Right;
    vector<vector<string>> CommandVector;
public:
    ConditionCommand(vector<vector<string>> CommandVector, string command,  string left, string sign, string right);
    void execute();
    bool condition();
};

#endif //FLIGHTGEAR_CONDITIONCOMMAND_H
