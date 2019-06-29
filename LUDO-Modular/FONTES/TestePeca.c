/***************************************************************************
*  $MCI M�dulo de implementa��o: TestePeca
*
*  Arquivo gerado:              TestePeca.c
*  Letras identificadoras:      TPECA
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros

***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    <stdlib.h>
#include    "peca.h"
#include	"TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"

#define MAX_PECAS 16 

#define VAZIO     0
#define NAO_VAZIO 1


#define TRUE  1
#define FALSE 0

/***********************************************************************
*
*  $FC Fun��o: TDADO &Testar dado
*
*  $ED Descri��o da fun��o
*     Cria um dado ponto
*
*     Comandos dispon�veis:
*
*     =criarpeca                         iPeca Cor CondRetEsp
*     =destruirpeca                      iPeca CondRetEsp
*     =obterstatus                       iPeca CondRetEsp
*	  =atualizapeca   					 iPeca Final Status CondRetEsp
*
***********************************************************************/

static const char RESET_PECA_CMD 		  [ ] = "=resetteste"     ;
static const char CRIAR_PECA_CMD          [ ] = "=criarpeca"     ;
static const char DESTRUIR_PECA_CMD       [ ] = "=destruirpeca"  ;
static const char OBTER_COR_CMD        	  [ ] = "=obtercor"   ;
static const char OBTER_FIM_CMD           [ ] = "=obterfim"   ;
static const char OBTER_STATUS_CMD        [ ] = "=obterstatus"   ;
static const char OBTER_INFO_CMD          [ ] = "=obterinfo"   ;
static const char ATUALIZAR_PECA_CMD      [ ] = "=atualizapeca"  ;

/**********************************************************************
* 
*         Vetor de PECAS
*
***********************************************************************/

PECA_tpPeca VPecas[MAX_PECAS];


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS &Testar peca
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 16 pecas, identificadas pelos �ndices 0 a 15
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de pecas. Provoca vazamento de mem�ria
*     =criarpeca                    iPeca  corEsp   CondRetEsp
*     =destruirpeca                 iPeca  CondRetEsp
*     =obtercor                 	iPeca  corEsp   CondRetEsp
*     =obterfim                  	iPeca  finalEsp CondRetEsp
*     =obterstatus             		iPeca  statusEsp CondRetEsp
*     =obterinfo                    iPeca  corEsp	finalEsp	stausEsp	CondRetEsp
*     =atualizapeca                 iPeca
*
***********************************************************************/

/***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos      = -1 ;
	int iPeca		  = -1 ;
	int corObtida     = -1 ;
	int corEsp		  = -1 ;
	int finalObtido   = -1 ;
	int finalEsp      = -1 ;
	char statusObtido      ;
	char statusEsp         ;
	int CondRetEsp    = -1 ;
	int CondRetObtido = -1 ;
	int i             = -1 ;

	/* reset vetor de pecas */

	if ( strcmp( ComandoTeste , RESET_PECA_CMD ) == 0 )
         {

            for( i = 0 ; i < MAX_PECAS ; i++ )
            {
               VPecas[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } 

	/* Testar CriarPeca */

	if( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "iii", &iPeca, &corEsp ,&CondRetEsp);
		if( numLidos != 3 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PECA_CriaPeca ( VPecas, iPeca, corEsp ) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Retorno errado") ;


	}
	
	/* Testar Destruir */
	
	else if ( strcmp( ComandoTeste , DESTRUIR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "ii", &iPeca ,&CondRetEsp ) ;

		if (numLidos != 2)
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PECA_DestroiPeca ( VPecas[iPeca] ) ;

		VPecas[iPeca] = NULL;

		return TST_CompararInt (CondRetEsp, CondRetObtido, "Retorno errado") ;

	}

	/* Testar Obter cor */

	else if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "iii", &iPeca , &corEsp ,&CondRetEsp ) ;

		if ( numLidos != 3)
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = PECA_ObtemCor ( VPecas[iPeca] , &corObtida ) ;

		
		if( CondRetEsp == PECA_CondRetOK )
		{
			return  TST_CompararInt(  corEsp , corObtida , "PECA_ObtemCor: valor de cor retornado inesperado ." ) ;
		} /* if */
				
		return TST_CompararInt( CondRetEsp , CondRetObtido , "PECA_ObtemCor: Condicao de retorno errada." ) ;

	}

	/* Testar Obter fim */

	else if ( strcmp( ComandoTeste , OBTER_FIM_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "iii", &iPeca , &finalEsp ,&CondRetEsp ) ;

		if ( numLidos != 3 )
		{
			return TST_CondRetParm ;
		} /* if */


		CondRetObtido = PECA_ObtemFim ( VPecas[iPeca] , &finalObtido );

		if( CondRetEsp == PECA_CondRetOK)
		{
			return  TST_CompararInt( finalObtido  , finalEsp , "PECA_ObtemFim: valor de fim retornado inesperado ." ) ;
		} /* if */
				
		return TST_CompararInt( CondRetObtido ,CondRetEsp , "PECA_ObtemFim: Condicao de retorno errada." ) ;

	}

	/* Testar Obter Status */

	else if ( strcmp( ComandoTeste , OBTER_STATUS_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ici", &iPeca, &statusEsp ,&CondRetEsp ) ;

		if (numLidos != 3)
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PECA_ObtemStatus ( VPecas[iPeca] , &statusObtido );

		if( CondRetEsp == PECA_CondRetOK)
		{
			return  TST_CompararChar(  statusEsp , statusObtido , "PECA_ObtemStatus: valor de status retornado inesperado ." ) ;
		} /* if */
				
		return TST_CompararInt( CondRetEsp , CondRetObtido , "PECA_ObtemStatus: Condicao de retorno errada." ) ;

	}

	/* Testar Obter info */

	else if ( strcmp( ComandoTeste , OBTER_INFO_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "iiici", &iPeca, &corEsp, &finalEsp, &statusEsp ,&CondRetEsp ) ;

		if ( numLidos != 5)
		{
			return TST_CondRetParm ;
		}


		CondRetObtido = PECA_ObtemInfo( VPecas[iPeca], &corObtida, &finalObtido, &statusObtido ) ;

		if( CondRetEsp == PECA_CondRetOK)
		{
			if((statusEsp != statusObtido)   ||  (corEsp != corObtida) || (finalEsp != finalObtido))
				return TST_CompararInt( -1 , 0 , "valor de retorno errado em info." ) ;
		} /* if */
				
		return TST_CompararInt( CondRetEsp , CondRetObtido , "PECA_ObtemInfo: Condicao de retorno errada." ) ;

	}

	/* Testar Atualiza Peca */

	else if ( strcmp( ComandoTeste , ATUALIZAR_PECA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "iici", &iPeca ,&finalEsp, &statusEsp, &CondRetEsp ) ;

		if ( numLidos != 4 )
		{
			return TST_CondRetParm ;
		}


		CondRetObtido = PECA_AtualizaPeca( VPecas[iPeca], finalEsp , statusEsp ) ;
				
		return TST_CompararInt( CondRetEsp , CondRetObtido , "PECA_AtualizaPeca: Condicao de retorno errada." ) ;

			}

    return TST_CondRetNaoConhec ;
			
}

/*********** Fim do m�dulo de implementa��o: TPECA **********/
