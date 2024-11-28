/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: definições de funcionalidades para manipulação do tipo Mapa
 * 
 * Autor(es): Gabriel de Pádua, Matheus Kauan
 * Data de criação: 15/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criada funçoes criar mapa e apagar mapa
 *    - v1.1 (gabriel)- 16/11/2024: criada funções mostrar mapa e preencher mapa
 *    - v1.2 (matheus)- 20/11/2024: criada função insere labirinto
 * 
 * Dependências:
 *    - mapa.h
 *    - utilites.h
 *    - pilha.h
 * 
 * Observações:
 *    - 
 **************************************************************/
#include "../headers/mapa.h"
#include "../headers/pilha.h"
#include "../headers/utilites.h"
/*

       int***       --> int**                --> int*     --> int
ponteiro pra matriz     ponteiro pra linha       vetor de inteiros 


*/


// typedef int*** ApontadorMapa _____________________ apontador de matriz de inteiros
// typedef int** Mapa __________________ matriz de inteiros 

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
        printf("Mapa nao existe\n");
        return;
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            mudarCorTexto(mapa[i][j]);
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

//Função para leitura de arquivo

void InsereLabirinto(ApontadorMapa mapa, char Labirinto[], estudante* aluno, coordenadas* dimensao)
{
    FILE* labirinto;
    char caminhoArquivo[100];
    int linha = 0;
    int qtdLinhas, qtdColunas, qtdChaves;
    int mapaCarregado = 1;

    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "../%s.txt", Labirinto);
    //printf("%s\n", caminhoArquivo);

    labirinto = fopen(caminhoArquivo, "r");

    if (labirinto == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", Labirinto);
        return;
    }

    // Lê a primeira linha com os metadados
    if (fscanf(labirinto, "%d %d %d", &qtdLinhas, &qtdColunas, &qtdChaves) != 3)
    {
        printf("Erro ao ler os metadados do arquivo.\n");
        fclose(labirinto);
        return;
    }

    // printf("Numero de linhas: %d\n", qtdLinhas);
    // printf("Numero de colunas: %d\n", qtdColunas);
    // printf("Numero de chaves: %d\n\n", qtdChaves);

    aluno->chaves_no_bolso = qtdChaves;
    dimensao->x = qtdLinhas;
    dimensao->y = qtdColunas;

    CriaMapa(mapa, qtdLinhas, qtdColunas);

    // Lê e ignora a linha com os metadados (não preenche na matriz)
    char linhaArquivo[qtdColunas + 2];  // Buffer para cada linha (+ 2 porque inclui '\n' e '\0')
    fgets(linhaArquivo, sizeof(linhaArquivo), labirinto);  // Pula a primeira linha

    
    for (int i = 0; i < qtdLinhas; i++)
    {
        if (fgets(linhaArquivo, sizeof(linhaArquivo), labirinto) != NULL)
        {
            int valores[qtdColunas];
            for (int j = 0; j < qtdColunas; j++)
            {
                // Converte cada caractere da linha para o valor inteiro correspondente
                if (linhaArquivo[j] >= '0' && linhaArquivo[j] <= '3')
                {
                    valores[j] = linhaArquivo[j] - '0';
                }else{
                    printf("Erro ao ler uma posicao do labirinto\n");
                    ApagaMapa(mapa, qtdLinhas);
                    mapaCarregado = 0;
                    break;
                }
               
            }

            PreencherMapa(mapa, i, valores, qtdColunas);
        }
        else
        {
            printf("Erro ao ler a linha %d do labirinto.\n", i + 1);
            ApagaMapa(mapa, qtdLinhas);
            mapaCarregado = 0;
            break;
        }
    }

    fclose(labirinto);

    //MostrarMapa(*mapa, qtdLinhas, qtdColunas);
    if(mapaCarregado) printf("\nMapa carregado com sucesso.\n\n");
    
}


//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 



