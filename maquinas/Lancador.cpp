//
// Created by rafao on 20/11/2026.
//

#include "maquinas/Lancador.h"
#include "Settings.h"

Lancador::Lancador(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::lancador_custo, 'L') {}

std::string Lancador::getNome() const {
    return "Lancador";
}

bool Lancador::aceita(const Item&) const {
    return false;  //...
}

void Lancador::recebe(Item*, int) {
    //...
}

void Lancador::atua(Fabrica&) {
    //...
}

int Lancador::getNumItens() const {
    return 0;
}

std::string Lancador::getConteudo() const {
    return "vazia";
}
