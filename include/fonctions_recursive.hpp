#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <random>
#include <fstream>
#include "structure.hpp"

using namespace std;

bool depassement(const Entrepot& entrepot);

void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m, vector<int>& meilleure_combinaison, int& cout_min, bool afficher_tout = false);

void choix_meilleure_combinaison(vector<Entrepot>& ent, int m);

int nb_magasin(vector<Entrepot>& entrepot);

bool test_capacite(vector<Entrepot> ent,int m);

int randInt(int min, int max, mt19937 &rng);

void lancer_recursive();