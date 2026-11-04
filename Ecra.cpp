#include <iostream>
#include "Ecra.h"

Ecra::Ecra(int linhas, int colunas) {
    max_linhas = (linhas < 1) ? 1 : linhas;
    max_colunas = (colunas < 1) ? 1 : colunas;
    cursor_linha = 0;
    cursor_coluna = 0;

    buffer = new char*[max_linhas];
    for (int i = 0; i < max_linhas; ++i) {
        buffer[i] = new char[max_colunas];
    }

    limpa();
}

Ecra::~Ecra() {
    for (int i = 0; i < max_linhas; ++i) {
        delete[] buffer[i];
    }
    delete[] buffer;
}

void Ecra::limpa() {
    for (int i = 0; i < max_linhas; ++i) {
        for (int j = 0; j < max_colunas; ++j) {
            buffer[i][j] = ' ';
        }
    }
    cursor_linha = 0;
    cursor_coluna = 0;
}

void Ecra::posicionaCursor(int linha, int coluna) {
    cursor_linha = linha;
    cursor_coluna = coluna;
}

void Ecra::escreveCaracter(char c) {
    if (cursor_linha >= 0 && cursor_linha < max_linhas &&
        cursor_coluna >= 0 && cursor_coluna < max_colunas) {
        buffer[cursor_linha][cursor_coluna] = c;
    }
    cursor_coluna++;
}

void Ecra::escreveString(const std::string& str) {
    for (char c : str) {
        escreveCaracter(c);
    }
}

void Ecra::escreveCaracter(int linha, int coluna, char c) {
    posicionaCursor(linha, coluna);
    escreveCaracter(c);
}

void Ecra::escreveString(int linha, int coluna, const std::string& str) {
    posicionaCursor(linha, coluna);
    escreveString(str);
}

void Ecra::desenhaMoldura(int l, int c, int alt, int larg) {
    if (alt < 2 || larg < 2) return;

    posicionaCursor(l, c);
    escreveCaracter('+');
    for (int i = 1; i < larg - 1; ++i)
        escreveCaracter('-');
    escreveCaracter('+');

    for (int i = 1; i < alt - 1; ++i) {
        escreveCaracter(l + i, c, '|');
        escreveCaracter(l + i, c + larg - 1, '|');
    }

    posicionaCursor(l + alt - 1, c);
    escreveCaracter('+');
    for (int i = 1; i < larg - 1; ++i)
        escreveCaracter('-');
    escreveCaracter('+');
}

void Ecra::mostra() const {
    int ultima_linha_valida = 0;
    bool encontrou_ultima = false;

    for (int i = max_linhas - 1; i >= 0 && !encontrou_ultima; --i) {
        for (int j = 0; j < max_colunas; ++j) {
            if (buffer[i][j] != ' ') {
                ultima_linha_valida = i;
                encontrou_ultima = true;
                break;
            }
        }
    }

    for (int i = 0; i <= ultima_linha_valida; ++i) {
        for (int j = 0; j < max_colunas; ++j) {
            std::cout << buffer[i][j];
        }
        std::cout << '\n';
    }
}