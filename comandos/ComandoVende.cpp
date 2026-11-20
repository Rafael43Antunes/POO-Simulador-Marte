#include <iostream>
#include "comandos/ComandoVende.h"
#include "simulador/Simulador.h"
#include "maquinas/Maquina.h"
#include "Settings.h"

void ComandoVende::executa(Simulador& sim, std::istringstream& args) {
    std::string texto_pos, extra;
    int linha = 0, coluna = 0;

    if (!(args >> texto_pos) || (args >> extra)) {
        erroSintaxe();
        return;
    }
    if (!lePosicao(texto_pos, linha, coluna)) {
        std::cout << "Erro: a posicao deve ter 2 letras minusculas (por exemplo ce).\n";
        return;
    }

    if (!fabricaExiste(sim)) return;
    Fabrica* fabrica = sim.getFabrica();

    Maquina* maquina = fabrica->getMaquina(linha, coluna);
    if (maquina == nullptr) {
        std::cout << "Erro: nao existe nenhuma maquina em " << texto_pos << ".\n";
        return;
    }

    int valor = maquina->getCusto() * Settings::maquina_percentagem_venda / 100;
    std::string nome = maquina->getNome();

    fabrica->removeMaquina(linha, coluna);
    fabrica->alteraCreditos(valor);

    std::cout << "Vendeu " << nome << " em " << texto_pos << " por " << valor << " creditos.\n";
    sim.mostraEcra();
}

std::string ComandoVende::getSintaxe() const {
    return "vende <lc>";
}

std::string ComandoVende::getAjuda() const {
    return "vende <lc>\n"
           "  Vende a maquina que se encontra na posicao <lc>. A fabrica recebe 50% do custo de compra.\n"
           "  Os itens que a maquina tiver no interior perdem-se.\n"
           "  Falha se a posicao for invalida ou nao tiver nenhuma maquina.\n"
           "  Exemplo: vende ce";
}