//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_RESIDENTIAL_H
#define UNTOITPOURTOUS_RESIDENTIAL_H


#include "Good.h"

class Residential : public Good {
protected:
    int nbRooms;
    bool garage;
public:

    Residential(double price, const std::string &address, double area, Seller *sellerRef, int nbRooms, bool garage);

    explicit Residential(Seller *sellerRef);

    virtual void show() const;
};


#endif //UNTOITPOURTOUS_RESIDENTIAL_H
