#include <iostream>
#include "comandos/ComandoAvanca.h"
#include "simulador/Simulador.h"

void ComandoAvanca::executa(Simulador& sim, std::istringstream& args) {
    std::string texto_n, extra;
    int n = 1;

    if (args >> texto_n) {
        if (!leInteiro(texto_n, n) || n <= 0) {
            std::cout << "Erro: n deve ser um inteiro positivo.\n";
            return;
        }
        if (args >> extra) {
            erroSintaxe();
            return;
        }
    }

    if (!fabricaExiste(sim)) return;

    for (int i = 0; i < n; ++i) {
        sim.getFabrica()->avancaInstante();
        sim.mostraEcra();
    }
}

std::string ComandoAvanca::getSintaxe() const {
    return "avanca [n]";
}

std::string ComandoAvanca::getAjuda() const {
    return "avanca [n]\n"
           "  Avanca n instantes (inteiro positivo; 1 se nao for indicado), um de cada vez.\n"
           "  Em cada instante as maquinas atuam e o ecra e apresentado no fim.\n"
           "  Falha se n nao for um inteiro positivo ou se a fabrica ainda nao existir.\n"
           "  Exemplo: avanca 10";
}
