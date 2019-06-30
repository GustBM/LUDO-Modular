#if ! defined( TABULEIRO_ )
#define TABULEIRO_

/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  M�dulo do tabuleiro para LUDO
*
*  Arquivo gerado:              tabuleiro.h
*  Letras identificadoras:      TAB
*
*
*  Projeto: INF 1301 / TESTE 2 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: GBM - Gustavo Barros Marchesan
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1       GBM     07/mai/2019 in�cio desenvolvimento
*	  2	    GBM	12/mai/2019 Jun��o dos m�dulos tabuleiro e peca
*	  3       GBM	12/mai/2019 Remo��o da peca como parte do tabuleiro
*
*  $ED Descri��o do m�dulo
*     M�dulo para cria��o e manipula��o do tabuleiro e pecas para o jogo LUDO
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

/***** Declara��es exportadas pelo m�dulo *****/

typedef struct TAB_tagTabuleiro * TAB_tppTabuleiro;

typedef struct TAB_tagCasaInfo * TAB_tppCasaInfo;

/***********************************************************************
*
*  $TC Tipo de dados: GT C�digos de retorno de fun��es
*
*
***********************************************************************/

   typedef enum {

            TAB_CondRetOK ,
               /* Fun��o executou corretamente */

            TAB_CondRetErro ,
               /* Erro de leitura de arquivo */

            TAB_CondRetMem
               /* Erro de espa�o na mem�ria */

   } TAB_CondRet ;


    typedef enum {

            CAS_CondRetOK ,
               /* Fun��o executou corretamente */

            CAS_CondRetCasaPoluida,
               /* Casa tem pecas de times distintos */
               
            CAS_CondRetBarreira
               /* tentativa de alterar casa com barreira inimiga */

   } CAS_CondRet ;

/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um tabuleiro para o LUDO, composto por uma lista circular
*	  composta por 56 posi��es e 4 listas comuns composta por 5 casas cada
*	  A fun��o n�o precisa de par�metros para fazer as listas porque ela j�
*	  ser� uma lista de casas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a tabela.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem a tabela.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*	  Caso haja um erro na cria��o da tabela inicial a fun��o retornar� NULL
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro ();

/***********************************************************************
*
*  $FC Fun��o: TAB  &Destruir Tabuleiro
*
*  $ED Descri��o da fun��o
*     Elimina o conteudo da de todas as listas do tabuleiro e depois 
*	  destroi ele
*
*  $EP Par�metros
*     pTab - ponteiro para a o tabuleiro a ser destruido
*
***********************************************************************/

TAB_CondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Imprime Tabuleiro
*
*  $ED Descri��o da fun��o
*     recebe um vetor de ponteiros de peca e o tabuleiro que estas pecas 
*        estao interagindo e imprime na tela as informações do jogo
*
*  $EP Par�metros
*     pTab  - ponteiro para a o tabuleiro a ser usado
*     pecas - vetor de ponteiro de pecas a ser usado
*
***********************************************************************/

void TAB_imprime(PECA_tpPeca* pecas, TAB_tppTabuleiro ptab);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Acessa casas 
*
*  $ED Descri��o da fun��o
*     recebe um tabuleiro e ponteiros para uma lista circular, uma casa e um ponteiro para um vetor de listas
*     atribui a cada um desses ponteiros os campos do tabuleiro.
*
*  $EP Par�metros
*     pTab  - ponteiro para a o tabuleiro a ser usado
*     casasNomais - ponteiro para casas normais do tabuleiro
*     casasIni - ponteiro para casa inicial do tabuleiro (casa inicial da peca vermelha)
*     casasFinais - ponteiro para ponteiros de casas finais do tabuleiro 
*
***********************************************************************/

void TAB_AcessaCasas ( TAB_tppTabuleiro pTab , LISC_tppListaC casasNomais, TAB_tppCasaInfo casaIni, LIS_tppLista* casasFinais);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Altera Casa 
*
*  $ED Descri��o da fun��o
*     Altera valores de uma casa seguindo as regras da partida
*
*  $EP Par�metros
*     CAS_CondRetCasaPoluida  - Casoa a casa já tenha peças de times distintos
*     CAS_CondRetOK - função ocorreu sem problemas
*     TAB_CondRetErro - Erro de leitura do arquivo
*
***********************************************************************/

CAS_CondRet TAB_AlteraCasa ( TAB_tppCasaInfo casa, PECA_tpPeca peca ) ;

#undef TABULEIRO_EXT


/*********** Fim do m�dulo de defini��o: TAB Modulo Tabuleiro **********/


#else
#endif