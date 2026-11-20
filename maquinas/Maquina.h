#ifndef PROJETO_MAQUINA_H
#define PROJETO_MAQUINA_H

#include <string>
#include "maquinas/Direcao.h"
#include "itens/Item.h"

class Fabrica;

// Classe base de todas as maquinas: posicao fixa, direcao de saida, custo e simbolo.
class Maquina {
private:
    int linha;
    int coluna;
    Direcao direcao;
    int custo;
    char simbolo;

protected:
    Maquina* vizinhoSaida(const Fabrica& fabrica) const;

    bool tentaEntregar(Fabrica& fabrica, Item* item);

public:
    Maquina(int l, int c, Direcao dir, int custo_compra, char simb);
    virtual ~Maquina();

    static Maquina* cria(char tipo, int linha, int coluna, Direcao direcao);

    static int custoDoTipo(char tipo);

    int getLinha() const;
    int getColuna() const;
    Direcao getDirecao() const;
    void setDirecao(Direcao nova);
    int getCusto() const;

    virtual char getCaracterVisual() const;

    virtual std::string getNome() const = 0;


    virtual bool aceita(const Item& item) const = 0;
    virtual void recebe(Item* item, int instante) = 0;

    // Comportamento da maquina em cada instante
    virtual void atua(Fabrica& fabrica) = 0;

    virtual int getNumItens() const = 0;
    virtual std::string getConteudo() const = 0;
    virtual std::string getDetalhes() const;

    std::string getInfo() const;
};

#endif //PROJETO_MAQUINA_H