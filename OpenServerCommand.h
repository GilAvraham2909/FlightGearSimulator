
#ifndef FLIGHTGEAR_OPENSERVERCOMMAND_H
#define FLIGHTGEAR_OPENSERVERCOMMAND_H

#include <vector>
#include "Command.h"

extern bool connected;

class OpenServerCommand : public Command{
private:
    int m_port;
    int m_fd;
    int m_socketFd;
    array<double, 36> m_array;
    unordered_map<string, double > m_map;

public:
    explicit OpenServerCommand(double port);
    void execute(vector<string> data) override ;
  explicit OpenServerCommand();
    void getInfoAboutSim();
    int readFromSim();
    int insertBufferToMap(char* buffer, int buffer_len);
    void closeServer();
};


#endif //FLIGHTGEAR_OPENSERVERCOMMAND_H
