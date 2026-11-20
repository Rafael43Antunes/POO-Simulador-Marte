#ifndef PROJETO_TRANSPORTADOR_H
#define PROJETO_TRANSPORTADOR_H

#include "maquinas/Maquina.h"

class Transportador : public Maquina {
public:
    Transportador(int l, int c, Direcao dir);

    std::string getNome() const override;
    char getCaracterVisual() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
};

#endif //PROJETO_TRANSPORTADOR_H