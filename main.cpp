#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Ecra.h"
#include "Settings.h"
#include "Fabrica.h"

int main() {
    srand((unsigned int)time(NULL));

    Ecra ecra(Settings::ecra_max_linhas, Settings::ecra_max_colunas);

    Fabrica fabrica(15, 20);

    bool a_executar = true;
    std::string linha_input;

    while (a_executar) {
        ecra.limpa();

        fabrica.desenha(ecra);

        int col_painel = 2 + fabrica.getColunas() + 2 + 4;
        ecra.desenhaMoldura(2, col_painel, 12, 32);

        ecra.escreveString(3, col_painel + 2, "Instante: 0");
        ecra.escreveString(4, col_painel + 2, "Creditos: " + std::to_string(Settings::fabrica_creditos_iniciais));
        ecra.escreveString(5, col_painel + 2, "Maquinas: 0");
        ecra.escreveString(6, col_painel + 2, "Engenheiros: 0");
        ecra.escreveString(8, col_painel + 2, "No ultimo instante:");
        ecra.escreveString(9, col_painel + 2, "(sem eventos)");

        ecra.mostra();

        std::cout << "\nComandos disponiveis nesta fase: 'lposicao <lc>' ou 'fim'\n> ";
        if (!std::getline(std::cin, linha_input)) {
            break; // Proteção caso o utilizador faça Ctrl+D / EOF
        }

        std::istringstream iss(linha_input);
        std::string comando;
        iss >> comando;

        if (comando.empty()) continue;

        if (comando == "fim") {
            a_executar = false;
            std::cout << "A encerrar o simulador de forma limpa...\n";
        }
        else if (comando == "lposicao") {
            std::string pos, extra;
            if (!(iss >> pos) || (iss >> extra) || pos.length() != 2) {
                std::cout << "=> ERRO: Sintaxe correta: lposicao <linha><coluna> (ex: lposicao ac)\n";
            } else {
                int linha = pos[0] - 'a';
                int coluna = pos[1] - 'a';

                Terreno* t = fabrica.getTerreno(linha, coluna);
                if (t != nullptr) {
                    std::cout << "=> Terreno na posicao " << pos << ": " << t->getDescricao() << "\n";
                } else {
                    std::cout << "=> Posicao invalida ou fora dos limites da fabrica.\n";
                }
            }

            std::cout << "(Pressione ENTER para continuar)";
            std::string pausa;
            std::getline(std::cin, pausa);
        }
        else {
            std::cout << "=> Comando nao reconhecido nesta fase.\n";
            std::cout << "(Pressione ENTER para continuar)";
            std::string pausa;
            std::getline(std::cin, pausa);
        }
    }

    return 0;
}