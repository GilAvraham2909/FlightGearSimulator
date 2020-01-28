# FlightSimulator
This program created in Advance Programing course in Bar-Ilan University 2020.

## About
An interpreter for a domain specific language that is used to control the FlightGear simulator.
The language control the simulator via a group of variables that exists in both the simulator and the language.
It start with 23 such variables, and more could be add by binding them to values that exists in the simulator.
The interpreter can interpret a script if run with the script path, or line by line from the console.

## Creator
Gil Avraham

- **I.D** : 318662939
- **Submit name** : avrahag6

## Installing
- optiional : Linux environment to run the code, i used Clion
- Download and install the simulator on your computer - https://www.flightgear.org/download/
- Add the generic_small.xml file to the /data/Protocol directory where you installed the simulator
- Config the following settings in the 'Settings' tab in the simulator:

  `--telnet=socket,in,10,127.0.0.1,5402,tcp`
  
  `--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small`


## Luxer
I brake the txt file into vector<vector<string>>

## Parser
I take every vector<string> and choose its spasiphic command and execute the command.

## Var
we use maps to get a value in o(1). the keys of the maps are the vars name or
the path of the values. all the maps are global in order to recognize in all class
in the project.

## Function
Function with number parameter or variables parameter.

## Commands 
The language is based on the "Command" design pattern, with the following commands:

    new var command:
    Create a new variable with a vlaue of double.

    print command:
    Print text or values to the console.
    when given a variable it will print it's value.
    when given an input that is in quotes, it will print all the text that in the quotes. `

    var assign command:
    Give a var a new value

    openDataServer command:
    Open server to listion to incoming updates form the simulator.
    The input is the port the server will listen to, and the frequency it will read the data.

    connect command:
    Connect to the simulator's server.
    This connection will be used to update it about changes in variables that were bined

    if command:
    Check if the a given expression is not 0.
    If it is'nt it will run the script that inside the code block that follows it.

    while command:
    Check if the a given expression is not 0.
    If it is'nt it will run the script that inside the code block that follows it.
    Then repeat it until the expression is 0.

    Both if and while commands are recursive. meaning you can have a while inside a while, or if with while in it and so on..

    sleep command:
    Make the main thread to sleep x milliseconds, when x is the input

The interpreter also support assigning complex expression, like : `var example = (3*3/3)-10*1000`


## Run
- compile in terminal (on linux) with command:

`g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread`

- run the out file with command:

`a.out fly.txt`
- press fly on flght simulator.


## Links
- My GitHub project https://github.com/GilAvraham2909/FlightSimulator.git
# FlightSimulator
This program created in Advance Programing course in Bar-Ilan University 2020.

## About
An interpreter for a domain specific language that is used to control the FlightGear simulator.
The language control the simulator via a group of variables that exists in both the simulator and the language.
It start with 23 such variables, and more could be add by binding them to values that exists in the simulator.
The interpreter can interpret a script if run with the script path, or line by line from the console.

## Creator
Gil Avraham

- **I.D** : 318662939
- **Submit name** : avrahag6

## Installing
- optiional : Linux environment to run the code, i used Clion
- Download and install the simulator on your computer - https://www.flightgear.org/download/
- Add the generic_small.xml file to the /data/Protocol directory where you installed the simulator
- Config the following settings in the 'Settings' tab in the simulator:

  `--telnet=socket,in,10,127.0.0.1,5402,tcp`
  
  `--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small`


## Luxer
I brake the txt file into vector<vector<string>>

## Parser
I take every vector<string> and choose its spasiphic command and execute the command.

## Var
we use maps to get a value in o(1). the keys of the maps are the vars name or
the path of the values. all the maps are global in order to recognize in all class
in the project.

## Function
Function with number parameter or variables parameter.

## Commands 
The language is based on the "Command" design pattern, with the following commands:

    new var command:
    Create a new variable with a vlaue of double.

    print command:
    Print text or values to the console.
    when given a variable it will print it's value.
    when given an input that is in quotes, it will print all the text that in the quotes. `

    var assign command:
    Give a var a new value

    openDataServer command:
    Open server to listion to incoming updates form the simulator.
    The input is the port the server will listen to, and the frequency it will read the data.

    connect command:
    Connect to the simulator's server.
    This connection will be used to update it about changes in variables that were bined

    if command:
    Check if the a given expression is not 0.
    If it is'nt it will run the script that inside the code block that follows it.

    while command:
    Check if the a given expression is not 0.
    If it is'nt it will run the script that inside the code block that follows it.
    Then repeat it until the expression is 0.

    Both if and while commands are recursive. meaning you can have a while inside a while, or if with while in it and so on..

    sleep command:
    Make the main thread to sleep x milliseconds, when x is the input

The interpreter also support assigning complex expression, like : `var example = (3*3/3)-10*1000`


## Run
- compile in terminal (on linux) with command:

`g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread`

- run the out file with command:

`a.out fly.txt`
- press fly on flght simulator.


## Links
- My GitHub project https://github.com/GilAvraham2909/FlightSimulator.git

