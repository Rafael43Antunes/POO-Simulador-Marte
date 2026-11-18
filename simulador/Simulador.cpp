#include <string>
#include "simulador/Simulador.h"
#include "Settings.h"

Simulador::Simulador()
    : fabrica(nullptr), a_executar(true),
      ecra(Settings::ecra_max_linhas, Settings::ecra_max_colunas) {}

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

void Simulador::mostraEcra() {
    if (fabrica == nullptr) return;

    ecra.limpa();
    fabrica->desenha(ecra);

    int col_painel = 2 + fabrica->getColunas() + 2 + 4;
    ecra.desenhaMoldura(2, col_painel, 12, 32);

    ecra.escreveString(3, col_painel + 2, "Instante: 0");
    ecra.escreveString(4, col_painel + 2, "Creditos: " + std::to_string(Settings::fabrica_creditos_iniciais));
    ecra.escreveString(5, col_painel + 2, "Maquinas: 0");
    ecra.escreveString(6, col_painel + 2, "Engenheiros: 0");
    ecra.escreveString(8, col_painel + 2, "No ultimo instante:");
    ecra.escreveString(9, col_painel + 2, "(sem eventos)");

    ecra.mostra();
}