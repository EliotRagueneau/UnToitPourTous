//
// Created by eliot on 25/02/19.
//

#include "../Headers/Utils.h"
#include <iostream>

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

bool Utils::minOrMax() {
    cout << "\t-[m]in\n\t-[M]ax\n";
    string userInput;
    cin >> userInput;
    cin.ignore();
    if (userInput == "M" || userInput == "MAX" || userInput == "max" || userInput == "maximum") {
        return true;
    } else if (userInput == "m" || userInput == "MIN" || userInput == "min" || userInput == "minimum") {
        return false;
    } else {
        cout << "Entrée non valide\n";
        return minOrMax();
    }
}


int Utils::selectType() {
    cout << "Quel type de bien souhaitez vous ?\n";
    cout << "\t-1. Une maison\n";
    cout << "\t-2. Un appartement\n";
    cout << "\t-3. Un terrain\n";
    cout << "\t-4. Un local professionnel\n";
    return getInt();
}


double Utils::getDouble() {
    double value;
    cin >> value;
    cin.ignore();
    return value;
}

int Utils::getInt() {
    int value;
    cin >> value;
    cin.ignore();
    return value;
}
