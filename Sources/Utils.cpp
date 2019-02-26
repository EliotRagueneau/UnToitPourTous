//
// Created by eliot on 25/02/19.
//

#include <iostream>
#include "../Headers/Utils.h"

using namespace std;

bool Utils::yesOrNo() {
    cout << "\t-[O]ui\n\t-[N]on\n";
    string userInput;
    cin >> userInput;
    cin.ignore();
    if (userInput == "O" || userInput == "o" || userInput == "Oui" || userInput == "oui") {
        return true;
    } else if (userInput == "N" || userInput == "n" || userInput == "Non" || userInput == "n") {
        return false;
    } else {
        cout << "Entrée non valide\n";
        return yesOrNo();
    }

}
