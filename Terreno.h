#ifndef PROJETO_TERRENO_H
#define PROJETO_TERRENO_H

#include <string>

class Terreno {
public:
    virtual ~Terreno() = default;

    virtual char getCaracterVisual() const = 0;
    virtual bool aceitaMaquinas() const = 0;
    virtual std::string getNome() const = 0;

    virtual std::string getDescricao() const;
    virtual bool isSolo() const;
    virtual bool isEsgotado() const;
};

class Solo : public Terreno {
public:
    char getCaracterVisual() const override;
    bool aceitaMaquinas() const override;
    std::string getNome() const override;
    bool isSolo() const override;
};

class Cratera : public Terreno {
public:
    char getCaracterVisual() const override;
    bool aceitaMaquinas() const override;
    std::string getNome() const override;
};

class Deposito : public Terreno {
private:
    char tipo_material;
    int quantidade;

public:
    Deposito(char tipo, int qtd);

    char getCaracterVisual() const override;
    bool aceitaMaquinas() const override;
    std::string getNome() const override;
    std::string getDescricao() const override;
    bool isEsgotado() const override;

    int getQuantidade() const;
};

#endif //PROJETO_TERRENO_H