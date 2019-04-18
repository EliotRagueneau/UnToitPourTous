//
// Created by eliot on 25/02/19.
//

#include "../../Headers/Clients/Seller.h"

using namespace std;

Seller::Seller() : Client() {}

Seller::Seller(const std::string &name, const std::string &address) : Client(name, address) {}

void Seller::addGood(const shared_ptr<Good> &good) {
    sellingGoodsList.push_back(good);
}

Seller::~Seller() {
    sellingGoodsList.clear();
}

void Seller::delGood(const std::shared_ptr<Good>& good) {
	sellingGoodsList.remove(good);
}