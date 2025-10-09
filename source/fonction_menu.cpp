#include <iostream>
#include "../include/fonctions_recursive.hpp"  // pour lancer_recursive()
#include "../include/fonction_menu.hpp"         // le header correspondant

using namespace std;

void lancer_menu() {
    int choix;

    cout << "=== MENU ===" << endl;
    cout << "1. Afficher la méthode récursive" << endl;
    cout << "2. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1:
            cout << "Vous avez choisi : méthode récursive" << endl;
            lancer_recursive(); // Appel de ta fonction principale
            break;

        case 2:
            cout << "Vous avez choisi de quitter, bonne journée !" << endl;
            break;

        default:
            cout << "Choix invalide. Veuillez entrer 1 ou 2." << endl;
            break;
    }
}
