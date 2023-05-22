#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcionarios.h"
#include "valida.h"

typedef struct funcionario Funcionario;

    

//Funções:

void modulofuncionarios(void){
    char opcao;
    do {
        opcao = telafuncionarios();
        switch(opcao) {
            case '1': 	cadastrarFuncionario();
                        break;
            case '2': 	pesquisarFuncionario();
                        break;
            case '3': 	editarFuncionario();
                        break;
            case '4': 	excluirFuncionario();
                        break;
        } 		
    } while (opcao != '0');
}

void cadastrarFuncionario(void) {
    Funcionario *func;

    func = telacadastrarfuncionario();
    gravarFuncionario(func);
    free(func);
}

void pesquisarFuncionario(void) {
    Funcionario *func;
    char* cpf;

    cpf = telapesquisarfuncionario();
    func = buscar_Funcionario(cpf);
    exibirFuncionario(func);
    free(func);
    free(cpf);

}

void editarFuncionario(void) {
    Funcionario* func;
    char* cpf;

    cpf = telaeditarfuncionario();
    func = buscar_Funcionario(cpf);
    if (func == NULL) {
        printf("\n\nFuncionario não encontrado");    
    } else {
        Funcionario* novoFuncionario = telacadastrarfuncionario();
        strcpy(func->cpf, novoFuncionario->cpf);
        regravarFuncionario(func);
        free(func);
        free(novoFuncionario);
    }
    free(cpf);
}

void excluirFuncionario(void){
    Funcionario* func;
    char* cpf;

    cpf = telaexcluirfuncionario();
    func = (Funcionario*) malloc(sizeof(Funcionario));
    func = buscar_Funcionario(cpf);
    if (func == NULL){
    printf("\n\nFuncionario não encontrado");    
    } else {
        func->status = false;
        regravarFuncionario(func);
        free(func);
    }
    free(cpf);
}

char telafuncionarios(void) {
    char op;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = =   Menu Funcionários = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um funcionário                                 ///\n");
    printf("///           2. Pesquisar funcionário                                    ///\n");
    printf("///           3. Editar funcionário                                       ///\n");
    printf("///           4. Excluir funcionário                                      ///\n");
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

Funcionario* telacadastrarfuncionario(void) {
    Funcionario *func;

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = Cadastrar Funcionário = = = = = = = =       ///\n");
    printf("///                                                                       ///\n");
    printf("///           CPF (apenas números): ");
    func = (Funcionario*) malloc(sizeof(Funcionario));
    do {
        printf("/// CPF (apenas números): ");
        scanf("%[0-9]", func->cpf);
        getchar();
    } while (!validar_cpf(func->cpf));
    printf("///           Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
    getchar();
    printf("///           E-mail: ");
    scanf("%[A-Za-z0-9@._]", func->email);
    getchar();
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[0-9/]", func->nasc);
    getchar();
    printf("///           Celular  (apenas números): ");
    scanf("%[0-9]", func->celular);
    getchar();
    func->status = true; 
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return func;
}

char* telapesquisarfuncionario(void){
    char* cpf;


    cpf = (char*) malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Pesquisar Funcionário = = = = = = = =       ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return cpf;
}

char* telaeditarfuncionario(void) {
    char* cpf;

    cpf = (char*) malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Editar Funcionário = = = = = = = =          ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return cpf;

}

char* telaexcluirfuncionario(void){
    char* cpf;

    cpf = (char*) malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Excluir Funcionário = = = = = = = =         ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return cpf;
}

void gravarFuncionario(Funcionario* func){
    FILE* fp;

    fp = fopen("funcionarios.dat", "ab");
    if (fp == NULL){
        printf("\n\nFuncionario não encontrado");
    }
    fwrite(func, sizeof(Funcionario), 1, fp);
    fclose(fp);
}

Funcionario* buscar_Funcionario(char* cpf){
    FILE* fp;
    Funcionario* func;

    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL){
        printf("\n\nFuncionario não encontrado");
    }
    while(fread(func, sizeof(Funcionario), 1,fp)){
        if ((strcmp(func->cpf, cpf) == 0) && (func->status == true)) {
			fclose(fp);
			return func;
		}
    }
    fclose(fp);
    return NULL;
}

void exibirFuncionario(Funcionario* func){
    if (func == NULL){
        printf("\n= = = Funcionario Inexistente = = =\n");
    } else {
        printf("\n= = = Funcionario Cadastrado = = =\n");
        printf("CPF: %s\n", func->cpf);
        printf("Nome: %s\n", func->nome);
        printf("Email: %s\n", func->email);
        printf("Data de nascimento: %s\n", func->nasc);
        printf("Celular: %s\n", func->celular);
        printf("Status: %d\n", func->status);

    }
    printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarFuncionario(Funcionario* func) {
    int achou;
    FILE* fp;
    Funcionario* funcLido;

    funcLido = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL){
        printf("\n= = = Funcionario Inexistente = = =\n");
    }
    achou = false;
    while(fread(funcLido, sizeof(Funcionario), 1, fp) && !achou){
        if (strcmp(funcLido->cpf, func->cpf) == 0){
            achou = true;
            fseek(fp, -1*sizeof(Funcionario), SEEK_CUR);
        fwrite(func, sizeof(Funcionario), 1, fp);    
        }
    }
    fclose(fp);
    free(funcLido);
}