#include "maquinas/Refinaria.h"
#include "Settings.h"

Refinaria::Refinaria(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::refinaria_custo, 'R') {}

std::string Refinaria::getNome() const {
    return "Refinaria";
}

bool Refinaria::aceita(const Item&) const {
    return false;  //...
}

void Refinaria::recebe(Item*, int) {
    //...
}

void Refinaria::atua(Fabrica&) {
    //...
}

int Refinaria::getNumItens() const {
    return 0;
}

std::string Refinaria::getConteudo() const {
    return "vazia";
}
