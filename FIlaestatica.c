#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 10

typedef struct {
    int inicio;
    int fim;
    int array[TAMANHO];
    int quantidade_de_elementos;
} Fila;

void Iniciazia(Fila *fila){
    fila->quantidade_de_elementos = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

void PushFila(Fila *fila){
    int valor;
    printf("Digite um Número para add na fila: \n");
    scanf("%i", &valor);

    fila->fim++;
    fila->array[fila->fim] = valor;
    fila->quantidade_de_elementos++;

} 

void ImprimeFila(Fila *fila){
    printf("Fila:\n");
    for (int i = fila->inicio; i <= fila->fim; i++){
        printf("%d ", fila->array[i]);
    }
    printf("\n");
}

void Desenfileirar(Fila *fila){
    fila->inicio++;
    fila->quantidade_de_elementos--;
}

int main(){
Fila fila;

Iniciazia(&fila);

PushFila(&fila);
PushFila(&fila);
PushFila(&fila);

ImprimeFila(&fila);
Desenfileirar(&fila);

ImprimeFila(&fila);
PushFila(&fila);

ImprimeFila(&fila);
    return 0;
}