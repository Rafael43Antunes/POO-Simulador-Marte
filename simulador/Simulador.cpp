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

    ecra.escreveString(3, col_painel + 2, "Instante: " + std::to_string(fabrica->getInstante()));
    ecra.escreveString(4, col_painel + 2, "Creditos: " + std::to_string(fabrica->getCreditos()));
    ecra.escreveString(5, col_painel + 2, "Maquinas: " + std::to_string(fabrica->getNumMaquinas()));
    ecra.escreveString(6, col_painel + 2, "Engenheiros: 0");

    ecra.escreveString(8, col_painel + 2, "No ultimo instante:");

    const std::vector<std::string>& eventos = fabrica->getEventos();
    const std::size_t max_linhas_eventos = 4;

    if (eventos.empty()) {
        ecra.escreveString(9, col_painel + 2, "(sem eventos)");
    }
    else if (eventos.size() <= max_linhas_eventos) {
        for (std::size_t i = 0; i < eventos.size(); ++i) {
            ecra.escreveString(9 + static_cast<int>(i), col_painel + 2, eventos[i].substr(0, 28));
        }
    }
    else {
        // Nao cabem todos: mostra os 3 primeiros e quantos ficaram por mostrar
        for (std::size_t i = 0; i < max_linhas_eventos - 1; ++i) {
            ecra.escreveString(9 + static_cast<int>(i), col_painel + 2, eventos[i].substr(0, 28));
        }
        ecra.escreveString(9 + static_cast<int>(max_linhas_eventos) - 1, col_painel + 2,
                           "(+" + std::to_string(eventos.size() - (max_linhas_eventos - 1)) + " eventos)");
    }

    ecra.mostra();
}