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

    Residential(double price, const std::string &address, double area, const std::shared_ptr<Seller>& seller, bool sold,
                int nbRooms, bool garage);

    explicit Residential(const std::shared_ptr<Seller>& seller);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

};


#endif //UNTOITPOURTOUS_RESIDENTIAL_H
