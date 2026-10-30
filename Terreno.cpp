#include "Terreno.h"

bool Terreno::isEsgotado() const {
    return false;
}

char Solo::getCaracterVisual() const {
    return ' ';
}

bool Solo::aceitaMaquinas() const {
    return true;
}

char Cratera::getCaracterVisual() const {
    return '#';
}

bool Cratera::aceitaMaquinas() const {
    return false;
}

Deposito::Deposito(char tipo, int qtd) : tipo_material(tipo), quantidade(qtd) {}

char Deposito::getCaracterVisual() const {
    return tipo_material;
}

bool Deposito::aceitaMaquinas() const {
    return true;
}

bool Deposito::isEsgotado() const {
    return quantidade <= 0;
}
