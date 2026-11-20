#ifndef PROJETO_COMANDOESTADO_H
#define PROJETO_COMANDOESTADO_H

#include "comandos/Comando.h"

class ComandoEstado : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDOESTADO_H
