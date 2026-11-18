// Interpretador.cpp
#include <iostream>
#include <sstream>
#include "comandos/Interpretador.h"
#include "comandos/ComandoFim.h"
#include "comandos/ComandoFabrica.h"
#include "comandos/ComandoCarrega.h"
#include "comandos/ComandoLposicao.h"

Comando* Interpretador::cria(const std::string& nome) {
    if (nome == "fim")
        return new ComandoFim();
    if (nome == "fabrica")
        return new ComandoFabrica();
    if (nome == "carrega")
        return new ComandoCarrega();
    if (nome == "lposicao")
        return new ComandoLposicao();
    return nullptr;
}

void Interpretador::processa(Simulador& sim, const std::string& linha) {
    std::istringstream iss(linha);
    std::string nome;
    iss >> nome;

    if (nome.empty()) return;

    Comando* cmd = cria(nome);
    if (cmd == nullptr) {
        std::cout << "Comando nao reconhecido: " << nome << "\n";
        return;
    }

    cmd->executa(sim, iss);
    delete cmd;
}