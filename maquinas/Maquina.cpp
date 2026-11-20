#include "maquinas/Maquina.h"
#include "maquinas/Perfuradora.h"
#include "maquinas/Transportador.h"
#include "maquinas/Refinaria.h"
#include "maquinas/Oficina.h"
#include "maquinas/Silo.h"
#include "maquinas/Lancador.h"
#include "simulador/Fabrica.h"
#include "Settings.h"

Maquina::Maquina(int l, int c, Direcao dir, int custo_compra, char simb)
    : linha(l), coluna(c), direcao(dir), custo(custo_compra), simbolo(simb) {}

Maquina::~Maquina() {}

Maquina* Maquina::cria(char tipo, int linha, int coluna, Direcao direcao) {
    switch (tipo) {
        case 'p': return new Perfuradora(linha, coluna, direcao);
        case 't': return new Transportador(linha, coluna, direcao);
        case 'r': return new Refinaria(linha, coluna, direcao);
        case 'o': return new Oficina(linha, coluna, direcao);
        case 's': return new Silo(linha, coluna, direcao);
        case 'l': return new Lancador(linha, coluna, direcao);
        default:  return nullptr;
    }
}

int Maquina::custoDoTipo(char tipo) {
    switch (tipo) {
        case 'p': return Settings::perfuradora_custo;
        case 't': return Settings::transportador_custo;
        case 'r': return Settings::refinaria_custo;
        case 'o': return Settings::oficina_custo;
        case 's': return Settings::silo_custo;
        case 'l': return Settings::lancador_custo;
        default:  return -1;
    }
}

Maquina* Maquina::vizinhoSaida(const Fabrica& fabrica) const {
    return fabrica.getMaquina(linha + deltaLinha(direcao), coluna + deltaColuna(direcao));
}

bool Maquina::tentaEntregar(Fabrica& fabrica, Item* item) {
    Maquina* vizinho = vizinhoSaida(fabrica);

    if (vizinho == nullptr || !vizinho->aceita(*item)) {
        return false;
    }

    vizinho->recebe(item, fabrica.getInstante());
    return true;
}

int Maquina::getLinha() const {
    return linha;
}

int Maquina::getColuna() const {
    return coluna;
}

Direcao Maquina::getDirecao() const {
    return direcao;
}

void Maquina::setDirecao(Direcao nova) {
    direcao = nova;
}

int Maquina::getCusto() const {
    return custo;
}

char Maquina::getCaracterVisual() const {
    return simbolo;
}

std::string Maquina::getDetalhes() const {
    return "";
}

std::string Maquina::getInfo() const {
    return getNome() + " (" + simbolo + ") em " + Fabrica::posicaoParaTexto(linha, coluna) +
           ", direcao " + direcaoParaChar(direcao) + ", " + getConteudo();
}