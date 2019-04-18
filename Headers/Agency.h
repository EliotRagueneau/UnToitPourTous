//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_AGENCY_H
#define UNTOITPOURTOUS_AGENCY_H


#include <list>
#include <memory>
#include "Goods/Good.h"
#include "Goods/House.h"
#include "Goods/Flat.h"
#include "Goods/Ground.h"
#include "Goods/Professional.h"
#include "Clients/Seller.h"
#include "Clients/Buyer.h"

class Agency {
private:
    std::list<std::shared_ptr<Good>> goods;
    std::map<std::string, std::shared_ptr<Seller>> sellers;
    std::map<std::string, std::shared_ptr<Buyer>> buyers;

    static std::shared_ptr<Good> getGoodByID(const std::list<std::shared_ptr<Good>> &goodsList);


    std::shared_ptr<Seller> getSellerRef(const std::string &sellerName);

    static void show(const std::list<std::shared_ptr<Good>> &goodsList);

    std::shared_ptr<Good>
    getGood(double price, double area, const std::string &address, const std::string &sellerName);

    static std::list<std::shared_ptr<Good>>
    filterGreaterPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterLowerPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterGreaterArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterLowerArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>> filterType(std::list<std::shared_ptr<Good>> goodsList);

    void search(const std::list<std::shared_ptr<Good>> &goodsList);

public:

    Agency();

    std::list<std::shared_ptr<Good>> getGoods() const;

    std::shared_ptr<Buyer> findBuyer();

    std::shared_ptr<Seller> findSeller();

    std::shared_ptr<Good> findGood();

    std::shared_ptr<Good> addGood();

    void show() const;

    std::shared_ptr<Buyer> addBuyer();

    void search();

    void visit();

    void save();

    void load();

	void sell();

    void addProposal();

	std::shared_ptr<Seller> getSellerRef();

	std::shared_ptr<Seller> addSellerFromBuyer(const std::shared_ptr<Buyer> &seller);

    virtual ~Agency();

	void reSell();
};


#endif //UNTOITPOURTOUS_AGENCY_H
