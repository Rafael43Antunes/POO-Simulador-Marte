// Interpretador.cpp
#include <iostream>
#include <sstream>
#include "comandos/Interpretador.h"
#include "comandos/ComandoFim.h"
#include "comandos/ComandoFabrica.h"
#include "comandos/ComandoCarrega.h"
#include "comandos/ComandoLposicao.h"
#include "comandos/ComandoAvanca.h"
#include "comandos/ComandoCompra.h"
#include "comandos/ComandoVende.h"
#include "comandos/ComandoRoda.h"
#include "comandos/ComandoEstado.h"
#include "comandos/ComandoAjuda.h"
#include "comandos/ComandoExecuta.h"

Comando* Interpretador::cria(const std::string& nome) {
    if (nome == "fim")
        return new ComandoFim();
    if (nome == "fabrica")
        return new ComandoFabrica();
    if (nome == "carrega")
        return new ComandoCarrega();
    if (nome == "lposicao")
        return new ComandoLposicao();
    if (nome == "avanca")
        return new ComandoAvanca();
    if (nome == "compra")
        return new ComandoCompra();
    if (nome == "vende")
        return new ComandoVende();
    if (nome == "roda")
        return new ComandoRoda();
    if (nome == "estado")
        return new ComandoEstado();
    if (nome == "ajuda")
        return new ComandoAjuda();
    if (nome == "executa")
        return new ComandoExecuta();
    return nullptr;
}

std::vector<std::string> Interpretador::nomes() {
    return {"ajuda", "fabrica", "carrega", "avanca", "compra", "vende",
            "roda", "estado", "lposicao", "executa", "fim"};
}

void Interpretador::processa(Simulador& sim, const std::string& linha) {
    std::istringstream iss(linha);
    std::string nome;
    iss >> nome;

    if (nome.empty()) return;

    Comando* cmd = cria(nome);
    if (cmd == nullptr) {
        std::cout << "Comando nao reconhecido: " << nome << ". Use 'ajuda' para ver a lista.\n";
        return;
    }

    cmd->executa(sim, iss);
    delete cmd;
}