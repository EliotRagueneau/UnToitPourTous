//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_CLIENTS_H
#define UNTOITPOURTOUS_CLIENTS_H


#include <string>
#include <fstream>

class Client {
protected:
    std::string name;
    std::string address;
public:
    Client(std::string name, std::string address);

    std::string getName() const;

    Client();

    virtual void save(std::ofstream& file) const;

};


#endif //UNTOITPOURTOUS_CLIENTS_H
