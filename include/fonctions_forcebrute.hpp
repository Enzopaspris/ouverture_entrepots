#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <random>
#include <fstream>
#include <chrono>
#include "structure.hpp"



int nb_magasin_force_brute(const std::vector<Entrepot>& entrepot);


void generer_combi_force_brute(std::vector<Entrepot>& ent, std::vector<int>& choix, int magasin, int m, std::vector<int>& meilleure_combinaison, int& cout_min, bool afficher_tout);


void choix_meilleure_combinaison_force_brute(std::vector<Entrepot>& ent, int m);

void lancer_force_brute();

