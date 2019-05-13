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
*     Cria uma Pe�a a partir de um �ndice dado no vetor.
*     Destroi uma Pe�a a partir de um �ndice dado no vetor.
*     Obtem informa��es sobre a Pe�a dado um indice no vetor.
*     Atualiza status e final de uma Pe�a dado um indice no vetor.
*
*     OBS IMPORTANTE: As 4 primeiras posi��es do vetor de pe�as destinam-se
*                     a cor vermelha, as pr�ximas 4 destinam-se a cor azul,
*                     e analogamente para a cor verde e amarelo.
*
**************************************************************************/

/*****************IMPORTANTE*********************
*
*  AS CORES DA PE�A S�O CLASSIFICADAS COMO:
*
*       0 - VERMELHO
*       1 - AZUL
*       2 - VERDE
*       3 - AMARELO

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
		/* Ocorreu tudo certo */

	PECA_CondRetFaltaMemoria , 
		/* Faltou mem�ria na aloca��o */

	PECA_CondRetCorInvalida ,
		/* Cor inv�lida */

	PECA_CondRetFimErrado ,
		/* Fim Errado */						

	PECA_CondRetExiste ,
		/* Peca existe */

	PECA_CondRetNaoExiste
		/* Peca nao existe */

	PECA_CondRetStatusErrado ,
		/* Status Errado */



} PECA_CondRet;

/***********************************************************************
*
*  $FC Fun��o: PECA &Criar PECA
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a, dado um indice, no vetor.
*
*  $EP Parametros
*  * peca - ponteiro para pe�a a ser criada
*    i    - indice da pe�a no vetor
* 	 cor  - cor da pe�a
*
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetExiste - Se peca ja existe
*     PECA_CondRetCorInvalida - se a cor passada n�o for entre 0 e 3
*     PECA_CondRetFaltaMemoria - se faltou memoria
*
***********************************************************************/
/* Assertivas de Entrada PECA_CriaPeca
*  Existir m�moria para criacao da pe�a
*  A pe�a nao pode existir para que seja criada (peca[i] = NULL)
*  A cor dada (int) tem que ser entre 0 e 3
*  Para todo peca[indice], peca = NULL.
*
*  Fim Assertiva de Entrada PECA_CriaPeca */

PECA_CondRet PECA_CriaPeca ( PECA_tpeca * peca, int i, int cor ) ;

/* Assertivas de Saida PECA_CriaPeca
*  A memoria referente a estrutura da peca tem que ser alocada
*  Para todo peca[i] criado, peca[i] != NULL
*  Para todo peca criado, peca->cor entre 0 e 3
*  A funcao retornara um PECA_CondRet
*
*  Fim Assertiva de Saida PECA_CriaPeca */
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
*
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetNaoExiste - se peca nao existe

***********************************************************************/
/* Assertivas de Entrada PECA_DestroiPeca
*  Existir pe�a ja criada (para toda peca , peca != NULL)
*
*  Fim Assertiva de Entrada PECA_DestroiPeca */

PECA_CondRet PECA_DestroiPeca ( PECA_tpPeca peca ) ;
 
/* Assertiva de Saida PECA_DestroiPeca
*  A peca deve ser destruida (para todo peca , peca = NULL)
*  A memoria alocada para peca deve ser liberada 
*  A funcao retorna um PECA_CondRet
*
*  Fim Assertiva de Saida PECA_DestroiPeca */
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
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemCor
*  Deve existir uma cor valida na peca (para todo peca, peca->cor entre 0 e 3)
*
*  Fim Assertiva de Entrada PECA_ObtemCor */

PECA_CondRet PECA_ObtemCor ( PECA_tpPeca peca , int * cor ) ;

/*  Assertiva de Saida PECA_ObtemCor
*   Dever� ser retornado uma cor v�lida (inteiro entre 0 e 3)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemCor */

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
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemFinal
*  Deve existir um valor final valido na peca
*
*  Fim Assertiva de Entrada PECA_ObtemFinal */

PECA_CondRet PECA_ObtemFinal ( PECA_tpPeca peca , int * final ) ;

/*  Assertiva de Saida PECA_ObtemFinal
*   Dever� ser retornado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemFinal */

/***********************************************************************
*
*  $FC Fun��o: PECA  &Obtem status
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a no vetor, informa seu status.
*
*  $EP Parametros
*   peca - pe�a que procura saber o status
*  * status - ponteiro passado para receber o status
*
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemStatus
*  Deve existir um status valido na peca
*
*  Fim Assertiva de Entrada PECA_ObtemStatus */

PECA_CondRet PECA_ObtemStatus ( PECA_tpPeca peca , char * status ) ;

/*  Assertiva de Saida PECA_ObtemStatus
*   Dever� ser retornado um status v�lido (caracter 'D' ou 'F')
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemStatus */

/***********************************************************************
*
*  $FC Fun��o: PECA  &Atualiza pe�a
*
*  $ED Descri��o da fun��o
*     Dado uma pe�a, atualiza o status e a condi��o final da pe�a.
*
*  $EP Parametros
*   peca - pe�a que procura saber a cor
*   final - atualizar se pe�a est� no est�gio final
*   status - atualizar se se pe�a est� em jogo
*
*  $FV Valor retornado
*     PECA_CondRetOK - se ocorreu tudo certo
*     PECA_CondRetStatusErrado - se status dado est� errado
*     PECA_CondRetFinalErrado - se final dado est� errado
*     PECA_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PECA_AtualizaPeca
*  Deve existir um status valido na peca
*  Deve existir um valor final valido na peca
*  A pe�a deve existi antes de chamar a fun��o.
*
*  Fim Assertiva de Entrada PECA_AtualizaPeca */

PECA_CondRet PECA_AtualizaPeca ( PECA_tpPeca peca , int final, char status ) ;

/*  Assertiva de Saida PECA_AtualizaPeca
*   Dever� ser atualizado um status v�lido (caracter 'D' ou 'F')
*   Dever� ser atualizado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_AtualizaPeca */

/********** Fim do m�dulo de defini��o: PECA M�dulo Pe�as **********/
 