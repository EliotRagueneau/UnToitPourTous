#include <iostream>
#include <Goods/Ground.h>
#include <fstream>

#include "../../Headers/Goods/Ground.h"
#include "../../Headers/Utils.h"

using namespace std;


Ground::Ground(double price, const std::string &address, double area, const shared_ptr<Seller> &seller, bool sold,
               bool buildable) : Good(price, address, area, seller, sold), buildable(buildable) {}

Ground::Ground(const shared_ptr<Seller> &seller) : Good(seller) {
    cout << "Peut-on construire sur le terrain ?\n";
    buildable = Utils::yesOrNo();
}

void Ground::show() const {
    Good::showID();
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
