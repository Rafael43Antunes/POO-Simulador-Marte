#ifndef PROJETO_COMANDOLPOSICAO_H
#define PROJETO_COMANDOLPOSICAO_H

#include "comandos/Comando.h"

class ComandoLposicao : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDOLPOSICAO_H
