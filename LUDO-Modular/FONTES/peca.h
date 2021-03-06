#if ! defined ( PECA_ )
#define PECA_

/***************************************************************************
*
*  $MCD M�dulo de defini��o: Modulo peca
*
*  Arquivo gerado:              peca.h
*  Letras identificadoras:      PECA
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
*
*  $ED Descri��o do m�dulo
*     Cria uma Pe�a a partir de um vetor de ponteiros para peca.
*     Destroi uma Pe�a a partir de um dado ponteiro para peca.
*     Obtem informa��es sobre a Pe�a a partir de um dado ponteiro para peca.
*     Atualiza status e final de uma Pe�a a partir de um dado ponteiro para peca.
*
*    
*
**************************************************************************/

/*****************INFORMACAO DA PECA*********************
*
*  	A COR DE CADA PE�A � CLASSIFICADA COMO:
*
*       0 - VERMELHO
*       1 - AZUL
*       2 - VERDE
*       3 - AMARELO
*
*	O STATUS DA PECA EH IDENTIFICADO COMO
*
*		'D' - Dentro to tabuleiro
*
*		'F' - Fora do tabuleiro
*
*	INDICACAO SE A PECA CHEGOU NA ULTIMA CASA
*	
*		0 - Nao
*		
*		1 - Sim
*
*
/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma pe�a */

typedef struct Peca * PECA_tpPeca; 
/***********************************************************************
*
*  $TC Tipo de dados: PECA condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da pe�a
*
***********************************************************************/
typedef enum {

	PECA_CondRetOK ,
		/* Condi��o de retorno correto */

	PECA_CondRetFaltaMemoria , 
		/* Condi��o de retorno por Falta de mem�ria na aloca��o */					

	PECA_CondRetExiste ,
		/* Condi��o de retorno que indica que Peca existe */

	PECA_CondRetNaoExiste,
		/* Condi��o de retorno que indica que Peca nao existe */

} PECA_CondRet;

/***********************************************************************
*
*  $FC Fun��o: PECA &Criar PECA
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a, dado um indice, no vetor de pecas.
*
*  $EP Parametros
*  * peca - vetor de ponteiros para peca a ser inserida a nova peca
*    i    - indice da peca no vetor de pecas
* 	 cor  - cor da pe�a
*
***********************************************************************/
/* Assertivas de Entrada PECA_CriaPeca
*  Existir m�moria suficiente para criacao do vetor de pe�as
*/

PECA_CondRet PECA_CriaPeca ( PECA_tpPeca* peca, int i, int cor ) ;

/* Assertivas de Saida PECA_CriaPeca
*  A memoria referente a estrutura da peca tem que ser alocada
*  Para todo peca[i] criado, peca[i] != NULL
*  Para todo peca criado, peca->cor deve estar entre 0 e 3
*  A funcao retornara um PECA_CondRet
*/
/***********************************************************************
*
*  $FC fun��o: PECA &Destruir pe�a
*
*  $ED Descri��o da fun��o
*     Destroi uma pe�a dado um indice, dentro do vetor.
*
*  $EP Parametros
*   *peca  -  peca a ser destruida.
*     i   -  indice no vetor

***********************************************************************/
/* Assertivas de Entrada PECA_DestroiPeca
*  Existir pe�a ja criada (para toda peca , peca != NULL)*/

PECA_CondRet PECA_DestroiPeca ( PECA_tpPeca peca ) ;
 
/* Assertiva de Saida PECA_DestroiPeca
*  A peca deve ser destruida (para todo peca , peca = NULL)
*  A memoria alocada para peca deve ser liberada 
*  A funcao retorna um PECA_CondRet */
/***********************************************************************
*
*  $FC Fun��o: PECA  &Obtem cor
*
*  $ED Descri��o da fun��o
*    informa a cor de uma pe�a dada no vetor.
*
*  $EP Parametros
*   peca - pe�a que procura saber a cor
*  * cor - ponteiro passado para receber a cor
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemCor
*  Deve existir uma cor valida na peca (para todo peca, peca->cor entre 0 e 3) */

PECA_CondRet PECA_ObtemCor ( PECA_tpPeca peca , int * cor ) ;

/*  Assertiva de Saida PECA_ObtemCor
*   Dever� ser retornado uma cor v�lida (inteiro entre 0 e 3)
*   A funcao retorna um PECA_CondRet */

/***********************************************************************
*
*  $FC Fun��o: PECA  &Obtem fim
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a no vetor, informa se est� na casa final.
*
*  $EP Parametros
*   peca - pe�a que procura saber o final
*  * final - ponteiro passado para receber o final
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemFim
*  Deve existir um valor final valido na peca */

PECA_CondRet PECA_ObtemFim ( PECA_tpPeca peca , int * final ) ;

/*  Assertiva de Saida PECA_ObtemFim
*   Dever� ser retornado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet */

/***********************************************************************
*
*  $FC Fun��o: PECA  &Obtem status
*
*  $ED Descri��o da fun��o
*     Informa o status de uma peca no vetor dado.
*
*  $EP Parametros
*   peca - pe�a que procura saber o status
*  * status - ponteiro passado que recebe o status
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemStatus
*  Deve existir um status valido na peca */

PECA_CondRet PECA_ObtemStatus ( PECA_tpPeca peca , char * status ) ;

/*  Assertiva de Saida PECA_ObtemStatus
*   Dever� ser retornado um status v�lido (caracter 'D' ou 'F')
*   A funcao retorna um PECA_CondRet */

/***********************************************************************
*
*  $FC Fun��o: PECA  &Atualiza pe�a
*
*  $ED Descri��o da fun��o
*     Dado uma pe�a, atualiza o status e a condi��o final da pe�a.
*
*  $EP Parametros
*   peca - pe�a que procura saber a cor
*   final - atualizar se a pe�a est� no est�gio final (insira -1 se quiser atualizar o status apenas)
*   status - atualizar se a pe�a est� em jogo (insira 'X' se quiser atualizar o final apenas)
*
***********************************************************************/

/* Assertivas de Entrada PECA_AtualizaPeca
*  Deve existir um status valido na peca
*  Deve existir um valor final valido na peca
*  A pe�a deve existi antes de chamar a fun��o. */

PECA_CondRet PECA_AtualizaPeca ( PECA_tpPeca peca , int final, char status ) ;

/*  Assertiva de Saida PECA_AtualizaPeca
*   Dever� ser atualizado um status v�lido (caracter 'D' ou 'F')
*   Dever� ser atualizado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet  */

/********** Fim do m�dulo de defini��o: PECA **********/

PECA_CondRet PECA_ObtemInfo( PECA_tpPeca peca, int* cor, int* final, char* status ) ;

 #endif
