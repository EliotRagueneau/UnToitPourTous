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
        cout << "\t-4. Rechercher un bien (Pour le visiter, faire une proposition de vente, ou en accepter une)\n";
        cout << "\t-----------------------\n";
        cout << "\t-5. Visiter un bien a partir de l'adresse du bien\n";
        cout << "\t-6. Proposer une offre a partir de l'adresse du bien\n";
        cout << "\t-7. Faire une vente a partir de l'adresse du bien\n";
        cout << "\t-----------------------\n";
        cout << "\t-8. Afficher les biens\n";
        cout << "\t-9. Afficher les vendeurs\n";
        cout << "\t-10. Afficher les acheteurs potentiels\n";
        cout << "\t-----------------------\n";
        cout << "\t-11. Sauvegarder l'agence\n";
        cout << "\t-12. Recharger l'agence\n";
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
            case 5: // Visiter via adresse
                unToitPourTous.visit();
                break;
            case 6: // Proposition d'offre via adresse
                unToitPourTous.addProposal();
                break;
            case 7: // Faire une vente via adresse
                unToitPourTous.sell();
                break;



            case 8: // Afficher les biens
                unToitPourTous.show();
                break;
            case 9: // Afficher les vendeurs
                unToitPourTous.showSellers();
                break;
            case 10: // Afficher les acheteurs potentiels
                unToitPourTous.showBuyers();
                break;

            case 11: // Sauvegarder les biens
                unToitPourTous.save();
                break;
            case 12: // Charger les biens à partir d'un fichier
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
    return 0;
}
