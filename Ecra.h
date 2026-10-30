//
// Created by rafao on 27/10/2026.
//

#ifndef ECRA_H
#define ECRA_H

#include <string>

class Ecra {
private:
    char** buffer;
    int max_linhas;
    int max_colunas;
    int cursor_linha;
    int cursor_coluna;

public:
    Ecra(int linhas, int colunas);

    ~Ecra();

    void limpa();
    void posicionaCursor(int linha, int coluna);
    void escreveCaracter(char c);
    void escreveString(const std::string& str);
    void desenhaMoldura(int l, int c, int alt, int larg);

    void mostra() const;
};


#endif //ECRA_H
