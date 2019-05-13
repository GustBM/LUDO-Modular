#if ! defined( TABULEIRO_ )
#define TABULEIRO_

/***************************************************************************
*
*  $MCD Módulo de definição: TAB  Módulo do tabuleiro para LUDO
*
*  Arquivo gerado:              tabuleiro.h
*  Letras identificadoras:      TAB
*
*
*  Projeto: INF 1301 / TESTE 2 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: GBM - Gustavo Barros Marchesan
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       GBM   07/mai/2019 início desenvolvimento
*	  2		  GBM	12/mai/2019 Junção dos módulos tabuleiro e peca
*	  3		  GBM	12/mai/2019 Remoção da peca como parte do tabuleiro
*
*  $ED Descrição do módulo
*     Módulo para criação e manipulação do tabuleiro e pecas para o jogo LUDO
*
***************************************************************************/

#if defined( TABULEIRO_OWN )
#define TABULEIRO_EXT
#else
#define TABULEIRO_EXT extern
#endif

#include "peca.h"
#include "lista_circular.h"
#include "lista.h"

/***** Declarações exportadas pelo módulo *****/

typedef struct TAB_tagTabuleiro * TAB_tppTabuleiro;

typedef struct TAB_tagCasaInfo * TAB_tppCasaInfo;

/***********************************************************************
*
*  $TC Tipo de dados: GT Códigos de retorno de funções
*
*
***********************************************************************/

   typedef enum {

         CondRetOK ,
               /* Função executou correto */

         CondRetErro ,
               /* Erro de leitura de arquivo */

         CondRetMem
               /* Erro de espaço na memória */

   } tpCondRet ;

/***********************************************************************
*
*  $FC Função: TAB  &Criar Tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro para o LUDO, composto por uma lista circular
*	  composta por 56 posições e 4 listas comuns composta por 5 casas cada
*	  A função não precisa de parâmetros para fazer as listas porque ela já
*	  será uma lista de casas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a tabela.
*     Este ponteiro será utilizado pelas funções que manipulem a tabela.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*	  Caso haja um erro na criação da tabela inicial a função retornará NULL
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro ();

/***********************************************************************
*
*  $FC Função: TAB  &Destruir Tabuleiro
*
*  $ED Descrição da função
*     Elemina o conteudo da de todas as listas do tabuleiro e depois 
*	  destroi ele
*
*  $EP Parâmetros
*     pTab - ponteiro para a o tabuleiro a ser destruido
*
***********************************************************************/

tpCondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab);

#undef TABULEIRO_EXT


/*********** Fim do módulo de definição: TAB Modulo Tabuleiro **********/


#else
#endif