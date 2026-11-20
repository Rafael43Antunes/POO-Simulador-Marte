#ifndef PROJETO_INTERPRETADOR_H
#define PROJETO_INTERPRETADOR_H

#include <string>
#include <vector>
#include "comandos/Comando.h"

class Simulador;

class Interpretador {
public:
    static Comando* cria(const std::string& nome);

    static std::vector<std::string> nomes();

    static void processa(Simulador& sim, const std::string& linha);
};

#endif //PROJETO_INTERPRETADOR_H