//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../../Headers/Goods/Residential.h"
#include "../../Headers/Utils.h"

using namespace std;


Residential::Residential(double price, const string &address, double area, Seller *sellerRef, int nbRooms, bool garage)
        : Good(price, address, area, sellerRef), nbRooms(nbRooms), garage(garage) {}

Residential::Residential(Seller *sellerRef) : Good(sellerRef) {
    cout << "Combien y a t'il de pièces dan sla résidence ?\n";
    cin >> nbRooms;
    cout << "Il y a t'il un garage dans la résidence ?\n";
    garage = Utils::yesOrNo();
}
