//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../Headers/Utils.h"
#include <string>

using namespace std;

bool Utils::yesOrNo() {
    cout << "\t-[O]ui\n\t-[N]on\n";
    string userInput;
    cin >> userInput;
    cin.ignore();
    if (userInput == "O" || userInput == "o" || userInput == "Oui" || userInput == "oui" || userInput == "OUI") {
        return true;
    } else if (userInput == "N" || userInput == "n" || userInput == "Non" || userInput == "n" || userInput == "NON") {
        return false;
    } else {
        cout << "Entrée non valide\n";
        return yesOrNo();
    }

}

void Utils::menuPrincipal(){
	cout << "1. Ajouter un bien\n";
	cout << "2. Ajouter un vendeur\n";
	cout << "3. Ajouter un acheteur\n";
	cout << "4. Faire une visite\n";
	cout << "5. Ajouter une proposition d'achat\n";
	cout << "6. Faire une vente\n";
	cout << "7. Faire une recherche de bien\n";
	cout << "8. Sauvegarder les biens\n";
	cout << "9. Charger les biens à partir d'un fichier\n";
	cout << "0. Quitter le programme\n";
}
