#include <cstdlib>
#include <fstream>
#include "simulador/Fabrica.h"
#include "Settings.h"

namespace {
    int limita(int valor, int maximo) {
        if (valor < 1) return 1;
        if (valor > maximo) return maximo;
        return valor;
    }
}

Fabrica::Fabrica(int num_linhas, int num_colunas)
    : Fabrica(limita(num_linhas, Settings::fabrica_max_linhas),
              limita(num_colunas, Settings::fabrica_max_colunas), true) {}

Fabrica::Fabrica(int num_linhas, int num_colunas, bool aleatoria)
    : linhas(num_linhas), colunas(num_colunas), mapa(new Terreno*[num_linhas * num_colunas]) {
    inicializaSolo();

    if (aleatoria) {
        espalhaCrateras(Settings::fabrica_num_crateras);
        espalhaDepositos(Settings::fabrica_num_depositos_ferro, '%');
        espalhaDepositos(Settings::fabrica_num_depositos_silicio, '$');
        espalhaDepositos(Settings::fabrica_num_depositos_gelo, '~');
    }
}

Fabrica::~Fabrica() {
    int total_posicoes = linhas * colunas;
    for (int i = 0; i < total_posicoes; ++i) {
        delete mapa[i];
    }
    delete[] mapa;
}

bool Fabrica::dimensoesValidas(int num_linhas, int num_colunas) {
    return num_linhas >= 1 && num_linhas <= Settings::fabrica_max_linhas &&
           num_colunas >= 1 && num_colunas <= Settings::fabrica_max_colunas;
}

int Fabrica::getLinhas() const {
    return linhas;
}

int Fabrica::getColunas() const {
    return colunas;
}

void Fabrica::inicializaSolo() {
    int total_posicoes = linhas * colunas;
    for (int i = 0; i < total_posicoes; ++i) {
        mapa[i] = new Solo();
    }
}

int Fabrica::contaSolosLivres() const {
    int livres = 0;
    int total_posicoes = linhas * colunas;
    for (int i = 0; i < total_posicoes; ++i) {
        if (mapa[i]->isSolo()) {
            livres++;
        }
    }
    return livres;
}

void Fabrica::espalhaCrateras(int num_crateras) {
    int livres = contaSolosLivres();
    if (num_crateras > livres) num_crateras = livres;

    int colocadas = 0;
    while (colocadas < num_crateras) {
        int r_linha = rand() % linhas;
        int r_coluna = rand() % colunas;

        if (mapa[(r_linha * colunas) + r_coluna]->isSolo()) {
            defineTerreno(r_linha, r_coluna, '#');
            colocadas++;
        }
    }
}

void Fabrica::espalhaDepositos(int num_depositos, char tipo) {
    int livres = contaSolosLivres();
    if (num_depositos > livres) num_depositos = livres;

    int colocados = 0;
    while (colocados < num_depositos) {
        int r_linha = rand() % linhas;
        int r_coluna = rand() % colunas;

        if (mapa[(r_linha * colunas) + r_coluna]->isSolo()) {
            defineTerreno(r_linha, r_coluna, tipo);
            colocados++;
        }
    }
}

// Troca o terreno da posicao pelo que corresponde ao simbolo (o mesmo do ficheiro de mapa).
// Devolve false se o simbolo nao existir.
bool Fabrica::defineTerreno(int l, int c, char simbolo) {
    Terreno* novo = nullptr;

    if (simbolo == '.') {
        return true;                     // ja e solo
    }
    else if (simbolo == '#') {
        novo = new Cratera();
    }
    else if (simbolo == '%' || simbolo == '$' || simbolo == '~') {
        int quantidade = Settings::deposito_quantidade_min +
            (rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));
        novo = new Deposito(simbolo, quantidade);
    }
    else {
        return false;
    }

    int indice = (l * colunas) + c;
    delete mapa[indice];
    mapa[indice] = novo;
    return true;
}

Fabrica* Fabrica::carrega(const std::string& nome_ficheiro) {
    std::ifstream ficheiro(nome_ficheiro);
    if (!ficheiro.is_open()) return nullptr;

    int nl = 0, nc = 0;
    if (!(ficheiro >> nl >> nc) || !dimensoesValidas(nl, nc)) return nullptr;

    std::string linha;
    std::getline(ficheiro, linha);       // resto da 1a linha: so pode ter espacos
    if (linha.find_first_not_of(" \t\r") != std::string::npos) return nullptr;

    Fabrica* f = new Fabrica(nl, nc, false);

    bool valido = true;
    for (int l = 0; l < nl && valido; ++l) {
        valido = static_cast<bool>(std::getline(ficheiro, linha));

        if (valido) {
            if (!linha.empty() && linha.back() == '\r') linha.pop_back();   // ficheiros do Windows
            valido = (static_cast<int>(linha.size()) == nc);
        }

        for (int c = 0; c < nc && valido; ++c) {
            valido = f->defineTerreno(l, c, linha[static_cast<std::size_t>(c)]);
        }
    }

    if (!valido) {
        delete f;
        return nullptr;
    }
    return f;
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
        ecra.escreveCaracter(static_cast<char>('A' + j));
    }

    ecra.desenhaMoldura(offset_linha, offset_coluna, linhas + 2, colunas + 2);

    for (int l = 0; l < linhas; ++l) {
        ecra.posicionaCursor(offset_linha + 1 + l, offset_coluna - 1);
        ecra.escreveCaracter(static_cast<char>('A' + l));

        ecra.posicionaCursor(offset_linha + 1 + l, offset_coluna + 1);
        for (int c = 0; c < colunas; ++c) {
            ecra.escreveCaracter(mapa[(l * colunas) + c]->getCaracterVisual());
        }
    }
}