/***************************************************************************
*  $MCI M�dulo de implementa��o: Modulo peca
*
*  Arquivo gerado:              peca.c
*  Letras identificadoras:      PECA
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "peca.h"

#define MAX_PECAS 16

typedef struct Peca {

	int cor ;
	    /* Cor definida entre 0 e 3 */

	int final;
	    /* Se a pe�a est� na reta final do jogo: Final = 1, caso contr�rio: Final = 0 */

	char status ;
        /* Se a pe�a est� dentro do jogo, status = 'D', caso esteja fora de jogo, status = 'F' */

} PECA;


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Funcao: PEC  &Cria Peca
*  ****/

PECA_CondRet PECA_CriaPeca ( PECA** peca, int i, int cor ) 
{

	assert((cor >= 0) && (cor <= 3));

	assert((i >= 0) && (i <= 15)); 

	if(peca[i] != NULL)
	{
		return PECA_CondRetExiste;
	}
	

	peca[i] = ( PECA * ) malloc ( sizeof ( PECA ) ) ;

	if ( peca[i] == NULL ) 
	{
		return PECA_CondRetFaltaMemoria ;
	}

	peca[i]->cor    = cor ;
	peca[i]->final  = 0   ;
	peca[i]->status = 'F' ;

	return PECA_CondRetOK ;

}

/***************************************************************************
*
*  Funcao: PEC  &Destroi Peca
*  ****/

PECA_CondRet PECA_DestroiPeca ( PECA *peca )
{
	if ( peca == NULL )
		return PECA_CondRetNaoExiste ;
	
	free( peca );
	

	return PECA_CondRetOK ;

} 

/***************************************************************************
*
*  Funcao: PEC  &Obtem cor da peca
*  ****/

PECA_CondRet PECA_ObtemCor ( PECA * peca , int* cor )
{
	if(peca == NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	*cor = peca->cor;

	return PECA_CondRetOK ;

}

/***************************************************************************
*
*  Funcao: PEC  &Obtem indicacao de final
*  ****/

PECA_CondRet PECA_ObtemFim ( PECA* peca , int* final )
{
	if(peca == NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	*final = peca->final  ;

	return PECA_CondRetOK ;

} 

/***************************************************************************
*
*  Funcao: PEC  &Obtem status da peca
*  ****/

PECA_CondRet PECA_ObtemStatus ( PECA* peca , char* status)
{
	if(peca == NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	*status = peca->status ;

	return PECA_CondRetOK ;

} 

/***************************************************************************
*
*  Funcao: PEC  &Obtem todas as informacoes de uma peca
*  ****/

PECA_CondRet PECA_ObtemInfo( PECA* peca, int* cor, int* final, char* status )
{
	if(peca == NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	PECA_ObtemCor ( peca , cor );
	PECA_ObtemFim ( peca , final );
	PECA_ObtemStatus ( peca , status);

	return PECA_CondRetOK;

}

/***************************************************************************
*
*  Funcao: PEC  &Atualiza todas as informacoes de uma peca
*  ****/


PECA_CondRet PECA_AtualizaPeca ( PECA* peca , int final, char status ) 
{

	assert(final == 0 || final == 1 || final == -1);

	assert(status == 'D' || status == 'F' || status == 'X');

	if(peca == NULL)
	{
		return PECA_CondRetNaoExiste;
	}
	if(final != -1)
		peca->final = final ;
	if(status != 'X')
		peca->status = status ;

	return PECA_CondRetOK ;

}