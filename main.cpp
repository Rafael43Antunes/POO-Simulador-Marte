#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "simulador/Simulador.h"
#include "comandos/Interpretador.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Simulador sim;

    std::cout << "Crie a fabrica com 'fabrica <nl> <nc>' ou 'carrega <ficheiro>'.\n";

    std::string linha;
    while (sim.estaAExecutar()) {
        std::cout << "> ";
        if (!std::getline(std::cin, linha)) {
            break;   // EOF (Ctrl+D)
        }

        Interpretador::processa(sim, linha);
    }

    return 0;
}