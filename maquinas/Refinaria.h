#ifndef PROJETO_REFINARIA_H
#define PROJETO_REFINARIA_H

#include "maquinas/Maquina.h"

class Refinaria : public Maquina {
public:
    Refinaria(int l, int c, Direcao dir);

    std::string getNome() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
};

#endif //PROJETO_REFINARIA_H