#include <iostream>
#include <set>
#include <vector>
#include "../include/fonctions_recursive.hpp"
using namespace std;

int main() {
    // Données exemple : 2 entrepôts, 5 magasins
    vector<Entrepot> ent = {
        {30, {40, 1},0, 2},   // entrepot 1
        {30, {24, 27}, 0, 1},
    };

    int m = 2; // nombre de magasins
    vector<int> choix(m); // choix[e] = entrepôt choisi pour le magasin e

    generer_combi(ent, choix, 0, m);

    return 0;
}