//
// Created by johnnie on 22/12/2019.
//

#ifndef FLIGHTGEAR_COMMAND_H
#define FLIGHTGEAR_COMMAND_H

using namespace std;
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
//interface
class Command {
 public:
  virtual void execute(vector<string> data) = 0;
};

#endif //FLIGHTGER_COMMAND_H
