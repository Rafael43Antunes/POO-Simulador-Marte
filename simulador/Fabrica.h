#ifndef PROJETO_FABRICA_H
#define PROJETO_FABRICA_H

#include <string>
#include <vector>
#include "terreno/Terreno.h"
#include "ecra/Ecra.h"

class Maquina;

class Fabrica {
private:
    int linhas;
    int colunas;
    Terreno** mapa;        // terreno de cada posicao (grelha achatada: linha * colunas + coluna)
    Maquina** maquinas;    // maquina de cada posicao (nullptr se nao existir), mesma indexacao
    int creditos;
    int instante;
    int num_maquinas;
    std::vector<std::string> eventos;

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

    static std::string posicaoParaTexto(int l, int c);

    int getLinhas() const;
    int getColunas() const;
    int getCreditos() const;
    int getInstante() const;
    int getNumMaquinas() const;

    void alteraCreditos(int variacao);

    Terreno* getTerreno(int l, int c) const;
    Maquina* getMaquina(int l, int c) const;


    bool colocaMaquina(Maquina* maquina);

    bool removeMaquina(int l, int c);

    void avancaInstante();

    void regista(const std::string& evento);
    const std::vector<std::string>& getEventos() const;

    void desenha(Ecra& ecra) const;
};

#endif //PROJETO_FABRICA_H