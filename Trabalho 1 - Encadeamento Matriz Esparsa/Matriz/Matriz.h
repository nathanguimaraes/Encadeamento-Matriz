#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct No {
    int linha;
    int coluna;
    int valor;
    struct No* proxLinha;
    struct No* proxColuna;
} No;

typedef struct {
    No* cabeca; // Cabeça da lista principal que armazena os nós da matriz esparsa
} MatrizEsparsa;

// Funções para manipulação da matriz esparsa
MatrizEsparsa* criaMatriz();
void insereElemento(MatrizEsparsa* matriz, int linha, int coluna, int valor);
int recuperaElemento(MatrizEsparsa* matriz, int linha, int coluna);
void removeElemento(MatrizEsparsa* matriz, int linha, int coluna);
void exibeVizinhos(MatrizEsparsa* matriz, int linha, int coluna);
void destroiMatriz(MatrizEsparsa* matriz);
void imprimeMatriz(MatrizEsparsa* matriz);
void imprimeMatrizEsparca(MatrizEsparsa* matriz);

#endif
