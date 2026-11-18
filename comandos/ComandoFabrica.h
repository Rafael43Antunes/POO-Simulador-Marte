#ifndef PROJETO_COMANDOFABRICA_H
#define PROJETO_COMANDOFABRICA_H

#include "comandos/Comando.h"

class ComandoFabrica : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};

#endif //PROJETO_COMANDOFABRICA_H