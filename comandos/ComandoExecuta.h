#ifndef PROJETO_COMANDOEXECUTA_H
#define PROJETO_COMANDOEXECUTA_H

#include "comandos/Comando.h"

class ComandoExecuta : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};

#endif //PROJETO_COMANDOEXECUTA_H