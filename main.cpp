#include <iostream>
#include <string>
#include "Ecra.h"
#include "Settings.h"

int main() {
    Ecra ecra(Settings::ecra_max_linhas, Settings::ecra_max_colunas);

    ecra.limpa();

    ecra.desenhaMoldura(2, 2, 10, 40);

    ecra.posicionaCursor(4, 5);
    ecra.escreveString("Simulador de Marte - POO 26/27");

    ecra.posicionaCursor(6, 5);
    ecra.escreveString("Creditos Iniciais: ");

    ecra.escreveString(std::to_string(Settings::fabrica_creditos_iniciais));

    ecra.mostra();

    return 0;

}