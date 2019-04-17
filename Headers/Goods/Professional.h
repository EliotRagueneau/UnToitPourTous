//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_PROFESSIONAL_H
#define UNTOITPOURTOUS_PROFESSIONAL_H


#include "Good.h"
#include <fstream>


class Professional : public Good{
private:
    double showcaseSize;
    bool storeRoom;

public:
    Professional(double price, const std::string &address, double area, Seller &sellerRef, bool sold,
                 double showcaseSize, bool storeRoom);

    explicit Professional(Seller &sellerRef);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;
};


#endif //UNTOITPOURTOUS_PROFESSIONAL_H
