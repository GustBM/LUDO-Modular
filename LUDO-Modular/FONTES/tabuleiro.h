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
*     1       GBM   07/mai/2019 in�cio desenvolvimento
*	  2		  GBM	12/mai/2019 Jun��o dos m�dulos tabuleiro e peca
*	  3		  GBM	12/mai/2019 Remo��o da peca como parte do tabuleiro
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
               /* Fun��o executou correto */

         TAB_CondRetErro ,
               /* Erro de leitura de arquivo */

         TAB_CondRetMem
               /* Erro de espa�o na mem�ria */

   } TAB_CondRet ;

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
*     Elemina o conteudo da de todas as listas do tabuleiro e depois 
*	  destroi ele
*
*  $EP Par�metros
*     pTab - ponteiro para a o tabuleiro a ser destruido
*
***********************************************************************/

TAB_CondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Limpa Casa
*
*  $ED Descri��o da fun��o
*     Elemina o conteudo de uma das casas
*
*  $EP Par�metros
*     pTab - ponteiro para a casa do tabuleiro a ser limpa
*
*  $FV Valor retornado
*	  Caso ocorre sem problemas; CondRetOK
*	  Caso contr�rio; CondRetErro
*
***********************************************************************/

TAB_CondRet TAB_LimpaCasa (TAB_tppCasaInfo casa);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Cria Casa
*
*  $ED Descri��o da fun��o
*     Cria uma casa no tabuleiro com o conteudo dado como par�metro
*
*  $EP Par�metros
*     conteudo - conteudo que ir� para a casa, tipo PECA
*
*  $FV Valor retornado
*	  Tetorna um ponteiro para a casa criada
*
***********************************************************************/

TAB_tppCasaInfo CriaCasa ( PECA_tpPeca conteudo );

#undef TABULEIRO_EXT


/*********** Fim do m�dulo de defini��o: TAB Modulo Tabuleiro **********/


#else
#endif