#include "../include/fonctions_forcebrute.hpp"

using namespace std;


int nb_magasin_force_brute(const vector<Entrepot>& entrepot) {
    if (entrepot.empty()) return 0;
    return entrepot[0].cout_app.size(); // nombre de magasins
}

/**
 * @brief Génère toutes les combinaisons possibles sans tenir compte de la capacité.
 * Calcule le coût total et, selon le mode, affiche tout ou garde le meilleur.
 * * @param ent Référence vers le vecteur des entrepôts.
 * @param choix Vecteur temporaire des affectations.
 * @param magasin Index du magasin actuel à affecter.
 * @param m Nombre total de magasins.
 * @param meilleure_combinaison Référence pour stocker la combinaison la moins chère.
 * @param cout_min Référence pour stocker le coût minimal.
 * @param afficher_tout Si vrai, affiche toutes les combinaisons; sinon, ne conserve que la meilleure.
 */
void generer_combi_force_brute(vector<Entrepot>& ent, vector<int>& choix, int magasin, int m, vector<int>& meilleure_combinaison, int& cout_min, bool afficher_tout) {
    // Cas de base : tous les magasins ont été affectés
    if (magasin == m) {
        int somme = 0;

        // Calcul du coût : méthode originale avec le flag 'est_ouvert'
        for (int i = 0; i < m; i++) {
            somme += ent[choix[i]].cout_app[i];
            ent[choix[i]].est_ouvert = true; // Marque les entrepôts utilisés
        }

        for (size_t i = 0; i < ent.size(); i++) {
            if (ent[i].est_ouvert) {
                somme += ent[i].cout_ouv;
                ent[i].est_ouvert = false; // Réinitialise le flag pour la prochaine combinaison
            }
        }

        // Logique d'affichage ou de stockage
        if (afficher_tout) {
            for (int i = 0; i < m; i++) {
                cout << "M" << i + 1 << "->E" << choix[i] + 1 << " ";
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
        //
        // MODIFICATION PRINCIPALE : LA CONDITION DE CAPACITÉ A ÉTÉ RETIRÉE
        // L'ancien code avait ici : if (depassement(ent[e])) { ... }
        //
        
        choix[magasin] = e;
        // Le backtracking sur la capacité (capa_actuel) n'est plus nécessaire
        generer_combi_force_brute(ent, choix, magasin + 1, m, meilleure_combinaison, cout_min, afficher_tout);
    }
}

/**
 * @brief Fonction principale pour gérer le choix et lancer la génération.
 * C'est ici qu'on ajoute les avertissements.
 * * @param ent Référence vers le vecteur des entrepôts.
 * @param m Nombre total de magasins.
 */
void choix_meilleure_combinaison_force_brute(vector<Entrepot>& ent, int m) {
    vector<int> choix(m);
    vector<int> meilleure_combinaison(m);
    int cout_min = INT32_MAX;

    // --- AVERTISSEMENT AJOUTÉ ---
    cout << "***************************************************************" << endl;
    cout << "ATTENTION : Ce mode ignore complètement la capacité des entrepôts." << endl;
    cout << "Les solutions peuvent donc ne pas être réalisables en pratique." << endl;
    cout << "***************************************************************" << endl << endl;

    cout << "Voulez-vous afficher la meilleure combinaison (1) ou toutes les combinaisons (0) ? : ";
    int reponse;
    cin >> reponse;

    auto start = std::chrono::high_resolution_clock::now();

    if (reponse == 1) {
        // Affiche uniquement la meilleure combinaison
        generer_combi_force_brute(ent, choix, 0, m, meilleure_combinaison, cout_min, false);
        cout << "\n Meilleure combinaison trouvée : " << endl;
        for (int i = 0; i < m; i++) {
            cout << "Magasin " << i + 1 << " -> Entrepôt " << meilleure_combinaison[i] + 1 << endl;
        }
        cout << "\n Coût total = " << cout_min << endl;
        
        // --- PRÉCISION FINALE AJOUTÉE ---
        cout << "\n(Rappel : cette solution est le minimum mathématique et peut ignorer les capacités réelles)" << endl;

    } else {
        // Affiche toutes les combinaisons
        cout << "\n--- Affichage de toutes les combinaisons (sans contraintes) ---\n" << endl;
        generer_combi_force_brute(ent, choix, 0, m, meilleure_combinaison, cout_min, true);
    }

    // Fin chronométrage
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Temps d'exécution : " << duration.count() << " secondes" << endl;
}

/**
 * @brief Point d'entrée pour lancer le programme
 */
void lancer_force_brute() {
    // Tes données d'origine
    vector<Entrepot> ent = {
        {30, {20, 28, 74, 2, 46, 42, 1, 10, 93, 47}, 0, 1, false},
        {30, {24, 27, 97, 55, 96, 22, 5, 73, 35, 65}, 0, 4, false},
        {30, {11, 82, 71, 73, 59, 29, 73, 13, 63, 55}, 0, 2, false},
        {30, {25, 83, 96, 69, 83, 67, 59, 43, 85, 71}, 0, 1, false},
        {30, {30, 74, 70, 61, 4, 59, 56, 96, 46, 95}, 0, 3, false},
    };
    
    int m = nb_magasin_force_brute(ent);

    choix_meilleure_combinaison_force_brute(ent, m);
}
