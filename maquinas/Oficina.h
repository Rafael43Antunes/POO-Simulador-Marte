//
// Created by rafao on 20/11/2026.
//

#ifndef PROJETO_OFICINA_H
#define PROJETO_OFICINA_H

#include "maquinas/Maquina.h"

class Oficina : public Maquina {
public:
    Oficina(int l, int c, Direcao dir);

    std::string getNome() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
};


#endif //PROJETO_OFICINA_H
