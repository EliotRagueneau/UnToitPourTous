//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/Professional.h>

#include "../../Headers/Goods/Professional.h"
#include "../../Headers/Utils.h"

using namespace std;

Professional::Professional(double price, const std::string &address, double area, shared_ptr<Seller> sellerRef,
                           bool sold,
                           double showcaseSize, bool storeRoom)
        : Good(price, address, area, sellerRef, sold), showcaseSize(showcaseSize),
                                             storeRoom(storeRoom) {}

Professional::Professional(shared_ptr<Seller> sellerRef) : Good(sellerRef) {
    cout << "Quelle est la surface de la vitrine ?\n";
    cin >> showcaseSize;
    cout << "Le local professionnel possède-t'il une pièce de stockage ?\n";
    storeRoom = Utils::yesOrNo();
}

void Professional::show() const {
    Good::printID();
    cout << "\t-Type : Local\n";
    Good::show();
    cout << "\t-Surface de la vitrine : " << showcaseSize << "m²\n";
    if (storeRoom) {
        cout << "\t-Le local possède une pièce de stockage\n";
    }
}

void Professional::save(ofstream &file) const {
    file << "Local" << endl;
    Good::save(file);
    file << showcaseSize << endl;
    file << storeRoom << endl;
}
