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

#define PECAS 4

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor das casas
*
*
***********************************************************************/


typedef struct TAB_tagCasaInfo {
 
    PECA_tpPeca conteudo[PECAS] ;
        /* Ponteiro para o conteudo da casa */

	LIS_tppLista desvio;
		/* ponteiro para lista de casas finais */

} TAB_tpCasaInfo;


/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do tabuleiro (uma lista circular e 4 listas)
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {

         LISC_tppListaC casasNormais;
               /* Ponteiro para a lista circular que ir� representar as casas normais do tabuleiro */
		 LIS_tppLista casasFinais[4];
		 		/* Ponteiro para vetor de lista das casas finais */	
		 TAB_tpCasaInfo* casaIni;
		 		/* Ponteiro para casa inicial vermelha */	

   } TAB_tpTabuleiro ;




typedef void ( *pFunc ) ( void * ) ; typedef void **ppVoid ;

/***** Prot�tipo das fun��es encapsuladas no m�dulo *****/
 
static TAB_tppCasaInfo CriaCasa ( PECA_tpPeca* conteudo , LIS_tppLista desvio) ;

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

	PECA_tpPeca peca_null[4];

	for(i=0;i<TIMES;i++)
		peca_null[i] = NULL;

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
				casa = CriaCasa ( peca_null , pLista[cor]) ;
				if(cor == 0){
					pTab -> casaIni = casa;
				}
				cor++;
		}
		else{
			casa = CriaCasa (peca_null , NULL) ;
		}
		
        if ( casa == NULL ) return NULL ;

        listcFlag = LISC_InserirElementoApos( pListaC , casa ) ;
		if ( listcFlag != LIS_CondRetOK ) return NULL;
    }

	for(cor=0;cor<TIMES;cor++){
		for( i = 0 ; i < TOT_CASAS_RETA_FINAL ; i++ ){
		 listFlag = LIS_InserirElementoApos( pLista[cor] , CriaCasa(peca_null,NULL) );
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

static TAB_tppCasaInfo CriaCasa ( PECA_tpPeca* conteudo, LIS_tppLista desvio )
{
	int i;

    TAB_tpCasaInfo *casa ;

	assert(conteudo != NULL);
     
    casa  = (TAB_tpCasaInfo *) malloc ( sizeof ( TAB_tpCasaInfo ) ) ;
     
    if( casa == NULL ) return NULL ;

	for(i=0;i<TIMES;i++)
		casa -> conteudo[i] = conteudo[i];
	
	casa -> desvio = desvio;

	assert(casa -> conteudo != NULL);
 
    return casa ;
} 

/***********************************************************************
*
*  $FC Fun��o: TAB  -Limpa Casa
*
***********************************************************************/

TAB_CondRet TAB_LimpaCasa (TAB_tppCasaInfo casa) 
{
	int i;

	if ( casa->conteudo != NULL )
    {
	for(i=0;i<TIMES;i++)
        PECA_DestroiPeca( casa->conteudo[i] ) ;
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

/***********************************************************************
*
*  $FC Fun��o: TAB  -imprime TAB
*
***********************************************************************/

void TAB_imprime(PECA_tpPeca* pecas, TAB_tppTabuleiro ptab, int num_jogadores){

	int linha, coluna;

	char tabuleiro[31][62] ={
							    "    __________          v---v---v---v         __________     " ,
                                "   |          |         |   |   |   |        |          |    " ,
                                "   |  R    R  |         |---+---+---|        |  B       |    " ,
                                "   |          |         |Rx2|   < B | <==    |          |    " ,
                                "   |          |         |---+---+---|        |          |    " ,
                                "   |__________|         |   |   |   |        |__________|    " ,
                                "                        |---+---+---|                        " ,
                                "                        |   |   |   |                        " ,
                                "                        |---+---+---|                        " ,
                                "                        |   |   |   |                        " ,
                                "     ||                 |---+---+---|                        " ,
                                "     vv                 |   |   |   |                        " ,
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,
                                "|   |   |   |   |   |   | X |   | X |   | B |   |   |   |   |" ,
                                "|---+vvv+---+---+---+---+---+---+---+---+---+---+---+---+---|" ,
                                "|   |   |   |   |   |   |   | X | B |   |   |   |   |   |   |" ,
                                "|---+---+---+---+---+---+---+---+---+---+---+---+---+^^^+---|" ,
                                "|   |   |   |   |   |   | X |   | X |   |   |   |   |   |   |" ,
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,
                                "                        |   |   |   |                ^^      " ,
                                "                        |---+---+---|                ||      " ,
                                "                        |   |   |   |                        " ,
                                "                        |---+---+---|                        " ,
                                "                        | Y |   |   |                        " ,
                                "    __________          |---+---+---|         __________     " ,
                                "   |          |         |   |   |   |        |          |    " ,
                                "   |  Y   Y   |         |---+---+---|        |  G    G  |    " ,
                                "   |          |     ==> |   >   |   |        |          |    " ,
                                "   |  Y       |         |---+---+---|        |  G    G  |    " ,
                                "   |__________|         |   |   |   |        |__________|    " ,
                                "                        ^---^---^---^                        " };

	
	LISC_ProcurarValor( ptab ->casasNormais , ptab->casaIni ) ;//tornar casa inicial vermelha como elemento inicial
	LISC_AvancarElementoCorrente( ptab ->casasNormais , 10 ); //ir para topo do tabuleiro

	for(linha=0;linha<TIMES;i++){
		IrInicioLista( ptab ->casasFinais[linha] ) ; //voltar para casa inicial
	}

	for(linha=0;linha < 31;linha++){
		for(coluna=0;coluna < 61;coluna++){

			if(linha > 0 && linha < 12 && linha % 2 == 1) //casas da area azul
			{ 
			
				if(coluna == 25) //casas circulares
				{ 
					PrintaCasa( ptab -> casasNormais);
					if(linha == 1)
						LISC_AvancarElementoCorrente( ptab ->casasNormais , 1);
					else
						LISC_AvancarElementoCorrente( ptab ->casasNormais , linha + 1);
				}
				else if(coluna == 33)
				{
					PrintaCasa( ptab -> casasNormais);
					LISC_AvancarElementoCorrente( ptab ->casasNormais , (linha + 2) * -1 );
				}
				else if(coluna == 29)
				{
					if(linha == 1)
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , 1);
					}
					else{
						PrintaCasaFim(ptab ->casasFinais[1]);
						LIS_AvancarElementoCorrente( ptab ->casasFinais[1] , 1) ;
					} 

				}

			coluna+=2;
			}
			else
			{
				printf("%c", tabuleiro[i][j]);
			}

			
		}
		printf("\n");
		if(linha == 12)
			{
				LISC_AvancarElementoCorrente( ptab ->casasNormais , -18);	
			}
	}
	
}


