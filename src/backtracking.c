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

int movimenta_estudante(Mapa mapa, estudante aluno, coordenadas dimensao, int *cont, pilha* stack, int *moveX, int *moveY, coordenadas posicao){
	
	if (pilhaVazia(stack)){
		return -1;
	}

    int moveu;
	posicao.x = olhaTopo(stack).x;
	posicao.y = olhaTopo(stack).y;

	//passo base, se chegou na linha 0. Sucesso saiu do labirinto
	if(posicao.x == 0){
	    printf("\nO estudante se moveu %d vezes e chegou na coluna %d da primeira linha\n", (*cont), posicao.y);

	    destroiPilha(stack);
	    return 0;
	}

	//Marca onde passou no labirinto
	mapa[posicao.x][posicao.y] = -1;
	moveu = 0;

	//tentativas de movimento
	for(int i = 0; i < 4; i++){
	    int x_atual = posicao.x + moveX[i];
	    int y_atual = posicao.y + moveY[i];
		
		#ifdef ANALISE
			contagemRecursiva++;
		#endif

		int ehMovimentavel = 0;
		
		//conferindo se não o movimento não está marcado e se ele está dentro das dimensões do mapa 
		if(x_atual >= 0 && y_atual >=0 && x_atual < dimensao.x && y_atual < dimensao.y){

			//Se caminho livre ou se porta e estudante com chave -> movimento permitido
			if(mapa[x_atual][y_atual] == 1 || (mapa[x_atual][y_atual] == 3 && aluno.chaves_no_bolso >= 1)){
			    printf("Linha: %d Coluna: %d\n",x_atual,y_atual);
			    ehMovimentavel = 1;
			}
		}
	    if(ehMovimentavel){
			empilha(stack, x_atual, y_atual);
			moveu = 1;
			//(*cont)++;

			//Contagem de chamadas recursivas
			#ifdef ANALISE
				topo = olhaTopo(stack);
				if(contagemRecursiva > 1){
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

	if(!moveu){
	    desempilha(stack);
	    if(!pilhaVazia(stack)){
			coordenadas topo = olhaTopo(stack);
			printf("Linha: %d Coluna: %d\n", topo.x, topo.y);
	    }
	}
	(*cont)++;
	return movimenta_estudante(mapa, aluno, dimensao, cont, stack, moveX, moveY, posicao);
}


void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno){
    coordenadas posicao;
    //Determina ponto de partida do mapa
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(mapa[i][j] == 0){
                posicao.x = i;
                posicao.y = j;
                break;
            }
        }
    }

    //define dimensão do mapa
	coordenadas dimensao;
    dimensao.x = linhas;
    dimensao.y = colunas;

    pilha* stack = criaPilha(dimensao.x * dimensao.y);
    empilha(stack, posicao.x, posicao.y);
    printf("Linha: %d Coluna: %d\n", posicao.x, posicao.y);

    int moveX[] = {-1,1,0,0};
    int moveY[] = {0,0,-1,1};

	int chamadasRecursivas = 0;

	if(movimenta_estudante(mapa, aluno, dimensao, &chamadasRecursivas, stack, moveX, moveY, posicao) == -1){
		printf("\nO estudante se moveu %d vezes e percebeu que o labirinto não tem saída!\n", chamadasRecursivas);
		destroiPilha(stack);
		return;

	}
}

void resultadoAnalise(){
    #ifdef ANALISE
        printf("chamadas recursivas = %d\n", contagemRecursiva);
        printf("nivel max = %d\n", pos_topo+1);
		contagemRecursiva = 0;
    #endif
}
