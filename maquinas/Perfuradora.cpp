#include "maquinas/Perfuradora.h"
#include "Settings.h"

Perfuradora::Perfuradora(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::perfuradora_custo, 'P') {}

std::string Perfuradora::getNome() const {
    return "Perfuradora";
}

bool Perfuradora::aceita(const Item&) const {
    return false;  //...
}

void Perfuradora::recebe(Item*, int) {
    //...
}

void Perfuradora::atua(Fabrica&) {
    //...
}

int Perfuradora::getNumItens() const {
    return 0;
}

std::string Perfuradora::getConteudo() const {
    return "vazia";
}