#ifndef PROJETO_FABRICA_H
#define PROJETO_FABRICA_H

#include <string>
#include "terreno/Terreno.h"
#include "ecra/Ecra.h"

class Fabrica {
private:
    int linhas;
    int colunas;
    Terreno** mapa;

    // Construtor comum: 'aleatoria' decide se espalha crateras e depositos
    Fabrica(int num_linhas, int num_colunas, bool aleatoria);

    void inicializaSolo();
    int contaSolosLivres() const;
    void espalhaCrateras(int num_crateras);
    void espalhaDepositos(int num_depositos, char tipo);
    bool defineTerreno(int l, int c, char simbolo);

public:
    Fabrica(int num_linhas, int num_colunas);
    ~Fabrica();

    Fabrica(const Fabrica&) = delete;
    Fabrica& operator=(const Fabrica&) = delete;

    static bool dimensoesValidas(int num_linhas, int num_colunas);
    static Fabrica* carrega(const std::string& nome_ficheiro);

    int getLinhas() const;
    int getColunas() const;

    Terreno* getTerreno(int l, int c) const;
    void desenha(Ecra& ecra) const;
};

#endif //PROJETO_FABRICA_H