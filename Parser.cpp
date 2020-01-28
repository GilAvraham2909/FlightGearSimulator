//
// Created by gili on 27.1.2020.
//

#include <list>
#include "Parser.h"
#include "Interpreter.h"
#include "ConnectClientCommand.h"
#include "ConditionCommand.h"
#include "Var.h"
#include "Function.h"

extern Interpreter I;
extern vector<thread*> m_thread_vector;
extern ConnectClientCommand* connectClientCommand;
extern unordered_map<string, Var*> varMap;
extern unordered_map<string, Function*> funcMap;
extern unordered_map<string, Command*> CommandMap;



Parser :: Parser() {}

void Parser :: parse(vector<vector<string>> CommandVector) {
    int length = CommandVector.size();
    for (int i = 0; i < length; ++i) {
      vector<string> data = CommandVector[i];
      string r = data[0];
      if (CommandMap.find(r)!= CommandMap.end()) {
        CommandMap[r]->execute(data);
      } else if (r.compare("if") == 0 || r.compare("while") == 0) {
        string command = r;
        string left = data[1];
        string sign = data[2];
        string right = data[3];
        i++;
        vector<vector<string>> conditionVector;
        int loop = 0;
        while (CommandVector[i][0] != "}" || loop) {
          if(CommandVector[i][0] == "while" || CommandVector[i][0] == "if") {
            loop++;
          }
          if (CommandVector[i][0] == "}") {
            loop--;
          }
          conditionVector.push_back(CommandVector[i]);
          i++;
        }
        ConditionCommand* condition = new ConditionCommand(conditionVector, command, left, sign, right);
        condition->execute();
      } else if(varMap.find(r)!= varMap.end()) {
        double d = I.interpret(data[2]);
        //update val
        varMap[r]->setVal(d);
      }
//      } else if (funcMap.find(r)!= funcMap.end()) {
//        vector<string> num;
//        while (it2 != (*it).end()) {
//          num.push_back(*it2);
//          it2++;
//        }
//        Function *f = funcMap[r];
//        f->setVariables(num);
//        f->execute();
//      } else if ((I.getMap().find(r) != I.getMap().end())) {
//        I.setMapValue(r, I.interpret(data[1]));
//      } else {
//        // create function
//        vector<vector<string>> conditionList;
//        vector<string> vars;
//        it2++;
//        while (it2 != (*it).end()) {
//          vars.push_back(*it2);
//          it2++;
//          if (it2 != (*it).end()){
//            it2++;
//          }
//        }
//        i++;
//        int condition = 0;
//        while (*(*it).begin() != "}" || condition) {
//          if (*(*it).begin() == "if" || *(*it).begin() == "while") {
//            condition++;
//          }
//          if (*(*it).begin() == "}") {
//            condition--;
//          }
//          conditionList.push_back(*it);
//          it++;
//        }
//        Function* f = new Function(conditionList, vars);
//        funcMap[r] = f;
//      }
    }
}