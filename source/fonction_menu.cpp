#include "../include/fonctions_arborescente.hpp"
#include "../include/fonctions_forcebrute.hpp"
#include "../include/fonction_menu.hpp"

void lancer_menu() {
    int choix;

    cout << "=== MENU ===" << endl;
    cout << "1. Afficher la méthode force brute" << endl;
    cout << "2. Afficher la méthode arborescente" << endl;
    cout << "3. Afficher la méthode arborescente - Entrepôts & Magasins aléatoires" << endl;
    cout << "4. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1:
            cout << "Vous avez choisi : méthode récursive" << endl;
            lancer_force_brute();
            break;
        case 2:
            cout << "Vous avez choisi : méthode arborescente" << endl;
            lancer_arborescente();
            break;
        case 3:
            cout << "Vous avez choisi : méthode arborescente - Entrepôts & Magasins aléatoires" << endl;
            lancer_arborescente_alea();
            break;
        case 4:
            cout << "Vous avez choisi de quitter, bonne journée !" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez entrer un nombre compris de 1 à 3." << endl;
            break;
    }
}
