#include <iostream>
#include "Utils.h"
#include "Agency.h"

using namespace std;

int main() {

    bool programme = true;
    Agency unToitPourTous = Agency();

    while (programme) {
        cout << "Bienvenue dans l'agence, les données ont été chargées, que voulez vous faire ?" << endl;
        cout << "\t-1. Ajouter un bien\n";
        cout << "\t-2. Ajouter un vendeur\n";
        cout << "\t-3. Ajouter un acheteur\n";
		cout << "\t-4. Remettre en vente un bien\n";
        cout << "\t-----------------------\n";
        cout << "\t-5. Rechercher un bien (Pour le visiter, faire une proposition de vente, ou en accepter une)\n";
        cout << "\t-----------------------\n";
        cout << "\t-6. Visiter un bien a partir de l'adresse du bien\n";
        cout << "\t-7. Proposer une offre a partir de l'adresse du bien\n";
        cout << "\t-8. Faire une vente a partir de l'adresse du bien\n";
        cout << "\t-----------------------\n";
        cout << "\t-9. Afficher les biens\n";
        cout << "\t-10. Afficher les vendeurs\n";
        cout << "\t-11. Afficher les acheteurs potentiels\n";
        cout << "\t-----------------------\n";
        cout << "\t-12. Sauvegarder l'agence\n";
        cout << "\t-13. Recharger l'agence\n";
        cout << "\t------------------------\n";
        cout << "\t-0. Quitter le programme\n";

        switch (Utils::getInt()) {
            case 1: //Ajouter un bien
                unToitPourTous.addGood();
                break;
            case 2: //Ajouter un vendeur
                unToitPourTous.getSeller();
                break;
            case 3: // Ajouter un acheteur
                unToitPourTous.addBuyer();
                break;
			case 4: // Remettre en vente un bien
				unToitPourTous.reSell();
				break;
            case 5: // Rechercher un bien
                unToitPourTous.search();
                break;
            case 6: // Visiter via adresse
                unToitPourTous.visit();
                break;
            case 7: // Proposition d'offre via adresse
                unToitPourTous.addProposal();
                break;
            case 8: // Faire une vente via adresse
                unToitPourTous.sell();
                break;
            case 9: // Afficher les biens
                unToitPourTous.show();
                break;
            case 10: // Afficher les vendeurs
                unToitPourTous.showSellers();
                break;
            case 11: // Afficher les acheteurs potentiels
                unToitPourTous.showBuyers();
                break;

            case 12: // Sauvegarder les biens
                unToitPourTous.save();
                break;
            case 13: // Charger les biens à partir d'un fichier
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
