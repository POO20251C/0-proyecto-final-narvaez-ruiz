#ifndef SALA_H
#define SALA_H

#include <vector>
#include "Enemigo.h"
#include "Arma.h"

class Sala {
public:
    int numero;
    std::vector<Enemigo> enemigos;
    Arma cofre;

    Sala(int numero, std::vector<Enemigo> enemigos, Arma cofre);
};

#endif
