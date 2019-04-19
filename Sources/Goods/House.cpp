#include <iostream>
#include <Goods/House.h>

#include "../../Headers/Goods/House.h"
#include "../../Headers/Utils.h"

using namespace std;

House::House(double price, const std::string &address, double area, const shared_ptr<Seller>& seller, bool sold,
             int nbRooms,
             bool garage,
             bool garden, bool swimmingPool)
        : Residential(price, address, area, seller, sold, nbRooms, garage), garden(garden),
                                  swimmingPool(swimmingPool) {}

House::House(const shared_ptr<Seller>& seller) : Residential(seller) {
    cout << "La maison possède t'elle un jardin ?\n";
    garden = Utils::yesOrNo();
    cout << "La maison possède t'elle une piscine ?\n";
    swimmingPool = Utils::yesOrNo();
}

void House::show() const {
    Good::showID();
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
