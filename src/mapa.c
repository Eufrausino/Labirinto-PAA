/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: definições de funcionalidades para manipulação do tipo Mapa
 * 
 * Autor(es): Gabriel de Pádua
 * Data de criação: 15/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 - 15/11/2024: criada funçoes criar mapa e apagar mapa
 *    - v1.1 - 16/11/2014: criada funções mostrar mapa e preencher mapa
 * 
 * Dependências:
 *    - mapa.h
 * 
 * Observações:
 *    - 
 **************************************************************/
#include "mapa.h"
/*

       int***       --> int**                --> int*     --> int
ponteiro pra matriz     ponteiro pra linha       vetor de inteiros 


*/

//typedef int*** Mapa;


void CriaMapa(ApontadorMapa mapa, int linhas, int colunas)
{   
    *mapa = (int**)malloc(linhas * sizeof(int*)); // Aloca memória para as linhas
    if (*mapa == NULL)
    {
        printf("Erro ao alocar memória para as linhas do mapa\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++)
    {
        (*mapa)[i] = (int*)malloc(colunas * sizeof(int)); // Aloca memória para as colunas
        if ((*mapa)[i] == NULL)
        {
            printf("Erro ao alocar memória para as colunas do mapa\n");

            for (int j = 0; j < i; j++) // Libera linhas já alocadas
            {
                free((*mapa)[j]);
            }
            free(*mapa);
            exit(1);
        }
    }
}

void ApagaMapa(ApontadorMapa mapa, int linhas)
{
    if (*mapa == NULL)
        return;

    // Libera cada linha do mapa
    for (int i = 0; i < linhas; i++)
    {
        free((*mapa)[i]);
    }

    // Libera a matriz de ponteiros
    free(*mapa);

    // Define o ponteiro principal como NULL para evitar dangling pointers
    *mapa = NULL;
}

void MostrarMapa(Mapa mapa, int linhas, int colunas)
{
    if (mapa == NULL)
    {
        printf("Mapa não existe\n");
        return;
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}

void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, int valores[],int qtdColunas){

    for (int i = 0; i < qtdColunas; i++)
    {
        (*mapa)[posicacaoLinha][i] = valores[i];
    }
    
}

//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 