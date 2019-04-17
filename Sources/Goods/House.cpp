//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/House.h>

#include "../../Headers/Goods/House.h"
#include "../../Headers/Utils.h"

using namespace std;

House::House(double price, const string &address, double area, Seller &sellerRef, int nbRooms, bool garage, bool garden,
             bool swimmingPool) : Residential(price, address, area, sellerRef, nbRooms, garage), garden(garden),
                                  swimmingPool(swimmingPool) {}

House::House(Seller &sellerRef) : Residential(sellerRef) {
    cout << "La maison possède t'elle un jardin ?\n";
    garden = Utils::yesOrNo();
    cout << "La maison possède t'elle une piscine ?\n";
    swimmingPool = Utils::yesOrNo();
}

void House::show() const {
    Residential::show();
    if (garden) {
        cout << "\t-L'appartement possède un balcon\n";
    }
    if (swimmingPool) {
        cout << "\t-L'appartement possède une cave\n";
    }
}

void House::save(std::ofstream &file) const {
    file << "Maison\n";
    Residential::save(file);
    file << garden << endl;
    file << swimmingPool << endl;
}
