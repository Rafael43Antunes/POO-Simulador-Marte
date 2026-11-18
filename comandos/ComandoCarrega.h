#ifndef PROJETO_COMANDOCARREGA_H
#define PROJETO_COMANDOCARREGA_H

#include "comandos/Comando.h"

class ComandoCarrega : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};

#endif //PROJETO_COMANDOCARREGA_H