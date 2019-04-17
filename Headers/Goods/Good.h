//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_GOODS_H
#define UNTOITPOURTOUS_GOODS_H


#include <string>
#include <map>
#include "../Clients/Seller.h"
#include "../Clients/Buyer.h"

class Good {
private:
    static int nbInstance;
protected:
    double price;
    std::string address;
    double area;
    Seller& sellerRef;
    int id;
    bool sold = false;
    std::map<Buyer, double> proposalsMap;

public:
    Seller &getSeller() const;

    Good(double price, const std::string &address, double area, Seller &sellerRef);

    explicit Good(Seller & sellerRef);

    Good(const Good& src);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;
};


#endif //UNTOITPOURTOUS_GOODS_H
