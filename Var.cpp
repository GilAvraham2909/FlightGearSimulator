//
// Created by gili on 27.1.2020.
//

#include "Var.h"
#include "Interpreter.h"

extern ConnectClientCommand* connectClientCommand;
extern unordered_map<string, Var*> varMap;
extern Interpreter I;

//constructor
Var::Var(string name, string path, ConnectClientCommand* connectCommand1, char sign) {
  this->name = name;
  this->path = path;
  this->connectCommand = connectCommand1;
  this->sign = sign;
}
Var:: Var(string name, string path, char sign) {
  this->name = name;
  this->path = path;
  this->sign = sign;
}
Var::  Var(string name, double val) {
  this->name = name;
  this->val = val;
}

void Var::execute(vector<string> data) {
  string name = data[1];
  string sign = data[2];
  string numOfEqual = data[3];
  if(sign == "->") {
    string path = data[4];
    //create variable that send to sim value
    Var *rightVar = new Var(name, path, connectClientCommand,'r');
    varMap[name] = rightVar;
  }
  if(sign.compare("<-") ==0) {
    string path = data[4];
    //create variable that get info from sim
    Var *leftVar = new Var(name, path, 'l');
    varMap[name] = leftVar;
  }
  if(sign.compare("=") ==0) {
    double val = I.interpret(numOfEqual);
    cout <<val<<endl;
    // create variable that get value
    Var* equalVar = new Var(name, val);
    varMap[name] = equalVar;
  }
}



//function
void Var::setVal(double val) {
  this->val = val;
  if (sign == 'r') {
    string massage = + "set " + this->path + " " + to_string(this->val) +" " + '\r' + '\n';
    connectCommand->sendToServer(massage);
  }
}
//getter
double Var::getVal() {
  return this->val;
}
string Var::getName() {
  return this->name;
}

string Var::getPath() {
  return this->path;
}

char Var::getSign() {
  return this->sign;
}
Var::Var() {}


