#ifndef PROJETO_COMANDOVENDE_H
#define PROJETO_COMANDOVENDE_H

#include "comandos/Comando.h"

class ComandoVende : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDOVENDE_H
