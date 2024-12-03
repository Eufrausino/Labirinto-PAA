/**************************************************************
 * Nome do arquivo: menu.h
 * Projeto: Labirinto-PAA
 * Descrição: Declarações de funcionalidades para manipulação do menu
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 27/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 27/11/2024: criada todas as funções do menu
 *    - v1.1 (gabriel)- 28/11/2024: criada declaração de função logo 
 * 
 * Dependências:
 *    - mapa.h
 *    - backtracking.h"
 *    - coordenadas.h"
 *    - estudante.h"
 *    - pilha.h"
 *    - utilites.h"
 * 
 * Observações:
 *    - 
 **************************************************************/
#ifndef MENU_H
#define MENU_H

#include "../headers/backtracking.h"
#include "../headers/coordenadas.h"
#include "../headers/estudante.h"
#include "../headers/pilha.h"
#include "../headers/utilites.h"

void menuPrincipal();
void logo();
void opcao1(ApontadorMapa mapa,ApontadorEstudante aluno, ApontadorCoordenadas dimensao);
void opcao2(Mapa mapa,estudante aluno,coordenadas dimensao);


#endif
