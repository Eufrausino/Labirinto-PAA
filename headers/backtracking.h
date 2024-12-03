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


#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "mapa.h"
#include "coordenadas.h"
#include "estudante.h"
#include "pilha.h"

void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno);
int movimenta_estudante(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao, pilha* stack, int* moveu, int* cont, int* moveX, int* moveY);
int movimentaAnalise(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao, pilha* stack, int* moveu, int* cont, int* moveX, int* moveY);
void exploraAnalise(Mapa mapa, int linhas, int colunas, estudante aluno);
void resultadoAnalise();
#endif
