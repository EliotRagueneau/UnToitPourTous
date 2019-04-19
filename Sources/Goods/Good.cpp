#include <iostream>
#include <limits>
#include <Goods/Good.h>
#include <fstream>
#include <Utils.h>

#include "../../Headers/Goods/Good.h"
#include "../../Headers/Clients/Seller.h"

using namespace std;

int Good::nbInstance = 0;

Good::Good(double price, std::string address, double area, const shared_ptr<Seller> &sellerRef, bool sold)
        : price(price), address(std::move(address)), area(area), seller(sellerRef), sold(sold) {
    id = ++nbInstance;
}

Good::Good(const shared_ptr<Seller> &sellerRef) : seller(sellerRef) {
    cout << "Quelle est l'adresse du bien ?\n";
    getline(cin, address);
    cout << "Quelle est le prix du bien (€)?\n";
    price = Utils::getDouble();
    cout << "Quelle est la surface du bien (m²)?\n";
    area = Utils::getDouble();
    id = ++nbInstance;
}

Good::Good(const Good &src) : price(src.price),
                              address(src.address), area(src.area),
                              seller(src.seller) {
    id = ++nbInstance;
}

Good::~Good() {
    proposalsMap.clear();
}

void Good::addProposal(const shared_ptr<Buyer> &ptrBuyer, double amount) {
    proposalsMap[ptrBuyer] = amount;
}

void Good::showID() const {
    cout << "Bien n°" << id << endl;
}

void Good::show() const {
    cout <<
         "\t-Prix : " << price << "€\n" <<
         "\t-Surface : " << area << "m²\n" <<
         "\t-Adresse : " << address << "\n" <<
         "\t-Nom du vendeur : " << getSellerName() << "\n";
}

void Good::showProposals() {
    for (auto &it : proposalsMap) {
        auto shared_data = it.first.lock();
        if (shared_data) {
            cout << shared_data->getName() << " Propose " << it.second << "€\n";
        }
    }
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

double Good::getPrice() const {
    return price;
}

string Good::getAddress() const {
    return address;
}

double Good::getArea() const {
    return area;
}

string Good::getSellerName() const {
    shared_ptr<Seller> sharedData = seller.lock();
    if (sharedData) {
        return sharedData->getName();
    }
    return "Vendeur supprimé";
}

int Good::getId() const {
    return id;
}

bool Good::isSold() const {
    return sold;
}

const map<weak_ptr<Buyer>, double, owner_less<weak_ptr<Buyer>>> &Good::getProposalsMap() const {
    return proposalsMap;
}

void Good::setPrice(const double &prix) {
    price = prix;
}

void Good::setSeller(const shared_ptr<Seller> &newSeller) {
    this->seller = newSeller;
}

void Good::setSold(bool status) {
    sold = status;
    price = 0;
}

void Good::cleanProposals() {
    proposalsMap.clear();
}



