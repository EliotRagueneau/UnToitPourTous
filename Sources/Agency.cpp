//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../Headers/Agency.h"
#include "../Headers/Goods/House.h"
#include "../Headers/Goods/Flat.h"
#include "../Headers/Goods/Ground.h"
#include "../Headers/Goods/Professional.h"

using namespace std;

void Agency::addGood() {
    Seller *sellerRef = getSellerRef();
    string sellerName = ((Client *) sellerRef)->getName();

    cout << "Quel type de bien souhaitez vous rajouter ?\n";
    cout << "\t-1. Une maison\n";
    cout << "\t-2. Un appartement\n";
    cout << "\t-3. Un terrain\n";
    cout << "\t-4. Un local professionnel\n";


    int goodKind;
    cin >> goodKind;
//    shared_ptr<Good> toAdd;

    switch (goodKind) {
        case 1: {
            //            toAdd = new House(sellerRef);
            shared_ptr<House> house(new House(sellerRef));
            goods.push_back(house);
            sellers[sellerName]->addGood(house);
            break;
        }

        case 2: {
            shared_ptr<Flat> flat(new Flat(sellerRef));
            goods.push_back(flat);
            sellers[sellerName]->addGood(flat);
            break;
        }
        case 3: {
            break;
        }
        default:
            cout << "Mauvaise entrée\n";
            addGood();
            break;

    }


}

Seller *Agency::getSellerRef() {
    cout << "Quel est le nom du vendeur ?\n";

    string sellerName;
    cin >> sellerName;

    if (sellers.count(sellerName) == 0) {
        cout << "Quel est l'adresse du vendeur ?\n";
        string sellerAdress;
        cin >> sellerAdress;
        sellers[sellerName] = new Seller(sellerName, sellerAdress);
    }
    return &(*sellers.find(sellerName)->second);
}

void Agency::addBuyer() {

}

void Agency::search() {

}

void Agency::deal() {

}

void Agency::visit() {

}

void Agency::save() {

}

void Agency::load() {

}
