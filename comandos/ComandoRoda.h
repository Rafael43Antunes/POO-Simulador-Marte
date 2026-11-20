#ifndef PROJETO_COMANDORODA_H
#define PROJETO_COMANDORODA_H

#include "comandos/Comando.h"

class ComandoRoda : public Comando {
public:
    void executa(Simulador& sim, std::istringstream& args) override;
    std::string getSintaxe() const override;
    std::string getAjuda() const override;
};


#endif //PROJETO_COMANDORODA_H
