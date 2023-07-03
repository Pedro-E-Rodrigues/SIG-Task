#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "relatorio.h"
#include "funcionarios.h"
#include "valida.h"
#include "tarefas.h"
#include <string.h>

void modulo_Relatorio(void){
    char opcao;
    do{
        opcao = telarelatorio();
        switch(opcao){
            case '1': listar_funcionarios();
                    break;
            case '2': listar_tarefasFunc();
                    break;        
        }    
    }while (opcao != '0');
}




char telarelatorio(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Relatórios  = = = = = = = = = = =            ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Listar Funcionarios                                      ///\n");
	printf("///           2. Exibir Tarefas por Funcionario                           ///\n");
	printf("///           3. Exibir Funcionarios por horario                          ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    scanf("%c", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}

void listar_funcionarios(void){
    FILE* fp;
    Funcionario* func;

    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    while(fread(func, sizeof(Funcionario), 1,fp)){
        exibirFuncionario(func);
        printf("/n");
    }
    fclose(fp);
    free(func);


}


void listar_tarefasFunc(void){
    FILE* fp;
    Tarefa* tar;
    char cpf[12];

    tar = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    printf("/// CPF (apenas números): ");
    scanf("%[0-9]",cpf);
    while(fread(tar, sizeof(Tarefa), 1,fp)){
        if (strcmp(tar->cpf,cpf)==0) {
            exibirTarefa(tar);
            printf("/n");
        }
    }
    fclose(fp);
    free(tar);


}