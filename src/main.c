/**************************************************************
 * Nome do arquivo: main.c
 * Projeto: Labirinto-PAA
 * Descrição: Programa de execução principal
 * 
 * Autor(es): Gabriel, Matheus, Ana, Gustavo  
 * Data de criação: 15/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- 15/11/2024: criado essa main, para inicialmente teste de mapa.c
 * 
 * Dependências:
 *   - menu.h
 * 
 * Observações:
 *
 **************************************************************/
#include "../headers/menu.h"

int main()
{
    //limparTerminalUnix();
    logo();
    menuPrincipal();
    return 0;
}
