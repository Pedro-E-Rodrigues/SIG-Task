#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tarefas.h"
#include "valida.h"

//Funções:

void modulotarefas(void){
    char opcao;
    do {
        opcao = telatarefas();
        switch(opcao) {
            case '1': 	visualizar_tarefa();
                        break;
            case '2': 	adicionar_tarefa();
                        break;
            case '3': 	editar_tarefa();
                        break;
            case '4': 	excluir_tarefa();
                        break;
        } 		
    } while (opcao != '0');
}

void visualizar_tarefa(void) {
    Tarefa *tar;
    char *id;

    id = tela_visualizar_tarefa();
    tar = buscar_Tarefa(id);
    exibirTarefa(tar);
    
    free(tar);
    free(id);
}

void adicionar_tarefa(void) {
    Tarefa *tar;
    
    tar = tela_adicionar_tarefa();
    salvar_tarefa(tar);

    free(tar);
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

char* tela_visualizar_tarefa(void){
    char* id;

    id = (char*) malloc(6*sizeof(char));
    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Visualizar Tarefas = = = = = = = =          ///\n");
    printf("///                                                                       ///\n");
    printf("            Digite o ID do Projeto: \n");
    scanf("%[^\n]", id);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return id;
}

Tarefa* tela_adicionar_tarefa(void){
    Tarefa *tar;

    tar = (Tarefa*) malloc(sizeof(Tarefa));
    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Adicionar Tarefas = = = = = = = =           ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Titulo/Nome: \n");
        printf("            => ");
        scanf("%[^\n]", tar->nome);
        getchar();
    } while (!validar_nome(tar->nome));
    printf("\n");

    do {
        printf("            ID do Projeto: \n");
        printf("            => ");
        scanf("%[^\n]", tar->id);
        getchar();
    } while (!valida_id(tar->id, 5));
    printf("\n");

    do {
        printf("            Data limite para entrega (dd/mm/aaaa): \n");
        printf("            => ");
        scanf("%[^\n]", tar->data_entrega);
        getchar();
    } while (!valida_data(tar->data_entrega));
    tar->status = true;
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
//Funções feitas por: quirinof

void tela_editar_tarefa(void){
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

void tela_excluir_tarefa(void){
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