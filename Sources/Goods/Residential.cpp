//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/Residential.h>

#include "../../Headers/Goods/Residential.h"
#include "../../Headers/Utils.h"

using namespace std;


Residential::Residential(double price, const string &address, double area, Seller &sellerRef, int nbRooms, bool garage)
        : Good(price, address, area, sellerRef), nbRooms(nbRooms), garage(garage) {}

Residential::Residential(Seller &sellerRef) : Good(sellerRef) {
    cout << "Combien y a t'il de pièces dans la résidence ?\n";
    cin >> nbRooms;
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
