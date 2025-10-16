#include "../include/fonctions_forcebrute.hpp"
#include <climits>
#include <functional>
#include <QString>
#include <vector>

using namespace std;

int nb_magasin_force_brute(const vector<Entrepot>& entrepot) {
    if (entrepot.empty()) return 0;
    return entrepot[0].cout_app.size();
}

void generer_combi_force_brute(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m,
                               vector<int>& meilleure_combinaison, int& cout_min,
                               bool afficher_tout,
                               std::function<void(const QString&)> output_callback) 
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
            QString ligne;
            for (int i = 0; i < m; i++) {
                ligne += "M" + QString::number(i + 1) + "->E" + QString::number(choix[i] + 1) + " ";
            }
            ligne += "=> Coût total = " + QString::number(somme);
            output_callback(ligne);
        }

        if (!afficher_tout && somme < cout_min) {
            cout_min = somme;
            meilleure_combinaison = choix;
        }
        return;
    }

    for (size_t e = 0; e < ent.size(); e++) {
        choix[magasin] = e;
        generer_combi_force_brute(ent, choix, magasin + 1, m, meilleure_combinaison, cout_min, afficher_tout, output_callback);
    }
}

void choix_meilleure_combinaison_force_brute(vector<Entrepot>& ent, int m, bool afficher_tout,
                                             std::function<void(const QString&)> output_callback) 
{
    vector<int> choix(m);
    vector<int> meilleure_combinaison(m);
    int cout_min = INT32_MAX;

    if (afficher_tout) {
        generer_combi_force_brute(ent, choix, 0, m, meilleure_combinaison, cout_min, true, output_callback);
    } else {
        generer_combi_force_brute(ent, choix, 0, m, meilleure_combinaison, cout_min, false, output_callback);
        output_callback("\nMeilleure combinaison trouvée :");
        for (int i = 0; i < m; i++) {
            output_callback("Magasin " + QString::number(i + 1) + " -> Entrepôt " + QString::number(meilleure_combinaison[i] + 1));
        }
        output_callback("\nCoût total = " + QString::number(cout_min));
        output_callback("\n(Rappel : cette solution est le minimum mathématique et peut ignorer les capacités réelles)");
    }
}

void lancer_force_brute(std::function<void(const QString&)> output_callback, bool afficher_tout) {
    /*vector<Entrepot> ent = {
        {30, {20, 28, 74, 2, 46, 42, 1, 10, 93, 47}, 0, 1, false},
        {30, {24, 27, 97, 55, 96, 22, 5, 73, 35, 65}, 0, 4, false},
        {30, {11, 82, 71, 73, 59, 29, 73, 13, 63, 55}, 0, 2, false},
        {30, {25, 83, 96, 69, 83, 67, 59, 43, 85, 71}, 0, 1, false},
        {30, {30, 74, 70, 61, 4, 59, 56, 96, 46, 95}, 0, 3, false},
    };
    
    int m = nb_magasin_force_brute(ent);
    choix_meilleure_combinaison_force_brute(ent, m, afficher_tout, output_callback);
    */
    }
