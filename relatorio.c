#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "relatorio.h"
#include "funcionarios.h"
#include "valida.h"

void moduloRelatorio(void){
    char opcao;
    do{
        opcao = telarelatorio();
        switch(opcao){
            case '1': lista_func();
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
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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