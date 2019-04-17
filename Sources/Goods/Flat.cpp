//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <Goods/Flat.h>

#include "../../Headers/Goods/Flat.h"
#include "../../Headers/Utils.h"

using namespace std;

Flat::Flat(double price, const std::string &address, double area, shared_ptr<Seller> sellerRef, bool sold, int nbRooms,
           bool garage, int floor, bool cave, bool balcony, int nbBuildingFlats) : Residential(price, address, area,
                                                                                               sellerRef, sold, nbRooms,
                                                                                               garage), floor(floor),
                                                                                   cave(cave), balcony(balcony),
                                                                                   nbBuildingFlats(nbBuildingFlats) {}

Flat::Flat(shared_ptr<Seller> sellerRef) : Residential(sellerRef) {
    cout << "A quel étage se trouve l'appartement ?\n";
    cin >> floor;
    cout << "L'apparatement possède t'il un balcon ?\n";
    balcony = Utils::yesOrNo();
    cout << "L'apparatement possède t'il une cave ?\n";
    cave = Utils::yesOrNo();
    cout << "Combien y a t'il d'appartements dans l'immeuble ?\n";
    cin >> nbBuildingFlats;
    cin.ignore();
}

void Flat::show() const {
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
