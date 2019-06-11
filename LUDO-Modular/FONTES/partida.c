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
*       1    |    GB      |   11/06/2019  | início desenvolvimento	
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "TABULEIRO.h"

#define PAR_OWN
#include "JOGO.h"
#undef PAR_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: PAR Partida de Ludo
 *
 ***********************************************************************/

typedef struct PAR_tagPartida
{
	TAB_tpTabuleiro pTabuleiro ;
	/* Ponteiro para Tabuleiro */
	
	PECA pecas[16] ;
	/* Vetor de Peças */
	
	int num_jogadores ;
	/* Numero de jogadores */
	
} PAR_Ludo ;

/***** Protótipo das funções encapsuladas no módulo *****/

static void LimpaCabeca ( JOGO_Ludo *pJogo ) ;

static void PAR_LancaDado ( int * pValor ) ;


/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
 *
 *  $FC Função: PAR  -Inicializa Jogo
 *
 ***********************************************************************/

PAR_CondRet PAR_InicializaJogo ( PAR_tppPartida * pJogo , int num , int *cor ) 
{
	int i ;

	TAB_tpLudo pTabuleiro   ;
	TAB_CondRet retorno_tab ;
	PEC_CondRet retorno_pec ;
	
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
	
	if ( retorno_tab != TAB_CondRetOK )
	{
		return PAR_CondRetFaltouMemoria ;
	}

	for ( i = 0 ; i < num ; i++ ) 
	{
		for ( k = 4*cor[i] ; k < k + 4 ; k++ ) 
		{
			retorno_pec = PEC_CriaPeca ( (*pJogo)->pecas , k , cor[i]) ;
			switch ( retorno_pec ) 
			{
				case PEC_CondRetFaltaMemoria :
					return PAR_CondRetFaltouMemoria ;
				case PEC_CondRetJaExiste :
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

static void PAR_LimpaCabeca ( PAR_Ludo *pJogo )
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

int PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) 
{
	int dado ;
	PAR_LancaDado ( &dado ) ;



	return dado;
}   /* Fim função: PAR  &Realiza Jogada */


/***********************************************************************
 *
 *  $FC Função: PAR  -Lanca Dado
 *
 ***********************************************************************/


static void PAR_LancaDado ( int * pValor )
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
	char * status;
	int cor, j = 0;
	int jogadores = [0, 0, 0, 0];
	vencedores = [];
	for (int i = 0; i < 16; i++)
	{
		PECA_ObtemStatus(*pJogo->pecas, status) ;
		if (strcmp(status, 'F'))
		{
			PECA_ObtemCor(*pJogo->pecas[i], &cor);
			jogadores[cor]++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if(jogadores[i] == 4) {
			vencedores[j] = i;
			j++;
		}
	}

	if (sizeof(vencedores) == 0)
	{
		return -1;
	} else {
		return 0;
	}

}/* Fim função: PAR  &Verifica Vencedor */