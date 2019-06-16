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


#define DIM_VT_PECAS  8

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

static const char CRIAR_VET_PECA_CMD      [ ] = "=criarvetpeca"  ;
static const char CRIAR_PECA_CMD          [ ] = "=criarpeca"     ;
static const char DESTRUIR_PECA_CMD       [ ] = "=destruirpeca"  ;
static const char OBTER_STATUS_CMD        [ ] = "=obterstatus"   ;
static const char ATUALIZAR_PECA_CMD      [ ] = "=atualizapeca"  ;

/**********************************************************************
* 
*         Vetor de PECAS
*
***********************************************************************/

PECA_tpPeca* mtxPecas[DIM_VT_PECAS];

/***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos      = -1 ;
	int iPeca		  = -1 ;
	int cor           = -1 ;
	int CondRetEsp    = -1 ;
	int CondRetObtido = -1 ;
	int final         = -1 ;
	int index		  = -1 ;
	char status            ;


	/* Testar CriarVetPeca */

	if( strcmp( ComandoTeste , CRIAR_VET_PECA_CMD  ) == 0 )
	{
		numLidos = LER_LerParametros( "ii", &iPeca,&CondRetEsp);
		if( numLidos != 2 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PECA_CriaVetPeca ( mtxPecas[iPeca]) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Retorno errado") ;


	}

	/* Testar CriarPeca */

	if( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "iiii", &iPeca,&index, &cor ,&CondRetEsp);
		if( numLidos != 4 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PECA_CriaPeca ( mtxPecas[iPeca],index , cor ) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Retorno errado") ;


	}
	
	/* Testar Destruir */
	
	else if ( strcmp( ComandoTeste , DESTRUIR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "iii", &iPeca, &index ,&CondRetEsp ) ;

		if ( numLidos != 3 )
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PECA_DestroiPeca ( mtxPecas[iPeca][index] ) ;

		return TST_CompararInt (CondRetEsp, CondRetObtido, "Retorno errado") ;

	}

		/* Testar Obter Status */

         else if ( strcmp( ComandoTeste , OBTER_STATUS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii", &iPeca, &index ,&CondRetEsp ) ;

			if ( numLidos != 3 )
			{
				return TST_CondRetParm ;
			}


            CondRetObtido = PECA_ObtemInfo( mtxPecas[iPeca][index], &cor, &final, &status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao obter status." ) ;

         }

		/* Testar Atualiza Peca */

         else if ( strcmp( ComandoTeste , ATUALIZAR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iiici", &iPeca, &index ,&final, &status, &CondRetEsp ) ;

            if (  numLidos != 5 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PECA_AtualizaPeca( mtxPecas[iPeca][index], final, status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao Atualiza Peca." ) ;

         }

    return TST_CondRetNaoConhec ;
			
}

/********** Fim do m�dulo de implementa��o: TPECA **********/