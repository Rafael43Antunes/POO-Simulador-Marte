#ifndef PROJETO_COMANDO_H
#define PROJETO_COMANDO_H

#include <sstream>
#include <string>
#include "maquinas/Direcao.h"

class Simulador;

// Classe base de todos os comandos. Cada comando valida os seus parametros,
// executa-se e sabe dar a sua propria ajuda.
class Comando {
protected:
    static bool lePosicao(const std::string& texto, int& linha, int& coluna);
    static bool leDirecao(const std::string& texto, Direcao& dir);
    static bool leInteiro(const std::string& texto, int& valor);
    static bool fabricaExiste(const Simulador& sim);

    void erroSintaxe() const;

public:
    virtual ~Comando();

    virtual void executa(Simulador& sim, std::istringstream& args) = 0;

    virtual std::string getSintaxe() const = 0;
    virtual std::string getAjuda() const = 0;
};

#endif //PROJETO_COMANDO_H