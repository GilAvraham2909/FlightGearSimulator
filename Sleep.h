//
// Created by gili on 27.1.2020.
//

#ifndef EX3__SLEEP_H_
#define EX3__SLEEP_H_

#include <vector>
#include "Command.h"
class Sleep:public Command {
 public:
  void execute(vector<string> data) override ;
  Sleep();
};

#endif //EX3__SLEEP_H_
