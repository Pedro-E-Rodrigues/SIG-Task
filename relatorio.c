#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "relatorio.h"



void telarelatorio(void){
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Relatórios  = = = = = = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}