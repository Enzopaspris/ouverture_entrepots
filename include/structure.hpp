#pragma once
#include <vector>
using namespace std;

struct Entrepot {
    unsigned int cout_ouv = 30;
    vector<int> cout_app;
    unsigned int capa_actuel;
    unsigned int capa_max;
    bool est_ouvert = false;
};


