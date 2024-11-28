#include "../headers/menu.h"

int main()
{
    limparTerminalUnix();
    logo();
    menuPrincipal();
    return 0;
}

    //NAO APAGAR ESSE CODIGO ABAIXO 
    // Mapa mapa = NULL;
    // estudante aluno;
    // coordenadas dimensao;

    // InsereLabirinto(&mapa, "labirinto", &aluno, &dimensao);
    // ExploraLabirinto(mapa, dimensao.x, dimensao.y, aluno);

/*
main()
    MostrarMapa(mapa, 5, 5);
    printf ("Mapa mostrado\n");
 
    CriaMapa(&mapa, 5, 5);
    printf ("Mapa criado\n");

    MostrarMapa(mapa, 4, 5);
    printf("Mapa mostrado 2\n");

    int vetor[] = {1, 2, 3, 4, 5};
    //PreencherMapa(&mapa, (int[]){1, 2, 3, 4, 5}, 0);
    PreencherMapa(&mapa,0,vetor,5);
    printf ("Mapa preenchido\n");
    
    MostrarMapa(mapa, 5, 5);

    ApagaMapa(&mapa, 5);
    printf ("Mapa apagado\n");
    return 0;   
*/
