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
    std::weak_ptr<Seller> sellerRef;
    int id;
    bool sold = false;
    std::map<std::weak_ptr<Buyer>, double, std::owner_less<std::weak_ptr<Buyer>>> proposalsMap;

public:
    Good(double price, std::string address, double area, const std::shared_ptr<Seller>& sellerRef, bool sold);

    explicit Good(const std::shared_ptr<Seller>& sellerRef);

    Good(const Good& src);

    std::string getSellerName() const;

    std::string getAddress() const;

    bool isSold() const;

    virtual void show() const;

	void addProposal(const std::shared_ptr<Buyer> &ptrBuyer, double amount);

    double getPrice() const;

    double getArea() const;

    virtual void save(std::ofstream &file) const;

    virtual void simpleSave(std::ofstream &file) const;

    virtual ~Good();

	void showProposals();

	void printID() const;

	virtual std::string getType() const = 0;

	void setSold(bool status);

    int getId() const;

	void cleanProposals();

    const std::map<std::weak_ptr<Buyer>, double, std::owner_less<std::weak_ptr<Buyer>>> &getProposalsMap() const;

    void setSellerRef(const std::shared_ptr<Seller> &seller);

	void setPrice(const double &prix);
};


#endif //UNTOITPOURTOUS_GOODS_H
