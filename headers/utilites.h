/**************************************************************
 * Nome do arquivo: utilites.h
 * Projeto: Labirinto-PAA
 * Descrição: Declarações de funcionalidades uteis para manipular o terminal, texto e legibilidade
 * 
 * Autor(es): Gabriel de Padua
 * Data de criação: 27/11/2024
 * 
 * Histórico de versões:
 *    - v1.0 (gabriel)- Declaradas cabeçalhos de limparTerminalUnix,  mudarCorTexto, e pressEnter
 * 
 * Dependências:
 *   - stdio.h
 *   - stdlib.h
 * 
 * Observações:
 *
 **************************************************************/
#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>

void limparTerminalUnix();
void mudarCorTexto(int numeroNaMatriz);
void pressEnter();

#endif