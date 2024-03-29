
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.

%{

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"
#define YYSTYPE long int

int yylex();
void yyerror(const char *s);

int num_vars;
char aux_string[128];

int ultimo_tipo;

// Implementar nivel lexico em stack
int nivel_lexico = -1;

int somente_identificador = 1;

id l_elem, elem_aux;

tipo_expressao pilha_expressao = NULL;
tipo_rotulo pilha_rotulos = NULL;

tipos_parametro tipo_parametro;

tipo_pilha_procedimentos pilha_procedimentos = NULL;


%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES NUMERO
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token MAIS MENOS DIV ASTERISCO
%token IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR MAIOR_IGUAL
%token IF THEN ELSE WHILE DO
%token AND OR
%token PROCEDURE FUNCTION
%token LABEL GOTO
%token READ WRITE
%token BOOLEAN INTEGER TRUE FALSE NEGACAO

%%

programa:
   {geraCodigo (NULL, "INPP");}
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco PONTO {
      geraCodigo (NULL, "PARA");
   }
;

bloco:
   {
      ++nivel_lexico;
   }
   parte_declaracoes
   comando_composto
   {
      sprintf(aux_string, "DMEM  %d", encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      geraCodigo(NULL, aux_string);
      libera_simbolos_internos_de_funcao(nivel_lexico);
      --nivel_lexico;
   }
;

parte_declaracoes:
   parte_declaracoes parte_declara_subrotinas |
   parte_declaracoes parte_declara_vars |
   parte_declaracoes parte_declara_rotulos |
;

parte_declara_rotulos:
   LABEL declara_rotulos PONTO_E_VIRGULA
;

declara_rotulos:
   declara_rotulos VIRGULA NUMERO  {
      insere_rotulo_tabela(token, nivel_lexico);
   } |
   NUMERO {
      insere_rotulo_tabela(token, nivel_lexico);
   }
;

parte_declara_vars:
   VAR declara_vars
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
      altera_tipo_tabela(ultimo_tipo, num_vars);
   }
   PONTO_E_VIRGULA
;

tipo:
   BOOLEAN {
      ultimo_tipo = booleano;
   } | INTEGER {
      ultimo_tipo = inteiro;
   }
;

lista_id_var:
   lista_id_var VIRGULA IDENT
   {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   } |
   IDENT
   {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   }
;

lista_idents:
   lista_idents VIRGULA IDENT {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   } |
   IDENT {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   }
;

parte_declara_subrotinas:
   declara_funcao PONTO_E_VIRGULA |
   declara_procedimento PONTO_E_VIRGULA
;

declara_procedimento:
   PROCEDURE
   IDENT {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, procedimento);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   }
   declara_parametros PONTO_E_VIRGULA bloco {
      sprintf(aux_string, "RTPR %d, %d", nivel_lexico + 1, tabela_de_simbolos->info_procedimento.qtd_parametros);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
;

declara_funcao:
   FUNCTION
   IDENT {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, funcao);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   } declara_parametros DOIS_PONTOS tipo {
      atualiza_retorno_funcao(ultimo_tipo);
   } PONTO_E_VIRGULA bloco {
      sprintf(aux_string, "RTPR %d, %d", nivel_lexico + 1, tabela_de_simbolos->info_procedimento.qtd_parametros);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   };
;

declara_parametros:
   ABRE_PARENTESES parametros_formais FECHA_PARENTESES {
      tipo_parametro = 0;
      atualiza_parametros_procedimento();
   } |
;

parametros_formais:
   parametros_formais PONTO_E_VIRGULA secao_de_parametros_formais |
   secao_de_parametros_formais
;

secao_de_parametros_formais:
   VAR {
      tipo_parametro = parametro_referencia;
      num_vars = 0;
   } lista_idents DOIS_PONTOS tipo {
      altera_tipo_tabela(ultimo_tipo, num_vars);
   } |
   {
      tipo_parametro = parametro_valor;
      num_vars = 0;
   }
   lista_idents DOIS_PONTOS tipo {
      altera_tipo_tabela(ultimo_tipo, num_vars);
   }
;

comando_composto:
   T_BEGIN comandos T_END |
   T_BEGIN comandos PONTO_E_VIRGULA T_END
;

comandos:
   comandos PONTO_E_VIRGULA comando |
   comando
;

comando:
   NUMERO {
      l_elem = busca_simbolo_na_tabela(token, label);
      sprintf(aux_string, "ENRT %d, %d", nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      geraCodigo(l_elem->info_rotulo.rotulo, aux_string);

   } DOIS_PONTOS comando_sem_rotulo |
   comando_sem_rotulo
;

comando_sem_rotulo:
   impressao |
   leitura |
   IDENT {strcpy(aux_string, token);} comando_com_ident |
   comando_condicional |
   desvio |
   comando_repetitivo |
   comando_composto |
;

desvio:
   GOTO NUMERO {
      elem_aux = busca_simbolo_na_tabela(token, label);
      sprintf(aux_string, "DSVR %s, %d, %d", elem_aux->info_rotulo.rotulo, elem_aux->nivel_lexico, nivel_lexico);
      geraCodigo(NULL, aux_string);
   };
;

comando_com_ident:
   atribuicao |
   chamada_procedimento
;

comando_fator_com_ident:
   IDENT {strcpy(aux_string, token);} comando_pos_ident;
;

comando_pos_ident:
   ABRE_PARENTESES {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, funcao))
      geraCodigo(NULL, "AMEM 1");
   } lista_de_expressoes FECHA_PARENTESES {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
         imprimeErro("O número de parâmtros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   } | {
      elem_aux = busca_simbolo_na_tabela(aux_string, variavel_ou_funcao_ou_param);
      if(elem_aux->tipo == funcao){
         EMPILHA_FUNCAO(busca_simbolo_na_tabela(token, funcao))
         geraCodigo(NULL, "AMEM 1");
         if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
            imprimeErro("O número de parâmtros não coincide com declaração");
         sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
         geraCodigo(NULL, aux_string);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
         DESEMPILHA_SIMPLES(pilha_procedimentos)
      }
      else {
         if(pilha_procedimentos){
            if (pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_parametro == parametro_referencia){
               if(!somente_identificador)
                  imprimeErro("Argumento inválido");
               somente_identificador = 0;
               sprintf(aux_string, "CREN %d, %d", elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
            }
            else
               sprintf(aux_string, "%s %d, %d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         }
         else
            sprintf(aux_string, "%s %d, %d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=encontra_tipo(elem_aux);
         geraCodigo(NULL, aux_string);
      }
   }
;

chamada_procedimento:
   {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, procedimento))
   } lista_parametros {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
         imprimeErro("O número de parâmetros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   }
;

lista_parametros:
   ABRE_PARENTESES lista_de_expressoes FECHA_PARENTESES |
;

lista_de_expressoes:
   lista_de_expressoes VIRGULA expressao_simples {
      if(pilha_procedimentos){
         somente_identificador = 1;
         if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_variavel)
            imprimeErro("os tipos de variavel nao coincidem");
         free(stack_pop((stack_t **)&pilha_expressao));
         ++pilha_procedimentos->conta_parametros;
      };
   } |
   expressao_simples {
      if(pilha_procedimentos){
         somente_identificador = 1;
         if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_variavel)
            imprimeErro("os tipos de variavel nao coincidem");
         free(stack_pop((stack_t **)&pilha_expressao));
         ++pilha_procedimentos->conta_parametros;
      };
   }
;

atribuicao:
   ATRIBUICAO {
      l_elem = busca_simbolo_na_tabela(aux_string, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", aux_string);
         imprimeErro(aux_string);
      }
   } expressao_simples {
      // ADICIONAR ERRO CASO SIMBOLOS DE TIPOS DIFERENTES
      if(encontra_tipo(l_elem) != pilha_expressao->tipo)
         imprimeErro("os tipos de variavel nao coincidem");
      free(stack_pop((stack_t **)&pilha_expressao));
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
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
      geraCodigo(NULL, "CMEG");
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
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "SOMA");
   } |
   expressao_simples MENOS termo {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "SUBT");
   } |
   expressao_simples OR termo {
      COMPARA_T_EXPRESSAO_E_POP(booleano)
      geraCodigo(NULL, "DISJ");
   } |
   termo
;

termo:
   termo ASTERISCO fator {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "MULT");
   } |
   termo DIV fator {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "DIVI");
   } |
   termo AND fator {
      COMPARA_T_EXPRESSAO_E_POP(booleano)
      geraCodigo(NULL, "CONJ");
   } |
   fator
;

fator:
   NUMERO {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=inteiro;
      sprintf(aux_string, "CRCT %s", token);
      geraCodigo(NULL, aux_string);
   } | booleano {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=booleano;
   } |
   ABRE_PARENTESES expressao FECHA_PARENTESES |
   NEGACAO fator {
      if(!pilha_expressao->tipo==booleano)
         imprimeErro("Tipo inválido");
      geraCodigo(NULL, "NEGA");
   } |
   comando_fator_com_ident
;

booleano:
   TRUE {
      sprintf(aux_string, "CRCT 0");
      geraCodigo(NULL, aux_string);
   } | FALSE {
      sprintf(aux_string, "CRCT 1");
      geraCodigo(NULL, aux_string);
   }
;


comando_condicional:
   IF expressao {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));

      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
   THEN  comando_sem_rotulo continuacao_condicional
;

continuacao_condicional:
   ELSE {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->next->rotulo, "NADA");
   } comando_sem_rotulo {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   } | {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
;


comando_repetitivo:
   WHILE {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "NADA");
      geraCodigo(pilha_rotulos->rotulo, aux_string);
   }
   expressao {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));

      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
   DO comando_sem_rotulo {
      sprintf(aux_string, "DSVS %s", pilha_rotulos->next->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
;

lista_de_expressoes_impressao:
   lista_de_expressoes_impressao VIRGULA expressao_simples {
      free(stack_pop((stack_t **)&pilha_expressao));
      geraCodigo(NULL, "IMPR");
   } |
   expressao_simples {
      free(stack_pop((stack_t **)&pilha_expressao));
      geraCodigo(NULL, "IMPR");
   }
;

lista_variaveis_leitura:
   lista_variaveis_leitura VIRGULA IDENT {
      l_elem = busca_simbolo_na_tabela(token, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", token);
         imprimeErro(aux_string);
      }
      geraCodigo(NULL, "LEIT");
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   }
   | IDENT {
      l_elem = busca_simbolo_na_tabela(token, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", token);
         imprimeErro(aux_string);
      }
      geraCodigo(NULL, "LEIT");
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   }
;

leitura:
   READ ABRE_PARENTESES lista_variaveis_leitura FECHA_PARENTESES
;


impressao:
   WRITE ABRE_PARENTESES lista_de_expressoes_impressao FECHA_PARENTESES
;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;


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

