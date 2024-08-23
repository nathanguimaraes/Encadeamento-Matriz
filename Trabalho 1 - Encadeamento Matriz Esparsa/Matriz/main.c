#include <stdio.h>
#include "Matriz.h"

int main() {
    // Cria uma matriz esparsa
    MatrizEsparsa* matriz = criaMatriz();

    // inserindo 20 elementos na matriz esparsa
     insereElemento(matriz, 0, 0, 5);
     insereElemento(matriz, 0, 1, 10);
     insereElemento(matriz, 0, 2, 15);
     insereElemento(matriz, 0, 3, 20);
     insereElemento(matriz, 0, 4, 25);
     insereElemento(matriz, 1, 0, 30);
     insereElemento(matriz, 1, 1, 35);
     insereElemento(matriz, 1, 2, 40);
     insereElemento(matriz, 1, 3, 45);
     insereElemento(matriz, 1, 4, 50);
     insereElemento(matriz, 2, 0, 55);
     insereElemento(matriz, 2, 1, 60);
     insereElemento(matriz, 2, 2, 65);
     insereElemento(matriz, 2, 3, 70);
     insereElemento(matriz, 2, 4, 75);
     insereElemento(matriz, 3, 0, 80);
     insereElemento(matriz, 3, 1, 85);
     insereElemento(matriz, 3, 2, 90);
     insereElemento(matriz, 3, 3, 95);
     insereElemento(matriz, 3, 4, 100);
     insereElemento(matriz, 4, 5, 100);


    // dados fornecidos no exemplo do trabalho
    //insereElemento(matriz, 1, 1, 50);
    //insereElemento(matriz, 2, 1, 10);
    //insereElemento(matriz, 2, 3, 20);
    //insereElemento(matriz, 4, 1, -30);
    //insereElemento(matriz, 4, 3, -60);
    //insereElemento(matriz, 4, 4, 5);


        // Imprime a matriz esparsa
    imprimeMatriz(matriz);

    printf("\n \n");

    // Exibe os vizinhos do elemento na posição (2, 1)
    exibeVizinhos(matriz, 2, 1);

    // Exibe os vizinhos do elemento na posição (2, 3)
    exibeVizinhos(matriz, 2, 3);

    // Exibe os vizinhos do elemento na posição (4, 3)
    exibeVizinhos(matriz, 4, 3);

    removeElemento(matriz, 2, 3);

    imprimeMatriz(matriz);





    // Destrói a matriz esparsa e libera memória
    destroiMatriz(matriz);

    return 0;
}
