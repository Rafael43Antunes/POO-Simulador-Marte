#include <iostream>
#include "comandos/ComandoCompra.h"
#include "simulador/Simulador.h"
#include "maquinas/Maquina.h"

void ComandoCompra::executa(Simulador& sim, std::istringstream& args) {
    std::string texto_tipo, texto_pos, texto_dir, extra;
    int linha = 0, coluna = 0;
    Direcao dir = Direcao::Cima;

    if (!(args >> texto_tipo >> texto_pos >> texto_dir) || (args >> extra)) {
        erroSintaxe();
        return;
    }

    if (texto_tipo.size() != 1 || Maquina::custoDoTipo(texto_tipo[0]) < 0) {
        std::cout << "Erro: tipo invalido (use p, t, r, o, s ou l).\n";
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
    Fabrica* fabrica = sim.getFabrica();

    Terreno* terreno = fabrica->getTerreno(linha, coluna);
    if (terreno == nullptr) {
        std::cout << "Erro: posicao fora dos limites da fabrica.\n";
        return;
    }
    if (!terreno->aceitaMaquinas()) {
        std::cout << "Erro: nao e possivel colocar uma maquina numa cratera.\n";
        return;
    }
    if (fabrica->getMaquina(linha, coluna) != nullptr) {
        std::cout << "Erro: a posicao " << texto_pos << " ja esta ocupada.\n";
        return;
    }

    int custo = Maquina::custoDoTipo(texto_tipo[0]);
    if (fabrica->getCreditos() < custo) {
        std::cout << "Erro: creditos insuficientes (custo " << custo
                  << ", tem " << fabrica->getCreditos() << ").\n";
        return;
    }

    Maquina* nova = Maquina::cria(texto_tipo[0], linha, coluna, dir);
    fabrica->colocaMaquina(nova);
    fabrica->alteraCreditos(-custo);

    std::cout << "Comprou " << nova->getNome() << " em " << texto_pos << " por " << custo << " creditos.\n";
    sim.mostraEcra();
}

std::string ComandoCompra::getSintaxe() const {
    return "compra <tipo> <lc> <dir>";
}

std::string ComandoCompra::getAjuda() const {
    return "compra <tipo> <lc> <dir>\n"
           "  Compra uma maquina do tipo indicado e coloca-a na posicao <lc> com a direcao de saida <dir>.\n"
           "  <tipo>: p (perfuradora), t (transportador), r (refinaria), o (oficina), s (silo), l (lancador).\n"
           "  <lc>: posicao (linha e coluna, em letras). <dir>: c (cima), b (baixo), e (esquerda) ou d (direita).\n"
           "  Falha se a posicao estiver ocupada, for uma cratera ou estiver fora da fabrica,\n"
           "  ou se nao houver creditos suficientes.\n"
           "  Exemplo: compra t ce d";
}