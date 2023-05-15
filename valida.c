#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "valida.h"

////////////////Validação de digito:
/// Autor: https://github.com/rauan-meirelles

int Digito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

////////////////Validação de letra:
/// Autor: https://github.com/rauan-meirelles

int validar_letra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

////////////////Validação de nome:
/// Autor: https://github.com/rauan-meirelles

int validar_nome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!validar_letra(nome[i])) {
      return 0;
    }
  }
	return 1;
}

////////////////Validação de cpf:
/// Autor: Chat.openai.com


bool validar_cpf(char cpf[]) {
    int i, j, digito1 = 0, digito2 = 0;
    
    // Verifica se o CPF tem 11 dígitos
    if (strlen(cpf) != 11) {
        return false;
    }
    
    // Verifica se todos os caracteres são dígitos
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    
    // Calcula o primeiro dígito verificador
    for (i = 0, j = 10; i < 9; i++, j--) {
        digito1 += (cpf[i] - '0') * j;
    }
    digito1 = (digito1 % 11 < 2) ? 0 : 11 - (digito1 % 11);
    
    // Verifica o primeiro dígito verificador
    if (digito1 != cpf[9] - '0') {
        return false;
    }
    
    // Calcula o segundo dígito verificador
    for (i = 0, j = 11; i < 10; i++, j--) {
        digito2 += (cpf[i] - '0') * j;
    }
    digito2 = (digito2 % 11 < 2) ? 0 : 11 - (digito2 % 11);
    
    // Verifica o segundo dígito verificador
    if (digito2 != cpf[10] - '0') {
        return false;
    }
    
    // CPF válido
    return true;
}

////////////////Validação de email:
/// Autor: Chat.openai.com


bool validar_email(char email[]) {
    int i, tam, arroba = 0;
    tam = strlen(email);
    
    if (tam < 5) {
        return false; // um email válido deve ter pelo menos 5 caracteres
    }
    
    for (i = 0; i < tam; i++) {
        if (email[i] == '@') {
            arroba++;
        } else if (email[i] == '.') {
            if (i < tam - 1 && email[i+1] == '.') {
                return false; // não pode haver dois pontos seguidos
            }
        }
    }
    
    if (arroba != 1) {
        return false; // deve haver exatamente um arroba no e-mail
    }
    
    if (email[0] == '@' || email[tam-1] == '@' ||
        email[0] == '.' || email[tam-1] == '.' || 
        email[tam-1] == '-') {
        return false; // não pode haver caracteres inválidos no início, fim ou após o arroba
    }
    
    return true;
}


////////////////Validação de data:
/// Autor: https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas

int valida_data(int dia, int mes, int ano) { 
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) ///verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) ///verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) ///verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) ///verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) ///verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}

////////////////Validação de hora:
/// Autor: Autor: http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/

int validar_horas(char hora) 
{
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;     
  
  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);  
  
  //para acessar os membros de uma struct usando o ponteiro
  //utilizamos o operador -> no nosso caso temos: 
  //data_hora_atual->membro_da_struct
  
  //Acessando dados convertidos para a struct data_hora_atual  
  printf("\nDia..........: %d\n", data_hora_atual->tm_mday);  
  
  //para retornar o mês corretamente devemos adicionar +1 
  //como vemos abaixo
  printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
  
  //para retornar o ano corretamente devemos adicionar 1900 
  //como vemos abaixo
  printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
  
  printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);  
  printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);
    
  /* Obtendo os valores da struct data_hora_atual  
    e formatando a saída de dados no formato 
    hora: minuto: segundo
     
  Para não ficar um printf muito longo em uma única linha
  de comando, quebrei a impressão em 3 partes mostrando
  uma informação em cada linha 
  */  
  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo  
  
  /* Obtendo os valores da struct data_hora_atual  
     e formatando a saída de dados no formato dia/mes/ano 
     
     Para não ficar um printf muito longo em uma única 
     linha de comando, quebrei a impressão em 3 partes
     sendo uma informação em cada linha   
  */  
  //dia do mês
  printf("\nData ........: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano
  
  return 0;
}