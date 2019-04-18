//
// Created by eliot on 25/02/19.
//

#include "../../Headers/Clients/Buyer.h"
#include "../../Headers/Goods/Good.h"

using namespace std;

Buyer::Buyer(const string &name, const string &address) : Client(name, address) {}

Buyer::~Buyer() {
    visitList.clear();
}

void Buyer::save(std::ofstream &file) const {
    Client::save(file);
    file << "<VisitedGoods>" << endl;
    for (const auto &visitedGoodPtr: visitList) {
        auto sharedData = visitedGoodPtr.lock();
        if (sharedData) {
            sharedData->simpleSave(file);
        }
    }
    file << "</VisitedGoods>" << endl;
}

void Buyer::visit(const shared_ptr<Good> &visitedGood) {
    visitList.push_back(visitedGood);
}


Buyer::Buyer() : Client() {}
