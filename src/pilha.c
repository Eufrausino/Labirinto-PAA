#include "../headers/pilha.h"

pilha* criaPilha(int tamanhoPilha)
{
    pilha* stack = (pilha*)malloc(sizeof(pilha));
    stack->dimensao = (coordenadas*)malloc(tamanhoPilha * sizeof(coordenadas));
    stack->topo = -1;
    stack->tamanhoPilha = tamanhoPilha;

    return stack;
}

int pilhaVazia(pilha* stack)
{
    return stack->topo == -1;
}

coordenadas desempilha(pilha* stack)
{
   if (pilhaVazia(stack)) {
        printf("Erro: Tentativa de desempilhar uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    return stack->dimensao[stack->topo--];
}

void empilha(pilha* stack, int x, int y)
{
    if (stack->topo + 1 >= stack->tamanhoPilha) {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
    stack->topo++;
    stack->dimensao[stack->topo].x = x;
    stack->dimensao[stack->topo].y = y;
}

coordenadas olhaTopo(pilha* stack)
{
    return stack->dimensao[stack->topo];
}

void destroiPilha(pilha* stack)
{
    free(stack->dimensao);
    free(stack);
}

