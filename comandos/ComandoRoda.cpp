#include <iostream>
#include "comandos/ComandoRoda.h"
#include "simulador/Simulador.h"
#include "maquinas/Maquina.h"

void ComandoRoda::executa(Simulador& sim, std::istringstream& args) {
    std::string texto_pos, texto_dir, extra;
    int linha = 0, coluna = 0;
    Direcao dir = Direcao::Cima;

    if (!(args >> texto_pos >> texto_dir) || (args >> extra)) {
        erroSintaxe();
        return;
    }
    if (!lePosicao(texto_pos, linha, coluna)) {
        std::cout << "Erro: a posicao deve ter 2 letras minusculas (por exemplo ce).\n";
        return;
    }
    if (!leDirecao(texto_dir, dir)) {
        std::cout << "Erro: a direcao deve ser c, b, e ou d.\n";
        return;
    }

    if (!fabricaExiste(sim)) return;

    Maquina* maquina = sim.getFabrica()->getMaquina(linha, coluna);
    if (maquina == nullptr) {
        std::cout << "Erro: nao existe nenhuma maquina em " << texto_pos << ".\n";
        return;
    }

    maquina->setDirecao(dir);
    std::cout << maquina->getNome() << " em " << texto_pos << " passou a ter a direcao " << texto_dir << ".\n";
    sim.mostraEcra();
}

std::string ComandoRoda::getSintaxe() const {
    return "roda <lc> <dir>";
}

std::string ComandoRoda::getAjuda() const {
    return "roda <lc> <dir>\n"
           "  Muda a direcao de saida da maquina que se encontra na posicao <lc>.\n"
           "  <dir>: c (cima), b (baixo), e (esquerda) ou d (direita).\n"
           "  Falha se a posicao for invalida ou nao tiver nenhuma maquina.\n"
           "  Exemplo: roda ce b";
}
