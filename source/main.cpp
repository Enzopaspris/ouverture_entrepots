#include <iostream>
#include <vector>
#include "../include/structure.hpp"
#include "../include/fonctions_recursive.hpp"

using namespace std;

int main() {
    // Exemple de données : 2 entrepôts, 2 magasins
    vector<Entrepot> ent = {
        {30, {40, 1}, 0, 2},
        {30, {24, 27}, 0, 1},
    };

    int m = 2; // nombre de magasins

    // Appel de la fonction qui gère la combinaison et l'interaction
    choix_meilleure_combinaison(ent, m);

    return 0;
}
