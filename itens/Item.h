#ifndef PROJETO_ITEM_H
#define PROJETO_ITEM_H

#include <string>


class Item {
private:
    int instante_recebido;

public:
    Item();
    virtual ~Item();

    virtual std::string getNome() const = 0;
    virtual char getCaracter() const = 0;
    virtual int getValor() const = 0;

    int getInstanteRecebido() const;
    void setInstanteRecebido(int instante);
};


class MateriaPrima : public Item {
};

class ProdutoRefinado : public Item {
};

class MinerioFerro : public MateriaPrima {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class SilicioBruto : public MateriaPrima {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class Gelo : public MateriaPrima {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class PlacaFerro : public ProdutoRefinado {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class SilicioPuro : public ProdutoRefinado {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class Agua : public ProdutoRefinado {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

class KitHabitat : public ProdutoRefinado {
public:
    std::string getNome() const override;
    char getCaracter() const override;
    int getValor() const override;
};

#endif //PROJETO_ITEM_H