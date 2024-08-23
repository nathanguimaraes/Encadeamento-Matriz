
#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"


MatrizEsparsa* criaMatriz() {
    MatrizEsparsa* matriz = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));
    matriz->cabeca = NULL;
    return matriz;
}

// Função para inserir um elemento na matriz
void insereElemento(MatrizEsparsa* matriz, int linha, int coluna, int valor){
    if (valor == 0)
        return;

    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->valor = valor;
    novoNo->proxLinha = NULL;
    novoNo->proxColuna = NULL;

    if (matriz->cabeca == NULL){
        matriz->cabeca = novoNo;
        return;
    }

    No* atual = matriz->cabeca;
    No* anterior = NULL;

    while(atual != NULL && (atual->linha < linha || (atual->linha == linha && atual->coluna < coluna))){
        anterior = atual;
        atual = atual->proxLinha;
    }

    if(anterior == NULL){
        novoNo->proxLinha = matriz->cabeca;
        matriz->cabeca = novoNo;
    } else {
        anterior->proxLinha = novoNo;
        novoNo->proxLinha = atual;
    }
}

//Função para recuperar o valor de um elemento
int recuperaElemento(MatrizEsparsa* matriz, int linha, int coluna){
    No* atual = matriz->cabeca;
    while (atual != NULL) {     //percorrendo toda a matriz
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->valor;
        }
        atual = atual->proxLinha;
    }
    return 0; //Retorna 0 se o elemento não estiver na matriz
}

//Função para remover um elemento
void removeElemento(MatrizEsparsa* matriz, int linha, int coluna){
    No* atual = matriz->cabeca;
    No* anterior = NULL;

    while (atual != NULL && (atual->linha != linha || atual->coluna != coluna)){
        anterior = atual;
        atual = atual->proxLinha;
    }

    if (atual == NULL)
        return;

    if (anterior == NULL){
        matriz->cabeca = atual->proxLinha;
    } else{
        anterior->proxLinha = atual->proxLinha;
    }
    free(atual); //libera memoria
}

// Função para exibir os elementos vizinhos (acima, direita, esquerda, abaixo)
void exibeVizinhos(MatrizEsparsa* matriz, int linha, int coluna){
    No* atual = matriz->cabeca;
    int acima = 0, abaixo = 0, direita = 0, esquerda = 0;

    while (atual != NULL){
        if (atual->linha == linha - 1 && atual->coluna == coluna){
            acima = atual->valor;
        }
        if (atual->linha == linha + 1 && atual->coluna == coluna){
            abaixo = atual->valor;
        }
        if (atual->linha == linha && atual->coluna == coluna - 1){
            esquerda = atual->valor;
        }
        if (atual->linha == linha && atual->coluna == coluna + 1){
            direita = atual->valor;
        }
        atual = atual->proxLinha;
    }

    printf("Vizinhos da posicao (%d, %d):\n", linha, coluna);
    printf("Acima: %d\n", acima);
    printf("Abaixo: %d\n", abaixo);
    printf("Esquerda: %d\n", esquerda);
    printf("Direita: %d\n", direita);
}

//Função para destruir a matriz esparsa e liberar a memória
void destroiMatriz(MatrizEsparsa* matriz){
    No* atual = matriz->cabeca;
    while (atual != NULL){          //percorre toda a matriz e remove
        No* prox = atual->proxLinha;
        free(atual);
        atual = prox;
    }
    free(matriz); //liberando memoria
}

// Funcao para imprimir a matriz esparsa (apenas elementos nao nulos)
void imprimeMatriz(MatrizEsparsa* matriz) {
    No* atual = matriz->cabeca;
    while (atual != NULL) {
        printf("Elemento na posicao (%d, %d): %d\n", atual->linha, atual->coluna, atual->valor);
        atual = atual->proxLinha;
    }
}

// Função para imprimir uma demonstração visual da matriz esparsa
void imprimeMatrizEsparca(MatrizEsparsa* matriz) {
    int tamanho = 3; // Supondo uma matriz de 3x3 para demonstração
    int matrizVisual[3][3] = {0}; // Inicializando toda a matriz com 0

    No* atual = matriz->cabeca;
    while (atual != NULL) {
        matrizVisual[atual->linha][atual->coluna] = atual->valor;
        atual = atual->proxLinha;
    }

    printf("Matriz Esparsa:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matrizVisual[i][j]);
        }
        printf("\n");
    }
}
