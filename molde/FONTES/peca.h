#if ! defined ( PEC_ )
#define PEC_

/***************************************************************************
*
*  $MCD M�dulo de defini��o: PEC M�dulo de Pe�a
*
*  Arquivo gerado:              PECAS.H  
*  Letras identificadoras:      PEC
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
*
*  $ED Descri��o do m�dulo
*     Cria, dado um indice no vetor, uma Pe�a.
*     Destroi, dado um indice no vetor, uma Pe�a.
*     Obtem, dado um indice no vetor, informa��es sobre a Pe�a.
*     Atualiza status e final, dado um indice no vetor, de uma Pe�a.
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
*
*************************************************/

#if defined( PEC_OWN )
#define PEC_EXT
#else
   #define PEC_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma pe�a */

typedef struct Peca * PEC_tpPeca; 

/***********************************************************************
*
*  $TC Tipo de dados: PEC condi��es de retorno
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
*  $FC Fun��o: PEC &Criar PEC
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a, dado um indice, no vetor.
*
*  $EP Parametros
*  * pPe�a - ponteiro para pe�a a ser criada
*    ind   - indice da pe�a no vetor
* 	 cor   - cor da pe�a
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetFaltaMemoria - se faltou memoria
*     PEC_CondRetJaExiste - Se peca ja existe
*     PEC_CondRetCorInvalida - se a cor passada n�o for entre 0 e 3
*
***********************************************************************/

/* Assertivas de Entrada PEC_CriaPeca
*  Existir m�moria para criacao da pe�a
*  A pe�a nao pode existir para que seja criada (pPeca[ind] = NULL)
*  A cor dada (int) tem que ser entre 0 e 3
*  Para todo pPeca[indice], pPeca = NULL.
*
*  Fim Assertiva de Entrada PEC_CriaPeca */

PEC_CondRet PEC_CriaPeca ( PEC_tpPeca * pPeca, int ind, int cor ) ;

/* Assertivas de Saida PEC_CriaPeca
*  A memoria referente a estrutura da peca tem que ser alocada
*  Para todo pPeca[ind] criado, pPeca[ind] != NULL
*  Para todo pPeca criado, pPeca->cor entre 0 e 3
*  A funcao retornara um PEC_CondRet
*
*  Fim Assertiva de Saida PEC_CriaPeca */

/***********************************************************************
*
*  $FC fun��o: PEC &Destruir pe�a
*
*  $ED Descri��o da fun��o
*     Destroi uma pe�a dado um indice, dentro do vetor.
*
*  $EP Parametros
*   *pPeca  -  peca a ser destruida.
*     ind   -  indice no vetor
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PEC_DestroiPeca
*  Existir pe�a ja criada (para todo pPeca , pPeca != NULL)
*
*  Fim Assertiva de Entrada PEC_DestroiPeca */

PEC_CondRet PEC_DestroiPeca ( PEC_tpPeca pPeca ) ;
 
/* Assertiva de Saida PEC_DestroiPeca
*  A peca deve ser destruida (para todo pPeca , pPeca = NULL)
*  A memoria alocada para peca deve ser liberada 
*  A funcao retorna um PEC_CondRet
*
*  Fim Assertiva de Saida PEC_DestroiPeca */

/***********************************************************************
*
*  $FC Fun��o: PEC  &Obtem cor
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a no vetor, informa sua cor.
*
*  $EP Parametros
*   pPeca - pe�a que procura saber a cor
*  * cor - ponteiro passado para receber a cor
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PEC_ObtemCor
*  Deve existir uma cor valida na peca (para todo pPeca, pPeca->cor entre 0 e 3)
*
*  Fim Assertiva de Entrada PEC_ObtemCor */

PEC_CondRet PEC_ObtemCor ( PEC_tpPeca pPeca , int * cor ) ;

/*  Assertiva de Saida PEC_ObtemCor
*   Dever� ser retornado uma cor v�lida (inteiro entre 0 e 3)
*   A funcao retorna um PEC_CondRet
*
*   Fim Assertiva de Saida PEC_ObtemCor */

/***********************************************************************
*
*  $FC Fun��o: PEC  &Obtem final
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a no vetor, informa se est� na casa final.
*
*  $EP Parametros
*   pPeca - pe�a que procura saber o final
*  * final - ponteiro passado para receber o final
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PEC_ObtemFinal
*  Deve existir um valor final valido na peca
*
*  Fim Assertiva de Entrada PEC_ObtemFinal */

PEC_CondRet PEC_ObtemFinal ( PEC_tpPeca pPeca , int * final ) ;

/*  Assertiva de Saida PEC_ObtemFinal
*   Dever� ser retornado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PEC_CondRet
*
*   Fim Assertiva de Saida PEC_ObtemFinal */

/***********************************************************************
*
*  $FC Fun��o: PEC  &Obtem status
*
*  $ED Descri��o da fun��o
*     Dada uma pe�a no vetor, informa seu status.
*
*  $EP Parametros
*   pPeca - pe�a que procura saber o status
*  * status - ponteiro passado para receber o status
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PEC_ObtemStatus
*  Deve existir um status valido na peca
*
*  Fim Assertiva de Entrada PEC_ObtemStatus */

PEC_CondRet PEC_ObtemStatus ( PEC_tpPeca pPeca , char * status ) ;

/*  Assertiva de Saida PEC_ObtemStatus
*   Dever� ser retornado um status v�lido (caracter 'D' ou 'F')
*   A funcao retorna um PEC_CondRet
*
*   Fim Assertiva de Saida PEC_ObtemStatus */

/***********************************************************************
*
*  $FC Fun��o: PEC  &Atualiza pe�a
*
*  $ED Descri��o da fun��o
*     Dado uma pe�a, atualiza o status e a condi��o final da pe�a.
*
*  $EP Parametros
*   pPeca - pe�a que procura saber a cor
*   final - atualizar se pe�a est� no est�gio final
*   status - atualizar se se pe�a est� em jogo
*
*  $FV Valor retornado
*     PEC_CondRetOK - se ocorreu tudo certo
*     PEC_CondRetStatusErrado - se status dado est� errado
*     PEC_CondRetFinalErrado - se final dado est� errado
*     PEC_CondRetNaoExiste - se peca nao existe
*
***********************************************************************/

/* Assertivas de Entrada PEC_AtualizaPeca
*  Deve existir um status valido na peca
*  Deve existir um valor final valido na peca
*  A pe�a deve existi antes de chamar a fun��o.
*
*  Fim Assertiva de Entrada PEC_AtualizaPeca */

PEC_CondRet PEC_AtualizaPeca ( PEC_tpPeca pPeca , int final, char status ) ;

/*  Assertiva de Saida PEC_AtualizaPeca
*   Dever� ser atualizado um status v�lido (caracter 'D' ou 'F')
*   Dever� ser atualizado um final v�lido (inteiro 1 ou 0)
*   A funcao retorna um PEC_CondRet
*
*   Fim Assertiva de Saida PEC_AtualizaPeca */

#undef PEC_EXT

/********** Fim do m�dulo de defini��o: PEC M�dulo Pe�as **********/
 
#else
#endif