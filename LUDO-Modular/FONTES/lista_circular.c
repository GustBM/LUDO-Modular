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
#include "Conta.h"
#include "cespdin.h"



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
      CNT_CONTAR( "LISC_LimparCabeca" ) ;
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
      CNT_CONTAR( "LISC_LiberarElemento" ) ;

      if ( ( pLista->ExcluirValor != NULL ) && ( pElem->pValor != NULL ))
      {
         CNT_CONTAR( "LISC_LiberarElemento_FuncoesCorretas" ) ;
         pLista->ExcluirValor( pElem->pValor ) ;
      } /* if */
      CNT_CONTAR( "LISC_LiberarElemento_LiberarElemento" ) ;

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
         CNT_CONTAR( "LISC_EsvaziarLista" ) ;
         assert( pLista != NULL ) ;
     // #endif

      if( pLista->pElemCorr == NULL){
         assert(pLista ->numElem == 0);
         CNT_CONTAR( "LISC_EsvaziarLista_ListaVazia" ) ;
         return LISC_CondRetListaVazia;
      }
      CNT_CONTAR( "LISC_EsvaziarLista_ListaNaoVazia" ) ;
      
      if(pLista ->numElem > 1){
         CNT_CONTAR( "LISC_EsvaziarLista_+1Elem" ) ;
         pElem = pLista->pElemCorr->pProx;

         do
      {
         CNT_CONTAR( "LISC_EsvaziarLista_while_Libera+1Elem" ) ;
         pProx = pElem->pProx ;
         LiberarElemento(pLista , pElem) ;

         pElem = pProx ;
      }  while ( pElem != pLista->pElemCorr );/* while */

      CNT_CONTAR( "LISC_EsvaziarLista_fim_while_Libera+1Elem" ) ;
      }
      else{
         CNT_CONTAR( "LISC_EsvaziarLista_1Elem" ) ;
         pElem = pLista->pElemCorr;
      }
      
      CNT_CONTAR( "LISC_EsvaziarLista_LiberaUltimo" ) ;
      
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

      CNT_CONTAR( "LISC_CriarLista" ) ;

      pLista = ( LIS_tpListaC * ) malloc( sizeof( LIS_tpListaC )) ;
      if ( pLista == NULL )
      {
         CNT_CONTAR( "LISC_CriarLista_FaltouMemoria" ) ;
         return NULL;
      } /* if */
      CNT_CONTAR( "LISC_CriarLista_NaoFaltouMemoria" ) ;

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
         CNT_CONTAR( "LISC_DestruirLista" ) ;
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

      CNT_CONTAR( "LISC_CriarElemento" ) ;

      pElem = ( tpElemListaCircular * ) malloc( sizeof( tpElemListaCircular )) ;
      if ( pElem == NULL )
      {
         CNT_CONTAR( "LISC_CriarElemento_FaltouMemoria" ) ;
         return NULL ;
      } /* if */

      CNT_CONTAR( "LISC_CriarElemento_NaoFaltouMemoria" ) ;

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
         CNT_CONTAR( "LISC_ObterValor" ) ;
         assert( pLista != NULL ) ;
      //#endif

      if ( pLista->pElemCorr == NULL )
      {
        CNT_CONTAR( "LISC_ObterValor_ListaVazia" ) ; 
        return 	LISC_CondRetListaVazia;
      } /* if */
      CNT_CONTAR( "LISC_ObterValor_OK" ) ;

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
         CNT_CONTAR( "LISC_ProcurarValor" ) ;
         assert( pLista  != NULL ) ;
     // #endif

      if ( pLista->pElemCorr == NULL)
      {
         assert(pLista ->numElem == 0);
         CNT_CONTAR( "LISC_ProcurarValor_ListaVazia" ) ;
         return LISC_CondRetListaVazia ;
      } /* if */
      
      CNT_CONTAR( "LISC_ProcurarValor_ListaNaoVazia" ) ;
      for (i=0,pElem  = pLista->pElemCorr ;i < n; pElem  = pElem->pProx, i++)
      {
         CNT_CONTAR( "LISC_ProcurarValor_for_Ini" ) ;
         comp = (pLista->CompararValor(pElem->pValor,pValor));
         
         if(((pLista->CompararValor) != NULL) && ((pElem->pValor) != NULL) && (pValor != NULL))
         {
            CNT_CONTAR( "LISC_ProcurarValor_for_FuncoesValidas" ) ;
            if (comp == 0)
            {
               CNT_CONTAR( "LISC_ProcurarValor_for_ValoresIguais" ) ;
               pLista->pElemCorr = pElem;
               return LISC_CondRetOK ;
            } /* if */ CNT_CONTAR( "LISC_ProcurarValor_for_ValoresDiferentes" ) ;
         }/* if */ CNT_CONTAR( "LISC_ProcurarValor_for_FuncoesInvalidas" ) ;
      } /* for */
      CNT_CONTAR( "LISC_ProcurarValor_NaoAchou" ) ;
      return LISC_CondRetNaoAchou ;

   } /* Fim funcao: LIS  &Procurar elemento contendo valor */

   /***************************************************************************
*
*  Funcao: LISC  &Inserir elemento antes
*  ****/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppListaC pLista ,void * pValor){

      tpElemListaCircular * pElem ;

      

     // #ifdef _DEBUG
         CNT_CONTAR( "LISC_InserirElementoAntes" ) ;
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inserir antes */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            CNT_CONTAR( "LISC_InserirElementoAntes_FaltouMemoria" ) ;
            return LISC_CondRetFaltouMemoria ;
         } /* if */
         CNT_CONTAR( "LISC_InserirElementoAntes_NaoFaltouMemoria" ) ;

      /* Encadear o elemento antes do elemento corrente */

         if ( pLista->pElemCorr == NULL )
         {
            CNT_CONTAR( "LISC_InserirElementoAntes_InsereListaVazia" ) ;
            pLista->pElemCorr = pElem ;
         } else
         {
            CNT_CONTAR( "LISC_InserirElementoAntes_InsereListaOcupada" ) ;
            if ( pLista->pElemCorr->pAnt != NULL )
            {
               CNT_CONTAR( "LISC_InserirElementoAntes_AnteriorNaoNulo" ) ;
               pElem->pAnt  = pLista->pElemCorr->pAnt ;
               pLista->pElemCorr->pAnt->pProx = pElem ;
            }
            CNT_CONTAR( "LISC_InserirElementoAntes_Anterior" ) ;

            pElem->pProx = pLista->pElemCorr ;
            pLista->pElemCorr->pAnt = pElem ;

            if(pLista->pElemCorr->pProx == NULL){
               CNT_CONTAR( "LISC_InserirElementoAntes_ProximoNulo" ) ;
               pElem->pAnt = pLista->pElemCorr ;
               pLista->pElemCorr->pProx = pElem ;
            }
         } /* if */
         CNT_CONTAR( "LISC_InserirElementoAntes_OK" ) ;

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
         CNT_CONTAR( "LISC_InserirElementoApos" ) ;
         assert( pLista != NULL ) ;
     // #endif

      /* Criar elemento a inerir apos */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            CNT_CONTAR( "LISC_InserirElementoApos_FaltouMemoria" ) ;
            return LISC_CondRetFaltouMemoria ;
         } /* if */

         CNT_CONTAR( "LISC_InserirElementoApos_NaoFaltouMemoria" ) ;

      /* Encadear o elemento apos o elemento */

         if ( pLista->pElemCorr == NULL )
         {
            CNT_CONTAR( "LISC_InserirElementoApos_InsereListaVazia" ) ;
            pLista->pElemCorr = pElem ;
            
         } else
         {
            CNT_CONTAR( "LISC_InserirElementoApos_InsereListaOcupada" ) ;
            if ( pLista->pElemCorr->pProx != NULL )
            {
               CNT_CONTAR( "LISC_InserirElementoApos_ProximoNaoNulo" ) ;
               pElem->pProx  = pLista->pElemCorr->pProx ;
               pLista->pElemCorr->pProx->pAnt = pElem ;
            }

            CNT_CONTAR( "LISC_InserirElementoApos_Proximo" ) ;

            pElem->pAnt = pLista->pElemCorr ;
            pLista->pElemCorr->pProx = pElem ;

            if(pLista->pElemCorr->pAnt == NULL){
               CNT_CONTAR( "LISC_InserirElementoApos_AnteriorNulo" ) ;
               pElem->pProx = pLista->pElemCorr ;
                pLista->pElemCorr->pAnt = pElem ;
            }

         } /* if */
         CNT_CONTAR( "LISC_InserirElementoApos_OK" ) ;
                  
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
         CNT_CONTAR( "LISC_ExcluirElemento" ) ;
         assert( pLista  != NULL ) ;
     // #endif

      if ( pLista->pElemCorr == NULL )
      {
         CNT_CONTAR( "LISC_ExcluirElemento_ListaVazia" ) ;
         return LISC_CondRetListaVazia ;
      } /* if */

      CNT_CONTAR( "LISC_ExcluirElemento_DesencadeiaEsq" ) ;

      pElem = pLista->pElemCorr ;

      /* Desencadeia a esquerda */

         if ( pElem->pAnt != NULL )
         {
            CNT_CONTAR( "LISC_ExcluirElemento_AnteriorNaoNulo" ) ;
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         }

         CNT_CONTAR( "LISC_ExcluirElemento_DesencadeiaDir" ) ; 

      /* Desencadeia a direita */

         if ( pElem->pProx != NULL )
         {
            CNT_CONTAR( "LISC_ExcluirElemento_ProximoNaoNulo" ) ;
            pElem->pProx->pAnt = pElem->pAnt ;
            pLista->pElemCorr    = pElem->pProx;
         }

         CNT_CONTAR( "LISC_ExcluirElemento_LiberarElemento" ) ;

      LiberarElemento( pLista , pElem ) ;

      return LISC_CondRetOK ;

   } /* Fim funcao: LISC  &Excluir elemento */
   
   /***************************************************************************
 *
 *  Funcao: LISC  &Avancar Elemento Corrente
 *  ****/

LISC_tpCondRet LISC_AvancarElementoCorrente( LISC_tppListaC pLista , int num ){
    tpElemListaCircular *pElem;

    CNT_CONTAR( "LISC_AvancarElementoCorrente" ) ;
    
    if( pLista->pElemCorr == NULL )
    {
      CNT_CONTAR( "LISC_AvancarElementoCorrente_ListaVazia" ) ;
      return LISC_CondRetListaVazia ;
    }
     CNT_CONTAR( "LISC_AvancarElementoCorrente_ListaNaoVazia" ) ;
    
    pElem = pLista->pElemCorr ;
    if ( num > 0 )
    {
      CNT_CONTAR( "LISC_AvancarElementoCorrente_num>0" ) ;
      while( num )
      {
         CNT_CONTAR( "LISC_AvancarElementoCorrente_while_num>0" ) ;
         pElem = pElem-> pProx;
         num-- ;
      }
      CNT_CONTAR( "LISC_AvancarElementoCorrente_num0+" ) ;
    }
    else if ( num < 0 )
    {
      CNT_CONTAR( "LISC_AvancarElementoCorrente_num<0" ) ; 
      while( num )
      {
         CNT_CONTAR( "LISC_AvancarElementoCorrente_while_num<0" ) ; 
         pElem = pElem-> pAnt;
         num++ ;
      }
      CNT_CONTAR( "LISC_AvancarElementoCorrente_num0-" ) ; 
    }
    
   CNT_CONTAR( "LISC_AvancarElementoCorrente_OK" ) ; 

   pLista->pElemCorr = pElem ;
   return LISC_CondRetOK ;
    
}

/* Fim Funcao: LISC  &Avancar Elemento Corrente */
   
   
   
