#include <memory>

//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <memory>
#include <limits>
#include <fstream>
#include <algorithm>
#include "../Headers/Agency.h"
#include "../Headers/Goods/Good.h"
#include "../Headers/Goods/House.h"
#include "../Headers/Goods/Flat.h"
#include "../Headers/Goods/Ground.h"
#include "../Headers/Goods/Professional.h"
#include "../Headers/Clients/Client.h"
#include "../Headers/Clients/Buyer.h"
#include "../Headers/Clients/Seller.h"
#include "../Headers/Utils.h"

using namespace std;

void Agency::addGood() {
    cout << "Vous allez rajouter un nouveau bien.\n";
    std::shared_ptr<Seller> sellerRef = getSellerRef();
    string sellerName = sellerRef->getName();

    cout << "Quel type de bien souhaitez vous rajouter ?\n";
    cout << "\t-1. Une maison\n";
    cout << "\t-2. Un appartement\n";
    cout << "\t-3. Un terrain\n";
    cout << "\t-4. Un local professionnel\n";


    int goodKind;
    cin >> goodKind;
    cin.ignore();
    shared_ptr<Good> toAdd;

    switch (goodKind) {
        case 1:
            toAdd = shared_ptr<Good>(new House(sellerRef));
            break;
        case 2:
            toAdd = shared_ptr<Good>(new Flat(sellerRef));
            break;
        case 3:
            toAdd = shared_ptr<Good>(new Ground(sellerRef));
            break;
        case 4:
            toAdd = shared_ptr<Good>(new Professional(sellerRef));
            break;

        default:
            cout << "Mauvaise entrée\n";
            addGood();
            return;
    }
    goods.push_back(toAdd);
    sellers[sellerName]->addGood(toAdd);
    toAdd->show();
    cout << "Bien ajouté\n\n";
}

shared_ptr<Seller> Agency::getSellerRef() {
    cout << "Quel est le nom du vendeur ?\n";

    string sellerName;
    getline(cin, sellerName);

    if (sellers.count(sellerName) == 0) {
        cout << "Quel est l'adresse du vendeur ?\n";
        string sellerAddress;
        getline(cin, sellerAddress);
        sellers[sellerName] = make_shared<Seller>(sellerName, sellerAddress);
    }
    return sellers.find(sellerName)->second;
}

shared_ptr<Seller> Agency::getSellerRef(const std::string &sellerName) {
    return sellers.find(sellerName)->second;
}

shared_ptr<Seller> Agency::addSellerFromBuyer(const shared_ptr<Buyer> &seller){
	shared_ptr<Seller> sellerRef = shared_ptr<Seller>(new Seller(seller->getName(), seller->getAddress());
	return sellerRef;
}

void Agency::show() const {
    for (const auto &good : goods) {
        if (!good->isSold()) {
            good->show();
            cout << "======================\n";
        }
    }
}

void Agency::addBuyer() {
	shared_ptr<Buyer> ptrNewBuyer;
	ptrNewBuyer = shared_ptr<Buyer>(new Buyer());
	buyers[ptrNewBuyer->getName()] = ptrNewBuyer;
}

void Agency::search() {

}

void Agency::deal() {

}

void Agency::visit() {
	std::shared_ptr<Buyer> buyerRef = Agency::findBuyer();
	std::shared_ptr<Good> goodRef = Agency::findGood();
	buyerRef->visit(goodRef);
}

void Agency::save() {
    ofstream goodsFile;
    goodsFile.open("../Data/biens.txt");
    if (goodsFile.is_open()) {
        for (const auto &good : goods) {
            good->save(goodsFile);
            goodsFile << endl;
        }
        goodsFile.close();
    }


    ofstream sellersFile;
    sellersFile.open("../Data/vendeurs.txt");
    if (sellersFile.is_open()) {
        for (const auto &seller : sellers) {
            seller.second->save(sellersFile);
            sellersFile << endl;
        }
        sellersFile.close();
    }

    ofstream buyersFile;
    buyersFile.open("../Data/acheteurs.txt");
    if (buyersFile.is_open()) {
        for (const auto &buyer : buyers) {
            buyer.second->save(sellersFile);
            buyersFile << endl;
        }
        buyersFile.close();
    }

}

void Agency::load() {
    string buffer;
    string name;
    string address;
    ifstream sellerFile("../Data/vendeurs.txt");
    if (sellerFile.is_open()) {
        while (getline(sellerFile, name)) {
            getline(sellerFile, address);
            sellers[name] = make_shared<Seller>(name, address);
            sellerFile.ignore();
        }
        sellerFile.close();
    }

    ifstream buyerFile("../Data/acheteurs.txt");
    if (buyerFile.is_open()) {
        while (getline(sellerFile, name)) {
            getline(sellerFile, address);
            while (buffer != "</VisitedGoods>") {
                getline(buyerFile, buffer);
            }
            buyers[name] = make_shared<Buyer>(name, address);
            sellerFile.ignore();
        }
        sellerFile.close();
    }


    string goodType;
    double goodPrice;
    double goodArea;
    string goodAddress;
    string goodSellerName;
    bool goodSold;
    double proposalAmount;

    int resiNbRooms;
    bool resiGarage;

    bool houseGarden;
    bool houseSwim;

    int flatFloor;
    bool flatCave;
    bool flatBalcony;
    int flatNbBuildingFlats;

    bool groundBuildable;

    double proShowcaseSize;
    bool proStoreRoom;

    list<pair<shared_ptr<Buyer>, double>> proposals;

    ifstream goodsFile("../Data/biens.txt");
    if (goodsFile.is_open()) {
        shared_ptr<Good> toAdd;
        while (getline(goodsFile, goodType)) {
            goodsFile >> goodPrice;
            goodsFile >> goodArea;
            goodsFile.ignore();
            getline(goodsFile, goodAddress);
            getline(goodsFile, goodSellerName);
            goodsFile >> goodSold;
            goodsFile.ignore();
            getline(goodsFile, buffer);
            getline(goodsFile, buffer);
            while (buffer != "</Propositions>") {
                name = buffer;
                goodsFile >> proposalAmount;
                goodsFile.ignore();
                proposals.emplace_back(buyers[name], proposalAmount);
                getline(goodsFile, buffer);
            }

            if (goodType == "Maison" || goodType == "Appartement") {
                goodsFile >> resiNbRooms;
                goodsFile >> resiGarage;

                if (goodType == "Maison") {
                    goodsFile >> houseGarden;
                    goodsFile >> houseSwim;
                    toAdd = shared_ptr<Good>(
                            new House(goodPrice, goodAddress, goodArea, getSellerRef(goodSellerName), goodSold,
                                      resiNbRooms,
                                      resiGarage, houseGarden, houseSwim));
                } else {
                    goodsFile >> flatFloor;
                    goodsFile >> flatCave;
                    goodsFile >> flatBalcony;
                    goodsFile >> flatNbBuildingFlats;
                    toAdd = shared_ptr<Good>(
                            new Flat(goodPrice, goodAddress, goodArea, getSellerRef(goodSellerName), goodSold,
                                     resiNbRooms,
                                     resiGarage, flatFloor, flatCave, flatBalcony, flatNbBuildingFlats));
                }

            } else if (goodType == "Terrain") {
                goodsFile >> groundBuildable;
                toAdd = shared_ptr<Good>(
                        new Ground(goodPrice, goodAddress, goodArea, getSellerRef(goodSellerName),
                                   goodSold, groundBuildable));

            } else if (goodType == "Local") {
                goodsFile >> proShowcaseSize;
                goodsFile >> proStoreRoom;
                toAdd = shared_ptr<Good>(
                        new Professional(goodPrice, goodAddress, goodArea, getSellerRef(goodSellerName), goodSold,
                                         proShowcaseSize, proStoreRoom));
            }
            for (const auto &proposal: proposals) {
                toAdd->addProposal(proposal.first, proposal.second);
            }

            goods.push_back(toAdd);
            sellers[goodSellerName]->addGood(toAdd);
            getline(goodsFile, buffer);
            getline(goodsFile, buffer);
        }
        goodsFile.close();
    }

    buyerFile.open("../Data/acheteurs.txt");
    if (buyerFile.is_open()) {
        while (getline(sellerFile, name)) {
            getline(sellerFile, address);

            getline(goodsFile, buffer);
            getline(goodsFile, buffer);
            while (buffer != "</VisitedGoods>") {
                goodAddress = buffer;
                goodsFile >> goodPrice;
                goodsFile >> goodArea;
                goodsFile.ignore();
                getline(goodsFile, goodSellerName);
                buyers[name]->visit(getGood(goodPrice, goodArea, goodAddress, goodSellerName));
                getline(goodsFile, buffer);
            }
            sellerFile.ignore();
        }
        sellerFile.close();
    }
}

void Agency::sell(){
	shared_ptr<Buyer> buyerRef = Agency::findBuyer();
	shared_ptr<Good> goodRef = Agency::findGood();
	shared_ptr<Seller> sellerRef = Agency::findSeller();
	goodRef->setSold(true);
	shared_ptr<Seller> newSellerRef = Agency::addSellerFromBuyer(buyerRef);



}


shared_ptr<Buyer> Agency::findBuyer() {
// Vérification si l'acheteur existe, récupération de l adresse de l'objet ou proposition de création de l'objet buyer
    cout << "Quel est le nom de l'acheteur?\n";
    string nomAcheteur;
    getline(cin, nomAcheteur); // vérifier que ca autorise les espaces si on décide d entré nom prénom 
    auto trouve = buyers.find(nomAcheteur);

    if (trouve == buyers.end()) {
        cout << "L'acheteur n'est pas enregistré dans l'agence\n";
        cout << "Voulez-vous ajouter cette acheteur?\n";
        if (Utils::yesOrNo()) {
            shared_ptr<Buyer> ptrNewBuyer;
            ptrNewBuyer = shared_ptr<Buyer>(new Buyer());
            buyers[ptrNewBuyer->getName()] = ptrNewBuyer;
            return ptrNewBuyer;
        } else {
            return nullptr;
        }
    } else {
        return trouve->second;
    }
}

std::shared_ptr<Good>
Agency::getGood(double price, double area, const std::string &address, const std::string &sellerName) {
    for (auto goodPtr: goods) {
        if (goodPtr->getPrice() == price
            && goodPtr->getArea() == area
            && goodPtr->getAddress() == address
            && goodPtr->getSeller()->getName() == sellerName) {
            return goodPtr;
        }
    }
    return nullptr;
}

/**
 * Vérification si le vendeur existe, récupération de l adresse de l'objet ou proposition de création de l'objet seller
 * @return
 */
shared_ptr<Seller> Agency::findSeller() {
    cout << "Quel est le nom de l'acheteur?\n";
    string nomVendeur;
    auto trouve = sellers.find(nomVendeur);

    if (trouve == sellers.end()) {
        cout << "Le vendeur n'est pas enregistré dans l'agence\n";
        return nullptr;
    } else {
        return trouve->second;
    }

}

/**
 * Recherche d'un bien via son adresse
 * @return
 */
shared_ptr<Good> Agency::findGood() {
    cout << "Quelle est l'adresse du bien?\n";
    string adresse;
    getline(cin, adresse);
    auto itGood = goods.begin();
    while (itGood != goods.end()) {
        if ((*itGood)->getAddress() == adresse) {
            return *itGood;
        } else {
            itGood++;
        }
    }
    cout << "L'adresse ne correspond à aucun bien\n";
    return nullptr;
}

/**
 * //mettre des possibilité de sortie de boucle meme si on en trouve pas d acheteur ou de bien
 * 1. trouver le bien
 * 2. trouver l acheteur
 * 3. demander le prix
 * 4. ajouter la proposition d achat dans la map de proposition du bien
 * */
void Agency::addProposal() {
    shared_ptr<Good> ptrBien = nullptr;
    while (ptrBien == nullptr) {
        cout << "Souhaitez-vous rechercher un bien?\n";
        if (Utils::yesOrNo()) {
            ptrBien = Agency::findGood();
        } else {
            cout << "Vous n'avez pas sélectionné de bien\n";
            break;
        }
    }

    if (ptrBien != nullptr) {
        shared_ptr<Buyer> ptrAcheteur = nullptr;
        while (ptrAcheteur == nullptr) {
            cout << "Souhaitez-vous rechercher un Acheteur?\n";
            if (Utils::yesOrNo()) {
                ptrAcheteur = Agency::findBuyer();
                cout << "Quel est le prix proposé par l'acheteur?\n";
                double prix;
                cin >> prix;
                cin.ignore();
                ptrBien->addProposal(ptrAcheteur, prix);
                cout << "Proposition enregistée\n"; // ajouter une methode show pour les propositions
                ptrBien->showProposals();
            } else {
                cout << "Vous n'avez pas sélectionné de bien\n";
                break;
            }
        }
    }
}

std::list<std::shared_ptr<Good>>
Agency::filterGreaterPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [priceThreshold](auto val) {
        return val->getPrice() >= priceThreshold && !val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterLowerPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [priceThreshold](auto val) {
        return val->getPrice() <= priceThreshold && !val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterGreaterArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [areaThreshold](auto val) {
        return val->getArea() >= areaThreshold && !val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterLowerArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [areaThreshold](auto val) {
        return val->getArea() <= areaThreshold && !val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>> Agency::filterType(std::list<std::shared_ptr<Good>> goodsList) {
    cout << "Quel type de bien souhaitez vous filtrer ?\n";
    cout << "\t-1. Une maison\n";
    cout << "\t-2. Un appartement\n";
    cout << "\t-3. Un terrain\n";
    cout << "\t-4. Un local professionnel\n";

    int goodKind;
    cin >> goodKind;
    cin.ignore();

    std::list<std::shared_ptr<Good>> filteredGoodsList;

    switch (goodKind) {
        case 1:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Maison" && !val->isSold();
            });
            break;
        case 2:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Appartement" && !val->isSold();
            });
            break;
        case 3:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Terrain" && !val->isSold();
            });
            break;
        case 4:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Local" && !val->isSold();
            });
            break;

        default:
            cout << "Mauvaise entrée\n";
            goodsList = filterType(goodsList);
            break;
    }

    return filteredGoodsList;
}


std::list<std::shared_ptr<Good>> Agency::getGoods() const {
    return list<shared_ptr<Good>>(goods);
}
