#include "fonctions_arborescente.hpp"

using namespace std;

// ----- Fonctions utilitaires -----
int nb_magasin(vector<Entrepot>& entrepot) {
    return entrepot[0].cout_app.size(); // nombre de magasins
}

bool depassement(const Entrepot& entrepot) {
    return entrepot.capa_actuel < entrepot.capa_max;
}

bool test_capacite(vector<Entrepot> ent, int m) {
    int total = 0;
    for(size_t i = 0; i < ent.size(); i++){
        total += ent[i].capa_max;
    }
    return total >= m;
}

// ----- Génération des combinaisons avec affichage du chemin -----
void generer_combi(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m, 
                   vector<int>& meilleure_combinaison, int& cout_min, 
                   bool afficher_tout,
                   function<void(const QString&)> output_callback,
                   int profondeur = 0)  // profondeur pour indentation
{
    if (magasin == m) {
        int somme = 0;
        for (int i = 0; i < m; i++) {
            somme += ent[choix[i]].cout_app[i];
            ent[choix[i]].est_ouvert = true;
        }
        for (size_t i = 0; i < ent.size(); i++) {
            if (ent[i].est_ouvert) {
                somme += ent[i].cout_ouv;
                ent[i].est_ouvert = false;
            }
        }

        if (afficher_tout) {
            QString s;
            for (int i = 0; i < m; i++) {
                s += QString("M%1->E%2 ").arg(i + 1).arg(choix[i] + 1);
            }
            s += QString("=> Coût total = %1").arg(somme);
            output_callback(s);
        }

        if (!afficher_tout && somme < cout_min) {
            cout_min = somme;
            meilleure_combinaison = choix;
        }
        return;
    }

    for (size_t e = 0; e < ent.size(); e++) {
        if (depassement(ent[e])) {
            choix[magasin] = e;
            ent[e].capa_actuel += 1;

            if (afficher_tout) {
                // Indentation pour visualiser le chemin
                QString indent;
                for (int i = 0; i < profondeur; i++) indent += "  ";
                output_callback(indent + QString("Attribuer magasin %1 à entrepôt %2").arg(magasin + 1).arg(e + 1));
            }

            generer_combi(ent, choix, magasin + 1, m, meilleure_combinaison, cout_min, afficher_tout, output_callback, profondeur + 1);

            ent[e].capa_actuel -= 1; // backtracking
        }
    }
}

// ----- Choix de la meilleure combinaison -----
void choix_meilleure_combinaison(vector<Entrepot>& ent, int m, bool afficher_tout,
                                 function<void(const QString&)> output_callback) 
{
    vector<int> choix(m);
    vector<int> meilleure_combinaison(m);
    int cout_min = INT32_MAX;

    generer_combi(ent, choix, 0, m, meilleure_combinaison, cout_min, afficher_tout, output_callback, 0);

    if (!afficher_tout) {
        QString result = "Meilleure combinaison :\n";
        for (int i = 0; i < m; i++) {
            result += QString("Magasin %1 -> Entrepôt %2\n").arg(i + 1).arg(meilleure_combinaison[i] + 1);
        }
        result += QString("\nCoût total = %1").arg(cout_min);
        output_callback(result);
    }
}

// ----- Fonction principale pour lancer l'arborescence -----
void lancer_arborescente(function<void(const QString&)> output_callback, bool afficher_tout) 
{
    vector<Entrepot> ent = {
        {30, {20,28,74,2,46,42,1,10,93,47}, 0, 1, false},
        {30, {24,27,97,55,96,22,5,73,35,65}, 0, 4, false},
        {30, {11,82,71,73,59,29,73,13,63,55}, 0, 2, false},
        {30, {25,83,96,69,83,67,59,43,85,71}, 0, 1, false},
        {30, {30,74,70,61,4,59,56,96,46,95}, 0, 3, false}
    };

    int m = nb_magasin(ent);
    if(test_capacite(ent, m)){
        choix_meilleure_combinaison(ent, m, afficher_tout, output_callback);
    } else {
        output_callback("Pas assez de capacité de livraison");
    }
}
