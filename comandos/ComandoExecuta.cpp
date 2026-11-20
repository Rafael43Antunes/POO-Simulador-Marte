#include <iostream>
#include <fstream>
#include "comandos/ComandoExecuta.h"
#include "comandos/Interpretador.h"
#include "simulador/Simulador.h"

namespace {
    int profundidade = 0;                   // evita que um ficheiro se chame a si proprio para sempre
    const int profundidade_maxima = 10;
}

void ComandoExecuta::executa(Simulador& sim, std::istringstream& args) {
    std::string nome, extra;

    if (!(args >> nome) || (args >> extra)) {
        erroSintaxe();
        return;
    }
    if (profundidade >= profundidade_maxima) {
        std::cout << "Erro: demasiados ficheiros 'executa' encadeados.\n";
        return;
    }

    std::ifstream ficheiro(nome);
    if (!ficheiro.is_open()) {
        std::cout << "Erro: nao foi possivel abrir o ficheiro '" << nome << "'.\n";
        return;
    }

    profundidade++;

    std::string linha;
    while (sim.estaAExecutar() && std::getline(ficheiro, linha)) {
        if (!linha.empty() && linha.back() == '\r') linha.pop_back();   // ficheiros do Windows

        std::cout << "> " << linha << "\n";
        Interpretador::processa(sim, linha);
    }

    profundidade--;
}

std::string ComandoExecuta::getSintaxe() const {
    return "executa <nome-do-ficheiro>";
}

std::string ComandoExecuta::getAjuda() const {
    return "executa <nome-do-ficheiro>\n"
           "  Le comandos do ficheiro indicado, um por linha, e executa-os exatamente como se fossem\n"
           "  escritos no teclado.\n"
           "  Falha se o ficheiro nao existir ou nao puder ser aberto.\n"
           "  Exemplo: executa teste1.txt";
}