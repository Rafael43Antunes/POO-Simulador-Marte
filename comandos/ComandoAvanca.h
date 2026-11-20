#ifndef PROJETO_COMANDOAVANCA_H
#define PROJETO_COMANDOAVANCA_H

#include "comandos/Comando.h"

class ComandoAvanca : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};

#endif //PROJETO_COMANDOAVANCA_H