#ifndef HEROE_H
#define HEROE_H

#include <string>
#include "Arma.h"

class Heroe {
public:
    std::string nombre;
    int hp;
    int atk;      // ataque base
    int def;
    int spd;
    int lck;
    Arma* armaEquipada;  // arma equipada (puede ser nullptr)

    Heroe(std::string nombre, int hp, int atk, int def, int spd, int lck);

    void equiparArma(Arma* arma);
    void atacar(int defensaObjetivo, int &hpObjetivo);
    int obtenerAtaqueTotal() const;
};

#endif
