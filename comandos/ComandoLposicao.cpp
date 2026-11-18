#include <iostream>
#include "comandos/ComandoLposicao.h"
#include "simulador/Simulador.h"

void ComandoLposicao::executa(Simulador& sim, std::istringstream& args) {
    std::string pos, texto_n, extra;
    int n = 0;

    if (!(args >> pos) || pos.size() != 2 ||
        pos[0] < 'a' || pos[0] > 'z' || pos[1] < 'a' || pos[1] > 'z') {
        std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
        return;
    }

    if (args >> texto_n) {
        std::istringstream conversao(texto_n);
        char lixo;
        if (!(conversao >> n) || (conversao >> lixo) || n < 0) {
            std::cout << "Erro: n deve ser um inteiro nao negativo.\n";
            return;
        }
    }

    if (args >> extra) {
        std::cout << "Erro de sintaxe. Use: " << getSintaxe() << "\n";
        return;
    }

    // Validar o estado: a fabrica tem de existir e a posicao de estar dentro dela
    Fabrica* fabrica = sim.getFabrica();
    if (fabrica == nullptr) {
        std::cout << "Erro: a fabrica ainda nao foi criada.\n";
        return;
    }

    int linha = pos[0] - 'a';
    int coluna = pos[1] - 'a';

    if (fabrica->getTerreno(linha, coluna) == nullptr) {
        std::cout << "Erro: posicao fora dos limites da fabrica.\n";
        return;
    }

    //Executar: mostra a posicao e, se n > 0, o quadrado de raio n à volta dela
    for (int l = linha - n; l <= linha + n; ++l) {
        for (int c = coluna - n; c <= coluna + n; ++c) {
            Terreno* t = fabrica->getTerreno(l, c);
            if (t != nullptr) {
                std::cout << static_cast<char>('a' + l) << static_cast<char>('a' + c)
                          << ": " << t->getDescricao() << "\n";
            }
        }
    }
}

std::string ComandoLposicao::getSintaxe() const {
    return "lposicao <lc> [n]";
}

std::string ComandoLposicao::getAjuda() const {
    return "lposicao <lc> [n]\n"
           "  Mostra a informacao da posicao <lc> (linha e coluna em letras).\n"
           "  Se for indicado n, mostra todas as posicoes do quadrado de raio n centrado em <lc>.\n"
           "  Falha se a fabrica nao existir, se a posicao estiver fora dos limites\n"
           "  ou se n nao for negativo.\n"
           "  Exemplo: lposicao df 2";
}