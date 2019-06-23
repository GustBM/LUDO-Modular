/***************************************************************************
*  $MCI M�dulo de implementa��o: TestePartida
*
*  Arquivo gerado:              TestePartida.c
*  Letras identificadoras:      TPARTIDA
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros

***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include	"lista_circular.h"
#include	"tabuleiro.h"
#include    "partida.h"

// static const char RESET_TAB_CMD         [ ] = "=resetteste"       ;
static const char CRIAR_PARTIDA        [ ] = "=criarpartida"    ;
static const char REALIZA_JOGADA       [ ] = "=realizajogada"   ;
static const char VERIFICA_VENCEDOR    [ ] = "=verificavencedor";

PAR_tppPartida vttPartida;

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ) {

    int numLidos      = -1 ;
	int Partida		  = -1 ;
	int cor           = -1 ;
    int numJog        = -1 ;
	int CondRetEsp    = -1 ;
	int CondRetObtido = -1 ;
	int venc          = -1 ;

    /* Testar CriarPartida */
    if ( strcmp( ComandoTeste , CRIAR_PARTIDA ) == 0 )
	{
		numLidos = LER_LerParametros( "iii", &Partida, &numJog, &cor);
		if( numLidos != 3 )
		{
			return TST_CondRetParm;
		}

		CondRetObtido = PAR_InicializaJogo ( Partida, numJog, cor ) ;

		return TST_CompararInt ( CondRetEsp, CondRetObtido, "Erro ao inicializar jogo") ;

	}

    /*Teste Realiza Jogada */

    else if ( strcmp( ComandoTeste , REALIZA_JOGADA ) == 0 )
	{
		numLidos = LER_LerParametros( "ii", &Partida, &cor ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		}

		CondRetObtido = PAR_RealizaJogada ( Partida, cor ) ;

		return TST_CompararInt (CondRetEsp, CondRetObtido, "Erro a Realizar a jogada") ;

	}

    /* Testar Verifica Vencedor */

    else if ( strcmp( ComandoTeste , VERIFICA_VENCEDOR ) == 0 )
    {

    numLidos = LER_LerParametros( "ii", &Partida ,&venc ) ;

    if ( numLidos != 2 )
    {
        return TST_CondRetParm ;
    }


    CondRetObtido = PAR_VerificaVencedor( Partida, venc ) ;
    
    return TST_CompararInt( CondRetEsp , CondRetObtido ,
                "Condicao de retorno ao verificar vencedor." ) ;

    }
}