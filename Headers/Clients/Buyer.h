//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_BUYERS_H
#define UNTOITPOURTOUS_BUYERS_H


#include "Client.h"
#include <list>
//#include "../Goods/Good.h"
class Good;

class Buyer : public Client {
private:
    std::list<Good*> visitList{};

};


#endif //UNTOITPOURTOUS_BUYERS_H
