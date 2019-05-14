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

#include "peca.h"
#include "lista_circular.h"
#include "lista.h"

#define TABULEIRO_OWN
#include "tabuleiro.h"
#undef TABULEIRO_OWN


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
 
    PECA * conteudo ;
        /* Ponteiro para o conteudo da casa */

} TAB_tpCasaInfo;
typedef void ( *pFunc ) ( void * ) ; typedef void **ppVoid ;

/***** Protótipo das funções encapsuladas no módulo *****/
 
static TAB_tppCasaInfo CriaCasa ( PECA * conteudo ) ;

static tpCondRet TAB_LimpaCasa (TAB_tpCasaInfo* casa);
 
static void TAB_LiberarCasa ( TAB_tpCasaInfo *pCasa ) ;


/***********************************************************************
*
*  $FC Função: TAB  -Cria o Tabuleiro
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro () {
	int i, k;
	TAB_tppTabuleiro pTab;
	LISC_tppListaC pListaC;
	LIS_tppLista pLista1, pLista2, pLista3, pLista4;
	TAB_tpCasaInfo *casa ;
	LISC_tpCondRet listcFlag;
	LIS_tpCondRet listFlag;

	pTab = ( TAB_tpTabuleiro * ) malloc( sizeof( TAB_tpTabuleiro));
	if ( pTab == NULL ) return NULL;

	pListaC = LISC_CriarLista ( ( pFunc ) TAB_LimpaCasa );
	if ( pListaC = NULL ) return NULL;

	pLista1 = LIS_CriarLista( ( pFunc ) TAB_LimpaCasa );
	if ( pLista1 = NULL ) return NULL;
	pLista2 = LIS_CriarLista( ( pFunc ) TAB_LimpaCasa );
	if ( pLista2 = NULL ) return NULL;
	pLista3 = LIS_CriarLista( ( pFunc ) TAB_LimpaCasa );
	if ( pLista3 = NULL ) return NULL;
	pLista4 = LIS_CriarLista( ( pFunc ) TAB_LimpaCasa );
	if ( pLista4 = NULL ) return NULL;

	for( k = 0; k < 55 ; k++ ){
		
		casa = CriaCasa ( NULL ) ;
        if ( casa == NULL ) return NULL ;

        listcFlag = LISC_InserirElementoAntes( pListaC , casa ) ;
		if ( listcFlag == LIS_CondRetOK ) return NULL;
    }

	for( i = 0 ; i < 4 ; i++ ){
		listFlag = LIS_InserirElementoApos( pLista1 , ( pFunc ) TAB_LimpaCasa ) ;
		if ( listFlag == LIS_CondRetOK ) return NULL;
    }
	for( i = 0 ; i < 4 ; i++ ){
		listFlag = LIS_InserirElementoApos( pLista2 , ( pFunc ) TAB_LimpaCasa ) ;
		if ( listFlag == LIS_CondRetOK ) return NULL;
    }
	for( i = 0 ; i < 4 ; i++ ){
		 listFlag = LIS_InserirElementoApos( pLista3 , ( pFunc ) TAB_LimpaCasa ) ;
		 if ( listFlag == LIS_CondRetOK ) return NULL;
    }
	for( i = 0 ; i < 4 ; i++ ){
		 listFlag = LIS_InserirElementoApos( pLista4 , ( pFunc ) TAB_LimpaCasa ) ;
		 if ( listFlag == LIS_CondRetOK ) return NULL;
    }
 
    pTab->casasNormais = pListaC ;
	pTab->casasFim1 = pLista1;
	pTab->casasFim2 = pLista2;
	pTab->casasFim3 = pLista3;
	pTab->casasFim4 = pLista4;
 
    return pTab ;

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
		
	LISC_EsvaziarLista( pTab->casasNormais ) ;
	LISC_DestruirLista( pTab->casasNormais ) ;
	LIS_EsvaziarLista( pTab->casasFim1 ) ;
	LIS_DestruirLista( pTab->casasFim1 ) ;
	LIS_EsvaziarLista( pTab->casasFim2 ) ;
	LIS_DestruirLista( pTab->casasFim2 ) ;
	LIS_EsvaziarLista( pTab->casasFim3 ) ;
	LIS_DestruirLista( pTab->casasFim3 ) ;
	LIS_EsvaziarLista( pTab->casasFim4 ) ;
	LIS_DestruirLista( pTab->casasFim4 ) ;

    free( pTab ) ;
	if ( pTab == NULL ) return CondRetOK;
	else return CondRetErro;
}


/***********************************************************************
*
*  $FC Função: TAB  -Cria Casa
*
***********************************************************************/

static TAB_tppCasaInfo CriaCasa ( PECA * conteudo )
{
    TAB_tpCasaInfo *casa ;
     
    casa  = (TAB_tpCasaInfo *) malloc ( sizeof ( TAB_tpCasaInfo ) ) ;
     
    if( casa == NULL ) return NULL ;

	casa->conteudo = conteudo;
 
    return casa ;
} 

/***********************************************************************
*
*  $FC Função: TAB  -Limpa Casa
*
***********************************************************************/

tpCondRet TAB_LimpaCasa (TAB_tpCasaInfo* casa) {

	if ( casa->conteudo != NULL )
    {
        destroi_peca ( casa->conteudo ) ;
    }
     
    casa = NULL ;

	if ( casa == NULL ) 
		return CondRetOK;
	else 
		return CondRetErro;
}