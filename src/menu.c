#include "../headers/menu.h"



void logo(){
   printf("                                                                                \n");
    printf("@@@        @@@@@@   @@@@@@@   @@@  @@@@@@@   @@@  @@@  @@@  @@@@@@@   @@@@@@   \n");
    printf("@@@       @@@@@@@@  @@@@@@@@  @@@  @@@@@@@@  @@@  @@@@ @@@  @@@@@@@  @@@@@@@@  \n");
    printf("@@!       @@!  @@@  @@!  @@@  @@!  @@!  @@@  @@!  @@!@!@@@    @@!    @@!  @@@  \n");
    printf("!@!       !@!  @!@  !@   @!@  !@!  !@!  @!@  !@!  !@!!@!@!    !@!    !@!  @!@  \n");
    printf("@!!       @!@!@!@!  @!@!@!@   !!@  @!@!!@!   !!@  @!@ !!@!    @!!    @!@  !@!  \n");
    printf("!!!       !!!@!!!!  !!!@!!!!  !!!  !!@!@!    !!!  !@!  !!!    !!!    !@!  !!!  \n");
    printf("!!:       !!:  !!!  !!:  !!!  !!:  !!: :!!   !!:  !!:  !!!    !!:    !!:  !!!  \n");
    printf(" :!:      :!:  !:!  :!:  !:!  :!:  :!:  !:!  :!:  :!:  !:!    :!:    :!:  !:!  \n");
    printf(" :: ::::  ::   :::   :: ::::   ::  ::   :::   ::   ::   ::     ::    ::::: ::  \n");
    printf(": :: : :   :   : :  :: : ::   :     :   : :  :    ::    :      :      : :  :  \n");


}

void menuPrincipal(){
    int opcao;

    //instanciei o mapa, aluno e dimensoes 
   
    ApontadorMapa guardaMapa = NULL;
    Mapa mapa = NULL;
    guardaMapa = &mapa;

    estudante aluno;
    coordenadas dimensao;

    //ApontadorMapa mapa = NULL; //inicialmente nao guarda mapa nenhum



    do{
        printf("\n\n");
        printf("Opcoes do programa:\n");
        printf("1) Carregar novo arquivo de dados.\n");
        printf("2) Processar e exibir resposta.\n");
        printf("3 ou qualquer outro caracter) Sair do programa.\n");
        printf("\nDigite um numero: ");
        scanf("%d", &opcao);

        switch(opcao){
            
            case 1:
                opcao1(guardaMapa, &aluno, &dimensao);
                break;
            case 2:
                opcao2(mapa, aluno, dimensao);
                break;
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 3);

}

void opcao1(ApontadorMapa mapa,ApontadorEstudante aluno, ApontadorCoordenadas dimensao){

    limparTerminalUnix();
    printf("Por favor, digite o nome do arquivo sem extensao: ");
    char nomeArquivo[50];
    scanf("%s", nomeArquivo);

    limparTerminalUnix();
    InsereLabirinto(&(*mapa),nomeArquivo , &(*aluno), &(*dimensao));

    printf("Deseja visualizar o mapa? (1 -> SIM, 0 -> NAO): ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1){
        printf("\n\n");
        MostrarMapa((*mapa), (*dimensao).x, dimensao->y);
        pressEnter();
        limparTerminalUnix();
    }
    else return;

    //TENHO Q OLHAR  SE MAPA JA EXISTE E DEPOIS APAGAR O QUE JATA E SOBREESCREVER 
}

void opcao2(Mapa mapa,estudante aluno,coordenadas dimensao){
    limparTerminalUnix();
    ExploraLabirinto(mapa, dimensao.x, dimensao.y, aluno);
}