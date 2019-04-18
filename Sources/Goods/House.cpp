//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/House.h>

#include "../../Headers/Goods/House.h"
#include "../../Headers/Utils.h"

using namespace std;

House::House(double price, const std::string &address, double area, shared_ptr<Seller> sellerRef, bool sold,
             int nbRooms,
             bool garage,
             bool garden, bool swimmingPool)
        : Residential(price, address, area, sellerRef, sold, nbRooms, garage), garden(garden),
                                  swimmingPool(swimmingPool) {}

House::House(shared_ptr<Seller> sellerRef) : Residential(sellerRef) {
    cout << "La maison possède t'elle un jardin ?\n";
    garden = Utils::yesOrNo();
    cout << "La maison possède t'elle une piscine ?\n";
    swimmingPool = Utils::yesOrNo();
}

void House::show() const {
    Good::printID();

    cout << "\t-Type : Maison\n";

    Residential::show();
    if (garden) {
        cout << "\t-La maison possède un jardin\n";
    }
    if (swimmingPool) {
        cout << "\t-La maison possède une piscine\n";
    }
}

void House::save(std::ofstream &file) const {
    file << "Maison\n";
    Residential::save(file);
    file << garden << endl;
    file << swimmingPool << endl;
}

string House::getType() const {
    return "Maison";
}
