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
    std::weak_ptr<Seller> seller;
    int id;
    bool sold = false;
    std::map<std::weak_ptr<Buyer>, double, std::owner_less<std::weak_ptr<Buyer>>> proposalsMap;

public:
    Good(double price, std::string address, double area, const std::shared_ptr<Seller>& sellerRef, bool sold);

    explicit Good(const std::shared_ptr<Seller>& sellerRef);

    Good(const Good& src);

    virtual ~Good();

    void addProposal(const std::shared_ptr<Buyer> &ptrBuyer, double amount);

    void showID() const;

    virtual void show() const;

    void showProposals();

    virtual void save(std::ofstream &file) const;

    virtual void simpleSave(std::ofstream &file) const;

    virtual std::string getType() const = 0;

    double getPrice() const;

    std::string getAddress() const;

    double getArea() const;

    std::string getSellerName() const;

    int getId() const;

    bool isSold() const;

    const std::map<std::weak_ptr<Buyer>, double, std::owner_less<std::weak_ptr<Buyer>>> &getProposalsMap() const;

    void setPrice(const double &prix);

    void setSeller(const std::shared_ptr<Seller> &newSeller);

    void setSold(bool status);

    void cleanProposals();
};


#endif //UNTOITPOURTOUS_GOODS_H
