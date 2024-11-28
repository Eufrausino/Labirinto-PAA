#ifndef MENU_H
#define MENU_H

#include "../headers/backtracking.h"
#include "../headers/coordenadas.h"
#include "../headers/estudante.h"
#include "../headers/pilha.h"
#include "../headers/utilites.h"


void menuPrincipal();
// void opcao1(Mapa Mapa, estudante aluno, coordenadas dimensao);
// void opcao2(Mapa Mapa, estudante aluno, coordenadas dimensao);
void logo();
void opcao1(ApontadorMapa mapa,ApontadorEstudante aluno, ApontadorCoordenadas dimensao);
void opcao2(Mapa mapa,estudante aluno,coordenadas dimensao);


#endif