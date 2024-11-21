#include "mapa.h"

int main()
{
    Mapa mapa = NULL;

    InsereLabirinto(&mapa, "labirinto.txt");

}

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