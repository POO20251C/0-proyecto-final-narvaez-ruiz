#include "Heroe.h"
#include <algorithm>

Heroe::Heroe(std::string nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck), armaEquipada(nullptr) {}

void Heroe::equiparArma(Arma* arma) {
    armaEquipada = arma;
}

int Heroe::obtenerAtaqueTotal() const {
    return atk + (armaEquipada ? armaEquipada->bonusAtk : 0);
}

void Heroe::atacar(int defensaObjetivo, int &hpObjetivo) {
    int daño = std::max(0, obtenerAtaqueTotal() - defensaObjetivo);
    hpObjetivo -= daño;
}
