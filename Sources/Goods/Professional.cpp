#include <iostream>
#include <Goods/Professional.h>

#include "../../Headers/Goods/Professional.h"
#include "../../Headers/Utils.h"

using namespace std;

Professional::Professional(double price, const std::string &address, double area, const shared_ptr<Seller> &seller,
                           bool sold, double showcaseSize, bool storeRoom) :
        Good(price, address, area, seller, sold), showcaseSize(showcaseSize), storeRoom(storeRoom) {}

Professional::Professional(const shared_ptr<Seller> &sellerRef) : Good(sellerRef) {
    cout << "Quelle est la surface de la vitrine ?\n";
    showcaseSize = Utils::getDouble();
    cout << "Le local professionnel possède-t'il une pièce de stockage ?\n";
    storeRoom = Utils::yesOrNo();
}

void Professional::show() const {
    Good::showID();
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

string Professional::getType() const {
    return "Local";
}
