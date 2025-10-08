#pragma once
#include <vector>
#include "structure.hpp"

using namespace std;

bool depassement(const Entrepot& entrepot);

void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m, vector<int>& meilleure_combinaison, int& cout_min, bool afficher_tout = false);

void choix_meilleure_combinaison(vector<Entrepot>& ent, int m);