#ifndef PROJETO_COMANDOFIM_H
#define PROJETO_COMANDOFIM_H

#include "comandos/Comando.h"

class ComandoFim : public Comando{
public:
    void executa(Simulador& sim, std::istringstream& args ) override;

    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDOFIM_H
