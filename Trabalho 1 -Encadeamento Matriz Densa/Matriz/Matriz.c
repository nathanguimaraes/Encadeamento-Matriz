#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

// Função para criar matriz densa
Matriz* criarMatriz(int linhas, int colunas) {
    Matriz *matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->elementos = (No***)malloc(linhas * sizeof(No**));

    for (int i = 0; i < linhas; i++) {
        matriz->elementos[i] = (No**)malloc(colunas * sizeof(No*));
        for (int j = 0; j < colunas; j++) {
            matriz->elementos[i][j] = (No*)malloc(sizeof(No));
            matriz->elementos[i][j]->valor = 0; //definido valores
            matriz->elementos[i][j]->anterior = NULL;
            matriz->elementos[i][j]->proximo = NULL;
        }
    }

    return matriz;
}

// Função para inserir um elemento na matriz
void inserirElemento(Matriz *matriz, int linha, int coluna, int valor) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        matriz->elementos[linha][coluna]->valor = valor;
    } else {
        printf("Posicao invalida.\n");
    }
}



//Função para remover um elemento da matriz
void removerElemento(Matriz *matriz, int linha, int coluna) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        matriz->elementos[linha][coluna]->valor = 0; // Definindo como 0 para representar remoção
    } else {
        printf("Posicao invalida.\n");
    }
}



// Função para imprimir a matriz
void imprimirMatriz(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d ", matriz->elementos[i][j]->valor);
        }
        printf("\n");
    }
}


// Função para exibir os vizinhos de um elemento
void exibirVizinhos(Matriz *matriz, int linha, int coluna) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        printf("Vizinhos do elemento na posicao (%d, %d):\n", linha, coluna);

        if (linha > 0) // Elemento acima
            printf("Acima: %d\n", matriz->elementos[linha-1][coluna]->valor);   //teste
        if (linha < matriz->linhas - 1) // Elemento abaixo
            printf("Abaixo: %d\n", matriz->elementos[linha+1][coluna]->valor);
        if (coluna > 0) // Elemento à esquerda
            printf("Esquerda: %d\n", matriz->elementos[linha][coluna-1]->valor);
             //printf("Esquerda: %d\n", matriz->elementos[linha][coluna-2]->valor)
        if (coluna < matriz->colunas - 1) // Elemento à direita
            printf("Direita: %d\n", matriz->elementos[linha][coluna+1]->valor);

    } else {
        printf("Posicao invalida.\n");
    }
}
// Função para destruir a matriz e liberar memória
void destruirMatriz(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            free(matriz->elementos[i][j]);
        }
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
    free(matriz);
}
