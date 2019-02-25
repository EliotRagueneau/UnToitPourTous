//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../../Headers/Goods/Professional.h"
#include "../../Headers/Utils.h"

using namespace std;

Professional::Professional(double price, const string &address, double area, Seller *sellerRef, double showcaseSize,
                           bool storeRoom) : Good(price, address, area, sellerRef), showcaseSize(showcaseSize),
                                             storeRoom(storeRoom) {}

Professional::Professional(Seller *sellerRef) : Good(sellerRef){
    cout << "Quelle est la surface de la vitrine ?\n";
    cin >> showcaseSize;
    cout << "Le local professionnel possède-t'il une pièce de stockage ?\n";
    storeRoom = Utils::yesOrNo();
}
