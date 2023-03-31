#include <stdio.h>
#include <stdlib.h>

//Funções:

void telamenu(void);
void telasobre(void);
void telafuncionarios(void);
void telacadastrarfuncionario(void);
void telapesquisarfuncionario(void);
void telaeditarfuncionario(void);
void telaexcluirfuncionario(void);

//principal:

int main(void) {
    telamenu();
    telasobre();
    telafuncionarios();
    telacadastrarfuncionario();
    telapesquisarfuncionario();
    telaeditarfuncionario();
    telaexcluirfuncionario();
    return 0;
 
}

void telamenu(void) {
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
    printf("///                Developed by @Pedro-E-Rodrigues-- 2023                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");               
    printf("///            1. Menu Funcionários                                         ///\n");
    printf("///            2. Menu Agenda                                               ///\n");
    printf("///            3. Sair                                                      ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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

void telafuncionarios(void) {
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
    getchar();
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