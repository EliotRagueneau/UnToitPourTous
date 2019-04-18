#include <utility>

//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/Ground.h>
#include <fstream>

#include "../../Headers/Goods/Ground.h"
#include "../../Headers/Utils.h"

using namespace std;


Ground::Ground(double price, const std::string &address, double area, shared_ptr<Seller> sellerRef, bool sold,
               bool buildable)
        : Good(price, address, area, move(sellerRef), sold), buildable(buildable) {}

Ground::Ground(shared_ptr<Seller> sellerRef) : Good(move(sellerRef)) {
    cout << "Peut-on construire sur le terrain ?\n";
    buildable = Utils::yesOrNo();
}

void Ground::show() const {
    Good::printID();
    cout << "\t-Type : Terrain\n";
    Good::show();
    if (buildable) {
        cout << "\t-On peut construire sur ce terrain\n";
    }
}

void Ground::save(ofstream &file) const {
    file << "Terrain\n";
    Good::save(file);
    file << buildable << endl;
}

string Ground::getType() const {
    return "Terrain";
}
