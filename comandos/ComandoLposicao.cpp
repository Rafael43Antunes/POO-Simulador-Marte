#include <iostream>
#include "comandos/ComandoLposicao.h"
#include "simulador/Simulador.h"
#include "maquinas/Maquina.h"

void ComandoLposicao::executa(Simulador& sim, std::istringstream& args) {
    std::string pos, texto_n, extra;
    int linha = 0, coluna = 0, n = 0;

    if (!(args >> pos) || !lePosicao(pos, linha, coluna)) {
        erroSintaxe();
        return;
    }

    if (args >> texto_n) {
        if (!leInteiro(texto_n, n) || n < 0) {
            std::cout << "Erro: n deve ser um inteiro nao negativo.\n";
            return;
        }
        if (args >> extra) {
            erroSintaxe();
            return;
        }
    }

    if (!fabricaExiste(sim)) return;
    Fabrica* fabrica = sim.getFabrica();

    if (fabrica->getTerreno(linha, coluna) == nullptr) {
        std::cout << "Erro: posicao fora dos limites da fabrica.\n";
        return;
    }

    for (int l = linha - n; l <= linha + n; ++l) {
        for (int c = coluna - n; c <= coluna + n; ++c) {
            Terreno* terreno = fabrica->getTerreno(l, c);   // nullptr se estiver fora
            if (terreno == nullptr) continue;

            std::cout << Fabrica::posicaoParaTexto(l, c) << ": " << terreno->getDescricao() << "\n";

            Maquina* maquina = fabrica->getMaquina(l, c);
            if (maquina != nullptr) {
                std::cout << "    " << maquina->getInfo() << "\n";

                std::string detalhes = maquina->getDetalhes();
                if (!detalhes.empty()) {
                    std::cout << "    " << detalhes << "\n";
                }
            }
        }
    }
}

std::string ComandoLposicao::getSintaxe() const {
    return "lposicao <lc> [n]";
}

std::string ComandoLposicao::getAjuda() const {
    return "lposicao <lc> [n]\n"
           "  Mostra a informacao da posicao <lc> (linha e coluna em letras): o terreno\n"
           "  (e a quantidade, se for um deposito) e a maquina que la estiver, com os\n"
           "  itens e a sua configuracao.\n"
           "  Se for indicado n, mostra todas as posicoes do quadrado de raio n centrado em <lc>.\n"
           "  Falha se a fabrica nao existir, se a posicao estiver fora dos limites\n"
           "  ou se n nao for um inteiro nao negativo.\n"
           "  Exemplo: lposicao df 2";
}