#ifndef PROJETO_TERRENO_H
#define PROJETO_TERRENO_H


class Terreno {
public:
    virtual ~Terreno() = default;

    virtual char getCaracterVirtual() const = 0;
    virtual bool aceitaMaquinas() const = 0;

    virtual bool isEsgotado() const;

};

class Solo : public Terreno {
public:
    char getCaracterVirtual() const override;
    bool aceitaMaquinas() const override;
};

class Cratera : public Terreno {
public:
    char getCaracterVisual() const override;
    bool aceitaMaquinas() const override;
};

class Deposito : public Terreno {
private:
    char tipo_material;
    int quantidade;

public:
    Deposito(char tipo, int qtd);

    char getCaracterVisual() const override;
    bool aceitaMaquinas() const override;
    bool isEsgotado() const override;
};



#endif //PROJETO_TERRENO_H
