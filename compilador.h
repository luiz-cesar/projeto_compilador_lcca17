/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prot�tipos e vai�veis globais do compilador
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

#define COMPARA_T_EXPRESSAO_E_POP                           \
  if (pilha_expressao->tipo != pilha_expressao->next->tipo) \
    imprimeErro("os tipos de variavel nao coincidem");      \
  free(stack_pop((stack_t **)&pilha_expressao));

#define COMPARA_T_RELACAO_BOOLEANA_E_POP                    \
  if (pilha_expressao->tipo != pilha_expressao->next->tipo) \
    imprimeErro("os tipos de variavel nao coincidem");      \
  free(stack_pop((stack_t **)&pilha_expressao));            \
  pilha_expressao->tipo = booleano;

#define GERA_E_EMPILHA_ROTULO                                                   \
  stack_push((stack_t **)&pilha_rotulos, malloc(sizeof(struct t_tipo_rotulo))); \
  pilha_rotulos->rotulo = gera_rotulo();

#define DESEMPILHA_ROTULO(NOME_VAR) \
  free(NOME_VAR->rotulo);           \
  free(stack_pop((stack_t **)&NOME_VAR));

#define COM_ARMAZENA_L_ELEM \
  l_elem->tipo == parametro_formal && l_elem->info_parametro.tipo_parametro == parametro_referencia ? "ARMI" : "ARMZ"

#define COM_CARREGA_ELEM_AUX \
  elem_aux->tipo == parametro_formal && elem_aux->info_parametro.tipo_parametro == parametro_referencia ? "CRVI" : "CRVL"

#define EMPILHA_FUNCAO(NOME_VAR)                                                                   \
  stack_push((stack_t **)&pilha_procedimentos, malloc(sizeof(struct t_tipo_pilha_procedimentos))); \
  pilha_procedimentos->item = NOME_VAR;

#define DESEMPILHA_SIMPLES(NOME_VAR) \
  free(stack_pop((stack_t **)&NOME_VAR));

// Enumeracao dos simbolos lidos pelo compilador
typedef enum simbolos
{
  simb_program,
  simb_var,
  simb_begin,
  simb_end,
  simb_identificador,
  simb_numero,
  simb_ponto,
  simb_virgula,
  simb_ponto_e_virgula,
  simb_dois_pontos,
  simb_atribuicao,
  simb_abre_parenteses,
  simb_fecha_parenteses,
  simb_if,
  simb_while,
  simb_mais,
  simb_menos,
  simb_asterisco,
  simb_div,
  simb_then,
  simb_else,
  simb_do,
  simb_igual,
  simb_diferente,
  simb_menor,
  simb_menor_igual,
  simb_maior,
  simb_maior_igual,
  simb_or,
  simb_and,
  simb_procedure,
  simb_function,
  simb_label,
  simb_goto
} simbolos;

/*********** DEFINICOES PARA VARIAVEIS SIMPLES ***********/

// Enumeracao dos tipos de variaveis possiveis
typedef enum tipos_var
{
  inteiro,
  booleano,
} tipos_var;

// Atributos de uma variavel simples
typedef struct
{
  // manter ordem
  int deslocamento;
  tipos_var tipo_variavel;
} t_variavel_simples;

/*********** DEFINICOES PARA PARAMETROS FORMAIS ***************/

typedef enum
{
  parametro_valor,
  parametro_referencia,
} tipos_parametro;

typedef struct
{
  // manter ordem
  int deslocamento;
  tipos_var tipo_variavel;
  tipos_parametro tipo_parametro;
} t_parametro_formal;

/*********** DEFINICOES PARA PROCEDIMENTOS ***************/

// Atributos de um procedimento
typedef struct
{
  char *rotulo;
  int qtd_variaveis_simples;
  int qtd_procedimentos_e_funcoes;
  int qtd_parametros;
  tipos_var tipo_retorno;
  t_parametro_formal *parametros;
} t_procedimento;

/*********** DEFINICOES PARA ROTULOS ***************/

// Atributos de um rotulo
typedef struct
{
  char *rotulo;
} t_rotulo;

/*********** DEFINICOES PARA TABELA DE SIMBOLOS **********/

// Enumeracao para os tipos de simbolos
typedef enum
{
  procedimento,
  funcao,
  variavel_simples,
  parametro_formal,
  label,
  variavel_ou_parametro,
  variavel_ou_funcao_ou_param,
} tipos_simbolo;

// Atributos de um simbolo
typedef struct t_id
{
  struct t_id *next;
  char *nome;
  int nivel_lexico;
  tipos_simbolo tipo;
  union {
    t_variavel_simples info_variavel;
    t_procedimento info_procedimento;
    t_parametro_formal info_parametro;
    t_rotulo info_rotulo;
  };
} * id;

/*********** DEFINICOES PARA PILHAS **********/

typedef struct t_tipo_expressao
{
  struct t_tipo_expressao *next;
  tipos_var tipo;
} * tipo_expressao;

typedef struct t_tipo_rotulo
{
  struct t_tipo_rotulo *next;
  char *rotulo;
} * tipo_rotulo;

typedef struct t_tipo_pilha_procedimentos
{
  struct t_tipo_pilha_procedimentos *next;
  id item;
} * tipo_pilha_procedimentos;

/* -------------------------------------------------------------------
* prototipo de funcoes
* ------------------------------------------------------------------- */

void geraCodigo(char *rot, char *comando);

int imprimeErro(char *erro);

char *gera_rotulo();

int insere_vs_tabela(char *ident, int nivel_lexico, int deslocamento);

int insere_pf_tabela(char *ident, int nivel_lexico, tipos_parametro tipo_parametro);

int insere_procedimento_tabela(char *ident, int nivel_lexico, tipos_simbolo tipo_simbolo);

int insere_rotulo_tabela(char *ident, int nivel_lexico);

void free_simbolo_na_tabela(int qtd);

id busca_simbolo_na_tabela(char *ident, tipos_simbolo tipo);

void altera_tipo_tabela(tipos_simbolo tipo_var, int qtd_simbolos);

tipos_var encontra_tipo(id simb);

int encontra_qtd_simbolos_antes_de_funcao(tipos_simbolo tipo_simbolo, int nivel_lexico);

int atualiza_parametros_procedimento();

int atualiza_retorno_funcao(tipos_simbolo tipo_var);

/* -------------------------------------------------------------------
* variaveis globais
* ------------------------------------------------------------------- */

extern simbolos simbolo,
    relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;
extern id tabela_de_simbolos;
extern tipo_expressao tabela_de_tipos_expressoes;

simbolos simbolo, relacao;
char token[TAM_TOKEN];
