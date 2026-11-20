//
// Created by rafao on 20/11/2026.
//

#include "maquinas/Oficina.h"
#include "Settings.h"

Oficina::Oficina(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::oficina_custo, 'O') {}

std::string Oficina::getNome() const {
    return "Oficina";
}

bool Oficina::aceita(const Item&) const {
    return false;  //...
}

void Oficina::recebe(Item*, int) {
    //...
}

void Oficina::atua(Fabrica&) {
    //...
}

int Oficina::getNumItens() const {
    return 0;
}

std::string Oficina::getConteudo() const {
    return "vazia";
}
