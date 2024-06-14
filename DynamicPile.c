#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
  int valor;    //item do nó
  struct No *proximo; //ptr proximo nó 
} No;

typedef struct {
  No *topo; //Ultimo elemento inserido
  int tamanho; //Tamanho da pilha
} PilhaDinamica;

void inicializarPilha(PilhaDinamica *pilha) {
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

void empilhar(int valor, PilhaDinamica *pilha) {
  No *novoNo = malloc(sizeof(No));
  novoNo->valor = valor;
  if (pilha->tamanho == 0)
    novoNo->proximo = NULL;
  else
    novoNo->proximo = pilha->topo;
  pilha->topo = novoNo;
  pilha->tamanho++;
}

void exibir(PilhaDinamica *pilha) {
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

void desempilhar(PilhaDinamica *pilha) {
  if (pilha->tamanho == 0) {
    printf("PilhaDinamica Está Vazia\n");
  } else {
    printf("[ %d ] Desempilhado\n", pilha->topo->valor);
    pilha->tamanho--;
    pilha->topo = pilha->topo->proximo;
  }
}

void limparPilha(PilhaDinamica *pilha) {
  printf("Limpando PilhaDinamica\n");
  No *temporario;
  temporario = pilha->topo;
  while (temporario != NULL) {
    printf("Liberando Recursos Alocados para Nó [%i] em %p\n", temporario->valor, temporario);
    free(temporario);
    temporario = temporario->proximo;
  }
}

int main() {
  PilhaDinamica pilha;
  inicializarPilha(&pilha);
  int novoItem;
  int opcao;
  while (opcao != 5) {
    printf("Escolha uma Opção\n");
    printf("1) Exibir PilhaDinamica\n");
    printf("2) Empilhar Item na PilhaDinamica\n");
    printf("3) Desempilhar Item da PilhaDinamica\n");
    printf("4) Esvaziar PilhaDinamica\n");
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
      printf("PilhaDinamica Está Vazia\n");
    }
    if (opcao == 5) limparPilha(&pilha);
  }
  printf("Programa Finalizado");

  return 0;
}