#ifndef PROJETO_COMANDO_H
#define PROJETO_COMANDO_H

#include <sstream>
#include <string>

class Simulador;

class Comando {
public:
    virtual ~Comando() = default;

    virtual void executa(Simulador& sim, std::istringstream& args) = 0;

    virtual std::string getSintaxe() const = 0;   
    virtual std::string getAjuda() const = 0;
};


#endif //PROJETO_COMANDO_H
