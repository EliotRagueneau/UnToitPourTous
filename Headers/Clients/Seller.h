//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_SELLERS_H
#define UNTOITPOURTOUS_SELLERS_H


#include "Client.h"
#include <list>
#include <memory>

class Good;

class Seller : public Client {
private:
    std::list<std::shared_ptr<Good> > sellingGoodsList;

public:
    void addGood(const std::shared_ptr<Good>& good);

    Seller(const std::string &name, const std::string &address);

    Seller();

    virtual ~Seller();
};


#endif //UNTOITPOURTOUS_SELLERS_H
