#include <iostream>
#include "comandos/ComandoFim.h"
#include "simulador/Simulador.h"

void ComandoFim::executa(Simulador& sim, std::istringstream& args) {
    std::string extra;
    if (args >> extra) {
        std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
        return;
    }

    sim.termina();
    std::cout << "A encerrar o simulador de forma limpa...\n";
}

std::string ComandoFim::getSintaxe() const {
    return "fim";
}

std::string ComandoFim::getAjuda() const {
    return "fim\n"
           "  Encerra o programa e liberta todos os recursos.\n"
           "  Nao tem parametros.\n"
           "  Exemplo: fim";
}

