typedef struct compromisso Compromisso;
struct compromisso {
    char nome_comp[51];
    char id[6];
    char id_tar[6];
    char cpf[12];
    char data_comp[11];
    int status;
};


///Assinaturas compromissos

void modulocompromissos(void);
void visualizar_compromisso(void);
void adicionar_compromisso(void);
void editar_compromisso(void);
void excluir_compromisso(void);

//telas
char* tela_visualizarcompromisso(void);
Compromisso* tela_adicionarcompromisso(void);
char telacompromissos(void);
char* tela_atualizar_compromisso(void);
void tela_editar_compromisso(Compromisso*);
void tela_editar_titulo_Compromisso(Compromisso*);
void tela_editar_id_Compromisso(Compromisso*);
void tela_editar_data_Compromisso(Compromisso*);
void tela_excluir_compromisso(char*);


void salvar_compromisso(Compromisso*);
Compromisso* buscar_Compromisso(char*);
void exibirCompromisso(Compromisso*);
void regravarCompromisso(Compromisso*);

//UTIL
char* gerar_id_comp(void);