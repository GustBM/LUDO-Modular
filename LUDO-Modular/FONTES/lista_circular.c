/***************************************************************************
*  $MCI Modulo de implementacao: LISC  Lista duplamente encadeada
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
*  $TC Tipo de dados: LISC Descritor da cabeca de lista circular
*
*
***********************************************************************/
typedef struct LISC_tagLista {

         tpElemListaCircular* pElemCorr ;
               /* Ponteiro para o elemento corrente da lista */

         int numElem ;
               /* Numero de elementos da lista */

         void ( * ExcluirValor ) ( void * pValor ) ;
               /* Ponteiro para a funcao de destruicao do valor contido em um elemento */
         int(*CompararValor) (void * pValor1, void * pValor2);
               /* Ponteiro para a funcao de comparacao dos valores contidos em dois elementos */

   } LIS_tpListaC;



 /*****  Codigo das funcoes exportadas pelo modulo  *****/

 /***********************************************************************
*
*  $FC Funcao: LISC  -Limpar a cabeca da lista circular
*
***********************************************************************/

void LimparCabeca( LISC_tppListaC pLista )
   {
      pLista->pElemCorr = NULL ;
      pLista->numElem   = 0 ;

   } /* Fim funcao: LISC  -Limpar a cabeca da lista circular */

/***********************************************************************
*
*  $FC Funcao: LISC  -Liberar elemento da lista circular
*
*  $ED Descricao da funcao
*     Elimina os espacos apontados pelo valor do elemento e o
*     proprio elemento.
*
***********************************************************************/

void LiberarElemento( LISC_tppListaC  pLista , tpElemListaCircular  * pElem   )
   {

      if ( ( pLista->ExcluirValor != NULL ) && ( pElem->pValor != NULL ))
      {
         
         pLista->ExcluirValor( pElem->pValor ) ;
      } /* if */

      free(pElem);

      pLista->numElem--;

   } /* Fim funcao: LISC  -Liberar elemento da lista circular */

/***************************************************************************
*
*  Funcao: LISC  &Esvaziar lista circular
*  ****/

LISC_tpCondRet LISC_EsvaziarLista( LISC_tppListaC pLista )
   {

      tpElemListaCircular * pElem ;
      tpElemListaCircular * pProx ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      if( pLista->pElemCorr == NULL){
         assert(pLista ->numElem == 0);
         return LISC_CondRetListaVazia;
      }

      
      if(pLista ->numElem > 1){
         pElem = pLista->pElemCorr->pProx;

         do
      {
         
         pProx = pElem->pProx ;
         LiberarElemento(pLista , pElem) ;

         pElem = pProx ;
      }  while ( pElem != pLista->pElemCorr );/* while */

      }
      else{
         pElem = pLista->pElemCorr;
      }
      

      
      LiberarElemento(pLista , pElem);
      
      LimparCabeca( pLista );

   return LISC_CondRetOK;
   } /* Fim funcao: LISC  &Esvaziar lista circular */


/***************************************************************************
*
*  Funcao: LISC  &Criar lista circular
*  ****/

LISC_tppListaC LISC_CriarLista(void( * ExcluirValor ) ( void * pDado ),
int(*CompararValor) (void * pValor1, void * pValor2)){

      LIS_tpListaC * pLista = NULL ;

      pLista = ( LIS_tpListaC * ) malloc( sizeof( LIS_tpListaC )) ;
      if ( pLista == NULL )
      {
         return NULL;
      } /* if */

      LimparCabeca( pLista );

      pLista-> ExcluirValor = ExcluirValor ;

      pLista-> CompararValor = CompararValor;

      return pLista ;

   } /* Fim funcao: LISC  &Criar lista circular */

/***************************************************************************
*
*  Funcao: LISC  &Destruir lista circular
*  ****/

void LISC_DestruirLista( LISC_tppListaC pLista )
   {
      int cond;
      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      cond = LISC_EsvaziarLista( pLista ) ;

      free( pLista ) ;

   } /* Fim funcao: LISC  &Destruir lista circular */

/***********************************************************************
*
*  $FC Funcao: LISC  -Criar o elemento
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

      (pLista->numElem) += 1;

      return pElem ;

} /* Fim funcao: LISC  -Criar o elemento */

/***************************************************************************
*
*  Funcao: LISC  &Obter referencia para o valor contido no elemento
*  ****/

 LISC_tpCondRet  LISC_ObterValor( LISC_tppListaC pLista, void ** val )
   {

      //#ifdef _DEBUG
         assert( pLista != NULL ) ;
      //#endif

      if ( pLista->pElemCorr == NULL )
      {
        return 	LISC_CondRetListaVazia;
      } /* if */

      *val = pLista->pElemCorr->pValor;
      return LISC_CondRetOK ;

   } /* Fim funcao: LISC  &Obter referencia para o valor contido no elemento */

/***************************************************************************
*
*  Funcao: LISC  &Procurar elemento na lista circular contendo valor dado
*  ****/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppListaC pLista , void * pValor )
   {

      tpElemListaCircular * pElem ;

	  int n = pLista->numElem;
	  int i;
      int comp;
     // #ifdef _DEBUG
         assert( pLista  != NULL ) ;
     // #endif

      if ( pLista->pElemCorr == NULL)
      {
         assert(pLista ->numElem == 0);
         return LISC_CondRetListaVazia ;
      } /* if */
      
      for (i=0,pElem  = pLista->pElemCorr ;i < n; pElem  = pElem->pProx, i++)
      {
         printf("corrente: %s   ",pElem->pValor );
         comp = (pLista->CompararValor(pElem->pValor,pValor));
         printf("comp = %d\t", comp);
         if(((pLista->CompararValor) != NULL) && ((pElem->pValor) != NULL) && (pValor != NULL)){
            if (comp == 0)
            {
               pLista->pElemCorr = pElem;
               return LISC_CondRetOK ;
            } /* if */
         }/* if */
      } /* for */

      return LISC_CondRetNaoAchou ;

   } /* Fim funcao: LIS  &Procurar elemento contendo valor */

   /***************************************************************************
*
*  Funcao: LISC  &Inserir elemento antes
*  ****/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppListaC pLista ,void * pValor){

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inserir antes */

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

            if(pLista->pElemCorr->pProx == NULL){
               pElem->pAnt = pLista->pElemCorr ;
               pLista->pElemCorr->pProx = pElem ;
            }
         } /* if */

         pLista->pElemCorr = pElem ;

         return LISC_CondRetOK ;

   } /* Fim funcao: LISC  &Inserir elemento antes */
   
   /***************************************************************************
*
*  Funcao: LISC  &Inserir elemento apos
*  ****/

   LISC_tpCondRet LISC_InserirElementoApos( LISC_tppListaC pLista ,
                                          void * pValor        )
      
   {

      tpElemListaCircular * pElem ;

     // #ifdef _DEBUG
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inerir apos */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LISC_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento apos o elemento */

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

            if(pLista->pElemCorr->pAnt == NULL){
               pElem->pProx = pLista->pElemCorr ;
                pLista->pElemCorr->pAnt = pElem ;
            }

         } /* if */
                  
         pLista->pElemCorr = pElem ;
                  
         return LISC_CondRetOK;

   } /* Fim funcao: LISC  &Inserir elemento apos */
   
   /***************************************************************************
*
*  Funcao: LISC  &Excluir elemento
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

      /* Desencadeia a esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } 

      /* Desencadeia a direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
            pLista->pElemCorr    = pElem->pProx;
         }

      LiberarElemento( pLista , pElem ) ;

      return LISC_CondRetOK ;

   } /* Fim funcao: LISC  &Excluir elemento */
   
   /***************************************************************************
 *
 *  Funcao: LISC  &Avancar Elemento Corrente
 *  ****/

LISC_tpCondRet LISC_AvancarElementoCorrente( LISC_tppListaC pLista , int num ){
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
   
   
   
