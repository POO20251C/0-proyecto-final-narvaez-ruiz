#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>

class Enemigo {
public:
    std::string tipo;
    std::string nombre;
    int hp;
    int atk;
    int def;
    int spd;
    int lck;

    Enemigo(std::string tipo, std::string nombre, int hp, int atk, int def, int spd, int lck);

    void atacar(int defensaObjetivo, int &hpObjetivo);

};

#endif
