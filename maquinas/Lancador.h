//
// Created by rafao on 20/11/2026.
//

#ifndef PROJETO_LANCADOR_H
#define PROJETO_LANCADOR_H

#include "maquinas/Maquina.h"

class Lancador : public Maquina {
public:
    Lancador(int l, int c, Direcao dir);

    std::string getNome() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
};


#endif //PROJETO_LANCADOR_H
