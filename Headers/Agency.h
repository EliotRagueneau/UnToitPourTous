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
    std::list<std::shared_ptr<Good>> goods;
    std::map<std::string, Seller *> sellers;
    std::map<std::string, Buyer *> buyers;
public:

    Seller *getSellerRef();

    void addGood();

    void show() const;

    void addBuyer();

    void search();

    void deal();

    void visit();

    void save();

    void load();

};


#endif //UNTOITPOURTOUS_AGENCY_H
