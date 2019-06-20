#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.h"
#include    "GENERICO.h"
#include    "LERPARM.h"

#include    "lista_circular.h"
#include    "CESPDIN.H"

static const char RESET_LISTAC_CMD         [ ] = "=resetteste"      ;
static const char CRIAR_LISTAC_CMD         [ ] = "=criarlista"      ;
static const char DESTRUIR_LISTAC_CMD      [ ] = "=destruirlista"   ;
static const char ESVAZIAR_LISTAC_CMD      [ ] = "=esvaziarlista"   ;
static const char INS_ELEM_ANTESC_CMD      [ ] = "=inselemantes"    ;
static const char INS_ELEM_APOSC_CMD       [ ] = "=inselemapos"     ;
static const char OBTER_VALORC_CMD         [ ] = "=obtervalorelem"  ;
static const char PROCURA_VALORC_CMD	    [ ] = "=procuravalorelem";	
static const char EXC_ELEMC_CMD            [ ] = "=excluirelem"     ;
static const char AVANCAR_ELEMC_CMD		    [ ] = "=avancarelem"     ;

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   8
#define DIM_VALOR     100

LISC_tppListaC   vtListas[ DIM_VT_LISTA ] ;

/***** Prototipos das funcoes encapuladas no modulo *****/

   static void DestruirValor( void * pValor ) ;

   static int CompararValor( void * pValor1 , void * pValor2);

   static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  Codigo das funcoes exportadas pelo modulo  *****/


/***********************************************************************
*
*  $FC Funcao: TLISC &Testar lista circular
*
*  $ED Descricao da funcao
*     Podem ser criadas ate 10 listas circulares, identificadas pelos indices 0 a 10
*
*     Comandos disponiveis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de memoria
*     =criarlista                   inxLista
*     =destruirlista                inxLista
*     =esvaziarlista                inxLista
*     =inselemantes                 inxLista  string  CondRetEsp
*     =inselemapos                  inxLista  string  CondRetEsp
*     =obtervalorelem               inxLista  string  CondRetEsp
*     =excluirelem                  inxLista  CondRetEsp
*     =procuravalorelem             inxLista  string  CondRetEsp
*     =avancarelem                  inxLista  numElem CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxLista  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1 ,
          CondRetObtido = -1;

      //TST_tpCondRet CondRet;

	  LISC_tpCondRet CondRet_Lista;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de teste de lista */

         if ( strcmp( ComandoTeste , RESET_LISTAC_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_LISTA ; i++ )
            {
               vtListas[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de lista */

      /* Testar CriarLista */

         else if ( strcmp( ComandoTeste , CRIAR_LISTAC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                       &inxLista ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxLista( inxLista , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            vtListas[ inxLista ] = LISC_CriarLista( DestruirValor, CompararValor ) ;

            return TST_CompararPonteiroNulo( 1 , vtListas[ inxLista ] ,
               "Erro em ponteiro de nova lista."  ) ;

         } /* fim ativa: Testar CriarLista */

      /* Testar Esvaziar lista lista */

         else if ( strcmp( ComandoTeste , ESVAZIAR_LISTAC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                               &inxLista ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            LISC_EsvaziarLista( vtListas[ inxLista ] ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar Esvaziar lista lista */

      /* Testar Destruir lista */

         else if ( strcmp( ComandoTeste , DESTRUIR_LISTAC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                               &inxLista ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            LISC_DestruirLista( vtListas[ inxLista ] ) ;
            vtListas[ inxLista ] = NULL ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar Destruir lista */

      /* Testar inserir elemento antes */

         else if ( strcmp( ComandoTeste , INS_ELEM_ANTESC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */

            strcpy( pDado , StringDado ) ;


            CondRet_Lista = LISC_InserirElementoAntes( vtListas[ inxLista ] , pDado ) ;

            if ( CondRet_Lista != LISC_CondRetOK )
            {
               free( pDado ) ;
            } /* if */

            return TST_CompararInt( CondRetEsp , CondRet_Lista ,
                     "Condicao de retorno errada ao inserir antes." ) ;

         } /* fim ativa: Testar inserir elemento antes */

      /* Testar inserir elemento apos */

         else if ( strcmp( ComandoTeste , INS_ELEM_APOSC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */

            strcpy( pDado , StringDado ) ;


            CondRet_Lista = LISC_InserirElementoApos( vtListas[ inxLista ] , pDado ) ;

            if ( CondRet_Lista != LISC_CondRetOK )
            {
               free( pDado ) ;
            } /* if */

            return TST_CompararInt( CondRetEsp , CondRet_Lista ,
                     "Condicao de retorno errada ao inserir apos."                   ) ;

         } /* fim ativa: Testar inserir elemento apos */

      /* Testar excluir simbolo */

         else if ( strcmp( ComandoTeste , EXC_ELEMC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                  &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( CondRetEsp ,
                      LISC_ExcluirElemento( vtListas[ inxLista ] ) ,
                     "Condi��o de retorno errada ao excluir."   ) ;

         } /* fim ativa: Testar excluir simbolo */

      /* Testar obter valor do elemento corrente */

         else if ( strcmp( ComandoTeste , OBTER_VALORC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista ,StringDado , &ValEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            pDado = ( char * )malloc(strlen(StringDado) + 1) ;
            
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria;
            } /* if */
            
            CondRetObtido = LISC_ObterValor( vtListas[ inxLista ], &pDado );
           
            if( CondRetObtido != LISC_CondRetListaVazia ){
                if( strcmp(pDado,StringDado) != 0){
                  return TST_CompararString( StringDado ,
                                     pDado   ,
                                     "valor retornado errado ao Obter Valor.");
                  }/*if */
            }/*if */
           
            if ( CondRetObtido != LISC_CondRetOK )
            {
               free( pDado ) ;
            } /* if */
            
            return TST_CompararInt( ValEsp , CondRetObtido ,
                     "Condicao de retorno errada ao Obter Valor." ) ;

         } /* fim ativa: Testar obter valor do elemento corrente */

			/* Testar procura valor */
		  else if ( strcmp( ComandoTeste , PROCURA_VALORC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &ValEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */			
			CondRetObtido = LISC_ProcurarValor( vtListas[ inxLista ], StringDado ) ;

         return TST_CompararInt( ValEsp , CondRetObtido ,
                         "Condicao de retorno errada ao Buscar Elemento." ) ;
         } /* fim ativa: Testar procura valor */
         
         	/* Testar avanca lista */
		  else if ( strcmp( ComandoTeste , AVANCAR_ELEMC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,
                       &inxLista , &numElem  , &ValEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = LISC_AvancarElementoCorrente( vtListas[ inxLista ] , numElem ) ;

            return TST_CompararInt( ValEsp , CondRetObtido ,
                         "Condicao de retorno errada ao Avancar elemento corrente." ) ;

         } /* fim ativa: Testar avanca lista */


      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TLIS &Testar lista */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim fun��o: TLIS -Destruir valor */

/***********************************************************************
*
*  $FC Fun��o: TLIS -comparar valor
*
***********************************************************************/

   int CompararValor( void * pValor1 , void * pValor2)
   {

     return strcmp( pValor1 , pValor2);

   } /* Fim fun��o: TLIS -Comparar valor */


/***********************************************************************
*
*  $FC Fun��o: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxLista( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtListas[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtListas[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TLISC -Validar indice de lista circular*/

/********** Fim do m�dulo de implementa��o: TLISC Teste lista circular de s�mbolos **********/
