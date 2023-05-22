////Assinaturas dos funcionarios

typedef struct funcionario Funcionario; 
    
struct funcionario {
    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];
    int status;
};
    



void modulofuncionarios(void);
char telafuncionarios(void);
Funcionario* telacadastrarfuncionario(void);
char* telapesquisarfuncionario(void);
char* telaeditarfuncionario(void);
char* telaexcluirfuncionario(void);
void cadastrarFuncionario(void);
void pesquisarFuncionario(void);
void editarFuncionario(void);
void excluirFuncionario(void);
void gravarFuncionario(Funcionario*);
void exibirFuncionario(Funcionario*);
Funcionario* buscar_Funcionario(char*);
void exibirFuncionario(Funcionario*);
void regravarFuncionario(Funcionario*);