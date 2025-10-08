#include <iostream>
#include <set>
#include <vector>
#include "../include/fonctions.hpp"
using namespace std;

// Définition de la fonction est_ouvert
bool est_ouvert(const Entrepot entrepot) {
    return entrepot.est_ouvert;
}

// Fonction qui renvoie vrai si la livraison peut se faire
bool depassement(const Entrepot entrepot){
    if(entrepot.capa_actuel < entrepot.capa_max){
        return true;
    }
    else{
        return false;
    }
}

// Définition de la fonction ratio cout_ouv/capa_max
double ratio_ouv_capa(const Entrepot entrepot) {
   if (entrepot.capa_max == 0) {
       cout << "La capacité maximale de l'entrepôt est de 0" << endl;
       return 0.0;    
   }
   return entrepot.cout_ouv / entrepot.capa_max;
}

//La fonction vérifie qu’un magasin est approvisionné par un seul entrepôt
bool est_approvisionne(const Magasin magasin) {
   if (magasin.entrepot_lie != -1) {
       return true;
   }
   return false;
}

//La fonction qui somme le coût d’approvisionnement par entrepôt
int somme_approvisionnement(const Entrepot &entrepot) {
    int somme = 0;
    for (size_t i = 0; i < entrepot.cout_app.size(); i++) {
        somme += entrepot.cout_app[i];
    }
    return somme;
}

// Fonction récursive pour générer toutes les combinaisons
void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m) {
    if (magasin == m) {
        // Calculer la somme des coûts d'approvisionnement
        int somme = 0;
        set<int> entrepots_utilises; // pour le coût d'ouverture
        for (int i = 0; i < m; i++) {
            somme += ent[choix[i]].cout_app[i];
            entrepots_utilises.insert(choix[i]);
        }

        // Ajouter le coût d'ouverture des entrepôts utilisés
        for (int e : entrepots_utilises) {
            somme += ent[e].cout_ouv;
        }

        // Affichage de la combinaison
        for (int i = 0; i < m; i++) {
            cout << "M" << i << "->E" << choix[i]+1 << " ";
        }
        cout << "=> Coût total = " << somme << endl;
        return;

    }

    // Boucle sur tous les entrepôts possibles pour ce magasin
    for (size_t e = 0; e < ent.size(); e++) {
        if (depassement(ent[e])) {  // Vérifie la capacité max
            choix[magasin] = e;
            ent[e].capa_actuel += 1; // Incrémente de la capa actuelle de l'entrepôt

            generer_combi(ent, choix, magasin + 1, m);

            ent[e].capa_actuel -= 1;  // Décrémente la capa actuelle pour revenir comme avant la récursion
        }
    }

}