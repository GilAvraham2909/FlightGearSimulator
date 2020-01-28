//
// Created by gili on 27.1.2020.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_

#include <vector>
#include <string>
#include "OpenServerCommand.h"
using  namespace std;

class Parser {
 private:
  OpenServerCommand* openServerCommand;
 public:
  Parser();
  void parse(vector<vector<string>> command);
};

#endif //EX3__PARSER_H_
