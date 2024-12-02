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
int movimenta_estudante(Mapa mapa, estudante aluno, coordenadas dimensao, int *cont, pilha* stack, int *moveX, int *moveY, coordenadas posicao);
void exploraAnalise(Mapa mapa, int linhas, int colunas, estudante aluno);
void resultadoAnalise();
#endif
