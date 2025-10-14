#include <iostream>
#include "../include/fonctions_arborescente.hpp"  // pour lancer_recursive()
#include "../include/fonctions_forcebrute.hpp"
#include "../include/fonction_menu.hpp"         // le header correspondant

using namespace std;

void lancer_menu() {
    int choix;

    cout << "=== MENU ===" << endl;
    cout << "1. Afficher la méthode force brute" << endl;
    cout << "2. Afficher la méthode arborescente" << endl;
    cout << "3. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1:
            cout << "Vous avez choisi : méthode récursive" << endl;
            lancer_force_brute(); // Appel forcebrute
            break;
        case 2:
            cout << "Vous avez choisi : méthode arborescente" << endl;
            lancer_arborescente(); // Appel arborescente
            break;

        case 3:
            cout << "Vous avez choisi de quitter, bonne journée !" << endl;
            break;

        default:
            cout << "Choix invalide. Veuillez entrer un nombre compris de 1 à 3." << endl;
            break;
    }
}
