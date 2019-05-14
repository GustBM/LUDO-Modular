/***************************************************************************
*  $MCI Módulo de implementação: LISC  Lista duplamente encadeada
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
*  $TC Tipo de dados: LISC Descritor da cabeça de lista circular
*
*
***********************************************************************/
typedef struct LISC_tagLista {

         tpElemListaCircular* pElemCorr ;
               /* Ponteiro para o elemento corrente da lista */

         int numElem ;
               /* Número de elementos da lista */

         void ( * ExcluirValor ) ( void * pValor ) ;
               /* Ponteiro para a função de destruição do valor contido em um elemento */

   } LIS_tpListaC;



 /*****  Código das funções exportadas pelo módulo  *****/

 /***********************************************************************
*
*  $FC Função: LISC  -Limpar a cabeça da lista circular
*
***********************************************************************/

void LimparCabeca( LISC_tppListaC pLista )
   {
      pLista->pElemCorr = NULL ;
      pLista->numElem   = 0 ;

   } /* Fim função: LISC  -Limpar a cabeça da lista circular */

/***********************************************************************
*
*  $FC Função: LISC  -Liberar elemento da lista circular
*
*  $ED Descrição da função
*     Elimina os espaços apontados pelo valor do elemento e o
*     próprio elemento.
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

   } /* Fim função: LISC  -Liberar elemento da lista circular */

/***************************************************************************
*
*  Função: LISC  &Esvaziar lista circular
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

   } /* Fim função: LISC  &Esvaziar lista circular */


/***************************************************************************
*
*  Função: LISC  &Criar lista circular
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

   } /* Fim função: LISC  &Criar lista circular*/

/***************************************************************************
*
*  Função: LISC  &Destruir lista circular
*  ****/

void LISC_DestruirLista( LISC_tppListaC pLista )
   {

      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      LISC_EsvaziarLista( pLista ) ;

      free( pLista ) ;

   } /* Fim função: LISC  &Destruir lista circular */

/***********************************************************************
*
*  $FC Função: LISC  -Criar o elemento
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

} /* Fim função: LISC  -Criar o elemento */

/***************************************************************************
*
*  Função: LISC  &Obter referência para o valor contido no elemento
*  ****/

   void * LISC_ObterValor( LISC_tppListaC pLista )
   {

      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      if ( pLista->pElemCorr == NULL )
      {
        return NULL ;
      } /* if */

      return pLista->pElemCorr->pValor ;

   } /* Fim função: LISC  &Obter referência para o valor contido no elemento */

/***************************************************************************
*
*  Função: LISC  &Procurar elemento na lista circular contendo valor dado
*  ****/

   LISC_tpCondRet LIS_ProcurarValor( LISC_tppListaC pLista , void * pValor        ) //MUDANCA PARA LISTA CIRCULAR
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

   } /* Fim função: LIS  &Procurar elemento contendo valor */

   /***************************************************************************
*
*  Função: LISC  &Inserir elemento antes
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

   } /* Fim função: LISC  &Inserir elemento antes */
   
   /***************************************************************************
*
*  Função: LISC  &Inserir elemento após
*  ****/

   LISC_tpCondRet LIS_InserirElementoApos( LISC_tppListaC pLista ,
                                          void * pValor        )
      
   {

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inerir após */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LISC_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento após o elemento */

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

   } /* Fim função: LISC  &Inserir elemento após */
   
   /***************************************************************************
*
*  Função: LISC  &Excluir elemento
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

      /* Desencadeia à esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } 

      /* Desencadeia à direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
         }

      LiberarElemento( pLista , pElem ) ;

      return LISC_CondRetOK ;

   } /* Fim função: LISC  &Excluir elemento */
   
   /***************************************************************************
 *
 *  Funcao: LISC  &Avancar Elemento Corrente
 *  ****/

LISC_tpCondRet LISC_AvancarElementoCorrente ( LISC_tppCircularC *pLista , int num )
{
    tpElemListaCircular *pElem ;
    
    if( pLista->pElemCorr == NULL )
    {
        return LISC_CondRetVazia ;
    }
    
    pElem = pLista->pElemCorr ;
    if ( num > 0 )
    {
        while( num )
        {
            pElem = pElem->prox ;
            num-- ;
        }
    }
    else if ( num < 0 )
    {
        while( num )
        {
            pElem = pElem->ant ;
            num++ ;
        }
    }
    
    pLista->pElemCorr = pElem ;
    return LISC_CondRetOK ;
    
}

/* Fim Funcao: LISC  &Avancar Elemento Corrente */
   
   
   
