/**************************************************************
 * Nome do arquivo: 
 * Projeto: Labirinto-PAA
 * Descrição: 
 * 
 * Autor(es): 
 * Data de criação: 27/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 - 
 * 
 * Dependências:
 *   - exemplo.h
 * 
 * Observações:
 *
 **************************************************************/

#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "coordenadas.h"

typedef struct Pilha
{
	coordenadas* dimensao;
	int topo;
	int tamanhoPilha;
}
pilha;

//-------------------Funções da Pilha------------------------
pilha* criaPilha(int tamanhoPilha);
int pilhaVazia(pilha* stack);
coordenadas desempilha(pilha* stack);
void empilha(pilha* stack, int x, int y);
coordenadas olhaTopo(pilha* stack);
void destroiPilha(pilha* stack);

#endif
