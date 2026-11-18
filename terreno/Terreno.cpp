#include "Terreno.h"

std::string Terreno::getDescricao() const {
    return getNome();
}

bool Terreno::isSolo() const {
    return false;
}

bool Terreno::isEsgotado() const {
    return false;
}

// --- Solo ---
char Solo::getCaracterVisual() const {
    return ' ';
}

bool Solo::aceitaMaquinas() const {
    return true;
}

std::string Solo::getNome() const {
    return "Solo";
}

bool Solo::isSolo() const {
    return true;
}

// Cratera
char Cratera::getCaracterVisual() const {
    return '#';
}

bool Cratera::aceitaMaquinas() const {
    return false;
}

std::string Cratera::getNome() const {
    return "Cratera";
}

// Deposito
Deposito::Deposito(char tipo, int qtd) : tipo_material(tipo), quantidade(qtd) {}

char Deposito::getCaracterVisual() const {
    return tipo_material;
}

bool Deposito::aceitaMaquinas() const {
    return true;
}

std::string Deposito::getNome() const {
    if (tipo_material == '%') return "Deposito de minerio de ferro";
    if (tipo_material == '$') return "Deposito de silicio bruto";
    if (tipo_material == '~') return "Deposito de gelo";
    return "Deposito";
}

std::string Deposito::getDescricao() const {
    return getNome() + " (quantidade: " + std::to_string(quantidade) + ")";
}

bool Deposito::isEsgotado() const {
    return quantidade <= 0;
}

int Deposito::getQuantidade() const {
    return quantidade;
}