#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "compromissos.h"
#include "valida.h"


//Funções:


void modulocompromissos(void){
    char opcao;
    do {
        opcao = telacompromissos();
        switch(opcao) {
            case '1': 	visualizar_compromisso();
                        break;
            case '2': 	adicionar_compromisso();
                        break;
            case '3': 	editar_compromisso();
                        break;
            case '4': 	excluir_compromisso();
                        break;
        } 		
    } while (opcao != '0');
}

void adicionar_compromisso(void) {
    Compromisso *comp;
    
    comp = tela_adicionarcompromisso();
    
    
    salvar_compromisso(comp);

    free(comp);
}

void visualizar_compromisso(void) {
    Compromisso *comp;
    char *id;

    id = tela_visualizarcompromisso();
    comp = buscar_Compromisso(id);
    exibirCompromisso(comp);
    free(comp);
    free(id);
}

void editar_compromisso(void) {
    Compromisso *comp;
    char *id;

    id = tela_atualizar_compromisso();
    comp = buscar_Compromisso(id);
    if (comp == NULL){
        printf(" ||               >>>>>> Compromisso inexistente <<<<<<                 ||\n");
    }
    else{
        tela_editar_compromisso(comp);
        strcpy(comp->id, id);
        regravarCompromisso(comp);
		free(comp);
    }
    free(id);
    

}

void excluir_compromisso(void) {
    Compromisso *comp;
    char id[6];

    tela_excluir_compromisso(id);
    comp = (Compromisso*) malloc(sizeof(Compromisso));
    comp = buscar_Compromisso(id);
    if (comp == NULL) {
        printf(" ||             >>>>>> Compromisso não encontrado! <<<<<<               ||\n");
    }
    else{
        comp->status = false;
        regravarCompromisso(comp);
    }
    free(comp);
    // free(id);


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

char* tela_visualizarcompromisso(void){
    char *id;

    id = (char*) malloc(6*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Visualizar Compromissos = = = = = = = =     ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Digite o ID do Compromisso: \n");
        printf("            => ");
        scanf("%[^\n]", id);
        getchar();
    } while (!valida_id(id, 5));
    printf("\n");
    printf(" ||               ------- Enter para continuar! --------            ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	getchar();

    return id;
}

Compromisso* tela_adicionarcompromisso(void){
    Compromisso *comp;

    comp = (Compromisso*) malloc(sizeof(Compromisso));
    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Adicionar Compromissos = = = = = = = =      ///\n");
    printf("///                                                                       ///\n");
     do {
        printf("            Nome do compromisso: \n");
        printf("            => ");
        scanf("%[^\n]", comp->nome_comp);
        getchar();
    } while(!validar_nome(comp->nome_comp));
    printf("\n");

    do {
        printf("            ID da tarefa relacionado: \n");
        printf("            => ");
        scanf("%[^\n]", comp->id_tar);
        getchar();
    } while (!valida_id(comp->id_tar, 5));
    printf("\n");

    do {
        printf("            CPF do Funcionario atribuido: \n");
        printf("            => ");
        scanf("%[^\n]", comp->cpf);
        getchar();
    } while (!validar_cpf(comp->cpf));   
    printf("\n");

    do {
        printf("            Data de entrega do compromisso(dd/mm/aaaa): \n");
        printf("            => ");
        scanf("%[^\n]", comp->data_comp);
        getchar();
    } while (!valida_data(comp->data_comp));

    printf("\n");
    strcpy(comp->id, gerar_id_comp());
    printf("            O ID do compromisso:\n");
    printf("            => %s", comp->id);
    getchar();
    
    comp->status = true;
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Compromisso cadastradao ......            ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();

    return comp;
}
char* tela_atualizar_compromisso(void){
    char *id;

    id = (char*) malloc(6*sizeof(char));
    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Atualizar Compromisso = = = = = = = =       ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Digite o ID do Compromisso: \n");
        printf("            => ");
        scanf("%[^\n]", id);
        getchar();
        break;
    } while (!valida_id(id, 5));
    printf("\n");

    return id;

}


void tela_editar_compromisso(Compromisso* comp) {
    char editar;

    do {
        system("cls||clear");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||                           __ EDITAR __                          ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 1 ] Titulo                                            ||\n");
        printf(" ||         [ 2 ] ID do compromisso                                 ||\n");
        printf(" ||         [ 3 ] Data para entrega                                 ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 0 ] Retornar ao menu de Compromissos                  ||\n");
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf("           Digite sua escolha: ");
        scanf("%c", &editar);
        getchar();
        printf("\n");
        switch (editar) {
            case '1': tela_editar_titulo_Compromisso(comp);
                      break;
            case '2': tela_editar_id_Compromisso(comp);
                      break;
            case '3': tela_editar_data_Compromisso(comp);
                      break;
        }
    } while (editar != '0');
    comp->status = true;
}
//Funções feitas por: https://github.com/quirinof

void tela_editar_titulo_Compromisso(Compromisso* comp){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo titulo do compromisso: \n");
        printf("         => ");
        scanf("%[^\n]", comp->nome_comp);
        getchar();
        break;
    } while (!validar_nome(comp->nome_comp));
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}
//Funções feitas por: https://github.com/quirinof

void tela_editar_id_Compromisso(Compromisso* comp){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("            Novo ID do compromisso: \n");
        printf("            => ");
        scanf("%[^\n]", comp->id);
        getchar();
        break;
    } while (!valida_id(comp->id, 5));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 

}
//Funções feitas por: https://github.com/quirinof

void tela_editar_data_Compromisso(Compromisso* comp){
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                           __ EDITAR __                          ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Nova data de entrega da tarefa (dd/mm/aaaa): \n");
        printf("         => ");
        scanf("%[^\n]", comp->data_comp);
        getchar();
        break;
    } while (!valida_data(comp->data_comp));    
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Informacao atualizada ......              ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 

}

void tela_excluir_compromisso(char* id){
    // char id[6];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Excluir Compromisso = = = = = = = =         ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("            Digite o ID do Compromisso: \n");
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
void salvar_compromisso(Compromisso* comp) {
    FILE* fp;
    fp = fopen("compromisso.dat", "ab");
    if(fp == NULL) {
        printf("Algo deu errado"); 
    }
    fwrite(comp, sizeof(Compromisso), 1, fp);
    fclose(fp);
}

Compromisso* buscar_Compromisso(char* id){
    FILE* fp;
    Compromisso* comp;

    comp = (Compromisso*) malloc(sizeof(Compromisso));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL){
        printf("\n\nCompromisso não encontrado");
    }
    while(fread(comp, sizeof(Compromisso), 1,fp)){
        if ((strcmp(comp->id, id) == 0) && (comp->status == true)) {
			fclose(fp);
			return comp;
		}
    }
    fclose(fp);
    return NULL;
}

void exibirCompromisso(Compromisso* comp){
    if (comp == NULL){
        printf("\n= = = Compromisso Inexistente = = =\n");
    } else {
        printf("\n= = = Compromisso encontrado = = =\n");
        printf("ID: %s\n", comp->id);
        printf("Nome: %s\n", comp->nome_comp);
        printf("Data de Entrega(dd/mm/aaaa): %s \n", comp->data_comp);
        printf("ID da tarefa relacionada: %s \n", comp->id_tar);
        printf("CPF do Funcionario relacionado: %s \n", comp->cpf);
        printf("Status: %d\n", comp->status);
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}
void regravarCompromisso(Compromisso* comp) {
    int achou;
    FILE* fp;
    Compromisso* compLido;

    compLido = (Compromisso*) malloc(sizeof(Compromisso));
    fp = fopen("compromisso.dat", "r+b");
    if (fp == NULL){
        printf("\n= = = Compromisso Inexistente = = =\n");
    }
    achou = false;
    while(fread(compLido, sizeof(Compromisso), 1, fp) && !achou){
        if (strcmp(compLido->id, comp->id) == 0){
            achou = true;
            fseek(fp, -1*sizeof(Compromisso), SEEK_CUR);
        fwrite(comp, sizeof(Compromisso), 1, fp);    
        }
    }
    fclose(fp);
    free(compLido);
}




//UTIL
char* gerar_id_comp(void){
    FILE *fp;
    Compromisso *comp;
    int id_gerado = 1;
    char *id;
    comp = (Compromisso*) malloc(sizeof(Compromisso));
    id = (char*) malloc(6 * sizeof(char));
    fp = fopen("compromisso.dat", "rb");
    if (fp != NULL) {
        while (fread(comp, sizeof(Compromisso), 1, fp) == 1) {
            id_gerado++;
        }
        fclose(fp);
        free(comp);
    }
    sprintf(id, "%05d", id_gerado);
    return id;
}