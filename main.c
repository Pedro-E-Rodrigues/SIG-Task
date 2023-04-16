#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Funções:

char telamenu(void);
void telasobre(void);

void modulofuncionarios(void);
char telafuncionarios(void);
void telacadastrarfuncionario(void);
void telapesquisarfuncionario(void);
void telaeditarfuncionario(void);
void telaexcluirfuncionario(void);

void modulocompromissos(void);
char telacompromissos(void);
void visualizarcompromisso(void);
void adicionarcompromisso(void);
void editarcompromisso(void);
void excluircompromisso(void);

void modulotarefas(void);
char telatarefas(void);
void visualizartarefa(void);
void adicionartarefa(void);
void editartarefa(void);
void excluirtarefa(void);

void telarelatorio(void);

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
            case '4':   // Módulo Relatórios
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

void modulofuncionarios(void){
    char opcao;
    do {
        opcao = telafuncionarios();
        switch(opcao) {
            case '1': 	telacadastrarfuncionario();
                        break;
            case '2': 	telapesquisarfuncionario();
                        break;
            case '3': 	telaeditarfuncionario();
                        break;
            case '4': 	telaexcluirfuncionario();
                        break;
        } 		
    } while (opcao != '0');
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

void telacadastrarfuncionario(void) {
    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = Cadastrar Funcionário = = = = = = = =       ///\n");
    printf("///                                                                       ///\n");
    printf("///           CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///           Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///           E-mail: ");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[0-9/]", nasc);
    getchar();
    printf("///           Celular  (apenas números): ");
    scanf("%[0-9]", celular);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telapesquisarfuncionario(void){
    char cpf[12];

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
    getchar();
}

void telaeditarfuncionario(void) {
    char cpf[12];

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
    getchar();

}

void telaexcluirfuncionario(void){
    char cpf[12];

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
    getchar();
}

void modulocompromissos(void){
    char opcao;
    do {
        opcao = telacompromissos();
        switch(opcao) {
            case '1': 	visualizarcompromisso();
                        break;
            case '2': 	adicionarcompromisso();
                        break;
            case '3': 	editarcompromisso();
                        break;
            case '4': 	excluircompromisso();
                        break;
        } 		
    } while (opcao != '0');
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

void visualizarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = = = Visualizar Compromissos = = = = = = = =     ///\n");
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

void adicionarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Adicionar Compromissos = = = = = = = =      ///\n");
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

void editarcompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Editar Compromissos = = = = = = = =         ///\n");
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

void excluircompromisso(void){
    char cpf[12];

    system("clear||cls");
    printf("\n"); 
    printf("///           = = = = = = = = Excluir Compromissos = = = = = = = =        ///\n");
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

void telarelatorio(void){
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("///           = = = = = = =  Relatórios  = = = = = = = = = = =               ///\n");
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