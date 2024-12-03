/**************************************************************
 * Nome do arquivo: utilites.c
 * Projeto: Labirinto-PAA
 * Descrição: Definçoes de funcionalidades uteis para manipular o terminal, texto e legibilidade
 * 
 * Autor(es):Gabriel de Pádua
 * Data de criação: 27/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- Criada limparTerminalUnix,  mudarCorTexto, e pressEnter
 * 
 * Dependências:
 *   - ultilities.h
 * 
 * Observações:
 *
 **************************************************************/
#include "../headers/utilites.h"


void limparTerminalUnix() {

    // caso eu queira relizar um atraso, posso pausar/esperar o processo usando a função 
    // sleep(2) //parametro e em segundos ;
    //faz parte da biblioteca <unistd.h> e está disponível em sistemas operacionais Unix-like, como Linux e macOS

    printf("\033[2J\033[H"); //limpa a tela
    printf("\033[H\033[J"); //posiciona o cursor no inicio do terminal (posiçao \033[h) e limpa a partir dai (\033[j)
    system("clear");
}

void mudarCorTexto(int numeroNaMatriz) {
/*  cores disponiveis: 
    0 - preto 
    1 - vermelho
    2 - verde
    3 - amarelo
    4 - azul
    5 - magenta
    6 - ciano 
    7 - branco */

    switch (numeroNaMatriz)
    {
    case 1:
        printf("\033[0;37m"); //branco
        break;
    case 2:
        printf("\033[0;34m"); //azul
        break;
    case 3:
        printf("\033[0;31m"); //vermelho
        break;
    case 4:
        printf("\033[0;33m"); //amarelo
        break;
    case 0:
        printf("\033[0;32m"); //verde
        break;
    
    default:
        printf("\033[0m"); // padrão (cor original)
        break;
    }

    //printf("\033[0;3%dm", cor);
}

void pressEnter(){
while (getchar() != '\n'); // Limpa o buffer até o Enter
printf("\n\nPressione Enter para continuar...");
getchar();
limparTerminalUnix();
}
