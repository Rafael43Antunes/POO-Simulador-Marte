#ifndef PROJETO_FABRICA_H
#define PROJETO_FABRICA_H

#include "Terreno.h"
#include "Ecra.h"

class Fabrica {
private:
    int linhas;
    int colunas;

    Terreno** mapa;

    void inicializaSolo();
    void espalhaCrateras(int num_crateras);
    void espalhaDepositos(int num_depositos, char tipo);

public:
    Fabrica(int num_linhas, int num_colunas);
    ~Fabrica();

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }

    Terreno* getTerreno(int l, int c) const;

    void desenha(Ecra& ecra) const;
};


#endif //PROJETO_FABRICA_H
