#include <iostream>
#include "comandos/ComandoFabrica.h"
#include "simulador/Simulador.h"
#include "Settings.h"

void ComandoFabrica::executa(Simulador& sim, std::istringstream& args) {
    int nl = 0, nc = 0;
    std::string extra;

    if (!(args >> nl >> nc) || (args >> extra)) {
        std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
        return;
    }

    if (sim.getFabrica() != nullptr) {
        std::cout << "Erro: a fabrica ja foi criada.\n";
        return;
    }

    if (!Fabrica::dimensoesValidas(nl, nc)) {
        std::cout << "Erro: dimensoes invalidas (entre 1 e "
                  << Settings::fabrica_max_linhas << " linhas e entre 1 e "
                  << Settings::fabrica_max_colunas << " colunas).\n";
        return;
    }

    sim.defineFabrica(new Fabrica(nl, nc));
    std::cout << "Fabrica criada: " << nl << "x" << nc << ".\n";
    sim.mostraEcra();
}

std::string ComandoFabrica::getSintaxe() const {
    return "fabrica <nl> <nc>";
}

std::string ComandoFabrica::getAjuda() const {
    return "fabrica <nl> <nc>\n"
           "  Cria a fabrica com <nl> linhas e <nc> colunas (maximo 26 cada).\n"
           "  Crateras e depositos sao colocados em posicoes aleatorias.\n"
           "  Falha se a fabrica ja existir ou se as dimensoes forem invalidas.\n"
           "  Exemplo: fabrica 12 20";
}