//
// Created by gili on 27.1.2020.
//

#include "Sleep.h"
#include "Interpreter.h"
extern Interpreter I;


void Sleep::execute(vector<string> data) {
  double d = I.interpret(data[1]);
  int x = (int)d;
  //sleep that tread
  this_thread::sleep_for(std::chrono::milliseconds(x));
}

Sleep::Sleep(){}
