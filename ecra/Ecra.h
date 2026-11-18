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

    Ecra(const Ecra&) = delete;
    Ecra& operator=(const Ecra&) = delete;

    void limpa();
    void posicionaCursor(int linha, int coluna);
    void escreveCaracter(char c);
    void escreveString(const std::string& str);
    
    void escreveCaracter(int linha, int coluna, char c);
    void escreveString(int linha, int coluna, const std::string& str);

    void desenhaMoldura(int l, int c, int alt, int larg);
    void mostra() const;
};

#endif //ECRA_H