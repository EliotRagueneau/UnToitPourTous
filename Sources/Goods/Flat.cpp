#include <iostream>
#include <Goods/Flat.h>

#include "../../Headers/Goods/Flat.h"
#include "../../Headers/Utils.h"

using namespace std;

Flat::Flat(double price, const std::string &address, double area, const shared_ptr<Seller> &seller, bool sold,
           int nbRooms, bool garage, int floor, bool cave, bool balcony, int nbBuildingFlats) :
        Residential(price, address, area, seller, sold, nbRooms, garage), floor(floor), cave(cave), balcony(balcony),
        nbBuildingFlats(nbBuildingFlats) {}

Flat::Flat(const shared_ptr<Seller> &seller) : Residential(seller) {
    cout << "A quel étage se trouve l'appartement ?\n";
    floor = Utils::getInt();
    cout << "L'apparatement possède t'il un balcon ?\n";
    balcony = Utils::yesOrNo();
    cout << "L'apparatement possède t'il une cave ?\n";
    cave = Utils::yesOrNo();
    cout << "Combien y a t'il d'appartements dans l'immeuble ?\n";
    nbBuildingFlats = Utils::getInt();
}

void Flat::show() const {
    Good::showID();
    cout << "\t-Type : Appartement\n";
    Residential::show();
    cout <<
         "\t-Étage : " << floor << "\n" <<
         "\t-Nombre d'appartements dans l'immeuble : " << nbBuildingFlats << "\n";
    if (balcony) {
        cout << "\t-L'appartement possède un balcon\n";
    }
    if (cave) {
        cout << "\t-L'appartement possède une cave\n";
    }
}

void Flat::save(std::ofstream &file) const {
    file << "Appartement\n";
    Residential::save(file);
    file << floor << endl;
    file << balcony << endl;
    file << cave << endl;
    file << nbBuildingFlats << endl;

}

std::string Flat::getType() const {
    return "Appartement";
}
