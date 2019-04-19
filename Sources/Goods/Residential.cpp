#include <iostream>
#include <Goods/Residential.h>

#include "../../Headers/Goods/Residential.h"
#include "../../Headers/Utils.h"

using namespace std;


Residential::Residential(double price, const string &address, double area, const shared_ptr<Seller> &seller, bool sold,
                         int nbRooms, bool garage) :
        Good(price, address, area, seller, sold), nbRooms(nbRooms), garage(garage) {}

Residential::Residential(const shared_ptr<Seller> &seller) : Good(seller) {
    cout << "Combien y a t'il de pièces dans la résidence ?\n";
    nbRooms = Utils::getInt();
    cout << "Il y a t'il un garage dans la résidence ?\n";
    garage = Utils::yesOrNo();
}

void Residential::show() const {
    Good::show();
    cout << "\t-Nombre de pièces : " << nbRooms << "\n";
    if (garage) {
        cout << "\t-La résidence possède un garage.\n";
    }
}

void Residential::save(std::ofstream &file) const {
    Good::save(file);
    file << nbRooms << endl;
    file << garage << endl;
}
