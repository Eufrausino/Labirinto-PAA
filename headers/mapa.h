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
//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 

#endif



// void opcao1(ApontadorMapa mapa, estudante* aluno, coordenadas* dimensao){


//     if (*mapa == NULL)
//     {
//         printf("Por favor, digite o nome do arquivo: ");
//         char nomeArquivo[50];
//         scanf("%s", nomeArquivo); 
//         InsereLabirinto((*mapa),nomeArquivo , &aluno, &dimensao);

//         printf("Deseja visualizar o mapa? (1 -> SIM, 0 -> NAO): ");
//         int opcao;
//         scanf("%d", &opcao);

//         if (opcao == 1){
//             printf("\n\n");
//             MostrarMapa(mapa, dimensao.x, dimensao.y);
//         }
//         else return;
//     }
    


    


// }