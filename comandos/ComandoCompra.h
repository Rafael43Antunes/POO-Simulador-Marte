#ifndef PROJETO_COMANDOCOMPRA_H
#define PROJETO_COMANDOCOMPRA_H

#include "comandos/Comando.h"

class ComandoCompra : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDOCOMPRA_H
