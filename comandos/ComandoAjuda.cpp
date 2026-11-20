#include <iostream>
#include "comandos/ComandoAjuda.h"
#include "comandos/Interpretador.h"

void ComandoAjuda::executa(Simulador&, std::istringstream& args) {
    std::string nome, extra;

    if (!(args >> nome)) {
        std::cout << "Comandos disponiveis:\n";
        for (const std::string& n : Interpretador::nomes()) {
            Comando* cmd = Interpretador::cria(n);
            std::cout << "  " << cmd->getSintaxe() << "\n";
            delete cmd;
        }
        return;
    }

    if (args >> extra) {
        erroSintaxe();
        return;
    }

    Comando* cmd = Interpretador::cria(nome);
    if (cmd == nullptr) {
        std::cout << "Erro: o comando '" << nome << "' nao existe. Use 'ajuda' para ver a lista.\n";
        return;
    }

    std::cout << cmd->getAjuda() << "\n";
    delete cmd;
}

std::string ComandoAjuda::getSintaxe() const {
    return "ajuda [comando]";
}

std::string ComandoAjuda::getAjuda() const {
    return "ajuda [comando]\n"
           "  Sem parametro: lista todos os comandos, um por linha, com a sintaxe resumida.\n"
           "  Com o nome de um comando: apresenta a ajuda detalhada desse comando.\n"
           "  Falha se o comando indicado nao existir.\n"
           "  Exemplo: ajuda compra";
}