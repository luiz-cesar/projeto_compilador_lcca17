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
  if (pilha_expressao->tipo == pilha_expressao->next->tipo) \
    free(stack_pop((stack_t **)&pilha_expressao));

#define COMPARA_T_RELACAO_BOOLEANA_E_POP                    \
  if (pilha_expressao->tipo == pilha_expressao->next->tipo) \
  {                                                         \
    free(stack_pop((stack_t **)&pilha_expressao));          \
    pilha_expressao->tipo = booleano;                       \
  }

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
  int nivel_lexico;
  int deslocamento;
  tipos_var tipo_variavel;
} t_variavel_simples;

/*********** DEFINICOES PARA PROCEDIMENTOS ***************/

// Atributos de um procedimento
typedef struct
{
  char *rotulo;
  int nivel_lexico;
} t_procedimento;

/*********** DEFINICOES PARA TABELA DE SIMBOLOS **********/

// Enumeracao para os tipos de simbolos
typedef enum
{
  procedimento,
  variavel_simples,
} tipos_simbolo;

// Atributos de um simbolo
typedef struct t_id
{
  struct t_id *next;
  char *nome;
  tipos_simbolo tipo;
  union {
    t_variavel_simples info_variavel;
    t_procedimento info_procedimento;
  };
} * id;

/*********** DEFINICOES PARA FILAS **********/

typedef struct t_tipo_expressao
{
  struct t_tipo_expressao *next;
  tipos_var tipo;
} * tipo_expressao;

/* -------------------------------------------------------------------
* prototipo de funcoes
* ------------------------------------------------------------------- */

void geraCodigo(char *rot, char *comando);

int imprimeErro(char *erro);

char *gera_rotulo();

int insere_vs_tabela(char *ident, int nivel_lexico, int deslocamento);

id busca_simbolo_na_tabela(char *ident, tipos_simbolo tipo);

void altera_tipo_tabela(tipos_simbolo tipo_var, int qtd_simbolos);

tipos_var encontra_tipo(id simb);

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
