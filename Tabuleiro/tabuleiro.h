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
*  Autores: Gustavo Barros Marchesan
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       GBM   07/mai/2019 in�cio desenvolvimento
*	  2		  GBM	12/mai/2019 Jun��o dos m�dulos tabuleiro e peca
*
*  $ED Descri��o do m�dulo
*     M�dulo para cria��o e manipula��o do tabuleiro e pecas para o jogo LUDO
*
***************************************************************************/

/***** Declara��es exportadas pelo m�dulo *****/

typedef struct TAB_tagTabuleiro * TAB_tppTabuleiro;

typedef struct TAB_tagCasaInfo * TAB_tppCasaInfo;

typedef struct peca* PECA;

/***********************************************************************
*
*  $TC Tipo de dados: GT C�digos de retorno de fun��es
*
*
***********************************************************************/

   typedef enum {

         CondRetOK ,
               /* Fun��o executou correto */

         CondRetErro ,
               /* Erro de leitura de arquivo */

         CondRetMem
               /* Erro de espa�o na mem�ria */

   } tpCondRet ;

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

void TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Limpa Casa Tab
*
*  $ED Descri��o da fun��o
*     Elemina o elemento do tabuleiro dado como par�metro
*
*  $EP Par�metros
*     casa - ponteiro para a casa a ser esvaziada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a fun��o ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informa��es adicionais
*
***********************************************************************/

tpCondRet TAB_LimpaCasaTab (TAB_tpCasaInfo casa);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Cria Peca
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a para o jogo de ludo.
*
*  $EP Par�metros
*     jogador - inteiro representando o jogador a qual a pe�a pertence
*	  ret - ponteiro de refer�ncia para a peca criada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a fun��o ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informa��es adicionais
*
***********************************************************************/

tpCondRet TAB_CriaPeca (int jogador, PECA* ret);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Destroi Peca
*
*  $ED Descri��o da fun��o
*     Elemina a peca do tabuleiro dado como par�metro
*
*  $EP Par�metros
*     p - ponteiro para a peca a ser eliminada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a fun��o ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informa��es adicionais
*
***********************************************************************/

tpCondRet TAB_DestroiPeca (PECA* p);