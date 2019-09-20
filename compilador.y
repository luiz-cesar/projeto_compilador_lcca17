
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"




int num_vars;
char aux_string[128];

// Implementar nivel lexico em stack
int nivel_lexico, deslocamento_variavel;

id l_elem, elem_aux;

tipo_expressao pilha_expressao = NULL;


%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES NUMERO
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token MAIS MENOS DIV ASTERISCO
%token IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL
%token IF THEN ELSE WHILE DO
%token AND OR

%%

programa:
   {geraCodigo (NULL, "INPP");}
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco PONTO
   {geraCodigo (NULL, "PARA"); /* DESALOCAR VARIAVEIS */ }
;

bloco:
   {
      deslocamento_variavel = 0;
      ++nivel_lexico;
   }
   parte_declaracoes
   comando_composto
;

parte_declaracoes:
   // parte_declaracoes |
   parte_declara_vars
;

parte_declara_vars:
   var
;

var:
   {}
   VAR declara_vars|
;

declara_vars:
   declara_vars declara_var |
   declara_var
;

declara_var:
   { num_vars = 0; }
   lista_id_var DOIS_PONTOS
   tipo
   {
      sprintf(aux_string, "AMEM  %d", num_vars);
      geraCodigo(NULL, aux_string);
      altera_tipo_tabela(inteiro, num_vars);
   }
   PONTO_E_VIRGULA
;

tipo:
   IDENT
;

lista_id_var:
   lista_id_var VIRGULA IDENT
   {
      insere_vs_tabela(token, nivel_lexico, deslocamento_variavel);
      ++num_vars;++deslocamento_variavel;
   } |
   IDENT
   {
      insere_vs_tabela(token, nivel_lexico, deslocamento_variavel);
      ++num_vars;++deslocamento_variavel;
   }
;

lista_idents:
   lista_idents VIRGULA IDENT |
   IDENT
;


comando_composto:
   T_BEGIN comandos T_END
;

comandos:
   comandos comando PONTO_E_VIRGULA |
   comando PONTO_E_VIRGULA |
   // COMANDO VAZIO PARA TESTES
;

comando:
   comando_sem_rotulo
;

comando_sem_rotulo:
   atribuicao |
   comando_condicional |
   comando_repetitivo |
   comando_composto
;

atribuicao:
   IDENT {
      l_elem = busca_simbolo_na_tabela(token, variavel_simples);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", "token");
         imprimeErro(aux_string);
      }
   }
   ATRIBUICAO expressao_simples {
      // ADICIONAR ERRO CASO SIMBOLOS DE TIPOS DIFERENTES
      if(encontra_tipo(l_elem) == pilha_expressao->tipo)
         free(stack_pop((stack_t **)&pilha_expressao));
      sprintf(aux_string, "ARMZ %d,%d", l_elem->info_variavel.nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   }
;

expressao:
   expressao_simples |
   relacao
;

relacao:
   expressao_simples IGUAL expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMIG");
   } |
   expressao_simples DIFERENTE expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMDG");
   } |
   expressao_simples MENOR expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMME");
   } |
   expressao_simples MENOR_IGUAL expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMIG");
   } |
   expressao_simples MAIOR expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMMA");
   } |
   expressao_simples MAIOR_IGUAL expressao_simples {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMAG");
   }
;

expressao_simples:
   expressao_simples MAIS termo {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "SOMA");
   } |
   expressao_simples MENOS termo {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "SUBT");
   } |
   expressao_simples OR termo {
      COMPARA_T_EXPRESSAO_E_POP
   } |
   termo
;

termo:
   termo ASTERISCO fator {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "MULT");
   } |
   termo DIV fator {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "DIVI");
   } |
   termo AND fator {
      COMPARA_T_EXPRESSAO_E_POP
   } |
   fator
;

fator:
   IDENT {
      // FAZER BUSCA DO TOKEN E ADICIONAR A PILHA DE TIPOS
      elem_aux = busca_simbolo_na_tabela(token, variavel_simples);
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=encontra_tipo(elem_aux);
      sprintf(aux_string, "CRVL %d,%d", elem_aux->info_variavel.nivel_lexico, elem_aux->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   } |
   NUMERO {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=inteiro;
      sprintf(aux_string, "CRCT %s", token);
      geraCodigo(NULL, aux_string);
   }
;

comando_condicional:
   IF expressao {
      sprintf(aux_string, "DSVF %s", gera_rotulo());
      geraCodigo(NULL, aux_string);
   }
   THEN comando_sem_rotulo {
      // R00: NADA
   } |
   IF expressao {
      sprintf(aux_string, "DSVF %s", gera_rotulo());
      geraCodigo(NULL, aux_string);
   }
   THEN comando_sem_rotulo {
      sprintf(aux_string, "DSVS %s", gera_rotulo());
      geraCodigo(NULL, aux_string);
   } ELSE {
      // R00: NADA
   } comando_sem_rotulo {
      // R01: NADA
   }
;

comando_repetitivo:
   WHILE {
      sprintf(aux_string, "NADA");
      // TEM Q SALVAR O ROTULO NA PILHA
      geraCodigo(gera_rotulo(), aux_string);
   }
   expressao {
      sprintf(aux_string, "DSVF %s", gera_rotulo());
      geraCodigo(NULL, aux_string);
   }
   DO comando_sem_rotulo
;

%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   deslocamento_variavel = 0;
   nivel_lexico = -1;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


   /* -------------------------------------------------------------------
   *  Inicia a Tabela de S�mbolos
   * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}

