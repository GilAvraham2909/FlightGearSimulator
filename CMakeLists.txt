cmake_minimum_required(VERSION 3.15)
project(EX3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(EX3 main.cpp Command.h ConditionCommand.cpp ConditionCommand.h ConnectClientCommand.cpp ConnectClientCommand.h Expression.h Function.cpp Function.h Interpreter.cpp Interpreter.h Lexer.cpp Lexer.h OpenServerCommand.cpp OpenServerCommand.h Parser.cpp Parser.h Var.cpp Var.h Print.cpp Print.h Sleep.cpp Sleep.h)