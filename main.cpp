//
// Created by eliot on 25/02/19.
//

#include <memory>
#include "Headers/Agency.h"

using namespace std;



int main() {
    Agency unToitPourTous;

    unToitPourTous.load();

    for (const auto& goodsPtr: Agency::filterGreaterArea(50, unToitPourTous.getGoods())) {
        goodsPtr->show();
    }

    unToitPourTous.show();
}