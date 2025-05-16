#ifndef ARMA_H
#define ARMA_H

#include <string>

class Arma {
public:
    std::string nombre;
    int bonusAtk;

    Arma(std::string nombre, int bonusAtk);
};

#endif
