#include "Fabrica.h"
#include "Fabrica.h"
#include "Settings.h"
#include <cstdlib>
#include <ctime>


Fabrica::Fabrica(int num_linhas, int num_colunas) {
    linhas = (num_linhas > Settings::fabrica_max_linhas) ? Settings::fabrica_max_linhas : num_linhas;
    colunas = (num_colunas > Settings::fabrica_max_colunas) ? Settings::fabrica_max_colunas : num_colunas;

    mapa = new Terreno*[linhas * colunas];

    srand((unsigned int)time(NULL));

    inicializaSolo();
    espalhaCrateras(Settings::fabrica_num_crateras);
    espalhaDepositos(Settings::fabrica_num_depositos_ferro, '%');
    espalhaDepositos(Settings::fabrica_num_depositos_silicio, '$');
    espalhaDepositos(Settings::fabrica_num_depositos_gelo, '~');
}

Fabrica::~Fabrica() {
    int total_posicoes = linhas * colunas;

    for (int i = 0; i < total_posicoes; ++i) {
        delete mapa[i];
    }
    delete[] mapa;
}

// Lógica de Geração do Mapa
void Fabrica::inicializaSolo() {
    int total_posicoes = linhas * colunas;

    for (int i = 0; i < total_posicoes; ++i) {
        mapa[i] = new Solo();
    }
}

void Fabrica::espalhaCrateras(int num_crateras) {
    int colocadas = 0;
    while (colocadas < num_crateras) {
        int r_linha = rand() % linhas;
        int r_coluna = rand() % colunas;

        int indice = (r_linha * colunas) + r_coluna;

        if (mapa[indice]->getCaracterVisual() == ' ') {
            delete mapa[indice];
            mapa[indice] = new Cratera();
            colocadas++;
        }
    }
}

void Fabrica::espalhaDepositos(int num_depositos, char tipo) {
    int colocados = 0;
    while (colocados < num_depositos) {
        int r_linha = rand() % linhas;
        int r_coluna = rand() % colunas;
        int indice = (r_linha * colunas) + r_coluna;

        if (mapa[indice]->getCaracterVisual() == ' ') {
            int quantidade = Settings::deposito_quantidade_min +
                (rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));

            delete mapa[indice];
            mapa[indice] = new Deposito(tipo, quantidade);
            colocados++;
        }
    }
}


Terreno* Fabrica::getTerreno(int l, int c) const {
    if (l < 0 || l >= linhas || c < 0 || c >= colunas) {
        return nullptr;
    }
    return mapa[(l * colunas) + c];
}

void Fabrica::desenha(Ecra& ecra) const {
    int offset_linha = 2;
    int offset_coluna = 2;

    ecra.posicionaCursor(offset_linha - 1, offset_coluna + 1);
    for (int j = 0; j < colunas; ++j) {
        ecra.escreveCaracter('A' + j);
    }

    ecra.desenhaMoldura(offset_linha, offset_coluna, linhas + 2, colunas + 2);

    for (int l = 0; l < linhas; ++l) {
        ecra.posicionaCursor(offset_linha + 1 + l, offset_coluna - 1);
        ecra.escreveCaracter('A' + l);
        
        ecra.posicionaCursor(offset_linha + 1 + l, offset_coluna + 1);
        for (int c = 0; c < colunas; ++c) {
            ecra.escreveCaracter(mapa[(l * colunas) + c]->getCaracterVisual());
        }
    }
}