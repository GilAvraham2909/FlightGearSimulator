//
// Created by gili on 27.1.2020.
//

#ifndef EX3__VAR_H_
#define EX3__VAR_H_

#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <array>
#include <unordered_map>
#include <stdlib.h>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include "ConnectClientCommand.h"

class Var: public Command {
 private:
  string name;
  string path = "n";
  double val = 0;
  char sign = 'n';
  ConnectClientCommand *connectCommand = NULL;
 public:
  Var(string name, string path, ConnectClientCommand *connectCommand1, char sign);
  Var(string name, string path, char sign);
  Var(string name, double val);
  void execute(vector<string>) override ;
  void setVal(double);
  double getVal();
  string getName();
  string getPath();
  char getSign();
  Var();
};

#endif //EX3__VAR_H_
