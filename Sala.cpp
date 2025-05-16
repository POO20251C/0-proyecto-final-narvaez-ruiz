#include "Sala.h"
#include "Enemigo.h"
#include "Arma.h"

Sala::Sala(int numero, std::vector<Enemigo> enemigos, Arma cofre)
    : numero(numero), enemigos(enemigos), cofre(cofre) {}
