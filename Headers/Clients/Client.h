//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_CLIENTS_H
#define UNTOITPOURTOUS_CLIENTS_H


#include <string>

class Client {
protected:
    std::string name;
    std::string address;
public:
    Client(const std::string &name, const std::string &address);

    std::string &getName();

    Client();

};


#endif //UNTOITPOURTOUS_CLIENTS_H
