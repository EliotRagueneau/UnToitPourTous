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
    explicit Ground(std::shared_ptr<Seller> sellerRef);

    Ground(double price, const std::string &address, double area, std::shared_ptr<Seller> sellerRef, bool sold,
           bool buildable);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

    virtual std::string getType() const;

};


#endif //UNTOITPOURTOUS_GROUNDS_H
