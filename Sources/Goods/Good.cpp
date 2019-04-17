#include <utility>

#include <utility>

//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <limits>
#include <Goods/Good.h>
#include <fstream>

#include "../../Headers/Goods/Good.h"
#include "../../Headers/Clients/Seller.h"

using namespace std;

int Good::nbInstance = 0;

Good::Good(const Good &src) : price(src.price),
                              address(src.address), area(src.area),
                              sellerRef(src.sellerRef) {
    id = ++nbInstance;
}

Good::Good(shared_ptr<Seller> sellerRef) : sellerRef(std::move(sellerRef)) {
    cout << "Quelle est l'adresse du bien ?\n";
    getline(cin, address);
    cout << "Quelle est le prix du bien (€)?\n";
    cin >> price;
    cout << "Quelle est la surface du bien (m²)?\n";
    cin >> area;
    cin.ignore();
    id = ++nbInstance;
}

Good::Good(double price, std::string address, double area, shared_ptr<Seller> sellerRef, bool sold)
        : price(price), address(std::move(address)),
          area(area), sellerRef(std::move(sellerRef)), sold(sold) {
    id = ++nbInstance;
}

shared_ptr<Seller> Good::getSeller() const {
    return sellerRef;
}

string Good::getAddress() const {
    return address;
}

void Good::show() const {
    cout << "Bien n°" << id << endl;
    cout <<
         "\t-Prix : " << price << "€\n" <<
         "\t-Surface : " << area << "m²\n" <<
         "\t-Adresse : " << address << "\n" <<
         "\t-Nom du vendeur : " << sellerRef->getName() << "\n";
}

void Good::save(ofstream &file) const {
    file << price << endl;
    file << area << endl;
    file << address << endl;
    file << sellerRef->getName() << endl;
    file << sold << endl;
    file << "<Propositions>" << endl;
    for (const auto& pair : proposalsMap) {
        file << pair.first->getName() << endl;
        file << pair.second << endl;
    }
    file << "</Propositions>" << endl;
}

void Good::simpleSave(std::ofstream &file) const {
    file << address << endl;
    file << price << endl;
    file << area << endl;
    file << sellerRef->getName() << endl;
}

Good::~Good() {
    proposalsMap.clear();
}

double Good::getPrice() const {
    return price;
}

double Good::getArea() const {
    return area;
}

void Good::addProposal(const shared_ptr<Buyer> &ptrBuyer, double price) {
	proposalsMap[ptrBuyer] = price;
}

