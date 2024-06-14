#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no {
  int valor;
  struct no *proximo;
} No;

typedef struct {
  No *topo;
  int tamanho;
} Pilha;

void inicializarPilha(Pilha *pilha) {
  pilha->topo    = NULL;
  pilha->tamanho = 0;
}

void empilhar(int valor, Pilha *pilha) {
  No *novoNo      = malloc(sizeof(No));
  novoNo->valor   = valor;
  if (pilha->tamanho == 0){
    novoNo->proximo = NULL;
  }else{
    novoNo->proximo = pilha->topo;}
    
  pilha->topo = novoNo;
  pilha->tamanho++;
}

void exibir(Pilha *pilha) {
  No *temporario;
  temporario = pilha->topo;
  printf("Exibindo PILHA c/ %i Itens: \n", pilha->tamanho);
  int i = pilha->tamanho;
  while (i > 0) {
    printf("Item: %i | Valor: [ %i ]\n", i, temporario->valor);
    temporario = temporario->proximo;
    i--;
  }
}

void desempilhar(Pilha *pilha) {
  if (pilha->tamanho == 0) {
    printf("Pilha Está Vazia\n");
  } else {
    printf("[ %d ] Desempilhado\n", pilha->topo->valor);
    pilha->tamanho--;
    pilha->topo = pilha->topo->proximo;
  }
}

void limparPilha(Pilha *pilha) {
  printf("Limpando Pilha\n");
  No *temporario;
  temporario = pilha->topo;
  while (temporario->proximo != NULL) {
    printf("Liberando Recursos Alocados para Nó [%i] em %p\n", temporario->valor, temporario);
    free(temporario);
    temporario = temporario->proximo;
  }
}

int main() {
  Pilha pilha;
  inicializarPilha(&pilha);
  int novoItem;
  int opcao;
  while (opcao != 5) {
    printf("Escolha uma Opção\n");
    printf("1) Exibir Pilha\n");
    printf("2) Empilhar Item na Pilha\n");
    printf("3) Desempilhar Item da Pilha\n");
    printf("4) Esvaziar Pilha\n");
    printf("5) Sair do Programa\n");
    scanf("%i", &opcao);
    if (opcao == 1) exibir(&pilha);
    if (opcao == 2) {
      printf("Digite um Número Inteiro: \n");
      scanf("%i", &novoItem);
      empilhar(novoItem, &pilha);
    }
    if (opcao == 3) desempilhar(&pilha);
    if (opcao == 4) {
      limparPilha(&pilha);
      inicializarPilha(&pilha);
      printf("Pilha Está Vazia\n");
    }
    if (opcao == 5) limparPilha(&pilha);
  }
  printf("Programa Finalizado"); 
  return 0;
} 