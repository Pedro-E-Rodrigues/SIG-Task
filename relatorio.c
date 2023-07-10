#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "relatorio.h"
#include "funcionarios.h"
#include "valida.h"
#include "tarefas.h"
#include "compromissos.h"
#include <string.h>

void relatorio_ordenado_fnc(Funcionario **);
void exibir_lista_fnc(Funcionario *);
void excluir_lista_fnc(Funcionario **);


void modulo_Relatorio(void){
    char opcao;
    do{
        opcao = telarelatorio();
        switch(opcao){
            case '1': listar_funcionarios();
                    break;
            case '2': listar_tarefasFunc();
                    break;
            case '3': listar_tarefas();
                    break;
            case '4': listar_compromissos();
                    break;   
            case '5': modulo_lista_ordenada_funcionarios();
                    break;                             
        }    
    }while (opcao != '0');
}

void modulo_lista_ordenada_funcionarios(void) {
    Funcionario *lista;
    lista = NULL;
    relatorio_ordenado_fnc(&lista);
    exibir_lista_fnc(lista);
    excluir_lista_fnc(&lista);
}


char telarelatorio(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Relatórios  = = = = = = = = = = =            ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Listar Funcionarios                                      ///\n");
	printf("///           2. Exibir Tarefas por Funcionario                           ///\n");
	printf("///           3. Listar Tarefas                                           ///\n");
    printf("///           4. Listar Compromissos                                      ///\n");
    printf("///           5. Listagem Ordenada dos Funcionarios                       ///\n");
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

void listar_tarefas(void){
    FILE* fp;
    Tarefa* tar;

    tar = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    while(fread(tar, sizeof(Tarefa), 1,fp)){
        exibirTarefa(tar);
        printf("/n");
    }
    fclose(fp);
    free(tar);


}

void listar_compromissos(void){
    FILE* fp;
    Compromisso* comp;

    comp = (Compromisso*) malloc(sizeof(Compromisso));
    fp = fopen("compromisso.dat", "rb");
    while(fread(comp, sizeof(Compromisso), 1,fp)){
        exibirCompromisso(comp);
        printf("/n");
    }
    fclose(fp);
    free(comp);


}

void listar_tarefasFunc(void){
    FILE* fp;
    Tarefa* tar;
    char cpf[12];

    tar = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    printf("/// CPF (apenas números): ");
    scanf("%[0-9]",cpf);
    getchar();
    while(fread(tar, sizeof(Tarefa), 1,fp)){
        if (strcmp(tar->cpf,cpf)==0) {
            exibirTarefa(tar);
            printf("\n");
        
        }
    }
    fclose(fp);
    free(tar);


}

void relatorio_ordenado_fnc(Funcionario **lista) {
    FILE *fp;
    Funcionario *func;

    excluir_lista_fnc(&(*lista));
    *lista = NULL;
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Algo deu Errado");
    }
    else {
        func = (Funcionario*) malloc(sizeof(Funcionario));
        while (fread(func, sizeof(Funcionario), 1, fp)) {
            if ((*lista == NULL) || (strcmp(func->nome, (*lista)->nome) < 0)) {
                func->prox = *lista;
                *lista = func;
            }
            else {
                Funcionario *ant = *lista;
                Funcionario *atu =  (*lista)->prox;
                while ((atu != NULL) && (strcmp(atu->nome, func->nome) < 0)) {
                    ant = atu;
                    atu = atu->prox;
                }
                ant->prox = func;
                func->prox = atu;
            }
            func = (Funcionario *) malloc(sizeof(Funcionario));
        }
        free(func);
        fclose(fp);
    }
} // by: @FlaviusGorgonio

void exibir_lista_fnc(Funcionario *aux) {
    system("cls||clear");
    while( aux != NULL){
        printf("CPF: %s\n", aux->cpf);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        printf("Data de nascimento: %s\n", aux->nasc);
        printf("Celular: %s\n", aux->celular);
        printf("Status: %d\n", aux->status);
        aux = aux->prox;
    }
    getchar();
}

void excluir_lista_fnc(Funcionario **lista) {
    Funcionario *func; 
    while (*lista != NULL) {
        func = *lista;
        *lista = (*lista)->prox;
        free(func);
    }
}
