#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tarefas.h"

//Funções:

void modulotarefas(void){
    char opcao;
    do {
        opcao = telatarefas();
        switch(opcao) {
            case '1': 	visualizartarefa();
                        break;
            case '2': 	adicionartarefa();
                        break;
            case '3': 	editartarefa();
                        break;
            case '4': 	excluirtarefa();
                        break;
        } 		
    } while (opcao != '0');
}

char telatarefas(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Tarefas  = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Visualizar tarefa                                        ///\n");
    printf("///           2. Adicionar tarefa                                         ///\n");
    printf("///           3. Editar tarefa                                            ///\n");
    printf("///           4. Excluir tarefa                                           ///\n");
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

void visualizartarefa(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Visualizar Tarefas = = = = = = = =          ///\n");
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

void adicionartarefa(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Adicionar Tarefas = = = = = = = =           ///\n");
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

void editartarefa(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Editar Tarefas = = = = = = = =              ///\n");
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

void excluirtarefa(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Excluir Tarefas = = = = = = = =             ///\n");
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
