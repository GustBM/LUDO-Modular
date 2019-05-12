/***************************************************************************
*  $MCI Módulo de implementação: TAB  Módulo do tabuleiro para LUDO
*
*  Arquivo gerado:              tabuleiro.c
*  Letras identificadoras:      TAB

***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "tabuleiro.h"
#include "peca.h"
#include "lista_circular.h"
#include "lista.h"

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do tabuleiro (uma lista circular e 4 listas)
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {

         LISC_tppListaC casasNormais ;
               /* Ponteiro para a lista circular que irá representar as casas normais do tabuleiro */

         LIS_tppLista casasFim1 ;
               /* Ponteiro para a lista das casas finais */

		 LIS_tppLista casasFim2 ;
               /* Ponteiro para a lista das casas finais */

		 LIS_tppLista casasFim3 ;
               /* Ponteiro para a lista das casas finais */

		 LIS_tppLista casasFim4 ;
               /* Ponteiro para a lista das casas finais */

   } TAB_tpTabuleiro ;


/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor das casas
*
*
***********************************************************************/

typedef struct TAB_tagCasaInfo {
	PECA * peca[4];
		/*Peça ocupando, podendo ser null*/

}TAB_tpCasaInfo;


/***********************************************************************
*
*  $FC Função: TAB  -Cria o Tabuleiro
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro () {
	TAB_tpTabuleiro * tab = NULL;
	TAB_tpCasaInfo * casaInfo = NULL;
	int i =0;

	tab = ( TAB_tpTabuleiro * ) malloc( sizeof( TAB_tpTabuleiro));
	memset(tab, 0, sizeof(TAB_tpTabuleiro));
	if ( tab == NULL ) return NULL;

	tab->casasNormais = LISC_CriarLista(TAB_Limpa);
	for ( i = 0; i < 55; i++) {
		if(!LISC_InserirElementoApos(tab->casasNormais,casaInfo)) {
			// ERRO AO INSERIR ELEMENTO
			return NULL;
		}
	}
	tab->casasFim1 = LIS_CriarLista(TAB_Limpa);
	for(i = 0; i < 4; i++) {
		if(!LIS_InserirElementoApos(tab->casasFim1,casaInfo)) {
			// ERRO AO INSERIR ELEMENTO
			return NULL;
		}
	}
	tab->casasFim2 = LIS_CriarLista(TAB_Limpa);
	for(i = 0; i < 4; i++) {
		if(!LIS_InserirElementoApos(tab->casasFim2,casaInfo)) {
			// ERRO AO INSERIR ELEMENTO
			return NULL;
		}
	}
	tab->casasFim3 = LIS_CriarLista(TAB_Limpa);
	for(i = 0; i < 4; i++) {
		if(!LIS_InserirElementoApos(tab->casasFim3,casaInfo)) {
			// ERRO AO INSERIR ELEMENTO
			return NULL;
		}
	}
	tab->casasFim4 = LIS_CriarLista(TAB_Limpa);
	for(i = 0; i < 4; i++) {
		if(!LIS_InserirElementoApos(tab->casasFim4,casaInfo)) {
			// ERRO AO INSERIR ELEMENTO
			return NULL;
		}
	}

	return tab;
}

/***********************************************************************
*
*  $FC Função: TAB  -Destuir o Tabuleiro
*
***********************************************************************/

tpCondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab )
{

    #ifdef _DEBUG
        assert( pTab != NULL ) ;
    #endif
		
	LISC_EsvaziarLista( pTab->casasNormais );
	LIS_EsvaziarLista( pTab->casasFim1 ) ;
	LIS_DestruirLista( pTab->casasFim1 ) ;
	LIS_EsvaziarLista( pTab->casasFim2 ) ;
	LIS_DestruirLista( pTab->casasFim2 ) ;
	LIS_EsvaziarLista( pTab->casasFim3 ) ;
	LIS_DestruirLista(  pTab->casasFim3 ) ;
	LIS_EsvaziarLista( pTab->casasFim4 ) ;
	LIS_DestruirLista( pTab->casasFim4 ) ;

    free( pTab ) ;
	if ( pTab == NULL ) return CondRetOK;
	else return CondRetErro;
}

/***********************************************************************
*
*  $FC Função: TAB  -Limpa Casa
*
***********************************************************************/

void TAB_Limpa( void * casa )
{
    free( casa );
}

/***********************************************************************
*
*  $FC Função: TAB  -Limpa Casa
*
***********************************************************************/

tpCondRet TAB_LimpaCasaTab (TAB_tpCasaInfo* casa) {
	TAB_Limpa( casa );

	if ( casa == NULL ) 
		return CondRetOK;
	else 
		return CondRetErro;
}