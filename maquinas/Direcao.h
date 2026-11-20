#ifndef PROJETO_DIRECAO_H
#define PROJETO_DIRECAO_H

// Direcao de saida de uma maquina: c (cima), b (baixo), e (esquerda), d (direita)
enum class Direcao { Cima, Baixo, Esquerda, Direita };

bool charParaDirecao(char c, Direcao& dir);

char direcaoParaChar(Direcao dir);

// Deslocamento (em linhas e colunas) para a posicao vizinha nessa direcao
int deltaLinha(Direcao dir);
int deltaColuna(Direcao dir);

#endif //PROJETO_DIRECAO_H