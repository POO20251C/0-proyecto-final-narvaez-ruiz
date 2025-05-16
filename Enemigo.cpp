#include "Enemigo.h"
#include "Heroe.h"
#include <algorithm>

Enemigo::Enemigo(std::string tipo, std::string nombre, int hp, int atk, int def, int spd, int lck)
    : tipo(tipo), nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Enemigo::atacar(int defensaObjetivo, int &hpObjetivo) {
    int daño = std::max(0, atk - defensaObjetivo);
    hpObjetivo -= daño;
}

