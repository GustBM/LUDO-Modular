/***************************************************************************
*  $MCI Módulo de implementação: PAR  Módulo da partida para LUDO
*
*  Arquivo gerado:              partida.c.c
*  Letras identificadoras:      PAR
*
*  Projeto: INF 1301 / Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
*  $HA Histórico de evolução:
*     Versão |  Autores   |      Data     |    Observações
*       1    |    GB      |   11/06/2019  | Início desenvolvimento
*       2    |    GB      |   12/06/2019  |      Ajustes
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tabuleiro.h"

#define PAR_OWN
#include "partida.h"
#undef PAR_OWN


#define NUM_PECA 4
#define MAX_PECAS 16 

/***********************************************************************
 *
 *  $TC Tipo de dados: PAR Partida de Ludo
 *
 ***********************************************************************/

typedef struct PAR_tagPartida
{
	TAB_tppTabuleiro pTabuleiro ;
	/* Ponteiro para Tabuleiro */
	
	PECA_tpPeca pecas[MAX_PECAS] ;
	/* Vetor de Peças */
	
	int num_jogadores ;
	/* Numero de jogadores */
	
} PAR_Ludo ;

/***** Protótipo das funções encapsuladas no módulo *****/

static void LimpaCabeca ( PAR_Ludo *pJogo ) ;

static void LancaDado ( int * pValor ) ;


/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
 *
 *  $FC Função: PAR  -Inicializa Jogo
 *
 ***********************************************************************/

PAR_CondRet PAR_InicializaJogo ( PAR_tppPartida * pJogo , int num , int *cor ) 
{
	int i, k;

	TAB_tppTabuleiro pTabuleiro ;
	PECA_CondRet retorno_pec 	;
	
	if ( num < 2 || num > 4 )
	{
		return PAR_CondRetNumeroDeJogadoresInvalido ;
	}

	for ( i = 0 ; i < num ; i++ )
	{
		if ( cor[i] < 0 || cor[i] > 3 )
		{
			return PAR_CondRetCorInvalida ;
		}
	}

	* pJogo = ( PAR_Ludo * ) malloc ( sizeof ( PAR_Ludo ) ) ;
	if ( pJogo == NULL )
	{
		return PAR_CondRetFaltouMemoria ;
	}
	
	LimpaCabeca ( *pJogo ) ;

	pTabuleiro = TAB_CriaTabuleiro() ;

	for ( i = 0 ; i < num ; i++ ) 
	{
		for ( k = NUM_PECA * cor[i] ; k < k + NUM_PECA ; k++ ) 
		{
			retorno_pec = PECA_CriaPeca ( (*pJogo)->pecas , k , cor[i]) ;
			switch ( retorno_pec ) 
			{
				case PECA_CondRetFaltaMemoria :
					return PAR_CondRetFaltouMemoria ;
				case PECA_CondRetExiste :
					return PAR_CondRetCorJaEscolhida ;
				default :
					printf ( "Erro inesperado \n" ) ;
			}
		}
	}

	(*pJogo)->pTabuleiro    = pTabuleiro ;
	(*pJogo)->num_jogadores = num        ;
	
	return PAR_CondRetOK ;
	
}  /* Fim função: PAR &Inicializa Jogo */


/***********************************************************************
 *
 *  $FC Função: PAR  -Limpa cabeça
 *
 ***********************************************************************/

static void LimpaCabeca ( PAR_Ludo *pJogo )
{
	int i ;
	pJogo->pTabuleiro = NULL ;

	for ( i = 0 ; i < 16 ; i++ )
		pJogo->pecas[i] = NULL ;

	pJogo->num_jogadores = 0 ;
}

/***********************************************************************
 *
 *  $FC Função: PAR  -Realiza Jogada
 *
 ***********************************************************************/

PAR_CondRet PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) 
{
	int dado ;
	if (cor < 0 || cor > 4)
	{
		return PAR_CondRetCorInvalida;
	}
	
	LancaDado ( &dado ) ;

	// WIP

	// for ( int i = 0; i < MAX_PECAS; i++)
	// {
	// 	if (pJogo->pecas[i] == cor) {

	// 	}
	// }
	
	return PAR_CondRetOK;
}   /* Fim função: PAR  &Realiza Jogada */


/***********************************************************************
 *
 *  $FC Função: PAR  -Lanca Dado
 *
 ***********************************************************************/


static void LancaDado ( int * pValor )
{
    int ValorAleatorio ;
  
    srand ( time ( NULL ) ) ;
    ValorAleatorio = ( rand() % 6 ) + 1 ;
      
    * pValor = ValorAleatorio ;
  
} /* Fim função: PAR  &Lanca Dado */



/***********************************************************************
 *
 *  $FC Função: PAR  -Verifica Ganhador
 *
 ***********************************************************************/

int PAR_VerificaVencedor( PAR_Ludo *pJogo, int * vencedores ) {
	int final, i;
	int cor, terminaram = 0;
	int jogadores[4] = {0, 0, 0, 0};
	int vencedoresTemp[4] = {0, 0, 0, 0};
	for (i = 0; i < 16; i++)
	{
		PECA_ObtemFinal (pJogo->pecas[i], &final );
		if (final == 1)
		{
			PECA_ObtemCor(pJogo->pecas[i], &cor);
			jogadores[cor]++;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if(jogadores[i] == 4) {
			vencedoresTemp[terminaram] = i;
			terminaram++;
		}
	}

	vencedores = vencedoresTemp;

	if (terminaram == 0)
	{
		return -1;
	} else if (terminaram == (pJogo ->num_jogadores) - 1){
		return 1;
	} else {
		return 0;
	}

}/* Fim função: PAR  &Verifica Vencedor */