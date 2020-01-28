//
// Created by gili on 27.1.2020.
//

#include "Print.h"
#include "Var.h"
#include "Interpreter.h"
extern unordered_map<string, Var*> varMap;
extern Interpreter I;

void Print::execute(vector<string> data) {
  if(varMap.find(data[1]) != varMap.end()) {
    cout <<varMap[data[1]]->getVal()<< endl;
  } else if (I.getMap().find(data[1]) != I.getMap().end()) {
    cout <<I.getMap()[data[1]]<< endl;
  } else {
    string print = data[1];
    cout<< print << endl;
  }
}

Print::Print(){}
