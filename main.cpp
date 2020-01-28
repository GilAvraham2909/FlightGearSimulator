#include <iostream>
#include "ConnectClientCommand.h"
#include "OpenServerCommand.h"
#include "Lexer.h"
#include "Var.h"
#include "Function.h"
#include "Parser.h"
#include "Print.h"
#include "Sleep.h"

using namespace std;

//global data
unordered_map<string, Var*> varMap;
unordered_map<string, Command*> CommandMap;
unordered_map<string, Function*> funcMap;
Interpreter I;
ConnectClientCommand* connectClientCommand = new ConnectClientCommand();
vector<thread*> m_thread_vector;

bool connected = false;

void initMap() {
     CommandMap["Print"] = new Print();
     CommandMap["Sleep"] = new Sleep();
     CommandMap["var"] = new Var();
     CommandMap["connectControlClient"] = connectClientCommand;
     CommandMap["openDataServer"] = new OpenServerCommand();



}


int main(int argc, char **argv) {
  //intinal
  initMap();
  //Lexer
  Lexer lex = Lexer();
  vector<vector<string>> command = lex.read(argv[1]);
    //parser
    Parser par = Parser();
    par.parse(command);
    //close the server
    connected = false;
    //close the client
    connectClientCommand->closeConnection();
    //free all memory
    for(unordered_map<string, Command*>::iterator it = CommandMap.begin(); it != CommandMap.end(); it++) {
        free(it->second);
    }
    for(unordered_map<string, Var*>::iterator it = varMap.begin(); it != varMap.end(); it++) {
        free(it->second);
    }
    for(unordered_map<string, Function*>::iterator it = funcMap.begin(); it != funcMap.end(); it++) {
        free(it->second);
    }
    for (unsigned int i = 0; i < m_thread_vector.size(); i++) {
        free(m_thread_vector[i]);
    }
    return 0;

}