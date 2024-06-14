#include <stdio.h>
#include <string.h>

typedef struct no_pilha no_pilha;

struct no_pilha{
int valor;
no_pilha *proximo;
};

typedef struct {
no_pilha* topo;
int tamanho;
} minha_pilha;

int conta_impares_pilha(minha_pilha *p){
    int conta_impar = 0;

    if (p == NULL && p->topo == NULL){
        printf("A pilha esta sem impares\n");
        return 0;
    }

    for (no_pilha *aux = p->topo; aux != NULL; aux = aux->proximo){
        if ((aux->valor % 2) == 1){
        conta_impar++;
        }
    }
    return conta_impar;
}

void exibir(minha_pilha *pilha) {
  no_pilha *temporario;
  temporario = pilha->topo;
  printf("Exibindo PILHA c/ %i Itens: \n", pilha->tamanho);
  int i = pilha->tamanho;
  while (i > 0) {
    printf("Item: %i | Valor: [ %i ]\n", i, temporario->valor);
    temporario = temporario->proximo;
    i--;
  } 
}

int main(){

    return 0;
}