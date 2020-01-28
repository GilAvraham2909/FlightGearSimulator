//
// Created by zvi on 12/19/19.
//

#include "Command.h"
#include "Lexer.h"
#include "Interpreter.h"
#include <fstream>
#include <string>
#include "Var.h"
#include "ConditionCommand.h"
#include "Function.h"
#include <unordered_map>
#include <thread>

using namespace std;

//global data
extern unordered_map<string, Function*> funcMap;
extern vector<thread*> m_thread_vector;
extern Interpreter I;

/// return if the string is a condition operator
bool isOperator(string s) {
    if (s == "=" || s == "==" || s == "<=" || s == ">=" || s == "!=" || s == "<" || s == ">") {
        return true;
    }
    return false;
}

// return the line without the word.
string eraseWord(string line, string word){
    string newLine = "";
    // num of " or ' ' we sould to remove.
    int add = 1;
    if (line[0] == '"') {
        add++;
    }
    // copy the new erase line to temp string called newLine
    for (unsigned int i = word.length() + add; i < line.length(); i++) {
        newLine += line[i];
    }
    return newLine;
}

//erase the latest char of word;
string eraseEnd(string word) {
    string newWord = "";
    unsigned int i;
    for (i = 0; i < word.length() - 1; i++) {
        newWord += word[i];
    }
    return newWord;
}

//erase first char of word
string eraseFirst(string word) {
    string temp = "";
    for (unsigned int i = 1; i < word.length(); i++) {
        temp += word[i];
    }
    return  temp;
}

//if don't have space, add space.
string addSpace(string line) {
    int comma = 0;
    string spaceLine = "";
    for (unsigned int i = 0; i < line.length(); i++) {
        //check if comma is open. if open close = 0, else open = 1.
        if(line[i] == '"') {
            if (comma) {
                comma = 0;
            } else {
                comma = 1;
            }
        }
        //condition for space before char
        if ((!comma) &&
            ((line[i] == '=' && line[i-1] != '<' && line[i+1] != '>' && line[i-1] != '>' && line[i-1] != '!' &&
            line[i-1] != '=') || line[i] == '<'  || (line[i] == '>' && (line[i-1] != '-' && line[i+1] != '=' &&
            line[i-1] != '=')) || (line[i] == '-' && line[i+1] == '>')) && line[i - 1] != ' ') {
            spaceLine += ' ';
        }
        //add char
        spaceLine += line[i];
        //condition for space after char
        if ((line[i] == '=' && line[i+1] != '>' && line[i+1] != '=') || (line[i] == '<' && (line[i+1] != '-'&&
        line[i+1] != '=')) || (line[i] == '>' && line[i+1] != '=' && line[i-1] != '=') && (line[i + 1] != ' ')) {
            spaceLine += ' ';
        }
    }
    return spaceLine;
}

//remove space in expression
string removeSpace(string word) {
    string temp = "";
    for (unsigned int i = 0; i < word.length(); i++) {
        if (word[i] != ' ') {
            temp += word[i];
        }
    }
    return temp;
}

// return the first word of the line (until there is a space)
string readWord(string line) {
    string first = "";
    int i = 0;
    while ((line[i] != ' ' || line[0] == '"' || (line[0] >= '0' && line[0] <= '9')) &&
           line[i] != '(' && line[i] != ')' && line[i] != ',' && line.length() != first.length() &&
           line[i] != '\t' && line[i] != '{') {
        first += line[i];
        i++;
    }
    //erase " "
    if (first[0] == '"' || first[first.length()-1] == '"') {
        string temp = "";
        int i = 0;
        int num = 0;
        while (first.length() != temp.length() - num) {
            if (first[i] != '"') {
                temp += first[i];
                i++;
            } else {
                if(i != 0) {
                    break;
                }
                i++;
                num++;
            }
        }
        first = temp;
    }
    return first;
}

//empty constractor
Lexer :: Lexer() {
}

//read the file and lexer to list.
vector<vector<string>> Lexer :: read(string fileName) {
    //open file
    fstream filePtr;
    filePtr.open(fileName);
    if (!filePtr.is_open()) {
        throw "Error open file " + fileName;
    }
    // create list of list *it->begin() command
  vector<vector<string>> commands;
    string line;
    while (getline(filePtr, line)) {
      vector<string> dataCommand;
      line = addSpace(line);
      while (line.length() != 0 && line != ")") {
            string word;
            if (dataCommand.size() != 0 && (isOperator(dataCommand.back()) || dataCommand.back() == "Sleep")) {
                word = line;
                //remove space
                while (word[0] == ' ') {
                    word = eraseFirst(word);
                    line = eraseFirst(line);
                }
                //erase { if in the end of string
                int wordLength = word.length() - 1;
                if(word[wordLength] == '{' || (dataCommand.back() == "Sleep" && word[wordLength] == ')')) {
                    word = eraseEnd(word);
                }
                while (word[word.length() - 1] == ' ') {
                    word = eraseEnd(word);
                    line = eraseEnd(line);
                }
                word = removeSpace(word);
                line = removeSpace(line);
                //end remove space
            } else {
                word = readWord(line);
            }
            line = eraseWord(line, word);
            //remove space in expression
            if(word[0] >= '0' && word[0] <= '9') {
                word = removeSpace(word);
            }
            //condition if there is expression
            if (((dataCommand.size() > 0) && (*(dataCommand.begin()) == "connectControlClient" || *(dataCommand.begin()) == "Sleep")
                || (word == "Sleep") || (word == "connectControlClient"))) {
                line = removeSpace(line);
            }
            if (word.length() != 0) {
              dataCommand.push_back(word);
            }
        }
        if(dataCommand.size() > 0) {
            commands.push_back(dataCommand);
        }
    }
    filePtr.close();
    return commands;
}

//parser

