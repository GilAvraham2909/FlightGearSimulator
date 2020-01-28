//
// Created by gili on 27.1.2020.
//

#ifndef EX3__PRINT_H_
#define EX3__PRINT_H_

#include <vector>
#include "Command.h"

class Print: public Command {
 public:
  void execute(vector<string> data) override;
  Print();
};

#endif //EX3__PRINT_H_
