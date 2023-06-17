//assinatura das validações:

#ifndef VALIDA_H
#define VALIDA_H

#include <stdbool.h>

bool validar_horas(char horas[]);
bool validar_email(char email[]);
bool validar_cpf(char cpf[]);

#endif /* VALIDA_H */


int digito(char);
int validar_letra(char);
int validar_nome(char*);
int verifica_data(int, int, int);
int valida_data(char*);
int valida_id(char*, int);
int quantidade_digitos(char*, int);

