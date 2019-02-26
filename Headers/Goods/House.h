//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_HOUSES_H
#define UNTOITPOURTOUS_HOUSES_H


#include "Residential.h"
class House : public Residential {
private:
    bool garden;
    bool swimmingPool;
public:
    explicit House(Seller *sellerRef);

    House(double price, const std::string &address, double area, Seller *sellerRef, int nbRooms, bool garage,
          bool garden, bool swimmingPool);

    virtual void show() const;
};


#endif //UNTOITPOURTOUS_HOUSES_H
