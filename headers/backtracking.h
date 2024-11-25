#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "mapa.h"
#include "coordenadas.h"
#include "estudante.h"

void ExploraLabirinto(Mapa mapa, int linhas, int colunas, estudante aluno);
int movimenta_estudante(int eixoX, int eixoY, Mapa mapa, estudante aluno, coordenadas dimensao);

#endif
