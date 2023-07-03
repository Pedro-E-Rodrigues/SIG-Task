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

void editar_tarefa(void) {
    Tarefa *tar;
    char *id;

    id = tela_atualizar_tarefa();
    tar = buscar_Tarefa(id);
    if (tar == NULL){
        printf(" ||               >>>>>> Tarefa inexistente <<<<<<                 ||\n");
    }
    else{
        tela_editar_tarefa(tar);
        strcpy(tar->id, id);
        regravarTarefa(tar);
		free(tar);
    }
    free(id);
    

}

void excluir_tarefa(void) {
    Tarefa *tar;
    char id[6];

    tela_excluir_tarefa(id);
    tar = (Tarefa*) malloc(sizeof(Tarefa));
    tar = buscar_Tarefa(id);
    if (tar == NULL) {
        printf(" ||             >>>>>> Projeto não encontrado! <<<<<<               ||\n");
    }
    else{
        tar->status = false;
        regravarTarefa(tar);
    }
    free(tar);
    // free(id);


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
        break;
    } while (!validar_nome(tar->nome));
    printf("\n");
    do {
        printf("            ID do Projeto: \n");
        printf("            => ");
        scanf("%[^\n]", tar->id);
        getchar();
        break;
    } while (!valida_id(tar->id, 5));
    printf("\n");
    do {
        printf("/// CPF (apenas números): ");
        scanf("%[0-9]", tar->cpf);
        getchar();
    } while (!validar_cpf(tar->cpf));
    do {
        printf("            Data limite para entrega (dd/mm/aaaa): \n");
        printf("            => ");
        scanf("%[^\n]", tar->data_entrega);
        getchar();
        break;
    } while (!valida_data(tar->data_entrega));
    tar->status = true;
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return tar;
}
//Funções feitas por: quirinof

char* tela_atualizar_tarefa(void){
    char *id;

    id = (char*) malloc(6*sizeof(char));
    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Atualizar Tarefas = = = = = = = =           ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Digite o ID do Projeto: \n");
        printf("            => ");
        scanf("%[^\n]", id);
        getchar();
        break;
    } while (!valida_id(id, 5));
    printf("\n");

    return id;

}

void tela_editar_tarefa(Tarefa* tar) {
    char editar;

    do {
        system("cls||clear");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||                           __ EDITAR __                          ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 1 ] Titulo                                            ||\n");
        printf(" ||         [ 2 ] ID                                                ||\n");
        printf(" ||         [ 3 ] Data para entrega                                 ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 0 ] Retornar ao menu de tarefas                       ||\n");
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf("           Digite sua escolha: ");
        scanf("%c", &editar);
        getchar();
        printf("\n");
        switch (editar) {
            case '1': tela_editar_titulo_Tarefa(tar);
                      break;
            case '2': tela_editar_id_Tarefa(tar);
                      break;
            case '3': tela_editar_data_Tarefa(tar);
                      break;
        }
    } while (editar != '0');
    tar->status = true;
}
//Funções feitas por: quirinof

void tela_editar_titulo_Tarefa(Tarefa* tar){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo titulo da tarefa: \n");
        printf("         => ");
        scanf("%[^\n]", tar->nome);
        getchar();
        break;
    } while (!validar_nome(tar->nome));
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}
//Funções feitas por: quirinof

void tela_editar_id_Tarefa(Tarefa* tar){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("            Novo ID da tarefa: \n");
        printf("            => ");
        scanf("%[^\n]", tar->id);
        getchar();
        break;
    } while (!valida_id(tar->id, 5));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 

}
//Funções feitas por: quirinof

void tela_editar_data_Tarefa(Tarefa* tar){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Nova data de entrega da tarefa (dd/mm/aaaa): \n");
        printf("         => ");
        scanf("%[^\n]", tar->data_entrega);
        getchar();
        break;
    } while (!valida_data(tar->data_entrega));    
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 

}
//Funções feitas por: quirinof
    // return tar;
void tela_excluir_tarefa(char* id){
    // char id[6];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Excluir Tarefas = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Digite o ID da Tarefa: \n");
        printf("            => ");
        scanf("%[^\n]", id);
        getchar();
        break;
    } while (!valida_id(id, 5));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                  ...... Tarefa excluido ......                  ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();

    // return id;
}

// Arquivamento
void salvar_tarefa(Tarefa* tar) {
    FILE* fp;
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