#include <iostream>
#include <vector>

struct Entrepot
{
    unsigned int cout_ouv;
    std::vector<int> cou_app;
    unsigned int capa_max;
};

struct Magasin
{
    unsigned int entrepot_lie = -1;
};


