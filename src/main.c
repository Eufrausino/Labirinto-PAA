#include "mapa.h"

int main()
{
    printf("Hello, World!\n");
    
    Mapa mapa = NULL;
    mapa = NULL; //era o certo ... criar entao o typedef ponteiro pra mapa e mapa(que é uma matriz de int ou seja int**) 
    
    CriaMapa(&mapa, 5, 5);

    printf ("Mapa criado\n");
    ApagaMapa(&mapa, 5);
    printf ("Mapa apagado\n");
    return 0;    
}