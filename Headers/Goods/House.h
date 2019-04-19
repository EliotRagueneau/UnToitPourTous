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
    House(double price, const std::string &address, double area, const std::shared_ptr<Seller> &seller, bool sold,
          int nbRooms, bool garage, bool garden, bool swimmingPool);

    explicit House(const std::shared_ptr<Seller> &seller);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

    virtual std::string getType() const;
};


#endif //UNTOITPOURTOUS_HOUSES_H
