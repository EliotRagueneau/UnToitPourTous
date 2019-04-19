#include <iostream>
#include <memory>
#include <limits>
#include <fstream>
#include <algorithm>
#include <vector>
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
#include "Utils.h"

using namespace std;

Agency::Agency() {
    load();
}

Agency::~Agency() {
    save();
    goods.clear();
    buyers.clear();
    sellers.clear();
}

shared_ptr<Good> Agency::addGood() {
    cout << "Vous allez rajouter un nouveau bien.\n";
    std::shared_ptr<Seller> seller = getSeller();
    string sellerName = seller->getName();

    shared_ptr<Good> toAdd;

    switch (Utils::selectType()) {
        case 1:
            toAdd = shared_ptr<Good>(new House(seller));
            break;
        case 2:
            toAdd = shared_ptr<Good>(new Flat(seller));
            break;
        case 3:
            toAdd = shared_ptr<Good>(new Ground(seller));
            break;
        case 4:
            toAdd = shared_ptr<Good>(new Professional(seller));
            break;

        default:
            cout << "Mauvaise entrée\n";
            addGood();
            break;
    }
    goods.push_back(toAdd);
    sellers[sellerName]->addGood(toAdd);
    toAdd->show();
    cout << "Bien ajouté\n\n";
    return toAdd;
}

shared_ptr<Seller> Agency::getSeller() {
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

shared_ptr<Buyer> Agency::addBuyer() {
    shared_ptr<Buyer> newBuyer;
    newBuyer = make_shared<Buyer>();
    buyers[newBuyer->getName()] = newBuyer;
    return newBuyer;
}

void Agency::reSell() {
    cout << "Comment voulez-vous choisir le bien à remettre en vente ?" << endl;
    cout << "\t-1. Par l'adresse du bien" << endl;
    cout << "\t-2. Par navigation et filtration parmi les biens vendus" << endl;
    shared_ptr<Good> good;
    switch (Utils::getInt()) {
        case 1:
            good = getGoodByAddress();
            good->setSold(false);
            cout << "Quelle est le prix de mise en vente?\n";
            good->setPrice(Utils::getDouble());
            break;
        case 2:
            reSell(filterSold(getGoods()));
            break;
        default:
            break;
    }
}

void Agency::search() {
    auto goodsList = getGoods();
    search(filterToSell(goodsList));
}

void Agency::visit() {
    shared_ptr<Good> good = getGoodByAddress();
    visit(good);
}

void Agency::addProposal() {
    shared_ptr<Good> good;
    while (good == nullptr) {
        cout << "Détermination du bien à laquelle l'on veut faire une proposition:\n";
        good = getGoodByAddress();
        if (good == nullptr) {
            cout << "Voulez vous abandonner la proposition d'achat ?" << endl;
            if (Utils::yesOrNo()) {
                return;
            }
        }
    }
    addProposal(good);
}

void Agency::sell() {
    sell(getGoodByAddress());
}


void Agency::show() const {
    for (const auto &good : goods) {
        if (!good->isSold()) {
            good->show();
            cout << "======================\n";
        }
    }
}

void Agency::showBuyers() const {
    cout << "Les acheteurs potentiels sont :" << endl;
    for (const auto &buyerPair : buyers) {
        buyerPair.second->show();
        cout << "- - - - - - - - - - - - - " << endl;
    }
}


void Agency::showSellers() const {
    cout << "Les vendeurs sont :" << endl;
    for (const auto &sellerPair : sellers) {
        sellerPair.second->show();
        cout << "- - - - - - - - - - - - - " << endl;
    }
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
            buyer.second->save(buyersFile);
            buyersFile << endl;
        }
        buyersFile.close();
    }
}


void Agency::load() {
    goods.clear();
    buyers.clear();
    sellers.clear();

    // Sellers loading
    string buffer, name, address;
    ifstream sellerFile("../Data/vendeurs.txt");
    if (sellerFile.is_open()) {
        while (getline(sellerFile, name)) {
            getline(sellerFile, address);
            sellers[name] = make_shared<Seller>(name, address);
            getline(sellerFile, buffer); // Empty line between Sellers
        }
        sellerFile.close();
    }

    // Buyers name + address Loading
    ifstream buyerFile("../Data/acheteurs.txt");
    if (buyerFile.is_open()) {
        while (getline(buyerFile, name)) {
            getline(buyerFile, address);
            while (buffer != "</VisitedGoods>") {
                getline(buyerFile, buffer);
            }
            buyers[name] = make_shared<Buyer>(name, address);
            getline(buyerFile, buffer);
        }
        buyerFile.close();
    }

    // Goods loading
    string goodType, goodAddress, goodSellerName;

    double goodPrice, goodArea, proposalAmount, proShowcaseSize;

    bool goodSold, resiGarage, houseGarden, houseSwim, flatCave, flatBalcony, groundBuildable, proStoreRoom;

    int resiNbRooms, flatFloor, flatNbBuildingFlats;

    list<pair<shared_ptr<Buyer>, double>> proposals; // List of propositions received for a specific good

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
            getline(goodsFile, buffer); // <Propositions>
            getline(goodsFile, buffer); // name OR </Propositions>
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
                            new House(goodPrice, goodAddress, goodArea, getSellerByName(goodSellerName), goodSold,
                                      resiNbRooms,
                                      resiGarage, houseGarden, houseSwim));
                } else {
                    goodsFile >> flatFloor;
                    goodsFile >> flatCave;
                    goodsFile >> flatBalcony;
                    goodsFile >> flatNbBuildingFlats;
                    toAdd = shared_ptr<Good>(
                            new Flat(goodPrice, goodAddress, goodArea, getSellerByName(goodSellerName), goodSold,
                                     resiNbRooms,
                                     resiGarage, flatFloor, flatCave, flatBalcony, flatNbBuildingFlats));
                }
            } else if (goodType == "Terrain") {
                goodsFile >> groundBuildable;
                toAdd = shared_ptr<Good>(
                        new Ground(goodPrice, goodAddress, goodArea, getSellerByName(goodSellerName),
                                   goodSold, groundBuildable));
            } else if (goodType == "Local") {
                goodsFile >> proShowcaseSize;
                goodsFile >> proStoreRoom;
                toAdd = shared_ptr<Good>(
                        new Professional(goodPrice, goodAddress, goodArea, getSellerByName(goodSellerName), goodSold,
                                         proShowcaseSize, proStoreRoom));
            }


            for (const auto &proposal: proposals) {
                toAdd->addProposal(proposal.first, proposal.second);
            }
            proposals.clear();

            goods.push_back(toAdd);
            sellers[goodSellerName]->addGood(toAdd);
            goodsFile.ignore();
            getline(goodsFile, buffer); // Empty line between Goods
        }
        goodsFile.close();
    }
    // Buyers visited Goods loading

    buyerFile.open("../Data/acheteurs.txt");
    if (buyerFile.is_open()) {
        while (getline(buyerFile, name)) {
            getline(buyerFile, address);
            getline(buyerFile, buffer); // <VisitedGoods>
            getline(buyerFile, buffer); // goodAddress or </VisitedGoods>
            while (buffer != "</VisitedGoods>") {
                goodAddress = buffer;
                buyerFile >> goodPrice;
                buyerFile >> goodArea;
                buyerFile.ignore();
                getline(buyerFile, goodSellerName);
                buyers[name]->visit(getGood(goodPrice, goodArea, goodAddress, goodSellerName));
                getline(buyerFile, buffer);
            }
            getline(buyerFile, buffer); // Empty line between buyers
        }
        buyerFile.close();
    }
}

// Private methods


void Agency::reSell(const list<shared_ptr<Good>> &soldGoods) {
    cout << "Voici les biens" << endl;
    show(soldGoods);
    cout << "Que souhaitez vous faire ?" << endl;
    cout << "\t-1. Affiner la recherche" << endl;
    cout << "\t-2. Remettre un bien sur le marché" << endl;
    cout << "\t-0. Quitter la recherche" << endl;

    shared_ptr<Good> good;
    switch (Utils::getInt()) {
        case 1:
            filterMenu(&Agency::reSell, soldGoods);
            break;
        case 2:
            good = getGoodByID(soldGoods);
            good->setSold(false);
            cout << "Quelle est le prix de mise en vente?\n";
            good->setPrice(Utils::getDouble());
            break;
        case 0:
            break;
        default:
            cout << "Vous n'avez pas donnée une entrée valide." << endl;
            cout << "Voulez-vous continuer la remise en vente ?." << endl;
            if (Utils::yesOrNo()) {
                reSell(soldGoods);
            }
    }
}

void Agency::show(const list<shared_ptr<Good>> &goodsList) {
    for (const auto &good : goodsList) {
        good->show();
        cout << "======================\n";
    }
}


void Agency::search(const list<shared_ptr<Good>> &goodsList) {
    cout << "Voici les biens" << endl;
    show(goodsList);
    cout << "Que souhaitez vous faire ?" << endl;
    cout << "\t-1. Affiner la recherche" << endl;
    cout << "\t-2. Visiter un bien" << endl;
    cout << "\t-3. Faire une proposition de vente" << endl;
    cout << "\t-4. Accepter une proposition de vente" << endl;
    cout << "\t-0. Quitter la recherche" << endl;

    shared_ptr<Buyer> buyer;
    shared_ptr<Seller> seller;
    shared_ptr<Good> good;
    switch (Utils::getInt()) {
        case 1:
            filterMenu(&Agency::search, goodsList);
            break;
        case 2: // Visite
            good = getGoodByID(goodsList);
            visit(good);
            break;
        case 3: // Proposer une offre
            good = getGoodByID(goodsList);
            addProposal(good);
            break;
        case 4: // Vente d'un bien
            good = getGoodByID(goodsList);
            sell(good);
            break;
        case 0: // Quitter navigation
            break;
        default:
            cout << "Vous n'avez pas sélectionner de choix valide." << endl;
            cout << "Voulez vous quitter la navigation ?" << endl;
            if (Utils::yesOrNo()) {
                break;
            } else {
                search(goodsList);
            }
    }
}

void Agency::visit(const shared_ptr<Good> &good) {
    shared_ptr<Buyer> buyer = getBuyerByName();
    buyer->visit(good);
}

void Agency::addProposal(const shared_ptr<Good> &good) {
    shared_ptr<Buyer> buyer;
    while (buyer == nullptr) {
        cout << "Détermination de l'acheteur qui propose une offre :\n";
        buyer = Agency::getBuyerByName();
        if (buyer == nullptr) {
            cout << "Voulez vous abandonner la proposition d'achat ?" << endl;
            if (Utils::yesOrNo()) {
                return;
            }
        }
    }

    cout << "Quel est le prix proposé par " << buyer->getName() << "?" << endl;
    good->addProposal(buyer, Utils::getDouble());

    cout << "Proposition enregistée\n";
    cout << "Les propositions pour ce bien sont :\n";
    good->showProposals();
}

void Agency::sell(const std::shared_ptr<Good> &good) {
    good->show();
    bool goodSold = false;
    while (!goodSold) {
        cout << "Les propositions pour ce bien sont :" << endl;
        auto proposals = good->getProposalsMap();
        int counter = 1;

        vector<shared_ptr<Buyer>> proposers;
        for (const auto &pair: proposals) {
            auto proposer = pair.first.lock();
            if (proposer) {
                cout << "\t-" << counter << " : " << proposer->getName() << " : " << pair.second << " €" << endl;
                proposers.push_back(proposer);
                counter++;
            }
        }
        cout << "Laquelle voulez vous accepter ?" << endl;
        int choice = Utils::getInt();
        if (choice != 0 && choice <= counter) {
            auto buyer = proposers[choice - 1]; // Select the new owner
            good->setSold(true); // The good is sold
            good->cleanProposals(); // The proposals are not valid anymore
            sellers[good->getSellerName()]->delGood(good); // Seller isn't anymore the owner of the good
            auto newSeller = buyer->toSeller(); // New owner is a future seller
            good->setSeller(newSeller); // Indicates the new owner of the good
            sellers[newSeller->getName()] = newSeller; // Add the new owner to sellers
            goodSold = true;
        } else {
            cout << "La proposition n°" << choice << " n'éxiste pas." << endl;
            cout << "Voulez vous stopper la transaction ?" << endl;
            if (Utils::yesOrNo()) {
                return;
            }
        }
    }
}

std::list<std::shared_ptr<Good>> Agency::getGoods() const {
    return list<shared_ptr<Good>>(goods);
}

std::shared_ptr<Good> Agency::getGoodByID(const std::list<std::shared_ptr<Good>> &goodsList) {
    cout << "Quel est le numéro du bien que vous voulez sélectionner ?" << endl;
    int id = Utils::getInt();
    for (auto good : goodsList) {
        if (good->getId() == id) {
            return good;
        }
    }

    cout << "Le numéro que vous avez fournis n'est pas disponible dans la liste que nous vous avons présenter." << endl;
    return getGoodByID(goodsList);
}

shared_ptr<Good> Agency::getGoodByAddress() {
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

std::shared_ptr<Good>
Agency::getGood(double price, double area, const std::string &address, const std::string &sellerName) {
    for (auto goodPtr: goods) {
        if (goodPtr->getPrice() == price
            && goodPtr->getArea() == area
            && goodPtr->getAddress() == address
            && goodPtr->getSellerName() == sellerName) {
            return goodPtr;
        }
    }
    return nullptr;
}

shared_ptr<Seller> Agency::getSellerByName(const std::string &sellerName) {
    return sellers.find(sellerName)->second;
}

shared_ptr<Buyer> Agency::getBuyerByName() {
    cout << "Quel est le nom de l'acheteur?\n";
    string buyerName;
    getline(cin, buyerName);
    auto foundBuyer = buyers.find(buyerName);

    if (foundBuyer == buyers.end()) {
        cout << "L'acheteur n'est pas enregistré dans l'agence\n";
        cout << "Voulez-vous ajouter cette acheteur?\n";
        if (Utils::yesOrNo()) {
            cout << "Quelle est l'adresse de " << buyerName << " ?" << endl;
            string address;
            getline(cin, address);
            buyers[buyerName] = make_shared<Buyer>(buyerName, address);
            return buyers[buyerName];
        } else {
            return nullptr;
        }
    } else {
        return foundBuyer->second;
    }
}

// Filters

void
Agency::filterMenu(void (Agency::*pmemfn)(const list<shared_ptr<Good>> &), const list<shared_ptr<Good>> &goodsList) {
    cout << "Vous voulez filtrer par :" << endl;
    cout << "\t-1. Prix" << endl;
    cout << "\t-2. Surface" << endl;
    cout << "\t-3. Type" << endl;
    switch (Utils::getInt()) {
        case 1: // Prix
            cout << "Vous voulez fixer le prix :" << endl;
            if (Utils::minOrMax()) {
                cout << "Quelle est le prix maximum ?" << endl;
                (this->*pmemfn)(filterLowerPrice(Utils::getDouble(), goodsList));
            } else {
                cout << "Quelle est le prix minimum ?" << endl;
                (this->*pmemfn)(filterGreaterPrice(Utils::getDouble(), goodsList));
            }
            break;
        case 2: // Surface
            cout << "Vous voulez fixer la surface :" << endl;
            if (Utils::minOrMax()) {
                cout << "Quelle est la surface maximum ?" << endl;
                (this->*pmemfn)(filterLowerArea(Utils::getDouble(), goodsList));
            } else {
                cout << "Quelle est la surface minimum ?" << endl;
                (this->*pmemfn)(filterGreaterArea(Utils::getDouble(), goodsList));
            }
            break;
        case 3: // Type
            (this->*pmemfn)(filterType(goodsList));
            break;
        default:
            cout << "Vous n'avez pas sélectionner de filtre valide." << endl;
            (this->*pmemfn)(goodsList);
            break;
    }
}

std::list<std::shared_ptr<Good>> Agency::filterToSell(std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
        return !val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>> Agency::filterSold(std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
        return val->isSold();
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterGreaterPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [priceThreshold](auto val) {
        return val->getPrice() >= priceThreshold;
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterLowerPrice(double priceThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [priceThreshold](auto val) {
        return val->getPrice() <= priceThreshold;
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterGreaterArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [areaThreshold](auto val) {
        return val->getArea() >= areaThreshold;
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>>
Agency::filterLowerArea(double areaThreshold, std::list<std::shared_ptr<Good>> goodsList) {
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [areaThreshold](auto val) {
        return val->getArea() <= areaThreshold;
    });
    return filteredGoodsList;
}

std::list<std::shared_ptr<Good>> Agency::filterType(std::list<std::shared_ptr<Good>> goodsList) {
    int goodKind = Utils::selectType();
    std::list<std::shared_ptr<Good>> filteredGoodsList;
    switch (goodKind) {
        case 1:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Maison";
            });
            break;
        case 2:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Appartement";
            });
            break;
        case 3:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Terrain";
            });
            break;
        case 4:
            copy_if(goodsList.begin(), goodsList.end(), back_inserter(filteredGoodsList), [](auto val) {
                return val->getType() == "Local";
            });
            break;
        default:
            cout << "Mauvaise entrée\n";
            goodsList = filterType(goodsList);
            break;
    }
    return filteredGoodsList;
}