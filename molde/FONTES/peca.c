/***************************************************************************
*  $MCI Módulo de implementação: PEC Módulo Peças
*
*  Arquivo gerado:              peca.c
*  Letras identificadoras:      PEC
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "peca.h"
#define PECAS_OWN
#undef PECAS_OWN


typedef struct Peca {

	int cor ;
	    /* Cor definida entre 0 e 3 */

	int final;
	    /* Se a peça está na reta final do jogo (1) ou não (0) */

	char status ;
        /* Se a peça está dentro do jogo 'D' ou fora de jogo 'F' */

} PECA;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PEC  &Criar Peca
*  ****/

PECA_CondRet PECA_CriaPeca ( PECA ** pPeca, int ind, int cor ) 
{
	if ( cor < 0 || cor > 3 )
	{
		return PECA_CondRetCorInvalida ;
	}

	if(pPeca[ind]!=NULL)
	{
		return PECA_CondRetExiste;
	}

	pPeca[ind] = ( PECA * ) malloc ( sizeof ( PECA ) ) ;

	if ( pPeca[ind] == NULL ) 
	{
		return PECA_CondRetFaltaMemoria ;
	}

	

	pPeca[ind]->cor    = cor ;
	pPeca[ind]->final  = 0   ;
	pPeca[ind]->status = 'F' ;

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Criar Peca */

/***************************************************************************
*
*  Função: PEC  &Destroi Peca
*  ****/

PECA_CondRet PECA_DestroiPeca ( PECA *pPeca )
{
	if ( pPeca == NULL )
		return PECA_CondRetNaoExiste ;
	
	free( pPeca );

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Destroi Peca */


/***************************************************************************
*
*  Função: PEC  &Obtem cor
*  ****/

PECA_CondRet PECA_ObtemCor ( PECA * pPeca , int * cor )
{
	if(pPeca==NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	* cor    = pPeca->cor    ;

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Obtem cor */


/***************************************************************************
*
*  Função: PEC  &Obtem final
*  ****/

PECA_CondRet PECA_ObtemFim ( PECA * pPeca , int * final )
{
	if(pPeca==NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	* final  = pPeca->final  ;

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Obtem final */


/***************************************************************************
*
*  Função: PEC  &Obtem status
*  ****/

PECA_CondRet PECA_ObtemStatus ( PECA * pPeca , char * status)
{
	if(pPeca==NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	* status = pPeca->status ;

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Obtem status */


/***************************************************************************
*
*  Função: PEC  &Atualiza Peca
*  ****/

PECA_CondRet PECA_AtualizaPeca ( PECA * pPeca , int final, char status ) 
{

	if(pPeca==NULL)
	{
		return PECA_CondRetNaoExiste;
	}

	if ( final < 0 || final > 1 )
	{
		return PECA_CondRetFimErrado ;
	}

	if ( status == 'D' || status == 'F' )
	{
		pPeca->final = final ;
		pPeca->status = status ;
	}
	else
	{
		return PECA_CondRetStatusErrado ;
	}

	return PECA_CondRetOK ;

} /* Fim função: PEC  &Atualiza Peca */

/********** Fim do módulo de implementação: PEC Módulo PECAS **********/