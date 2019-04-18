// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_UTILS_H
#define UNTOITPOURTOUS_UTILS_H


#include <list>
#include <memory>
#include "Goods/Good.h"
#include "Goods/House.h"
#include "Goods/Flat.h"
#include "Goods/Ground.h"
#include "Goods/Professional.h"
#include "Clients/Seller.h"
#include "Clients/Buyer.h"

class Utils {

public:
    static bool yesOrNo();

    static bool minOrMax();

    static int selectType();

    static double getDouble();

    static int getInt();
};


#endif //UNTOITPOURTOUS_UTILS_H
