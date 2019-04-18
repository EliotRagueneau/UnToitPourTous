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

Good::Good(const shared_ptr<Seller> &sellerRef) : sellerRef(sellerRef) {
    cout << "Quelle est l'adresse du bien ?\n";
    getline(cin, address);
    cout << "Quelle est le prix du bien (€)?\n";
    cin >> price;
    cout << "Quelle est la surface du bien (m²)?\n";
    cin >> area;
    cin.ignore();
    id = ++nbInstance;
}

Good::Good(double price, std::string address, double area, const shared_ptr<Seller> &sellerRef, bool sold)
        : price(price), address(std::move(address)),
          area(area), sellerRef(sellerRef), sold(sold) {
    id = ++nbInstance;
}

string Good::getSellerName() const {
    shared_ptr<Seller> sharedData = sellerRef.lock();
    if (sharedData) {
        return sharedData->getName();
    }
}

string Good::getAddress() const {
    return address;
}

void Good::show() const {
    cout <<
         "\t-Prix : " << price << "€\n" <<
         "\t-Surface : " << area << "m²\n" <<
         "\t-Adresse : " << address << "\n" <<
         "\t-Nom du vendeur : " << getSellerName() << "\n";
}

void Good::save(ofstream &file) const {
    file << price << endl;
    file << area << endl;
    file << address << endl;
    file << getSellerName() << endl;
    file << sold << endl;
    file << "<Propositions>" << endl;
    for (const auto &pair : proposalsMap) {
        auto shared_data = pair.first.lock();
        if (shared_data) {
            file << shared_data->getName() << endl;
            file << pair.second << endl;
        }
    }
    file << "</Propositions>" << endl;
}

void Good::simpleSave(std::ofstream &file) const {
    file << address << endl;
    file << price << endl;
    file << area << endl;
    file << getSellerName() << endl;
}

Good::~Good() {
    proposalsMap.clear();
}

void Good::showProposals() {
    for (auto &it : proposalsMap) {
        auto shared_data = it.first.lock();
        if (shared_data) {
            cout << shared_data->getName() << " Propose " << it.second << "€\n";
        }
    }
}

double Good::getPrice() const {
    return price;
}

double Good::getArea() const {
    return area;
}

void Good::addProposal(const shared_ptr<Buyer> &ptrBuyer, double amount) {
    proposalsMap[ptrBuyer] = amount;
}

void Good::printID() const {
    cout << "Bien n°" << id << endl;
}

bool Good::isSold() const {
    return sold;
}


void Good::setSold(bool status) {
    sold = status;
    price = 0;
}

int Good::getId() const {
    return id;
}

void Good::cleanProposals() {
	proposalsMap.clear();
}

void Good::setSellerRef(const std::shared_ptr<Seller>& seller) {
	sellerRef = seller;
}

void Good::setPrice(const double &prix){
	price = prix;
}

const map<weak_ptr<Buyer>, double, owner_less<weak_ptr<Buyer>>> &Good::getProposalsMap() const {
    return proposalsMap;
}

