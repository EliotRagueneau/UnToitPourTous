//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include <memory>
#include "Headers/Agency.h"
#include "Headers/Utils.h"
#include "Headers/Clients/Buyer.h"
#include "Headers/Clients/Client.h"
#include "Headers/Clients/Seller.h"
#include "Headers/Goods/Flat.h"
#include "Headers/Goods/Good.h"
#include "Headers/Goods/Ground.h"
#include "Headers/Goods/House.h"
#include "Headers/Goods/Professional.h"
#include "Headers/Goods/Residential.h"

using namespace std;

int main() {

	bool programme = true;
	Agency unToitPourTous = Agency();

	while (programme) {
		Utils::menuPrincipal();
		int input;
		cin >> input;
		cin.ignore();
		switch (input)
		{
		case 1: //Ajouter un bien
			unToitPourTous.addGood();
			break;
		case 2: //Ajouter un vendeur
			unToitPourTous.addSeller();
			break;
		case 3: // Ajouter un acheteur
			unToitPourTous.addBuyer();
			break;
		case 4: // Faire une visite
			unToitPourTous.addVisit();
			break;
		case 5: // Ajouter une proposition d'achat
			unToitPourTous.addProposal();
			break;
		case 6: // Faire une vente
			unToitPourTous.sell();
			break;
		case 7: //  Faire une recherche de bien
			break;
		case 8: // Sauvegarder les biens
			unToitPourTous.save();
			break;
		case 9: // Charger les biens à partir d'un fichier
			unToitPourTous.load();
			break;
		case 0: // Quitter le programme
			programme = false;
			cout << "Fermeture du programme\n";
			break;
		default:
			cout << "Votre entrée est invalide\n";
			cout << "Merci d'entrée une entier compris entre 0 et 9\n";
			break;
		}
	}

	system("pause");
	return 0;
}
