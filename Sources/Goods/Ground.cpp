//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../../Headers/Goods/Ground.h"
#include "../../Headers/Utils.h"

using namespace std;


Ground::Ground(double price, const string &address, double area, Seller *sellerRef,
               bool buildable) : Good(price, address, area, sellerRef), buildable(buildable) {}

Ground::Ground(Seller *sellerRef) : Good(sellerRef) {
    cout << "Peut-on construire sur le terrain ?\n";
    buildable = Utils::yesOrNo();
}
