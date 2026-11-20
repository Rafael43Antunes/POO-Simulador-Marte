#ifndef PROJETO_PERFURADORA_H
#define PROJETO_PERFURADORA_H

#include "maquinas/Maquina.h"

class Perfuradora : public Maquina {
public:
    Perfuradora(int l, int c, Direcao dir);

    std::string getNome() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
};

#endif //PROJETO_PERFURADORA_H