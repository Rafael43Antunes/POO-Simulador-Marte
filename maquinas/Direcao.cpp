#include "maquinas/Direcao.h"

bool charParaDirecao(char c, Direcao& dir) {
    switch (c) {
        case 'c': dir = Direcao::Cima;     return true;
        case 'b': dir = Direcao::Baixo;    return true;
        case 'e': dir = Direcao::Esquerda; return true;
        case 'd': dir = Direcao::Direita;  return true;
        default:  return false;
    }
}

char direcaoParaChar(Direcao dir) {
    switch (dir) {
        case Direcao::Cima:     return 'c';
        case Direcao::Baixo:    return 'b';
        case Direcao::Esquerda: return 'e';
        case Direcao::Direita:  return 'd';
    }
    return '?';
}

int deltaLinha(Direcao dir) {
    if (dir == Direcao::Cima) return -1;
    if (dir == Direcao::Baixo) return 1;
    return 0;
}

int deltaColuna(Direcao dir) {
    if (dir == Direcao::Esquerda) return -1;
    if (dir == Direcao::Direita) return 1;
    return 0;
}