/***************************************************************************
*  $MCI Módulo de implementação: PAR  Módulo da partida para LUDO
*
*  Arquivo gerado:              partida.c
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
*       3    |    GB      |   23/06/2019  |      Ajustes    
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "tabuleiro.h"
#include "peca.h"

#define PAR_OWN
#include "partida.h"
#undef PAR_OWN


#define NUM_PECA_PLAYER 4
#define MAX_PECAS 16 
#define MAX_PLAYERS 4
#define MIN_PLAYERS 2

#define VERMELHO 0
#define AMARELO 3

#define ROLA_DADO ((rand() % 6) + 1)

#define NENHUM 0

#define NUM_JOGADORES_MENOS1 ((pJogo ->num_jogadores) - 1)

#define TERMINOU 1

#define NAO_TERMINOU 1

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

static int ProcuraPeca ( TAB_tppTabuleiro pTabuleiro , PECA_tpPeca pPeca ) ;


/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
 *
 *  $FC Função: PAR  -Inicializa Jogo
 *
 ***********************************************************************/

PAR_CondRet PAR_InicializaJogo ( PAR_tppPartida pJogo , int num , int *cor ) 
{
	int i;

	TAB_tppTabuleiro pTabuleiro ;
	PECA_CondRet retorno_pec 	;
	
	if ( num < MIN_PLAYERS || num > MAX_PLAYERS )
	{
		return PAR_CondRetNumeroDeJogadoresInvalido ;
	}

	for ( i = 0 ; i < num ; i++ )
	{
		if ( cor[i] < VERMELHO || cor[i] > AMARELO )
		{
			return PAR_CondRetCorInvalida ;
		}
	}

	pJogo = ( PAR_Ludo * ) malloc ( sizeof ( PAR_Ludo ) ) ;
	if ( pJogo == NULL )
	{
		return PAR_CondRetFaltouMemoria ;
	}
	
	LimpaCabeca ( pJogo ) ;

	pTabuleiro = TAB_CriaTabuleiro() ;
	if(pTabuleiro == NULL)
		return PAR_CondRetFaltouMemoria ;

	for ( i = 0 ; i < MAX_PLAYERS ; i++ ) 
	{
		retorno_pec = PECA_CriaPeca ( pJogo ->pecas , i , cor[i]) ;
			switch ( retorno_pec ) 
			{
				case PECA_CondRetFaltaMemoria :
					return PAR_CondRetFaltouMemoria ;
				case PECA_CondRetExiste :
					return PAR_CondRetCorJaEscolhida ;
				case PECA_CondRetOK :
					break;
				default :
					printf("Erro inesperado\n");
					exit(0);
			}
	}

	pJogo->pTabuleiro    = pTabuleiro ;
	pJogo->num_jogadores = num        ;
	
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

	for ( i = 0 ; i < MAX_PECAS ; i++ )
		pJogo->pecas[i] = NULL ;

	pJogo->num_jogadores = NENHUM ;
}

/***********************************************************************
 *
 *  $FC Função: PAR  -Realiza Jogada
 *
 ***********************************************************************/

PAR_CondRet PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) 
{
	int dado, i;
	if (cor < VERMELHO || cor > AMARELO)
	{
		return PAR_CondRetCorInvalida;
	}
	
	LancaDado ( &dado ) ;

	for (i = 0; i < MAX_PECAS; i++)
	{
		if (pJogo->pecas[cor]) {
			// WIP
		}
	}
	
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
    ValorAleatorio = ROLA_DADO;
      
    * pValor = ValorAleatorio ;
  
} /* Fim função: PAR  &Lanca Dado */



/***********************************************************************
 *
 *  $FC Função: PAR  -Verifica Ganhador
 *
 ***********************************************************************/
#define NO_FIM 1


int PAR_VerificaVencedor( PAR_Ludo *pJogo, int * vencedores ) {
	int final, i;
	int cor, terminaram = NENHUM;
	int jogadores[MAX_PLAYERS] = {0, 0, 0, 0};
	int vencedoresTemp[MAX_PLAYERS] = {0, 0, 0, 0};
	for (i = 0; i < MAX_PECAS; i++)
	{
		 PECA_ObtemFim (pJogo->pecas[i], &final );
		if (final == NO_FIM)
		{
			PECA_ObtemCor(pJogo->pecas[i], &cor);
			jogadores[cor]++;
		}
	}

	for (i = 0; i < MAX_PLAYERS; i++)
	{
		if(jogadores[i] == MAX_PLAYERS) 
		{
			vencedoresTemp[terminaram] = i;
			terminaram++;
		}
	}

	vencedores = vencedoresTemp;

	if (terminaram == NENHUM)
	{
		return -1;
	} 
	else if (terminaram == NUM_JOGADORES_MENOS1 || terminaram == MAX_PLAYERS){
		return 1;
	} 
	else 
	{
		return 0;
	}

}/* Fim função: PAR  &Verifica Vencedor */



/***********************************************************************
 *
 *  $FC Função: PAR  -Realiza Jogada
 *
 ***********************************************************************/

#define MAX_DADO 6
#define MIN_DADO 1
#define FORA_DO_JOGO 'F'
#define NAO_EXISTE 0

PAR_CondRet PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) 
{
	int dado, i, cond, auxCor  = 0;
	int final;
	char status;

	PECA_CondRet retPeca;
	TAB_tppCasaInfo pCasa, aux;
	TAB_tppTabuleiro pTab;

	LISC_tppListaC casasNomais;
	TAB_tppCasaInfo casaIni; 
	LIS_tppLista *casasFinais;

	LIS_tppLista caminho_final ;
    LIS_tpCondRet retorno_lis ;

	if (cor < VERMELHO || cor > AMARELO)
	{
		return PAR_CondRetCorInvalida;
	}
	
	LancaDado ( &dado ) ;

	if (dado > MAX_DADO || dado < MIN_DADO) {
		return PAR_CondRetMovInvalido;
	}

	retPeca = PECA_ObtemCor(pJogo->pecas, &cor);
	if (retPeca != PECA_CondRetOK) {
		return PAR_CondRetPecaNaoExiste;
	}

	TAB_AcessaCasas(pJogo->pTabuleiro, casasNomais, casaIni, casasFinais);

	PECA_ObtemFim( pJogo->pecas, &final);
	PECA_ObtemStatus ( pJogo->pecas , &status ) ;

	if ( status == FORA_DO_JOGO )
    {
        return PAR_CondRetPecaFora ;
    }

    if ( final == NO_FIM )
    {
        return PAR_CondRetMovInvalido ;
    }
 
    cond = ProcuraPeca ( pJogo->pTabuleiro , pJogo->pecas ) ;
    if ( cond == NAO_EXISTE )
    {
        return PAR_CondRetPecaNaoExiste ;
    }

	pCasa = LIS_ObterValor ( casaIni );
	aux = pCasa ;
	pTab = pJogo->pTabuleiro;
	if ( pCasa == pJogo->pecas ) { 
		PECA_ObtemCor(aux, &auxCor);
		while ( auxCor != cor && dado > 0 ) {
    		LIS_AvancarElementoCorrente ( pCasa , 1 ) ;
    		aux = LIS_ObterValor ( pCasa ) ;
    		dado-- ;
    	}
		if ( dado != 0 ) {
    		caminho_final = casasFinais ;
    		LIS_IrInicioLista ( caminho_final ) ;
    		retorno_lis = LIS_AvancarElementoCorrente ( caminho_final , dado-1 ) ;
    		if ( retorno_lis == LIS_CondRetFimLista )
    			return PAR_CondRetMovInvalido ;
    		aux = LIS_ObterValor ( caminho_final ) ;
    	}
	}

	if ( caminho_final != NULL ) { 

        retorno_lis = LIS_AvancarElementoCorrente ( caminho_final , 1 ) ;       
        if ( retorno_lis == LIS_CondRetFimLista ) {
            PECA_AtualizaPeca ( pJogo->pecas , 1 , 'D' ) ;
			TAB_LimpaCasa(pCasa);
            return PAR_CondRetOK ;
        }

    }

	// if ( aux->conteudo != NULL ) {
    
    //     PECA_ObtemInfo ( aux->conteudo , &cor2, &final2, &status2 ) ;
    //     if ( cor2 == cor ) 
    //         return PAR_CondRetMovInvalido ;
              
    //     PEC_AtualizaPeca ( aux->conteudo , 0 , 'F' ) ;
        
    // }

    TAB_LimpaCasa(pCasa);
	
	return PAR_CondRetOK;
}   /* Fim função: PAR  &Realiza Jogada */
