#include <iostream>
#include "comandos/ComandoEstado.h"
#include "simulador/Simulador.h"
#include "maquinas/Maquina.h"

void ComandoEstado::executa(Simulador& sim, std::istringstream& args) {
    std::string extra;

    if (args >> extra) {
        erroSintaxe();
        return;
    }
    if (!fabricaExiste(sim)) return;

    Fabrica* fabrica = sim.getFabrica();

    std::cout << "Instante: " << fabrica->getInstante() << "\n";
    std::cout << "Creditos: " << fabrica->getCreditos() << "\n";
    std::cout << "Maquinas (" << fabrica->getNumMaquinas() << "):\n";

    for (int l = 0; l < fabrica->getLinhas(); ++l) {
        for (int c = 0; c < fabrica->getColunas(); ++c) {
            Maquina* m = fabrica->getMaquina(l, c);
            if (m != nullptr) {
                std::cout << "  " << m->getInfo() << "\n";
            }
        }
    }

    std::cout << "Engenheiros: 0\n";
    std::cout << "Itens enviados para a Terra: nenhum\n";
}

std::string ComandoEstado::getSintaxe() const {
    return "estado";
}

std::string ComandoEstado::getAjuda() const {
    return "estado\n"
           "  Apresenta o instante atual, os creditos, as maquinas (tipo, posicao, direcao e conteudo),\n"
           "  os engenheiros e os itens enviados para a Terra.\n"
           "  Nao tem parametros. Falha se a fabrica ainda nao existir.\n"
           "  Exemplo: estado";
}