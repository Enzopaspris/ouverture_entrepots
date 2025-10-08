/**
 * @file fonctions_entrepots.cpp
 * @brief Fonctions pour la gestion des entrepôts et magasins
 * 
 * Ce fichier contient des fonctions permettant de vérifier l'état des entrepôts,
 * calculer les coûts d'approvisionnement et générer toutes les combinaisons possibles
 * d'affectation des magasins aux entrepôts.
 */

#include <iostream>
#include <set>
#include <vector>
#include "../include/fonctions_recursive.hpp"

using namespace std;



/**
 * @brief Vérifie si un entrepôt peut accueillir une nouvelle livraison
 * 
 * @param entrepot L'entrepôt à vérifier
 * @return true si la capacité actuelle est inférieure à la capacité maximale
 * @return false sinon
 */
bool depassement(const Entrepot entrepot) {
    if (entrepot.capa_actuel < entrepot.capa_max) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Génère toutes les combinaisons possibles magasins->entrepôts
 *        en respectant les capacités et calcule le coût total
 * 
 * @param ent Vecteur des entrepôts disponibles
 * @param choix Vecteur des affectations magasins->entrepôts (taille = nombre de magasins)
 * @param magasin Index du magasin actuel à affecter
 * @param m Nombre total de magasins
 */
void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m) {
    // Cas de base : tous les magasins ont été assignés
    if (magasin == m) {
        int somme = 0;
        set<int> entrepots_utilises; // Ensemble pour stocker les entrepôts utilisés

        // Calcul de la somme des coûts d'approvisionnement
        for (int i = 0; i < m; i++) {
            somme += ent[choix[i]].cout_app[i];
            entrepots_utilises.insert(choix[i]); // Marquer l'entrepôt comme utilisé
        }

        // Ajouter le coût d'ouverture des entrepôts utilisés
        for (int e : entrepots_utilises) {
            somme += ent[e].cout_ouv;
        }

        // Affichage de la combinaison et du coût total
        for (int i = 0; i < m; i++) {
            cout << "M" << i << "->E" << choix[i] + 1 << " ";
        }
        cout << "=> Coût total = " << somme << endl;
        return;
    }

    // Boucle sur tous les entrepôts possibles pour ce magasin
    for (size_t e = 0; e < ent.size(); e++) {
        if (depassement(ent[e])) { // Vérifie que la capacité de l'entrepôt le permet
            choix[magasin] = e;
            ent[e].capa_actuel += 1; // Incrémenter la capacité actuelle pour ce choix

            generer_combi(ent, choix, magasin + 1, m); // Appel récursif pour le magasin suivant

            ent[e].capa_actuel -= 1; // Décrémenter la capacité après retour de la récursion (backtracking)
        }
    }
}
