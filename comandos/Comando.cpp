#include <iostream>
#include "comandos/Comando.h"
#include "simulador/Simulador.h"

Comando::~Comando() {}

bool Comando::lePosicao(const std::string& texto, int& linha, int& coluna) {
    if (texto.size() != 2) return false;
    if (texto[0] < 'a' || texto[0] > 'z' || texto[1] < 'a' || texto[1] > 'z') return false;

    linha = texto[0] - 'a';
    coluna = texto[1] - 'a';
    return true;
}

bool Comando::leDirecao(const std::string& texto, Direcao& dir) {
    return texto.size() == 1 && charParaDirecao(texto[0], dir);
}

bool Comando::leInteiro(const std::string& texto, int& valor) {
    std::istringstream conversao(texto);
    char lixo;
    return (conversao >> valor) && !(conversao >> lixo);
}

bool Comando::fabricaExiste(const Simulador& sim) {
    if (sim.getFabrica() == nullptr) {
        std::cout << "Erro: a fabrica ainda nao foi criada.\n";
        return false;
    }
    return true;
}

void Comando::erroSintaxe() const {
    std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
}
