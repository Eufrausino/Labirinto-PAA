#include "../headers/backtracking.h"
#include "../headers/pilha.h"

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

    int moveX[] = {-1,1,0,0};
    int moveY[] = {0,0,-1,1};
    int moveu;

    while(!pilhaVazia(stack))
    {
        posicao.x = olhaTopo(stack).x;
        posicao.y = olhaTopo(stack).y;
        //passo base, se chegou na linha 0. Sucesso saiu do labirinto
        if(posicao.x == 0)
        {
            printf("\nO estudante se moveu %d vezes e chegou na coluna %d da primeira linha\n", cont, posicao.y);

            destroiPilha(stack);
            return;
        }
        //Marca onde passou no labirinto
        mapa[posicao.x][posicao.y] = -1;
        moveu = 0;

        for(int i = 0; i < 4; i++)
        {
            int x_atual = posicao.x + moveX[i];
            int y_atual = posicao.y + moveY[i];

            if(movimenta_estudante(x_atual, y_atual, mapa, aluno, dimensao))
            {
                empilha(stack, x_atual, y_atual);
                moveu = 1;
                break;
            }
        }

        if(!moveu)
        {
            desempilha(stack);
            if(!pilhaVazia(stack))
            {
                coordenadas topo = olhaTopo(stack);
                printf("Linha: %d Coluna: %d\n", topo.x, topo.y);
            }
        }
        cont++;
    }
    printf("\nO estudante se moveu %d e percebeu que o labirinto não tem saída!\n", cont);
    destroiPilha(stack);
    return;
}

