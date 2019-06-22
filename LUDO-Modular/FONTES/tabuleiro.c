/***************************************************************************
*  $MCI M�dulo de implementa��o: TAB  M�dulo do tabuleiro para LUDO
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


#define TOT_CASAS_TAB 52
#define INTERVALO_CASAS_INI 13

#define TOT_CASAS_RETA_FINAL 6

#define TIMES 4


/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do tabuleiro (uma lista circular e 4 listas)
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {

         LISC_tppListaC casasNormais ;
               /* Ponteiro para a lista circular que ir� representar as casas normais do tabuleiro */
		 LIS_tppLista casasFinais[4];
		 		/* Ponteiro para vetor de lista das casas finais */	

   } TAB_tpTabuleiro ;


/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor das casas
*
*
***********************************************************************/


typedef struct TAB_tagCasaInfo {
 
    PECA_tpPeca conteudo ;
        /* Ponteiro para o conteudo da casa */

	LIS_tppLista desvio;
		/* ponteiro para lista de casas finais */

} TAB_tpCasaInfo;

typedef void ( *pFunc ) ( void * ) ; typedef void **ppVoid ;

/***** Prot�tipo das fun��es encapsuladas no m�dulo *****/
 
static TAB_tppCasaInfo CriaCasa ( PECA_tpPeca conteudo , LIS_tppLista desvio) ;

static TAB_CondRet TAB_LimpaCasa (TAB_tpCasaInfo* casa);

static int TAB_ComparaCasa(TAB_tpCasaInfo* casa1 ,TAB_tpCasaInfo* casa2);	
 
static void TAB_LiberarCasa ( TAB_tpCasaInfo *pCasa ) ;


/***********************************************************************
*
*  $FC Fun��o: TAB  -Cria o Tabuleiro
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro () {
	int i, k, cor;

	TAB_tppTabuleiro pTab;

	LISC_tppListaC pListaC;

	LIS_tppLista pLista[TIMES];

	TAB_tpCasaInfo *casa ;

	LISC_tpCondRet listcFlag;

	LIS_tpCondRet listFlag;

	pTab = ( TAB_tpTabuleiro * ) malloc( sizeof(TAB_tpTabuleiro));
	if ( pTab == NULL ) return NULL;

	pListaC = LISC_CriarLista ( TAB_LimpaCasa , TAB_ComparaCasa );
	if ( pListaC == NULL ) return NULL;

	for(cor = 0;cor < TIMES;cor++){
		pLista[cor] = LIS_CriarLista( ( pFunc ) TAB_LimpaCasa );
		if ( pLista[cor] == NULL ) 
			return NULL;
	}

	cor = 0;
	for( k = 0; k < TOT_CASAS_TAB ; k++ ){
		
		if(k % INTERVALO_CASAS_INI == 0){
				casa = CriaCasa ( NULL , pLista[cor]) ;
				cor++;
		}
		else{
			casa = CriaCasa ( NULL , NULL) ;
		}
		
        if ( casa == NULL ) return NULL ;

        listcFlag = LISC_InserirElementoAntes( pListaC , casa ) ;
		if ( listcFlag != LIS_CondRetOK ) return NULL;
    }

	for(cor=0;cor<TIMES;cor++){
		for( i = 0 ; i < TOT_CASAS_RETA_FINAL ; i++ ){
		 listFlag = LIS_InserirElementoApos( pLista[cor] , CriaCasa(NULL,NULL) );
		 if ( listFlag != LIS_CondRetOK ) return NULL;
    	}
	}
 
    pTab->casasNormais = pListaC ;

	for(cor = 0;cor < TIMES;cor++){
		pTab-> casasFinais[cor] = pLista[cor];
	}

    return pTab;

}

/***********************************************************************
*
*  $FC Fun��o: TAB  -Destuir o Tabuleiro
*
***********************************************************************/

TAB_CondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab )
{
	int cor;

    #ifdef _DEBUG
        assert( pTab != NULL ) ;
    #endif
	
	for(cor=0;cor<TIMES;cor++){
		LIS_DestruirLista( pTab->casasFinais[cor] ) ;
	}

	LISC_DestruirLista( pTab->casasNormais ) ;


    free( pTab ) ;
	
	return TAB_CondRetOK;

}


/***********************************************************************
*
*  $FC Fun��o: TAB  -Cria Casa
*
***********************************************************************/

static TAB_tppCasaInfo CriaCasa ( PECA_tpPeca conteudo, LIS_tppLista desvio )
{
    TAB_tpCasaInfo *casa ;

	assert(conteudo == NULL);
     
    casa  = (TAB_tpCasaInfo *) malloc ( sizeof ( TAB_tpCasaInfo ) ) ;
     
    if( casa == NULL ) return NULL ;

	casa -> conteudo = conteudo;
	
	casa -> desvio = desvio;

	assert(casa -> conteudo == NULL);
 
    return casa ;
} 

/***********************************************************************
*
*  $FC Fun��o: TAB  -Limpa Casa
*
***********************************************************************/

TAB_CondRet TAB_LimpaCasa (TAB_tppCasaInfo casa) 
{

	if ( casa->conteudo != NULL )
    {
        PECA_DestroiPeca( casa->conteudo ) ;
    }

	if( casa -> desvio != NULL)
	{
		LIS_DestruirLista( casa -> desvio ) ; 
	}
    
	free(casa);
	
	return TAB_CondRetOK;
}
/***********************************************************************
*
*  $FC Fun��o: TAB  -Compara Casas
*
***********************************************************************/


static int TAB_ComparaCasa(TAB_tpCasaInfo* casa1 ,TAB_tpCasaInfo* casa2){

	if(casa1 == casa2){
		return 0;
	}  
	return -1;
}
