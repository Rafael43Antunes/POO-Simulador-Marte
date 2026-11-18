#include <iostream>
#include "comandos/ComandoCarrega.h"
#include "simulador/Simulador.h"

void ComandoCarrega::executa(Simulador& sim, std::istringstream& args) {
    std::string nome, extra;

    if (!(args >> nome) || (args >> extra)) {
        std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
        return;
    }

    if (sim.getFabrica() != nullptr) {
        std::cout << "Erro: a fabrica ja foi criada.\n";
        return;
    }

    Fabrica* nova = Fabrica::carrega(nome);
    if (nova == nullptr) {
        std::cout << "Erro: nao foi possivel carregar o mapa (ficheiro inexistente ou formato invalido).\n";
        return;
    }

    sim.defineFabrica(nova);
    std::cout << "Fabrica carregada de '" << nome << "'.\n";
    sim.mostraEcra();
}

std::string ComandoCarrega::getSintaxe() const {
    return "carrega <nome-do-ficheiro>";
}

std::string ComandoCarrega::getAjuda() const {
    return "carrega <nome-do-ficheiro>\n"
           "  Cria a fabrica a partir do mapa descrito no ficheiro.\n"
           "  Falha se o ficheiro nao existir ou nao respeitar o formato,\n"
           "  ou se a fabrica ja tiver sido criada.\n"
           "  Exemplo: carrega mapa1.txt";
}