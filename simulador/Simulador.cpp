#include "Simulador.h"

Simulador::Simulador() : fabrica(nullptr), a_executar(true) {}

Simulador::~Simulador() {
    delete fabrica;
}

Fabrica* Simulador::getFabrica() const {
    return fabrica;
}

void Simulador::defineFabrica(Fabrica* nova) {
    delete fabrica;
    fabrica = nova;
}

bool Simulador::estaAExecutar() const {
    return a_executar;
}

void Simulador::termina() {
    a_executar = false;
}