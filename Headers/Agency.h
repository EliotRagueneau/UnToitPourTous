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
#include "Clients/Seller.h"
#include "Clients/Buyer.h"

class Agency {
private:
    std::list<std::shared_ptr<Good>> goods;
    std::map<std::string, std::shared_ptr<Seller>> sellers;
    std::map<std::string, std::shared_ptr<Buyer>> buyers;
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

    void addProposal();

	shared_ptr<Buyer> findBuyer();

	shared_ptr<Seller> findSeller();

	shared_ptr<Good> findGood();
};


#endif //UNTOITPOURTOUS_AGENCY_H
