//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../../Headers/Clients/Client.h"
using namespace std;

Client::Client(const string &name, const string &address) : name(name), address(address) {}

Client::Client() {
    cout << "Quel est le nom du client ?\n";
    cin >> name;
    cout << "Quel est l'adresse du client ?\n";
    cin >> address;
}

string &Client::getName() {
    return name;
}
