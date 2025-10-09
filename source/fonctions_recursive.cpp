/**
 * @file fonctions_recursive.cpp
 * @brief Fonctions pour générer les combinaisons magasins->entrepôts et choisir la meilleure
 */

#include "../include/fonctions_recursive.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int nb_magasin(vector<Entrepot>& entrepot) {
    return entrepot[0].cout_app.size(); // nombre de magasins
}

/**
 * @brief Vérifie si un entrepôt peut accueillir une livraison supplémentaire
 * 
 * @param entrepot Référence constante vers l'entrepôt à vérifier
 * @return true si la capacité actuelle est inférieure à la capacité maximale
 * @return false sinon
 */
bool depassement(const Entrepot& entrepot) {
    return entrepot.capa_actuel < entrepot.capa_max;
}

/**
 * @brief Génère toutes les combinaisons possibles magasins->entrepôts
 *        et calcule le coût total. Peut afficher toutes les combinaisons
 *        ou uniquement déterminer la combinaison la moins chère.
 * 
 * @param ent Référence vers le vecteur des entrepôts
 * @param choix Référence vers le vecteur temporaire des affectations magasins->entrepôts
 * @param magasin Index du magasin actuel à affecter
 * @param m Nombre total de magasins
 * @param meilleure_combinaison Référence vers le vecteur qui stockera la combinaison la moins chère
 * @param cout_min Référence vers l'entier qui stockera le coût minimal
 * @param afficher_tout Si vrai, affiche toutes les combinaisons ; sinon, ne conserve que la meilleure
 */
void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m, vector<int>& meilleure_combinaison, int& cout_min, bool afficher_tout) {
    // Cas de base : tous les magasins ont été affectés
    if (magasin == m) {
        int somme = 0;
        set<int> entrepots_utilises;

        for (int i = 0; i < m; i++) {
            somme += ent[choix[i]].cout_app[i];
            entrepots_utilises.insert(choix[i]);
        }

        for (int e : entrepots_utilises) {
            somme += ent[e].cout_ouv;
        }

        if (afficher_tout) {
            for (int i = 0; i < m; i++) {
                cout << "M" << i << "->E" << choix[i] + 1 << " ";
            }
            cout << "=> Coût total = " << somme << endl;
        }

        if (!afficher_tout && somme < cout_min) {
            cout_min = somme;
            meilleure_combinaison = choix;
        }

        return;
    }

    // Boucle sur tous les entrepôts possibles pour le magasin actuel
    for (size_t e = 0; e < ent.size(); e++) {
        if (depassement(ent[e])) {
            choix[magasin] = e;
            ent[e].capa_actuel += 1; // Backtracking : incrémente la capacité

            generer_combi(ent, choix, magasin + 1, m, meilleure_combinaison, cout_min, afficher_tout);

            ent[e].capa_actuel -= 1; // Backtracking : décrémente après retour récursif
        }
    }
}



/**
 * @brief Fonction principale pour gérer le choix de la meilleure combinaison.
 *        Demande à l'utilisateur s'il souhaite afficher la meilleure combinaison ou toutes.
 * 
 * @param ent Référence vers le vecteur des entrepôts
 * @param m Nombre total de magasins
 */
void choix_meilleure_combinaison(vector<Entrepot>& ent, int m) {
    vector<int> choix(m);
    vector<int> meilleure_combinaison(m);
    int cout_min = INT32_MAX;

    cout << "Voulez-vous afficher la meilleure combinaison ? (1 = oui, 0 = non) : ";
    int reponse;
    cin >> reponse;

    if (reponse == 1) {
        // Affiche uniquement la meilleure combinaison
        generer_combi(ent, choix, 0, m, meilleure_combinaison, cout_min, false);
        cout << "Meilleure combinaison : " << endl;
        for (int i = 0; i < m; i++) {
            cout << "Magasin " << i +1 << " -> Entrepôt " << meilleure_combinaison[i] + 1 << endl;
        }
        cout << "\nCoût total = " << cout_min << endl;
    } else {
        // Affiche toutes les combinaisons
        cout << "Toutes les combinaisons :\n";
        generer_combi(ent, choix, 0, m, meilleure_combinaison, cout_min, true);
    }
}


bool test_capacite(vector<Entrepot> ent,int m){
    int total = 0;
    for(size_t i = 0; i < ent.size() ; i++){
        total += ent[i].capa_max;
    }

    return (total >= m);
}

void lancer_recursive(){
    // Exemple de données : 5 entrepôts, 10 magasins
    vector<Entrepot> ent = {
        {30, {20, 28, 74, 2, 46, 42, 1, 10, 93, 47}, 0, 1},
        {30, {24, 27, 97, 55, 96, 22, 5, 73, 35, 65}, 0, 2},
        {30, {11, 82, 71, 73, 59, 29, 73, 13, 63, 55}, 0, 4},
        {30, {25, 83, 96, 69, 83, 67, 59, 43, 85, 71}, 0, 1},
        {30, {30, 74, 70, 61, 4, 59, 56, 96, 46, 95}, 0, 3},
    };
    
    int m = nb_magasin(ent);

    if(test_capacite(ent,m)){
        // Appel de la fonction qui gère la combinaison et l'interaction
        choix_meilleure_combinaison(ent, m);
    }
    else {
        cout << "Pas assez de capacité de livraison";
    }

}