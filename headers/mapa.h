/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: prototipos e declarações de funções e tipos abstratos de dados. 
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 15/11/2024
 *
 * Histórico de versões:
 *    - v1.0 - 15/11/2024: criada funçoes criar mapa e apagar mapa
 *    - v1.1 - 16/11/2014: criada funções mostrar mapa e preencher mapa
 *    - v1.2 - 20/11/2024: criado função de leitura de arquivo para o labirinto
 * 
 * Dependências:
 *    - stdio.h
 *    - stdlib.h
 * 
 * Observações:
 *    - 
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "coordenadas.h"
#include "estudante.h"

//-------------------Renomeando tipos de dados-------------------
typedef int*** ApontadorMapa;// apontador de matriz de inteiros
typedef int** Mapa; // matriz de inteiros 
//-------------------Protótipos de funções-------------------
void CriaMapa(ApontadorMapa mapa, int linhas, int colunas);
void ApagaMapa(ApontadorMapa mapa, int linhas);
void MostrarMapa(Mapa mapa, int linhas, int colunas);
void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, int valores[],int qtdColunas);
void InsereLabirinto(ApontadorMapa mapa, char Labirinto[], estudante* aluno, coordenadas* dimensao);
//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 
