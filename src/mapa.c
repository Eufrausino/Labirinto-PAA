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

//void PreencherMapa(ApontadorMapa mapa, int linhas, int colunas, int vetor[])

//preencher Mapa

//Modificar valor da matriz

//mostrar matriz 

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 