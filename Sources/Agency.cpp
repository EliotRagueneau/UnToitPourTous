#include <memory>

//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <limits>
#include <fstream>
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
    Seller sellerRef = getSellerRef();
    string sellerName = sellerRef.getName();

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
            break;
    }
    goods.push_back(toAdd);
    sellers[sellerName]->addGood(toAdd);
    toAdd->show();
    cout << "Bien ajouté\n\n";
}

Seller &Agency::getSellerRef() {
    cout << "Quel est le nom du vendeur ?\n";

    string sellerName;
    getline(cin, sellerName);

    if (sellers.count(sellerName) == 0) {
        cout << "Quel est l'adresse du vendeur ?\n";
        string sellerAddress;
        getline(cin, sellerAddress);
        sellers[sellerName] = make_shared<Seller>(sellerName, sellerAddress);
    }
    return *sellers.find(sellerName)->second;
}

void Agency::show() const {
    for (const auto &good : goods) {
        good->show();
        cout << "======================\n";
    }
}

void Agency::addBuyer() {

}

void Agency::search() {

}

void Agency::deal() {

}

void Agency::visit() {

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
    string sellerName;
    string sellerAddress;
    ifstream sellerFile("../Data/vendeurs.txt");
    if (sellerFile.is_open()) {
        while (getline(sellerFile, sellerName)) {
            getline(sellerFile, sellerAddress);
            sellers[sellerName] = make_shared<Seller>(sellerName, sellerAddress);
            sellerFile.ignore();
        }
        sellerFile.close();
    }

    string goodType;
    double goodPrice;
    double goodArea;
    string goodAddress;
    string goodSellerName;

    int resiNbRooms;
    bool resiGarage;


    ifstream goodsFile;
    goodsFile.open("../Data/biens.txt");
    if (goodsFile.is_open()) {
        while (getline(goodsFile, goodType)) {
            goodsFile >> goodPrice;
            goodsFile >> goodArea;
            goodsFile.ignore();
            getline(goodsFile, goodAddress);
            getline(goodsFile, goodSellerName);

            if (goodType == "Maison") {


            } else if (goodType == "Appartement") {

            } else if (goodType == "Terrain") {

            } else if (goodType == "Local") {

            }

        }
        goodsFile.close();
    }

}

shared_ptr<Buyer> Agency::findBuyer(){
// Vérification si l'acheteur existe, récupération de l adresse de l'objet ou proposition de création de l'objet buyer
    cout << "Quelle est le nom de l'acheteur\n?";
    string nomAcheteur;
    getline(cin, nomAcheteur); // vérifier que ca autorise les espaces si on décide d entré nom prénom 
    map<string, shared_ptr<Buyer>>::iterator trouve = buyers.find(nomAcheteur);

    if(trouve == buyers.end())
    {
        cout << "L'acheteur n'est pas enregistré dans l'agence\n";
        cout << "Voulez-vous ajouter cette acheteur?\n";
		bool rep = Utils::yesOrNo();
        if (rep == true){
			shared_ptr<Buyer> ptrNewBuyer;
			ptrNewBuyer = shared_ptr<Buyer>(new Buyer());
			buyers[ptrNewBuyer->getName()] = ptrNewBuyer;
        }
        else if(rep == false){
            return nullptr;
        }
    }
    else{
        return trouve->second; 
    }
}

shared_ptr<Seller> Agency::findSeller(){
    // Vérification si le vendeur existe, récupération de l adresse de l'objet ou proposition de création de l'objet seller
    cout << "Quelle est le nom de l'acheteur?\n";
    string nomVendeur;
    map<string, shared_ptr<Seller>>::iterator trouve = sellers.find(nomVendeur);

    if(trouve == sellers.end()){
        cout << "Le vendeur n'est pas enregistré dans l'agence\n";
        return nullptr;
    }
    else{
        return trouve->second; 
    }

}

shared_ptr<Good> Agency::findGood(){ //recherche d'un bien via son adresse
	cout << "Quelle est l'adresse du bien?\n";
	string adresse;
	getline(cin, adresse);
	list<shared_ptr<Good>>::iterator itGood = goods.begin();
	while (itGood != goods.end()) {
		if ((*itGood)->getAddress() == adresse) {
			return *itGood;
		}
		else {
			itGood++;
		}
	}
	cout << "L'adresse ne correspond à aucun bien\n";
	return nullptr;
}

/*1. trouver le bien
2. trouver l acheteur
3. demander le prix
4. ajouter la proposition d achat dans la map de proposition du bien*/
void Agency::addProposal(){ //mettre des possibilité de sortie de boucle meme si on en trouve pas d acheteur ou de bien

	shared_ptr<Good> ptrBien = nullptr;
	while (ptrBien == nullptr) {
		cout << "Souhaitez-vous rechercher un bien?\n";
		bool rep;
		rep = Utils::yesOrNo();
		if (rep == true) {
			ptrBien = Agency::findGood();
		}
		else if (rep == false) {
			cout << "Vous n'avez pas sélectionné de bien\n";
			break;
		}
	}

	if (ptrBien != nullptr) {
		shared_ptr<Buyer> ptrAcheteur = nullptr;
		while (ptrAcheteur == nullptr) {
			cout << "Souhaitez-vous rechercher un Acheteur?\n";
			bool rep;
			rep = Utils::yesOrNo();
			if (rep == true) {
				ptrAcheteur = Agency::findBuyer();
			}
			else if (rep == false) {
				cout << "Vous n'avez pas sélectionné de bien\n";
				break;
			}
		}

		if (ptrBien != nullptr) {
			cout << "Quel est le prix proposé par l'acheteur?\n";
			double prix;
			cin >> prix;
			cin.ignore();
			ptrBien->addProposal(ptrAcheteur, prix);
		}
	}

}

