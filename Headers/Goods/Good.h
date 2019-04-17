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
    std::map<std::shared_ptr<Buyer>, double> proposalsMap;

public:
    Seller &getSeller() const;

    Good(double price, const std::string &address, double area, Seller &sellerRef, bool sold);

    std::string getAddress() const;

    explicit Good(Seller & sellerRef);

    Good(const Good& src);

    virtual void show() const;

	void addProposal(const std::shared_ptr<Buyer> &ptrBuyer, double price);

    double getPrice() const;

    double getArea() const;

    virtual void save(std::ofstream &file) const;

    virtual void simpleSave(std::ofstream &file) const;

    virtual ~Good();
};


#endif //UNTOITPOURTOUS_GOODS_H
