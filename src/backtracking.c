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

#include "../headers/backtracking.h"
#include "../headers/pilha.h"
#include "../headers/analise.h"
#include <stdio.h>

#ifdef ANALISE

int contagemRecursiva = 0;
int max_recursividade = 0;
coordenadas topo;
int pos_topo;
pilha* auxiliar;

#endif

int movimenta_estudante(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao, pilha* stack, int* moveu, int* cont, int* moveX, int* moveY)
{
    if (pilhaVazia(stack)) return 0;

    coordenadas posicao = olhaTopo(stack);
    if (posicao.x == 0) return 1;

    *moveu = 0;  // Inicializa moveu como 0
    mapa[posicao.x][posicao.y] = -1;

    for (int i = 0; i < 4; i++) {
        eixoX = posicao.x + moveX[i];
        eixoY = posicao.y + moveY[i];

        // Verifica limites do mapa
        if (eixoX < 0 || eixoX >= dimensao.x || eixoY < 0 || eixoY >= dimensao.y) continue;

        if (mapa[eixoX][eixoY] == 1 || mapa[eixoX][eixoY] == 4 || 
           (mapa[eixoX][eixoY] == 3 && aluno.chaves_no_bolso >= 1)) {
            empilha(stack, eixoX, eixoY);
            printf("Linha: %d Coluna: %d\n", eixoX, eixoY);
            if (mapa[eixoX][eixoY] == 3) aluno.chaves_no_bolso--;
            if (mapa[eixoX][eixoY] == 4) {
                aluno.chaves_no_bolso++;
                aluno.pos_chave.x = eixoX;
                aluno.pos_chave.y = eixoY;
            }
            *moveu = 1;
            break;
        }
    }

    if (!*moveu) {
        desempilha(stack);
        if (!pilhaVazia(stack)) {
            coordenadas topo = olhaTopo(stack);
            if (topo.x == aluno.pos_chave.x && topo.y == aluno.pos_chave.y) {
                mapa[aluno.pos_chave.x][aluno.pos_chave.y] = 4;
                aluno.chaves_no_bolso--;
                printf("Aluno devolveu a chave na posição (%d,%d)\n", aluno.pos_chave.x, aluno.pos_chave.y);
            }
            printf("Linha: %d Coluna: %d\n", topo.x, topo.y);
        }
    }

    (*cont)++;
    return movimenta_estudante(eixoX, eixoY, mapa, aluno, dimensao, stack, moveu, cont, moveX, moveY);
}

void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno)
{
    coordenadas posicao;

    // Determina ponto de partida do mapa
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 0) {
                posicao.x = i;
                posicao.y = j;
                break;
            }
        }
    }

    coordenadas dimensao = {linhas, colunas};
    pilha* stack = criaPilha(dimensao.x * dimensao.y);
    empilha(stack, posicao.x, posicao.y);
    printf("Linha: %d Coluna: %d\n", posicao.x, posicao.y);

    int cont = 0;
    int moveX[] = {-1, 1, 0, 0};
    int moveY[] = {0, 0, -1, 1};
    int moveu = 0;

    int k = movimenta_estudante(posicao.x, posicao.y, mapa, aluno, dimensao, stack, &moveu, &cont, moveX, moveY);

    if (k == 1)
    {
        printf("\nO estudante se moveu %d vezes e chegou na coluna %d da primeira linha\n", cont, posicao.y);
    }
    else
    {
        printf("\nO estudante se moveu %d vezes e percebeu que o labirinto não tem saída!\n", cont);
    }
    destroiPilha(stack);
    return;
}

int movimentaAnalise(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao, pilha* stack, int* moveu, int* cont, int* moveX, int* moveY)
{

    if (pilhaVazia(stack)) return 0;

    coordenadas posicao = olhaTopo(stack);

    if (posicao.x == 0) return 1;

    *moveu = 0;  // Inicializa moveu como 0
    mapa[posicao.x][posicao.y] = -1;

    for (int i = 0; i < 4; i++) {
        eixoX = posicao.x + moveX[i];
        eixoY = posicao.y + moveY[i];
        #ifdef ANALISE
            contagemRecursiva++;
        #endif
        // Verifica limites do mapa
        if (eixoX < 0 || eixoX >= dimensao.x || eixoY < 0 || eixoY >= dimensao.y) continue;

        if (mapa[eixoX][eixoY] == 1 || mapa[eixoX][eixoY] == 4 || 
           (mapa[eixoX][eixoY] == 3 && aluno.chaves_no_bolso >= 1)) {
            empilha(stack, eixoX, eixoY);
            printf("Linha: %d Coluna: %d\n", eixoX, eixoY);
            if (mapa[eixoX][eixoY] == 3) aluno.chaves_no_bolso--;
            if (mapa[eixoX][eixoY] == 4) {
                aluno.chaves_no_bolso++;
                aluno.pos_chave.x = eixoX;
                aluno.pos_chave.y = eixoY;
            }
            *moveu = 1;

            #ifdef ANALISE
                    topo = olhaTopo(stack);
                    if(contagemRecursiva > 1)
                    {
                        if(pos_topo < stack->topo) pos_topo = stack->topo;
                    }
                    else pos_topo = stack->topo;
                    auxiliar = criaPilha(dimensao.x * dimensao.y);
                    while(!pilhaVazia(stack))
                    {
                        coordenadas aux = desempilha(stack);
                        empilha(auxiliar, aux.x, aux.y);
                    }
                    
                    while(!pilhaVazia(auxiliar))
                    {
                        coordenadas aux = desempilha(auxiliar);
                        empilha(stack, aux.x, aux.y);
                    }
                    destroiPilha(auxiliar);
            #endif
            break;
        }
    }

    if (!*moveu) {
        desempilha(stack);
        if (!pilhaVazia(stack)) {
            coordenadas topo = olhaTopo(stack);
            if (topo.x == aluno.pos_chave.x && topo.y == aluno.pos_chave.y) {
                mapa[aluno.pos_chave.x][aluno.pos_chave.y] = 4;
                aluno.chaves_no_bolso--;
                printf("Aluno devolveu a chave na posição (%d,%d)\n", aluno.pos_chave.x, aluno.pos_chave.y);
            }
            printf("Linha: %d Coluna: %d\n", topo.x, topo.y);
        }
    }

    (*cont)++;
    return movimentaAnalise(eixoX, eixoY, mapa, aluno, dimensao, stack, moveu, cont, moveX, moveY);
}

void exploraAnalise(Mapa mapa, int linhas, int colunas, estudante aluno)
{
    coordenadas posicao;

    // Determina ponto de partida do mapa
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 0) {
                posicao.x = i;
                posicao.y = j;
                break;
            }
        }
    }

    coordenadas dimensao = {linhas, colunas};
    pilha* stack = criaPilha(dimensao.x * dimensao.y);
    empilha(stack, posicao.x, posicao.y);
    printf("Linha: %d Coluna: %d\n", posicao.x, posicao.y);

    int cont = 0;
    int moveX[] = {-1, 1, 0, 0};
    int moveY[] = {0, 0, -1, 1};
    int moveu = 0;

    int k = movimentaAnalise(posicao.x, posicao.y, mapa, aluno, dimensao, stack, &moveu, &cont, moveX, moveY);

    if (k == 1)
    {
        printf("\nO estudante se moveu %d vezes e chegou na coluna %d da primeira linha\n", cont, posicao.y);
    }
    else
    {
        printf("\nO estudante se moveu %d vezes e percebeu que o labirinto não tem saída!\n", cont);
    }
    destroiPilha(stack);
    return;
}

void resultadoAnalise()
{
    #ifdef ANALISE
        printf("Quantidade de chamadas recursivas = %d\n", contagemRecursiva);
        printf("Nível máximo de recursividade = %d\n", pos_topo+1);
        contagemRecursiva = 0;
        
    #endif
}
