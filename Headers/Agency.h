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

public:

    Agency();

    virtual ~Agency();

    std::shared_ptr<Good> addGood();

    std::shared_ptr<Seller> getSellerRef();

    std::shared_ptr<Buyer> addBuyer();

    void reSell();

    void search();

    void visit();

    void addProposal();

    void sell();

    void show() const;

    void showBuyers() const;

    void showSellers() const;

    void save();

    void load();

private:  // Private Methods
    void reSell(const std::list<std::shared_ptr<Good>>& soldGoods);

    static void show(const std::list<std::shared_ptr<Good>> &goodsList);

    void search(const std::list<std::shared_ptr<Good>> &goodsList);

    void visit(const std::shared_ptr<Good>& goodRef);

    void addProposal(const std::shared_ptr<Good>& goodRef);

    void sell(const std::shared_ptr<Good> &);

    std::list<std::shared_ptr<Good>> getGoods() const;

    static std::shared_ptr<Good> getGoodByID(const std::list<std::shared_ptr<Good>> &goodsList);

    std::shared_ptr<Good> getGoodByAddress();

    std::shared_ptr<Good>
    getGood(double price, double area, const std::string &address, const std::string &sellerName);

    std::shared_ptr<Seller> getSellerByName(const std::string &sellerName);

    std::shared_ptr<Buyer> getBuyerByName();

    // Filters

    static std::list<std::shared_ptr<Good>>
    filterSold(std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterToSell(std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterGreaterPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterLowerPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterGreaterArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>>
    filterLowerArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList);

    static std::list<std::shared_ptr<Good>> filterType(std::list<std::shared_ptr<Good>> goodsList);

};


#endif //UNTOITPOURTOUS_AGENCY_H
