#ifndef PROJETO_COMANDOAJUDA_H
#define PROJETO_COMANDOAJUDA_H

#include "comandos/Comando.h"

class ComandoAjuda : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};

#endif //PROJETO_COMANDOAJUDA_H