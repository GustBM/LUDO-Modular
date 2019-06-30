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

#define TRUE 1
#define FALSE 0


#define TOT_CASAS_TAB 52
#define INTERVALO_CASAS_INI 13

#define TOT_CASAS_RETA_FINAL 6

#define TIMES 4

#define PECAS 4

/* DEFINES PARA INTERFACE */

//PRINTA PECA
#define TOT_PECAS 16

#define INI_VERMELHO 0
#define FIM_VERMELHO 3
#define INI_AZUL 4
#define FIM_AZUL 7
#define INI_VERDE 8
#define FIM_VERDE 11

//PRINTA CASA
#define NENHUM_PRESENTE 0
#define NENHUMA_COR -1
#define UM_PRESENTE 1 


#define LINHAS_TAB 31
#define COLUNAS_TAB_NULO 62
#define COLUNAS_TAB 61

#define IDA_TOPO 10

#define VERMELHO 0
#define AZUL 1
#define VERDE 2
#define AMARELO 3

//MOVIMENTO NA AREA AZUL
#define AVANCA_AREA_AZUL(linha) ((linha) + 1) 
#define RETROCEDE_AREA_AZUL(linha) ((linha + 2) * -1)

//MOVIMENTO NA AREA VERMELHA E VERDE
#define AVANCO_AREA_VERMELHA_VERDE_1 13
#define AVANCO_AREA_VERDE_VERMELHA_1 -26
#define AVANCO_AREA_VERDE_VERMELHA_2 25
#define AVANCO_AREA_VERMELHA_VERDE_2 26
#define AVANCO_AREA_VERMELHA_VERDE_3 -13 

#define AVANCO_AREA_VERDE_AMARELA 18 

//MOVIMENTO GERAL
#define RETROCESSO_UNICO -1
#define AVANCO_UNICO 1
#define PROX_CASA 2


//LINHAS E COLUNAS DA BORDA
#define LINHA_BORDA_SUP 1
#define LINHA_BORDA_INF 29
#define COLUNA_LESTE_BORDA 57
#define COLUNA_OESTE_BORDA 1
#define FIM_DE_LINHA 61

//LINHAS E COLUNAS DE INICIOS DAS PECAS 
#define COLUNA_VERMELHO_AMARELO_0 6
#define COLUNA_VERMELHO_AMARELO_1 11

#define COLUNA_AZUL_VERDE_0 53
#define COLUNA_AZUL_VERDE_1 48

#define LINHA_VERMELHO_AZUL_0 2
#define LINHA_VERMELHO_AZUL_1 4

#define LINHA_AMARELO_VERDE_0 26
#define LINHA_AMARELO_VERDE_1 28

//NOMES DAS PECAS
#define PECA_VERMELHA_1 0
#define PECA_VERMELHA_2 1
#define PECA_VERMELHA_3 2
#define PECA_VERMELHA_4 3
#define PECA_AZUL_1 4
#define PECA_AZUL_2 5
#define PECA_AZUL_3 6
#define PECA_AZUL_4 7
#define PECA_VERDE_1 8
#define PECA_VERDE_2 9
#define PECA_VERDE_3 10
#define PECA_VERDE_4 11
#define PECA_AMARELA_1 12
#define PECA_AMARELA_2 13
#define PECA_AMARELA_3 14
#define PECA_AMARELA_4 15

//VERIFICA LOCAL DE CASAS POR COR
#define AREA_AZUL(linha)((linha) > 0 && (linha) < 12 && (linha) % 2 == 1 ? TRUE: FALSE) 
#define LINHAS_VERMELHAS_VERDES(linha)((linha) > 12 && (linha) < 18 && (linha) % 2 == 1? TRUE:FALSE)
#define COLUNA_VERMELHA(coluna)((coluna) % 4 == 1 && (coluna) > 0 && (coluna) < 26? TRUE:FALSE)
#define COLUNA_FIM_VERMELHA(coluna)((coluna) > 4  && (coluna) < 26 && (coluna) % 4 == 1? TRUE:FALSE)
#define COLUNA_VERDE(coluna)((coluna) % 4 == 1 && (coluna) > 36 && (coluna) < 61? TRUE:FALSE) 
#define COLUNA_FIM_VERDE(coluna)((coluna) > 36  && (coluna) < 57 && (coluna) % 4 == 1? TRUE:FALSE)
#define AREA_AMARELA(linha)((linha) > 18 && (linha) < 30 && (linha) % 2 == 1? TRUE:FALSE)

//LINHAS E COLUNAS DE CASAS
#define COLUNA_AZUL_AMARELA_1 25
#define COLUNA_AZUL_AMARELA_2 29
#define COLUNA_AZUL_AMARELA_3 33

#define LINHA_VERMELHA_VERDE_1 13
#define LINHA_VERMELHA_VERDE_2 15
#define LINHA_VERMELHA_VERDE_3 17

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

void TAB_AcessaCasas ( TAB_tppTabuleiro pTab , LISC_tppListaC casasNomais, TAB_tppCasaInfo casasIni, LIS_tppLista casasFinais) {
	casasNomais = pTab->casasNormais;
	casasIni = pTab->casaIni;
	casasFinais = pTab->casasFinais;
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
*  $FC Fun��o: TAB  -imprime Peca
*
***********************************************************************/

void PrintaPeca(PECA_tpPeca* pecas,int ind){

	char status;

	if(ind >= INI_VERMELHO && ind < TOT_PECAS)
	{
		PECA_ObtemStatus (pecas[ind] , &status ) ;

		if(status == 'F')
		{
			if(ind >= INI_VERMELHO && ind <= FIM_VERMELHO)
			{
				printf("R");
			}
			else if(ind >= INI_AZUL && ind <= FIM_AZUL)
			{
				printf("B");
			}
			else if(ind >= INI_VERDE && ind <= FIM_VERDE)
			{
				printf("G");
			}
			else
			{
				printf("Y");
			}
		}
		else{
			printf(" ");
		}

		
	}
	else{
		printf("Z");
	}

}

/***********************************************************************
*
*  $FC Fun��o: TAB  -imprime casas finais
*
***********************************************************************/

void PrintaCasaFim(LIS_tppLista pLista){

	int i;

	int cor = NENHUMA_COR;

	char letra[] = {'R','B','G','Y'};

	int presentes = NENHUM_PRESENTE;

	TAB_tpCasaInfo* imprime = LIS_ObterValor( pLista );

	

	for(i=0;i<PECAS;i++)
	{
		if(imprime -> conteudo[i] != NULL)
		{
			PECA_ObtemCor ( imprime -> conteudo[i], &cor ) ;
			presentes++;
		}
	}

	if(presentes == NENHUM_PRESENTE && cor == NENHUMA_COR)
		printf("   ");
	else{
		

		if(presentes == UM_PRESENTE)
		{
			printf(" %c ",letra[cor]);
		}
		else{
			printf("%cx%d",letra[cor], presentes);
		}
	} 


}

/***********************************************************************
*
*  $FC Fun��o: TAB  -imprime casas normais
*
***********************************************************************/

void PrintaCasa(LISC_tppListaC pLista)
{

	int i;

	int cor = NENHUMA_COR;

	char letra[] = {'R','B','G','Y'};

	int presentes = NENHUM_PRESENTE;

	TAB_tpCasaInfo* imprime;
	LISC_ObterValor( pLista, &imprime );

	for(i=0;i<PECAS;i++)
	{
		if(imprime -> conteudo[i] != NULL)
		{
			PECA_ObtemCor ( imprime -> conteudo[i], &cor ) ;
			presentes++;
		}
	}

	if(presentes == NENHUM_PRESENTE && cor == NENHUMA_COR)
	{
		printf("   ");
	}	
	else
	{
		if(presentes == UM_PRESENTE)
		{
			printf(" %c ",letra[cor]);
		}
		else
		{
			printf("%cx%d",letra[cor], presentes);
		}
	} 


}

/***********************************************************************
*
*  $FC Fun��o: TAB  -Avanca lista circular pela area amarela para print
*
***********************************************************************/

int AvancaCiruclarAreaAmarela(int indx)
{
	//assert((indx >= 0) && (indx <= 6)); 

	int deslocamento[] = {-12,-10,-8,-6,-4,-2};

	return deslocamento[indx];

}

/***********************************************************************
*
*  $FC Fun��o: TAB  -Retrocede lista circular pela area amarela para print
*
***********************************************************************/

int RetrocedeCiruclarAreaAmarela(int indx)
{
	//assert((indx >= 0) && (indx <= 6)); 

	int deslocamento[] = {11,9,7,5,3,1};

	return deslocamento[indx];
}


/***********************************************************************
*
*  $FC Fun��o: TAB  -imprime TAB
*
***********************************************************************/


void TAB_imprime(PECA_tpPeca* pecas, TAB_tppTabuleiro ptab){

	int linha, coluna;

	int indx_amarelo = 0;
		
	char tabuleiro[LINHAS_TAB][COLUNAS_TAB_NULO] ={	
	//							 0         1         2         3         4         5         6
	//                           0123456789012345678901234567890123456789012345678901234567890		
								"    __________          v---v---v---v         __________     " ,//0	0
                                "   |          |         |   |   |   |        |          |    " ,//1
                                "   |  R    R  |         |---+---+---|        |  B       |    " ,//2
                                "   |          |         |Rx2|   < B | <==    |          |    " ,//3
                                "   |          |         |---+---+---|        |          |    " ,//4
                                "   |__________|         |   |   |   |        |__________|    " ,//5
                                "                        |---+---+---|                        " ,//6
                                "                        |   |   |   |                        " ,//7
                                "                        |---+---+---|                        " ,//8
                                "                        |   |   |   |                        " ,//9
                                "     ||                 |---+---+---|                        " ,//0	1
                                "     vv                 |   |   |   |                        " ,//1
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,//2
                                "|   |   |   |   |   |RX2| X |   | X |   | B |   |   |   |   |" ,//3
                                "|---+vvv+---+---+---+---+---+---+---+---+---+---+---+---+---|" ,//4
                                "|   |   |   |   |   |   |   | X | B |   |   |   |   |   |   |" ,//5
                                "|---+---+---+---+---+---+---+---+---+---+---+---+---+^^^+---|" ,//6
                                "|   |   |   |   |   |   | X |   | X |   |   |   |   |   |   |" ,//7
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,//8
                                "                        |   |   |   |                ^^      " ,//9
                                "                        |---+---+---|                ||      " ,//0	2
                                "                        |   |   |   |                        " ,//1
                                "                        |---+---+---|                        " ,//2
                                "                        | Y |   |   |                        " ,//3
                                "    __________          |---+---+---|         __________     " ,//4
                                "   |          |         |   |   |   |        |          |    " ,//5
                                "   |  Y    Y  |         |---+---+---|        |  G    G  |    " ,//6
                                "   |          |     ==> |   >   |   |        |          |    " ,//7
                                "   |  Y       |         |---+---+---|        |  G    G  |    " ,//8
                                "   |__________|         |   |   |   |        |__________|    " ,//9
                                "                        ^---^---^---^                        "  //0	3
								};

	
	LISC_ProcurarValor( ptab ->casasNormais , ptab->casaIni ) ;//tornar casa inicial vermelha como elemento inicial
	LISC_AvancarElementoCorrente( ptab ->casasNormais , IDA_TOPO ); //ir para topo do tabuleiro

	
	IrInicioLista( ptab ->casasFinais[VERMELHO] ) ; //voltar para casa inicial
	IrInicioLista( ptab ->casasFinais[AZUL] ) ;
	IrFinalLista( ptab ->casasFinais[VERDE] ) ;
	IrFinalLista( ptab ->casasFinais[AMARELO] ) ;

	for(linha=0;linha < LINHAS_TAB;linha++){
		for(coluna=0;coluna < COLUNAS_TAB;coluna++){

			if(AREA_AZUL(linha)) //casas da area azul
			{ 
				if(coluna == COLUNA_AZUL_AMARELA_1) //casas circulares
				{ 
					PrintaCasa( ptab -> casasNormais);
					if(linha == LINHA_BORDA_SUP)
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_UNICO );
					else
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCA_AREA_AZUL(linha));
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_AMARELA_3)
				{
					PrintaCasa( ptab -> casasNormais);
					LISC_AvancarElementoCorrente( ptab ->casasNormais , RETROCEDE_AREA_AZUL(linha) );
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_AMARELA_2)
				{
					if(linha == LINHA_BORDA_SUP)
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_UNICO);
					}
					else{
						PrintaCasaFim(ptab ->casasFinais[AZUL]);
						LIS_AvancarElementoCorrente( ptab ->casasFinais[AZUL] , AVANCO_UNICO) ;
					} 
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_VERMELHO_AMARELO_0)
				{
					if(linha == LINHA_VERMELHO_AZUL_0)
						PrintaPeca(pecas,PECA_VERMELHA_1);
					if(linha == LINHA_VERMELHO_AZUL_1)
						PrintaPeca(pecas,PECA_VERMELHA_3);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_VERMELHO_AMARELO_1)
				{
					if(linha == LINHA_VERMELHO_AZUL_0)
						PrintaPeca(pecas,PECA_VERMELHA_2);
					if(linha == LINHA_VERMELHO_AZUL_1)
						PrintaPeca(pecas,PECA_VERMELHA_4);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_VERDE_1)
				{
					if(linha == LINHA_VERMELHO_AZUL_0)
						PrintaPeca(pecas,PECA_AZUL_1);
					if(linha == LINHA_VERMELHO_AZUL_1)
						PrintaPeca(pecas,PECA_AZUL_3);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_VERDE_0)
				{
					if(linha == LINHA_VERMELHO_AZUL_0)
						PrintaPeca(pecas,PECA_AZUL_2);
					if(linha == LINHA_VERMELHO_AZUL_1)
						PrintaPeca(pecas,PECA_AZUL_4);
					coluna+=PROX_CASA;
				}
			}
			else if(LINHAS_VERMELHAS_VERDES(linha)) //casas da area vermelha ou verde
			{ 
				if(linha == LINHA_VERMELHA_VERDE_1)
				{	
					if(COLUNA_VERMELHA(coluna))
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_UNICO);
						coluna+=PROX_CASA;		
					}
					if(coluna == COLUNA_AZUL_AMARELA_2)
					{
						PrintaCasaFim(ptab ->casasFinais[AZUL]);
						coluna+=PROX_CASA;
					}
					if(COLUNA_VERDE(coluna))
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_UNICO);
						coluna+=PROX_CASA;		
					}
					if(coluna == COLUNA_AZUL_AMARELA_1) 
					{
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_AREA_VERMELHA_VERDE_1);
						coluna+=PROX_CASA;
					}
					if(coluna == FIM_DE_LINHA)
					{
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_AREA_VERDE_VERMELHA_1);
					}
						
				}
				else if(linha == LINHA_VERMELHA_VERDE_2)
				{
					if(coluna == COLUNA_OESTE_BORDA) 
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_AREA_VERMELHA_VERDE_2);
					}
					if(COLUNA_FIM_VERMELHA(coluna))
					{
						PrintaCasaFim(ptab ->casasFinais[VERMELHO]);
						LIS_AvancarElementoCorrente( ptab ->casasFinais[VERMELHO] , AVANCO_UNICO);
					}
					if(COLUNA_FIM_VERDE(coluna))
					{
						PrintaCasaFim(ptab ->casasFinais[VERDE]);
						LIS_AvancarElementoCorrente( ptab ->casasFinais[VERDE] , RETROCESSO_UNICO);
					}
					if(coluna == COLUNA_LESTE_BORDA)
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais ,  AVANCO_AREA_VERDE_VERMELHA_2);
					}
				coluna+=PROX_CASA;
				}
				else if(linha == LINHA_VERMELHA_VERDE_3)
				{
					if(COLUNA_VERMELHA(coluna))
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , RETROCESSO_UNICO);
						coluna+=PROX_CASA;		
					}
					if(coluna == COLUNA_AZUL_AMARELA_2)
					{
						PrintaCasaFim(ptab ->casasFinais[AMARELO]);
						coluna+=PROX_CASA;
					}
					if(COLUNA_VERDE(coluna))
					{
						PrintaCasa( ptab -> casasNormais);
						LISC_AvancarElementoCorrente( ptab ->casasNormais , RETROCESSO_UNICO);	
						coluna+=PROX_CASA;	
					}
					if(coluna == COLUNA_AZUL_AMARELA_1)
					{
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_AREA_VERMELHA_VERDE_3);
						coluna+=PROX_CASA;
					}
					if(coluna == FIM_DE_LINHA) 
					{
						LISC_AvancarElementoCorrente( ptab ->casasNormais , AVANCO_AREA_VERDE_AMARELA); 
					}
				}
			}
			else if(AREA_AMARELA(linha)) //casas da area amarela 
			{ 
				if(coluna == COLUNA_AZUL_AMARELA_1)
				{
					PrintaCasa( ptab -> casasNormais);
					LISC_AvancarElementoCorrente( ptab ->casasNormais , RetrocedeCiruclarAreaAmarela(indx_amarelo));
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_AMARELA_2)
				{
					if(linha == LINHA_BORDA_INF)
					{
						PrintaCasa( ptab -> casasNormais);
					}
					else
					{
						PrintaCasaFim(ptab ->casasFinais[AMARELO]);
						LIS_AvancarElementoCorrente( ptab ->casasFinais[AMARELO] , RETROCESSO_UNICO) ;
					} 
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_AMARELA_3)
				{
					PrintaCasa( ptab -> casasNormais);
					LISC_AvancarElementoCorrente( ptab ->casasNormais , AvancaCiruclarAreaAmarela(indx_amarelo));
					indx_amarelo++;
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_VERMELHO_AMARELO_0)
				{
					if(linha == LINHA_AMARELO_VERDE_0)
						PrintaPeca(pecas,PECA_VERDE_1);
					if(linha == LINHA_AMARELO_VERDE_1)
						PrintaPeca(pecas,PECA_VERDE_3);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_VERMELHO_AMARELO_1)
				{
					if(linha == LINHA_AMARELO_VERDE_0)
						PrintaPeca(pecas,PECA_VERDE_2);
					if(linha == LINHA_AMARELO_VERDE_1)
						PrintaPeca(pecas,PECA_VERDE_4);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_VERDE_1)
				{
					if(linha == LINHA_AMARELO_VERDE_0)
						PrintaPeca(pecas,PECA_AMARELA_1);
					if(linha == LINHA_AMARELO_VERDE_1)
						PrintaPeca(pecas,PECA_AMARELA_3);
					coluna+=PROX_CASA;
				}
				else if(coluna == COLUNA_AZUL_VERDE_0)
				{
					if(linha == LINHA_AMARELO_VERDE_0)
						PrintaPeca(pecas,PECA_AMARELA_2);
					if(linha == LINHA_AMARELO_VERDE_1)
						PrintaPeca(pecas,PECA_AMARELA_4);
					coluna+=PROX_CASA;
				}
			}
			else
			{
				printf("%c", tabuleiro[linha][coluna]);
			}
		}
		printf("\n");
	}
}
