#include <iostream>
#include <vector>
#include "../include/structure.hpp"
#include "../include/fonctions_recursive.hpp"

using namespace std;

int main() {
    // Exemple de données : 5 entrepôts, 10 magasins
    vector<Entrepot> ent = {
        {30, {20, 28, 74, 2, 46, 42, 1, 10, 93, 47}, 0, 1},
        {30, {24, 27, 97, 55, 96, 22, 5, 73, 35, 65}, 0, 4},
        {30, {11, 82, 71, 73, 59, 29, 73, 13, 63, 55}, 0, 2},
        {30, {25, 83, 96, 69, 83, 67, 59, 43, 85, 71}, 0, 1},
        {30, {30, 74, 70, 61, 4, 59, 56, 96, 46, 95}, 0, 3},
    };

    // Appel de la fonction qui gère la combinaison et l'interaction
    choix_meilleure_combinaison(ent, nb_magasin(ent));

    return 0;
}
