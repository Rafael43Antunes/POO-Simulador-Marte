//
// Created by rafao on 20/11/2026.
//

#ifndef PROJETO_SILO_H
#define PROJETO_SILO_H

#include "maquinas/Maquina.h"

class Silo : public Maquina {
private:
    struct No {
        Item* item;
        No* seguinte;
    };

    No* primeiro;
    No* ultimo;       // mais recente
    int total;
    int prob_perda;   // percentagem de perder o item mais antigo, por instante

    void acrescenta(Item* item);
    Item* retiraMaisAntigo();   

public:
    Silo(int l, int c, Direcao dir);
    ~Silo() override;

    Silo(const Silo&) = delete;
    Silo& operator=(const Silo&) = delete;

    std::string getNome() const override;

    bool aceita(const Item& item) const override;
    void recebe(Item* item, int instante) override;
    void atua(Fabrica& fabrica) override;

    int getNumItens() const override;
    std::string getConteudo() const override;
    std::string getDetalhes() const override;

    int getProbPerda() const;
};

#endif //PROJETO_SILO_H
