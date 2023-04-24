#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "compromissos.h"


//Funções:


void modulocompromissos(void){
    char opcao;
    do {
        opcao = telacompromissos();
        switch(opcao) {
            case '1': 	visualizarcompromisso();
                        break;
            case '2': 	adicionarcompromisso();
                        break;
            case '3': 	editarcompromisso();
                        break;
            case '4': 	excluircompromisso();
                        break;
        } 		
    } while (opcao != '0');
}

char telacompromissos(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Compromissos = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Visualizar compromissos                                  ///\n");
    printf("///           2. Adicionar compromisso                                    ///\n");
    printf("///           3. Editar compromisso                                       ///\n");
    printf("///           4. Excluir compromissos                                     ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}

void visualizarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Visualizar Compromissos = = = = = = = =     ///\n");
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

void adicionarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Adicionar Compromissos = = = = = = = =      ///\n");
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

void editarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Editar Compromissos = = = = = = = =         ///\n");
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

void excluircompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Excluir Compromissos = = = = = = = =        ///\n");
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