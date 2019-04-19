//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_PROFESSIONAL_H
#define UNTOITPOURTOUS_PROFESSIONAL_H


#include "Good.h"


class Professional : public Good{
private:
    double showcaseSize;
    bool storeRoom;

public:
    Professional(double price, const std::string &address, double area, const std::shared_ptr<Seller>& seller, bool sold,
                 double showcaseSize, bool storeRoom);

    explicit Professional(const std::shared_ptr<Seller>& sellerRef);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

    virtual std::string getType() const;
};


#endif //UNTOITPOURTOUS_PROFESSIONAL_H
