/**************************************************************
 * Nome do arquivo: mapa.c
 * Projeto: Labirinto-PAA
 * Descrição: definições de funcionalidades para manipulação do tipo Mapa
 * 
 * Autor(es): Gabriel de Pádua, Matheus Kauan
 * Data de criação: 15/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 - 15/11/2024: criada funçoes criar mapa e apagar mapa
 *    - v1.1 - 16/11/2024: criada funções mostrar mapa e preencher mapa
 *    - v1.2 - 20/11/2024: criado função de leitura de arquivo para o labirinto
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
        printf("Mapa nao existe\n");
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

//Função para leitura de arquivo

void InsereLabirinto(ApontadorMapa mapa, char Labirinto[], estudante* aluno, coordenadas* dimensao)
{
    FILE* labirinto;
    char caminhoArquivo[30];
    int linha = 0;
    int qtdLinhas, qtdColunas, qtdChaves;
    int mapaCarregado = 1;

    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "../%s", Labirinto);
    printf("%s\n", caminhoArquivo);

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

    printf("Numero de linhas: %d\n", qtdLinhas);
    printf("Numero de colunas: %d\n", qtdColunas);
    printf("Numero de chaves: %d\n\n", qtdChaves);

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

    MostrarMapa(*mapa, qtdLinhas, qtdColunas);
    if(mapaCarregado) printf("Mapa carregado com sucesso.\n");
        
}


//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 

pilha* criaPilha(int tamanhoPilha)
{
    pilha* stack = (pilha*)malloc(sizeof(pilha));
    stack->dimensao = (coordenadas*)malloc(tamanhoPilha * sizeof(coordenadas));
    stack->topo = -1;
    stack->tamanhoPilha = tamanhoPilha;

    return stack;
}

int pilhaVazia(pilha* stack)
{
    return stack->topo == -1;
}

coordenadas desempilha(pilha* stack)
{
   if (pilhaVazia(stack)) {
        printf("Erro: Tentativa de desempilhar uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    return stack->dimensao[stack->topo--];
}

void empilha(pilha* stack, int x, int y)
{
    if (stack->topo + 1 >= stack->tamanhoPilha) {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
    stack->topo++;
    stack->dimensao[stack->topo].x = x;
    stack->dimensao[stack->topo].y = y;
}

coordenadas olhaTopo(pilha* stack)
{
    return stack->dimensao[stack->topo];
}

void destroiPilha(pilha* stack)
{
    free(stack->dimensao);
    free(stack);
}

int movimenta_estudante(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao)
{
    //Confere posição do movimento está dentro do mapa
    if(eixoX >= 0 && eixoY >=0 && eixoX < dimensao.x && eixoY < dimensao.y)
    {
        //Se caminho livre ou se porta e estudante com chave -> movimento permitido
        if(mapa[eixoX][eixoY] == 1 || (mapa[eixoX][eixoY] == 3 && aluno.chaves_no_bolso >= 1))
        {
            printf("Linha: %d Coluna: %d\n",eixoX,eixoY);
            return 1;
        }
    }
    return 0;
}

void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno)
{
    coordenadas posicao;
    //Determina ponto de partida do mapa
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(mapa[i][j] == 0)
            {
                posicao.x = i;
                posicao.y = j;
                break;
            }
        }
    }
    coordenadas dimensao;
    coordenadas ponto_partida;
    ponto_partida.x = posicao.x;
    ponto_partida.y = posicao.y;
    //define dimensão do mapa
    dimensao.x = linhas;
    dimensao.y = colunas;
    //cria pilha que guarda as movimentações do backtracking
    pilha* stack = criaPilha(dimensao.x*dimensao.y);
    empilha(stack, posicao.x, posicao.y);
    printf("Linha: %d Coluna: %d\n", posicao.x, posicao.y);
    int cont = 0;

    while(!pilhaVazia(stack))
    {
        posicao.x = olhaTopo(stack).x;
        posicao.y = olhaTopo(stack).y;
        //passo base, se chegou na linha 0. Sucesso saiu do labirinto
        if(posicao.x == 0)
        {
            printf("O estudante se moveu %d vezes e chegou na coluna %d da primeira linha\n", cont, posicao.y);

            destroiPilha(stack);
            return;
        }
        //Marca onde passou no labirinto
        mapa[posicao.x][posicao.y] = -1;
        
        //Se posição válida, realiza movimentação em cada uma das direções: cima, baixo, esquerda ou direita
        if(movimenta_estudante(posicao.x + 1, posicao.y, mapa, aluno,dimensao))
        {
            empilha(stack, posicao.x+1,posicao.y);
        }

        else if(movimenta_estudante(posicao.x - 1, posicao.y, mapa, aluno,dimensao))
        {
            empilha(stack, posicao.x-1,posicao.y);
            }

        else if(movimenta_estudante(posicao.x, posicao.y+1, mapa, aluno,dimensao))
        {
            empilha(stack, posicao.x,posicao.y+1);
        }

        else if(movimenta_estudante(posicao.x, posicao.y-1, mapa, aluno,dimensao))
        {
            empilha(stack, posicao.x,posicao.y-1);
        }
        else
        { 
            //Se nenhuma movimentação deu certo, volta para o passo anterior
            desempilha(stack);
            if(olhaTopo(stack).x != ponto_partida.x && olhaTopo(stack).y != ponto_partida.y)
            {
                printf("Linha: %d Coluna: %d\n", olhaTopo(stack).x, olhaTopo(stack).y);
            }
            else if (olhaTopo(stack).x == ponto_partida.x && olhaTopo(stack).y == ponto_partida.y)
            {
                cont++;
                break;
            }
        }
        cont++;
    }
    printf("\nO estudante se moveu %d e percebeu que o labirinto não tem saída!\n", cont);
    destroiPilha(stack);
    return;
}

