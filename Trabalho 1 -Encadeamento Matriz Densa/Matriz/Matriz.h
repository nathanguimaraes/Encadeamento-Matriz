
// Definição do nó da lista duplamente encadeada
typedef struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

// Definição da matriz densa
typedef struct {
    No ***elementos;
    int linhas;
    int colunas;
} Matriz;

// Funções para manipulação da matriz
Matriz* criarMatriz(int linhas, int colunas);
void inserirElemento(Matriz *matriz, int linha, int coluna, int valor);
void removerElemento(Matriz *matriz, int linha, int coluna);
void imprimirMatriz(Matriz *matriz);
void exibirVizinhos(Matriz *matriz, int linha, int coluna);
void destruirMatriz(Matriz *matriz);
