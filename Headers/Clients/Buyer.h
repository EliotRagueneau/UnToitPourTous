//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_BUYERS_H
#define UNTOITPOURTOUS_BUYERS_H


#include "Client.h"
#include "Seller.h"
#include <list>
#include <memory>

//#include "../Goods/Good.h"
class Good;

class Buyer : public Client {
private:
    std::list<std::weak_ptr<Good>> visitList;
public:
    virtual ~Buyer();

    Buyer();

    Buyer(const std::string &name, const std::string &address);

    void save(std::ofstream& file) const;

    void visit(const std::shared_ptr<Good> &bien);

    std::shared_ptr<Seller> toSeller();
};

#endif //UNTOITPOURTOUS_BUYERS_H
