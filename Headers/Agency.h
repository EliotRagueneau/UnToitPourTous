//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_AGENCY_H
#define UNTOITPOURTOUS_AGENCY_H


#include <list>
#include <memory>
#include "Goods/Good.h"
#include "Goods/House.h"
#include "Goods/Flat.h"
#include "Goods/Ground.h"
#include "Goods/Professional.h"

class Agency {
private:
//    std::list<House> houses;
//    std::list<Flat> flats;
//    std::list<Ground> grounds;
//    std::list<Professional> professionals;

    std::list<std::shared_ptr<Good>> goods;
    std::map<std::string, Seller *> sellers;
    std::map<std::string, Buyer *> buyers;
public:

    Seller *getSellerRef();

    void addGood();

    void addBuyer();

    void search();

    void deal();

    void visit();

    void save();

    void load();

};


#endif //UNTOITPOURTOUS_AGENCY_H
