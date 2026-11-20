#include "maquinas/Transportador.h"
#include "Settings.h"

Transportador::Transportador(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::transportador_custo, 'T') {}

std::string Transportador::getNome() const {
    return "Transportador";
}


char Transportador::getCaracterVisual() const {
    switch (getDirecao()) {
        case Direcao::Cima:     return '^';
        case Direcao::Baixo:    return 'v';
        case Direcao::Esquerda: return '<';
        case Direcao::Direita:  return '>';
    }
    return 'T';
}

bool Transportador::aceita(const Item&) const {
    return false;  //...
}

void Transportador::recebe(Item*, int) {
}

void Transportador::atua(Fabrica&) {
}

int Transportador::getNumItens() const {
    return 0;
}

std::string Transportador::getConteudo() const {
    return "vazio";
}