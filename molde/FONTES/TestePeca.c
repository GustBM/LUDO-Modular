/***************************************************************************
*  $MCI M�dulo de implementa��o: TestePeca
*
*  Arquivo gerado:              TestePeca.c
*  Letras identificadoras:      TPEC
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

#define MAX_PECAS 15 //USADO PARA VETOR DE PECAS

/***********************************************************************
*
*  $FC Fun��o: TDADO &Testar dado
*
*  $ED Descri��o da fun��o
*     Cria um dado ponto
*
*     Comandos dispon�veis:
*
*     =criarpeca                         IndPeca Cor CondRetEsp
*     =destruirpeca                      IndPeca CondRetEsp
*     =obterstatus                       IndPeca CondRetEsp
*	  =atualizapeca   					 IndPeca Final Status CondRetEsp
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

PEC_tpPeca vtPecas[MAX_PECAS];

/***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int numLidos      = -1 ;
	int indPeca		  = -1 ;
	int cor           = -1 ;
	int CondRetEsp    = -1 ;
	int CondRetObtido = -1 ;
	int final         = -1 ;
	char status            ;
	PEC_tpPeca *p          ;

	/* Testar Criar */

	if( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "iii", &indPeca, &cor ,&CondRetEsp);
		if( numLidos != 3 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PEC_CriaPeca ( vtPecas, indPeca, cor ) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Retorno errado") ;


	} /* fim ativa: Testar Criar */
	
	/* Testar Destruir */
	
	else if ( strcmp( ComandoTeste , DESTRUIR_PECA_CMD ) == 0 )
	{
		numLidos = LER_LerParametros( "ii", &indPeca, &CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PEC_DestroiPeca ( vtPecas, indPeca ) ;
		p = NULL ;

		return TST_CompararInt (CondRetEsp, CondRetObtido, "Retorno errado") ;

	}  /* fim ativa: Testar */

		/* Testar Obter Status */

         else if ( strcmp( ComandoTeste , OBTER_STATUS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii", &indPeca, &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PEC_ObtemInfo( vtPecas[indPeca], &cor, &final, &status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao obter status." ) ;

         } /* fim ativa: Testar Obter Status */

		/* Testar Atualiza Peca */

         else if ( strcmp( ComandoTeste , ATUALIZAR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iici", &indPeca, &final, &status, &CondRetEsp ) ;

            if (  numLidos != 4 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PEC_AtualizaPeca( vtPecas[indPeca], final, status ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao Atualiza Peca." ) ;

         } /* fim ativa: Testar Atualiza Peca */

    return TST_CondRetNaoConhec ;
			
}  /* Fim fun��o: TPEC &Testar pe�a */

/********** Fim do m�dulo de implementa��o: TPEC Teste lista de s�mbolos **********/