#include "itens/Item.h"
#include "Settings.h"

Item::Item() : instante_recebido(0) {}

Item::~Item() {}

int Item::getInstanteRecebido() const {
    return instante_recebido;
}

void Item::setInstanteRecebido(int instante) {
    instante_recebido = instante;
}

std::string MinerioFerro::getNome() const {
    return "Minerio de ferro";
}

char MinerioFerro::getCaracter() const {
    return 'f';
}

int MinerioFerro::getValor() const {
    return Settings::valor_minerio_ferro;
}

std::string SilicioBruto::getNome() const {
    return "Silicio bruto";
}

char SilicioBruto::getCaracter() const {
    return 's';
}

int SilicioBruto::getValor() const {
    return Settings::valor_silicio_bruto;
}

std::string Gelo::getNome() const {
    return "Gelo";
}

char Gelo::getCaracter() const {
    return 'g';
}

int Gelo::getValor() const {
    return Settings::valor_gelo;
}

std::string PlacaFerro::getNome() const {
    return "Placa de ferro";
}

char PlacaFerro::getCaracter() const {
    return 'p';
}

int PlacaFerro::getValor() const {
    return Settings::valor_placa_ferro;
}

std::string SilicioPuro::getNome() const {
    return "Silicio puro";
}

char SilicioPuro::getCaracter() const {
    return 'i';
}

int SilicioPuro::getValor() const {
    return Settings::valor_silicio_puro;
}

std::string Agua::getNome() const {
    return "Agua";
}

char Agua::getCaracter() const {
    return 'a';
}

int Agua::getValor() const {
    return Settings::valor_agua;
}

std::string KitHabitat::getNome() const {
    return "Kit de habitat";
}

char KitHabitat::getCaracter() const {
    return 'k';
}

int KitHabitat::getValor() const {
    return Settings::valor_kit_habitat;
}