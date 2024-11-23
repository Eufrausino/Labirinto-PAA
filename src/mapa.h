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




//-------------------Renomeando tipos de dados-------------------

typedef int*** ApontadorMapa;// apontador de matriz de inteiros
typedef int** Mapa; // matriz de inteiros 
typedef struct estudante
{
	int chaves_no_bolso;
}
estudante;

typedef struct  coordenadas
{
	int x,y;
}
coordenadas;

typedef struct Pilha
{
	coordenadas* dimensao;
	int topo;
	int tamanhoPilha;
}
pilha;

//-------------------Funções da Pilha------------------------
pilha* criaPilha(int tamanhoPilha);
int pilhaVazia(pilha* stack);
coordenadas desempilha(pilha* stack);
void empilha(pilha* stack, int x, int y);
coordenadas olhaTopo(pilha* stack);
void destroiPilha(pilha* stack);
//-------------------Protótipos de funções-------------------
void CriaMapa(ApontadorMapa mapa, int linhas, int colunas);
void ApagaMapa(ApontadorMapa mapa, int linhas);
void MostrarMapa(Mapa mapa, int linhas, int colunas);
void PreencherMapa(ApontadorMapa mapa, int posicacaoLinha, int valores[],int qtdColunas);
void InsereLabirinto(ApontadorMapa mapa, char Labirinto[], estudante* aluno, coordenadas* dimensao);
void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno);
int movimenta_estudante(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao);

//Modificar valor da matriz

//verificar se a matriz está vazia

//FUTURAMENTE mostrar posição do aluno de Programação 
