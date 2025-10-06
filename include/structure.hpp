#pragma once
#include <vector>
using namespace std;

struct Entrepot {
    unsigned int cout_ouv;
    vector<int> cout_app;
    unsigned int capa_actuel;
    unsigned int capa_max;
    bool est_ouvert = false;


};

struct Magasin {
    int entrepot_lie = -1;
};
