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
        cout << "Bienvenue dans l'agence, les données ont été chargées, que voulez vous faire ?" << endl;
        cout << "\t-1. Ajouter un bien\n";
        cout << "\t-2. Ajouter un vendeur\n";
        cout << "\t-3. Ajouter un acheteur\n";
        cout << "\t-----------------------\n";
        cout << "\t-4. Rechercher un bien (Pour le visiter ou faire une proposition de vente)\n";
        cout << "\t-5. Faire une vente\n";
        cout << "\t-----------------------\n";
        cout << "\t-6. Sauvegarder l'agence\n";
        cout << "\t-7. Recharger l'agence\n";
        cout << "\t------------------------\n";
        cout << "\t-0. Quitter le programme\n";

        int input;
        cin >> input;
        cin.ignore();
        switch (input) {
            case 1: //Ajouter un bien
                unToitPourTous.addGood();
                break;
            case 2: //Ajouter un vendeur
                unToitPourTous.getSellerRef();
                break;
            case 3: // Ajouter un acheteur
                unToitPourTous.addBuyer();
                break;
            case 4: // Rechercher un bien
                unToitPourTous.search();
                break;
            case 5: // Faire une vente
//                unToitPourTous.sell();
                break;
            case 6: // Sauvegarder les biens
                unToitPourTous.save();
                break;
            case 7: // Charger les biens à partir d'un fichier
                unToitPourTous.load();
                break;
            case 0: // Quitter le programme
                programme = false;
                cout << "Fermeture du programme\n";
                break;
            default:
                cout << "Votre entrée est invalide\n";
                cout << "Merci d'entrée une entier compris entre 0 et 7\n";
                break;
        }
    }

    system("pause");
    return 0;
}
