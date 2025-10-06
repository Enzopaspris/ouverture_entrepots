#include <iostream>
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

bool est_approvisionne(const Magasin magasin) {
   if (magasin.entrepot_lie != -1) {
       return true;
   }
   return false;
}
