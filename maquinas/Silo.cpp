#include <cstdlib>
#include "maquinas/Silo.h"
#include "simulador/Fabrica.h"
#include "Settings.h"

Silo::Silo(int l, int c, Direcao dir)
    : Maquina(l, c, dir, Settings::silo_custo, 'S'),
      primeiro(nullptr), ultimo(nullptr), total(0), prob_perda(Settings::silo_prob_perda) {}

// Os itens que ainda estiverem no silo perdem-se
Silo::~Silo() {
    while (primeiro != nullptr) {
        delete retiraMaisAntigo();
    }
}

std::string Silo::getNome() const {
    return "Silo";
}

void Silo::acrescenta(Item* item) {
    No* novo = new No{item, nullptr};

    if (ultimo == nullptr) {
        primeiro = novo;
    } else {
        ultimo->seguinte = novo;
    }
    ultimo = novo;
    total++;
}

Item* Silo::retiraMaisAntigo() {
    if (primeiro == nullptr) {
        return nullptr;
    }

    No* no = primeiro;
    Item* item = no->item;

    primeiro = no->seguinte;
    if (primeiro == nullptr) {
        ultimo = nullptr;
    }

    delete no;
    total--;
    return item;
}

bool Silo::aceita(const Item&) const {
    return true;   // sem limite de capacidade, aceita qualquer item
}

void Silo::recebe(Item* item, int instante) {
    item->setInstanteRecebido(instante);
    acrescenta(item);
}

void Silo::atua(Fabrica& fabrica) {
    if (primeiro == nullptr) {
        return;
    }

    if (std::rand() % 100 < prob_perda) {
        delete retiraMaisAntigo();
        fabrica.regista("silo em " + Fabrica::posicaoParaTexto(getLinha(), getColuna()) + " perdeu item");

        if (primeiro == nullptr) {
            return;
        }
    }

    if (primeiro->item->getInstanteRecebido() >= fabrica.getInstante()) {
        return;
    }

    if (tentaEntregar(fabrica, primeiro->item)) {
        retiraMaisAntigo();   
    }
}

int Silo::getNumItens() const {
    return total;
}

std::string Silo::getConteudo() const {
    if (total == 0) {
        return "vazio";
    }
    return std::to_string(total) + (total == 1 ? " item" : " itens");
}

std::string Silo::getDetalhes() const {
    std::string texto = "probabilidade de perda: " + std::to_string(prob_perda) + "%; itens (do mais antigo): ";

    if (total == 0) {
        return texto + "nenhum";
    }

    for (No* no = primeiro; no != nullptr; no = no->seguinte) {
        texto += no->item->getCaracter();
        if (no->seguinte != nullptr) texto += ' ';
    }
    return texto;
}

int Silo::getProbPerda() const {
    return prob_perda;
}
