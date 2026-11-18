#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ecra/Ecra.h"
#include "Settings.h"
#include "simulador/Simulador.h"
#include "comandos/Comando.h"
#include "comandos/ComandoFim.h"
#include "comandos/ComandoLposicao.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Ecra ecra(Settings::ecra_max_linhas, Settings::ecra_max_colunas);

    Simulador sim;
    sim.defineFabrica(new Fabrica(15,20));

    std::string linha_input;

    while (sim.estaAExecutar()) {
        Fabrica* fabrica = sim.getFabrica();

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

        std::cout << "\nComandos disponiveis nesta fase: 'lposicao <lc>' ou 'fim'\n> ";
        if (!std::getline(std::cin, linha_input)) {
            break;
        }

        std::istringstream iss(linha_input);
        std::string nome;
        iss >> nome;

        if (nome.empty()) continue;

        Comando* cmd = nullptr;
        if (nome == "fim")
            cmd = new ComandoFim();
        else if (nome == "lposicao")
            cmd = new ComandoLposicao();

        if (cmd != nullptr) {
            cmd->executa(sim, iss);
            delete cmd;
        } else {
            std::cout << "Comando nao reconhecido nesta fase.\n";
        }

        if (sim.estaAExecutar()) {
            std::cout << "(Pressione ENTER para continuar)";
            std::string pausa;
            std::getline(std::cin, pausa);
        }
    }

    return 0;
}