/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: prototipos e declarações de funções e tipos abstratos de dados. 
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 15/11/2024
 *
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criado cabeçalho de funçoes criar mapa e apagar mapa
 *    - v1.1 (gabriel)- 16/11/2014: criada cabeçalho de funções mostrar mapa e preencher mapa
 *    - v1.2 (matheus)- 20/11/2024: criado função de leitura de arquivo para o labirinto
 * 
 * Dependências:
 *    - stdio.h
 *    - stdlib.h
 *    - coordenadas.h
 *    - estudante.h
 *    - utilites.h
 *     
 * 
 * Observações:
 *    - 
 **************************************************************/
#ifndef MAPA_H
#define MAPA_H

#include "../headers/utilites.h"
#include <stdio.h>
#include <stdlib.h>
#include "coordenadas.h"
#include "estudante.h"
#include <time.h>

//-------------------Renomeando tipos de dados-------------------
typedef int*** ApontadorMapa;// apontador de matriz de inteiros
typedef int** Mapa; // matriz de inteiros 


//-------------------Protótipos de funções-------------------
void CriaMapa(ApontadorMapa mapa, int linhas, int colunas);
void ApagaMapa(ApontadorMapa mapa, int linhas);
void MostrarMapa(Mapa mapa, int linhas, int colunas);
void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, int valores[],int qtdColunas);

//Função para leitura de arquivo
void InsereLabirinto(ApontadorMapa mapa, char Labirinto[], estudante* aluno, coordenadas* dimensao);


// Definições para cores
#define VERDE 0
#define BRANCO 1
#define AZUL 2
#define VERMELHO 3
#define AMARELO 4

void gerarLabirinto(const char *nomeArquivo, int largura, int altura, int chaves, int dificuldade);

//FUTURAMENTE mostrar posição do aluno de Programação 

#endif

