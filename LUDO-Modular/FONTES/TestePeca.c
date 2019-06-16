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

#define N_TIMES 4
#define MAX_PECAS 4 //USADO PARA VETOR DE PECAS

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

static const char CRIAR_PECA_CMD          [ ] = "=criarpeca"     ;
static const char DESTRUIR_PECA_CMD       [ ] = "=destruirpeca"  ;
static const char OBTER_STATUS_CMD        [ ] = "=obterstatus"   ;
static const char ATUALIZAR_PECA_CMD      [ ] = "=atualizapeca"  ;

/**********************************************************************
* 
*         Vetor de PECAS
*
***********************************************************************/

PECA_tpPeca vtPecas[N_TIMES][MAX_PECAS];

/***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos      = -1 ;
	int iPeca		  = -1 ;
	int cor           = -1 ;
	int CondRetEsp    = -1 ;
	int CondRetObtido = -1 ;
	int final         = -1 ;
	char status            ;
	PECA_tpPeca *p          ;

	/* Testar Criar */

	if( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "iii", &iPeca, &cor ,&CondRetEsp);
		if( numLidos != 3 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PECA_CriaPeca ( vtPecas[N_TIMES], iPeca, cor ) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Retorno errado") ;


	}
	
	/* Testar Destruir */
	
	else if ( strcmp( ComandoTeste , DESTRUIR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "ii", &iPeca, &CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PECA_DestroiPeca ( vtPecas[N_TIMES][iPeca] ) ;
		p = NULL ;

		return TST_CompararInt (CondRetEsp, CondRetObtido, "Retorno errado") ;

	}

		/* Testar Obter Status */

         else if ( strcmp( ComandoTeste , OBTER_STATUS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii", &iPeca, &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PECA_ObtemInfo( vtPecas[N_TIMES][iPeca], &cor, &final, &status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao obter status." ) ;

         }

		/* Testar Atualiza Peca */

         else if ( strcmp( ComandoTeste , ATUALIZAR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iici", &iPeca, &final, &status, &CondRetEsp ) ;

            if (  numLidos != 4 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PECA_AtualizaPeca( vtPecas[N_TIMES][iPeca], final, status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao Atualiza Peca." ) ;

         }

    return TST_CondRetNaoConhec ;
			
}

/********** Fim do m�dulo de implementa��o: TPECA **********/