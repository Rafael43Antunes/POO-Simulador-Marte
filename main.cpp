#include <iostream>
#include <string>
#include "Ecra.h"
#include "Settings.h"
#include "Fabrica.h"

int main() {
    Ecra ecra(Settings::ecra_max_linhas, Settings::ecra_max_colunas);

    Fabrica fabrica(15,20);

    bool a_executar = true;
    std::string comando;

    while (a_executar) {
        ecra.limpa();

        fabrica.desenha(ecra);

        int col_painel = 2 + (fabrica.getColunas() * 2) + 2 + 4;
        ecra.desenhaMoldura(2, col_painel, 10, 30);

        ecra.posicionaCursor(3, col_painel + 2);
        ecra.escreveString("Instante: 0"); // Fixo por agora

        ecra.posicionaCursor(5, col_painel + 2);
        ecra.escreveString("Creditos: " + std::to_string(Settings::fabrica_creditos_iniciais));

        ecra.posicionaCursor(7, col_painel + 2);
        ecra.escreveString("Maquinas: 0"); // Fixo por agora

        ecra.mostra();

        std::cout << "\nComandos disponiveis nesta fase: 'lposicao' ou 'fim'\n";
        std::cout << "> ";
        std::cin >> comando;

        if (comando == "fim") {
            a_executar = false;
            std::cout << "A encerrar o simulador de forma limpa...\n";
        }
        else if (comando == "lposicao") {
            std::string pos;
            std::cin >> pos;

            if (pos.length() >= 2) {
                int linha = pos[0] - 'a';
                int coluna = pos[1] - 'a';

                Terreno* t = fabrica.getTerreno(linha, coluna);
                if (t != nullptr) {
                    std::cout << "=> Terreno na posicao " << pos << ": '"
                              << t->getCaracterVisual() << "'\n";
                } else {
                    std::cout << "=> Posicao invalida ou fora dos limites.\n";
                }
            }else {
                std::cout << "Erro de sintaxe: Use 2 letras para a posicao (por ex: ac).\n";
            }

            std::cout << "(Pressione ENTER para continuar)";
            std::cin.ignore();
            std::cin.get();
        }
        else {
            std::cout << "Comando nao reconhecido nesta fase.\n";
        }

    }

    return 0;

}