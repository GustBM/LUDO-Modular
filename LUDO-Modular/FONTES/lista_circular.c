/***************************************************************************
*  $MCI M�dulo de implementa��o: LISC  Lista duplamente encadeada
*
*  Arquivo gerado:              Lista_circular.c
*  Letras identificadoras:      LISC

***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "lista_circular.h"



/***********************************************************************
*
*  $TC Tipo de dados: LISC Elemento da lista circular
*
*
***********************************************************************/

typedef struct tagElemLista {

         void * pValor ;
               /* Ponteiro para o valor contido no elemento */

         struct tagElemLista* pAnt ;
               /* Ponteiro para o elemento predecessor */

         struct tagElemLista* pProx ;
               /* Ponteiro para o elemento sucessor */

   } tpElemListaCircular;
/***********************************************************************
*
*  $TC Tipo de dados: LISC Descritor da cabe�a de lista circular
*
*
***********************************************************************/
typedef struct LISC_tagLista {

         tpElemListaCircular* pElemCorr ;
               /* Ponteiro para o elemento corrente da lista */

         int numElem ;
               /* N�mero de elementos da lista */

         void ( * ExcluirValor ) ( void * pValor ) ;
               /* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */

   } LIS_tpListaC;



 /*****  C�digo das fun��es exportadas pelo m�dulo  *****/

 /***********************************************************************
*
*  $FC Fun��o: LISC  -Limpar a cabe�a da lista circular
*
***********************************************************************/

void LimparCabeca( LISC_tppListaC pLista )
   {
      pLista->pElemCorr = NULL ;
      pLista->numElem   = 0 ;

   } /* Fim fun��o: LISC  -Limpar a cabe�a da lista circular */

/***********************************************************************
*
*  $FC Fun��o: LISC  -Liberar elemento da lista circular
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

void LiberarElemento( LISC_tppListaC  pLista , tpElemListaCircular  * pElem   )
   {

      if ( ( pLista->ExcluirValor != NULL ) && ( pElem->pValor != NULL ))
      {
         pLista->ExcluirValor( pElem->pValor ) ;
      } /* if */

      free(pElem) ;

      pLista->numElem-- ;

   } /* Fim fun��o: LISC  -Liberar elemento da lista circular */

/***************************************************************************
*
*  Fun��o: LISC  &Esvaziar lista circular
*  ****/

void LISC_EsvaziarLista( LISC_tppListaC pLista )
   {

      tpElemListaCircular * pElem ;
      tpElemListaCircular * pProx ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      pElem = pLista->pElemCorr;
      while ( pElem != NULL )
      {
         pProx = pElem->pProx ;
         LiberarElemento(pLista , pElem) ;
         pElem = pProx ;
      } /* while */

      LimparCabeca( pLista ) ;

   } /* Fim fun��o: LISC  &Esvaziar lista circular */


/***************************************************************************
*
*  Fun��o: LISC  &Criar lista circular
*  ****/

LISC_tppListaC LISC_CriarLista(void( * ExcluirValor ) ( void * pDado )){

      LIS_tpListaC * pLista = NULL ;

      pLista = ( LIS_tpListaC * ) malloc( sizeof( LIS_tpListaC )) ;
      if ( pLista == NULL )
      {
         return NULL;
      } /* if */

      LimparCabeca( pLista );

      pLista-> ExcluirValor = ExcluirValor ;

      return pLista ;

   } /* Fim fun��o: LISC  &Criar lista circular*/

/***************************************************************************
*
*  Fun��o: LISC  &Destruir lista circular
*  ****/

void LISC_DestruirLista( LISC_tppListaC pLista )
   {

      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      LISC_EsvaziarLista( pLista ) ;

      free( pLista ) ;

   } /* Fim fun��o: LISC  &Destruir lista circular */

/***********************************************************************
*
*  $FC Fun��o: LISC  -Criar o elemento
*
***********************************************************************/

tpElemListaCircular* CriarElemento( LISC_tppListaC pLista , void *	pValor ){

      tpElemListaCircular * pElem;

      pElem = ( tpElemListaCircular * ) malloc( sizeof( tpElemListaCircular )) ;
      if ( pElem == NULL )
      {
         return NULL ;
      } /* if */

      pElem->pValor = pValor;
      pElem->pAnt   = NULL;
      pElem->pProx  = NULL;

      pLista->numElem ++;

      return pElem ;

} /* Fim fun��o: LISC  -Criar o elemento */

/***************************************************************************
*
*  Fun��o: LISC  &Obter refer�ncia para o valor contido no elemento
*  ****/

 LISC_tpCondRet  LISC_ObterValor( LISC_tppListaC pLista, void * val )
   {

      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      if ( pLista->pElemCorr == NULL )
      {
        return 	LISC_CondRetListaVazia;
      } /* if */

      val = pLista->pElemCorr->pValor ;
      return LISC_CondRetOK ;

   } /* Fim fun��o: LISC  &Obter refer�ncia para o valor contido no elemento */

/***************************************************************************
*
*  Fun��o: LISC  &Procurar elemento na lista circular contendo valor dado
*  ****/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppListaC pLista , void * pValor )
   {

      tpElemListaCircular * pElem ;

	  int n = pLista->numElem;
	  int i;

     // #ifdef _DEBUG
         assert( pLista  != NULL ) ;
     // #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LISC_CondRetListaVazia ;
      } /* if */

      for (i=0,pElem  = pLista->pElemCorr ;i < n; pElem  = pElem->pProx, i++)
      {
         if ( pElem->pValor == pValor )
         {
            pLista->pElemCorr = pElem ;
            return LISC_CondRetOK ;
         } /* if */
      } /* for */

      return LISC_CondRetNaoAchou ;

   } /* Fim fun��o: LIS  &Procurar elemento contendo valor */

   /***************************************************************************
*
*  Fun��o: LISC  &Inserir elemento antes
*  ****/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppListaC pLista ,void * pValor){

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inerir antes */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LISC_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento antes do elemento corrente */

         if ( pLista->pElemCorr == NULL )
         {
            pLista->pElemCorr = pElem ;
         } else
         {
            if ( pLista->pElemCorr->pAnt != NULL )
            {
               pElem->pAnt  = pLista->pElemCorr->pAnt ;
               pLista->pElemCorr->pAnt->pProx = pElem ;
            }

            pElem->pProx = pLista->pElemCorr ;
            pLista->pElemCorr->pAnt = pElem ;
         } /* if */

         pLista->pElemCorr = pElem ;

         return LISC_CondRetOK ;

   } /* Fim fun��o: LISC  &Inserir elemento antes */
   
   /***************************************************************************
*
*  Fun��o: LISC  &Inserir elemento ap�s
*  ****/

   LISC_tpCondRet LISC_InserirElementoApos( LISC_tppListaC pLista ,
                                          void * pValor        )
      
   {

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inerir ap�s */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LISC_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento ap�s o elemento */

         if ( pLista->pElemCorr == NULL )
         {
            pLista->pElemCorr = pElem ;
            
         } else
         {
            if ( pLista->pElemCorr->pProx != NULL )
            {
               pElem->pProx  = pLista->pElemCorr->pProx ;
               pLista->pElemCorr->pProx->pAnt = pElem ;
            }

            pElem->pAnt = pLista->pElemCorr ;
            pLista->pElemCorr->pProx = pElem ;

         } /* if */
                  
         pLista->pElemCorr = pElem ;
                  
         return LISC_CondRetOK;

   } /* Fim fun��o: LISC  &Inserir elemento ap�s */
   
   /***************************************************************************
*
*  Fun��o: LISC  &Excluir elemento
*  ****/

   LISC_tpCondRet LISC_ExcluirElemento( LISC_tppListaC pLista )
   {

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista  != NULL ) ;
     // #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LISC_CondRetListaVazia ;
      } /* if */

      pElem = pLista->pElemCorr ;

      /* Desencadeia � esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } 

      /* Desencadeia � direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
         }

      LiberarElemento( pLista , pElem ) ;

      return LISC_CondRetOK ;

   } /* Fim fun��o: LISC  &Excluir elemento */
   
   /***************************************************************************
 *
 *  Funcao: LISC  &Avancar Elemento Corrente
 *  ****/

LISC_tpCondRet LISC_AvancarElementoCorrente ( LISC_tppListaC pLista , int num ){
    tpElemListaCircular *pElem;
    
    if( pLista->pElemCorr == NULL )
    {
        return LISC_CondRetListaVazia ;
    }
    
    pElem = pLista->pElemCorr ;
    if ( num > 0 )
    {
        while( num )
        {
            pElem = pElem-> pProx;
            num-- ;
        }
    }
    else if ( num < 0 )
    {
        while( num )
        {
            pElem = pElem-> pAnt;
            num++ ;
        }
    }
    
    pLista->pElemCorr = pElem ;
    return LISC_CondRetOK ;
    
}

/* Fim Funcao: LISC  &Avancar Elemento Corrente */
   
   
   
