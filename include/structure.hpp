#pragma once
#include <vector>

struct Entrepot {
    unsigned int cout_ouv;
    std::vector<int> cou_app;
    unsigned int capa_max;
    bool est_ouvert = false;
};

struct Magasin {
    int entrepot_lie = -1;
};
