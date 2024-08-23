#include <stdio.h>
#include "Matriz.h"

int main() {
    //Criando matriz (x, y)
    Matriz *matriz = criarMatriz(3, 3);

    //Inserindo elementos na matriz
    inserirElemento(matriz, 0, 0, 10);
    inserirElemento(matriz, 0, 1, 20);
    inserirElemento(matriz, 0, 2, 30);
    inserirElemento(matriz, 1, 0, 40);
    inserirElemento(matriz, 1, 1, 50);
    inserirElemento(matriz, 1, 2, 60);
    inserirElemento(matriz, 2, 0, 70);
    inserirElemento(matriz, 2, 1, 80);
    inserirElemento(matriz, 2, 2, 90);

    //Imprimindo a matriz
    printf("Matriz 3x3:\n");
    imprimirMatriz(matriz);

    //Exibindo os vizinhos dado uma posicao
    printf("\nVizinhos do elemento na posicao (1, 1):\n");
    exibirVizinhos(matriz, 1, 1);

    // Removendo o elemento
    printf("\nRemovendo o elemento da posicao (1, 1)...\n");
    //teste
    removerElemento(matriz, 1, 1);

    // Imprimindo a matriz
    printf("Matriz apos a remocao:\n");
    imprimirMatriz(matriz);


    // Destruindo a matriz e liberando a memória
    destruirMatriz(matriz);

    return 0;
}
