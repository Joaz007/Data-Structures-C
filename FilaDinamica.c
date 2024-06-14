#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Definição da estrutura da fila
typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

// Função para criar um novo nó
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para criar uma fila vazia
void criarFila(Fila *fila) {
    fila = malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    fila->inicio = fila->fim = NULL;
    return;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para enfileirar um elemento
void enfileirar(Fila* fila, int dado) {
    No* novoNo = criarNo(dado);
    if (estaVazia(fila)) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}
// Função para excluir a fila
void excluirFila(Fila* fila) {
    No* atual = fila->inicio;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(fila);
}

// Função para desenfileirar um elemento
int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        exit(1);
    }
    int dado = fila->inicio->dado;
    No* temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(temp);
    return dado;
}

// Função para exibir o elemento na frente da fila
int frente(Fila* fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        exit(1);
    }
    return fila->inicio->dado;
}

// Função principal
int main() {
    Fila fila;
    criarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    printf("Desenfileirando: %d\n", desenfileirar(&fila));
    printf("Desenfileirando: %d\n", desenfileirar(&fila));

    printf("Elemento na inicio da fila: %d\n", inicio(&fila));

    enfileirar(&fila, 40);

    printf("Elemento na inicio da fila: %d\n", inicio(&fila));

    excluirFila(&fila);

    return 0;
}
