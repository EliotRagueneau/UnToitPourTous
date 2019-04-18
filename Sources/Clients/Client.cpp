#include <utility>

//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Clients/Client.h>

#include "../../Headers/Clients/Client.h"
using namespace std;

Client::Client(string name, string address) : name(move(name)), address(move(address)) {}

Client::Client() {
    cout << "Quel est le nom du client ?\n";
    getline(cin, name);
    cout << "Quel est l'adresse du client ?\n";
    getline(cin, address);
}

string Client::getName() const {
    return name;
}

void Client::save(std::ofstream &file) const {
    file << name << endl;
    file << address << endl;
}

std::string Client::getAddress()
{
	return address;
}


