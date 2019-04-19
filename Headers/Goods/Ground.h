//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_GROUNDS_H
#define UNTOITPOURTOUS_GROUNDS_H


#include "Good.h"

class Ground : public Good {
private:
    bool buildable;
public:
    Ground(double price, const std::string &address, double area, const std::shared_ptr<Seller> &seller, bool sold,
           bool buildable);

    explicit Ground(const std::shared_ptr<Seller> &seller);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

    virtual std::string getType() const;

};


#endif //UNTOITPOURTOUS_GROUNDS_H
