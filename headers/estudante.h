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
#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include "coordenadas.h"

typedef struct estudante
{
	int chaves_no_bolso;
	coordenadas pos_chave;
}
estudante;

//ponteiro pra estrutura de estudante
typedef estudante* ApontadorEstudante;

#endif
