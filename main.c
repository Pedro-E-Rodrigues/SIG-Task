#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcionarios.h"
#include "compromissos.h"
#include "tarefas.h"
#include "relatorio.h"

//Funções:

char telamenu(void);
void telasobre(void);


//principal:

int main(void) {
    char opcao;

    do {
        opcao = telamenu();
        switch(opcao) {
            case '1':   modulofuncionarios();
                        break;
            case '2':   modulocompromissos();
                        break;
            case '3':   modulotarefas();
                        break;
            case '4':   modulo_Relatorio();
                        break;
            case '5':   telasobre();
                        break;
            
        } 	
    } while (opcao != '0');

    return 0;
 
}

char telamenu(void) {
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///                 Bacharelado Sistemas de Informação                      ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///           Projeto SIG-Task: Agenda de Tarefas e Compromissos            ///\n");
    printf("///                Developed by @Pedro-E-Rodrigues -2023                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");               
    printf("///            1. Menu Funcionários                                         ///\n");
    printf("///            2. Menu Compromissos                                         ///\n");
    printf("///            3. Menu Tarefas                                              ///\n");
    printf("///            4. Relatórios                                                ///\n");
    printf("///            5. Sobre                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}

void telasobre(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 Agenda de Tarefas e Compromissos                        ///\n");
    printf("///                                                                         ///\n");
    printf("///      Projeto desenvolvido visando ajudar pessoas a gerenciar            ///\n");
    printf("///      melhor seu tempo e manter-se organizadas.                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



