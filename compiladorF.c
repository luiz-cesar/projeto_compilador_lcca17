
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Fun��es auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"

/* -------------------------------------------------------------------
*  definicoes para minimizar o codigo durante o desenvolvimento
* ------------------------------------------------------------------- */

#define EXECUCAO_BASICA_DA_TABELA_DE_SIMBOLOS           \
  id simbolo = tabela_de_simbolos;                      \
  while (simbolo)                                       \
  {                                                     \
    if (simbolo->nome == ident)                         \
      return 0;                                         \
    simbolo = simbolo->next;                            \
  }                                                     \
  simbolo = malloc(sizeof(struct t_id));                \
  simbolo->nome = malloc(strlen(ident) * sizeof(char)); \
  strcpy(simbolo->nome, ident);

#define PUSH_SIMBOLO_NA_TABELA_DE_SIMBOLOS stack_push((stack_t **)&tabela_de_simbolos, (stack_t *)simbolo);

/* -------------------------------------------------------------------
*  vari�veis globais
* ------------------------------------------------------------------- */

FILE *fp = NULL;

id tabela_de_simbolos = NULL;
tipo_expressao tabela_de_tipos_expressoes = NULL;

int contador_de_rotulos = 0;

/* -------------------------------------------------------------------
* procedimentos basicos do compilador
* ------------------------------------------------------------------- */

void geraCodigo(char *rot, char *comando)
{

  if (fp == NULL)
  {
    fp = fopen("MEPA", "w");
  }

  if (rot == NULL)
  {
    fprintf(fp, "      %s\n", comando);
    fflush(fp);
  }
  else
  {
    fprintf(fp, "%s: %s \n", rot, comando);
    fflush(fp);
  }
}

int imprimeErro(char *erro)
{
  fprintf(stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

char *gera_rotulo()
{
  char *rotulo = malloc(5 * sizeof(char));
  sprintf(rotulo, "R%03d", contador_de_rotulos);
  ++contador_de_rotulos;
  return rotulo;
}

/* -------------------------------------------------------------------
* procedimentos de insercao e remocao na tabela de simbolos
* ------------------------------------------------------------------- */

int insere_vs_tabela(char *ident, int nivel_lexico, int deslocamento)
{
  EXECUCAO_BASICA_DA_TABELA_DE_SIMBOLOS

  simbolo->tipo = variavel_simples;
  simbolo->info_variavel.nivel_lexico = nivel_lexico;
  simbolo->info_variavel.deslocamento = deslocamento;

  PUSH_SIMBOLO_NA_TABELA_DE_SIMBOLOS

  return 1;
}

int insere_procedimento_tabela(char *ident, int nivel_lexico)
{
  char *rotulo = gera_rotulo();

  EXECUCAO_BASICA_DA_TABELA_DE_SIMBOLOS

  simbolo->tipo = procedimento;
  simbolo->info_procedimento.nivel_lexico = nivel_lexico;
  simbolo->info_procedimento.rotulo = rotulo;

  PUSH_SIMBOLO_NA_TABELA_DE_SIMBOLOS

  return 1;
}

// int desaloca_procedimento_tabela(){
//   id simbolo = tabela_de_simbolos;
// }

/* -------------------------------------------------------------------
* procedimentos genericos da tabela de simbolos
* ------------------------------------------------------------------- */

// Libera o simbolo da tabela dependendo do seu tipo
void free_simbolo_na_tabela(int qtd)
{
  id simb;
  for (int i = 0; i < qtd; ++i)
  {
    simb = (struct t_id *)stack_pop((stack_t **)&tabela_de_simbolos);

    switch (simb->tipo)
    {
    case variavel_simples:
      break;
    default:
      break;
    }
    free(simb->nome);
    free(simb);
  }
}

id busca_simbolo_na_tabela(char *ident, tipos_simbolo tipo)
{
  id simb = tabela_de_simbolos;
  while (simb)
  {
    if (strcmp(simb->nome, ident) == 0)
    {
      if (simb->tipo == tipo)
        return simb;
      else
        return NULL;
    }
    simb = simb->next;
  }
}

/* -------------------------------------------------------------------
* procedimentos na tabela de simbolos especificos de cada tipo
* ------------------------------------------------------------------- */

void altera_tipo_tabela(tipos_simbolo tipo_var, int qtd_simbolos)
{
  id identificador = tabela_de_simbolos;
  for (int i = 0; i < qtd_simbolos; ++i)
  {
    identificador->info_variavel.tipo_variavel = tipo_var;
    identificador = identificador->next;
  }
}

tipos_var encontra_tipo(id simb)
{
  if (simb->tipo == variavel_simples)
    return simb->info_variavel.tipo_variavel;
}

int encontra_qtd_simbolos_antes_de_funcao(tipos_simbolo tipo_simbolo)
{
  int num_simbolos_ultima_funcao = 0;

  id simbolo = tabela_de_simbolos;
  while (simbolo && simbolo->tipo != procedimento)
  {
    if (simbolo->tipo == tipo_simbolo)
      ++num_simbolos_ultima_funcao;
    simbolo = simbolo->next;
  }
  return num_simbolos_ultima_funcao;
}
