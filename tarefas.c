#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tarefas.h"
#include "valida.h"

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

// Arquivamento
void salvar_tarefa(Tarefa* tar) {
    FILE *fp;
    fp = fopen("tarefa.dat", "ab");
    if(fp == NULL) {
        printf("Algo deu errado"); 
    }
    fwrite(tar, sizeof(Tarefa), 1, fp);
    fclose(fp);
}

Tarefa* buscar_Tarefa(char* id){
    FILE* fp;
    Tarefa* tar;

    tar = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL){
        printf("\n\nTarefa não encontrada");
    }
    while(fread(tar, sizeof(Tarefa), 1,fp)){
        if ((strcmp(tar->id, id) == 0) && (tar->status == true)) {
			fclose(fp);
			return tar;
		}
    }
    fclose(fp);
    return NULL;
}

void exibirTarefa(Tarefa* tar){
    if (tar == NULL){
        printf("\n= = = Tarefa Inexistente = = =\n");
    } else {
        printf("\n= = = Tarefa Cadastrada = = =\n");
        printf("ID: %s\n", tar->id);
        printf("Nome: %s\n", tar->nome);
        printf("Data de Entrega(dd/mm/aaaa): %s \n", tar->data_entrega);
        printf("Status: %d\n", tar->status);

    }
    printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarTarefa(Tarefa* tar) {
    int achou;
    FILE* fp;
    Tarefa* tarLido;

    tarLido = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "r+b");
    if (fp == NULL){
        printf("\n= = = Tarefa Inexistente = = =\n");
    }
    achou = false;
    while(fread(tarLido, sizeof(Tarefa), 1, fp) && !achou){
        if (strcmp(tarLido->id, tar->id) == 0){
            achou = true;
            fseek(fp, -1*sizeof(Tarefa), SEEK_CUR);
        fwrite(tar, sizeof(Tarefa), 1, fp);    
        }
    }
    fclose(fp);
    free(tarLido);
}