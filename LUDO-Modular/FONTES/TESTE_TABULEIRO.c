#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include	"lista_circular.h"

#include	"tabuleiro.h"

static const char RESET_TAB_CMD         [ ] = "=resetteste"     ;
static const char CRIAR_TABULEIRO [] = "=criartabuleiro";
static const char DESTRUIR_TABULEIRO [] = "=destruirtabuleiro";
static const char LIMPA_CASA [] = "=limpacasa";

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_TAB   10
#define DIM_VALOR     100

TAB_tppTabuleiro  vttabuleiros[DIM_VT_TAB];


/***** Protótipos das funções encapuladas no módulo *****/

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB &Testar lista
*
*  $ED Descrição da função
*     Podem ser criadas até 10 listas, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de memória
*     =criartabuleiro               inxLista
*     =destruirtabuleiro            inxLista
*     =limpacasa                    inxLista
*     
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxLista  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      TST_tpCondRet CondRet ;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de teste de tabuleiro */

         if ( strcmp( ComandoTeste ,RESET_TAB_CMD  ) == 0 )
         {

            for( i = 0 ; i <  DIM_VT_TAB ; i++ )
            {
              vttabuleiros[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de tabuleiro */

      /* Testar Criartabuleiro */

         else if ( strcmp( ComandoTeste , CRIAR_TABULEIRO ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                       &inxLista ) ;

            if ( ( numLidos != 1 ) || ( ! ValidarInxLista( inxLista , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

             vttabuleiros[ inxLista ] =  TAB_CriaTabuleiro(  ) ;

            return TST_CompararPonteiroNulo( 1 , vttabuleiros[ inxLista ] ,
               "Erro em ponteiro de nova lista."  ) ;

         } /* fim ativa: Testar Criar tabuleiro */


      /* Testar Destruir tabuleiro */

         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                               &inxLista ) ;

            if ( ( numLidos != 1 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            TAB_DestruirTabuleiro( vttabuleiros[ inxLista ] ) ;
           vttabuleiros[ inxLista ] = NULL ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar Destruir lista */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TTAB&Testar Tabuleiro */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim função: TLIS -Destruir valor */


/***********************************************************************
*
*  $FC Função: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxLista( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_TAB ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vttabuleiros[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vttabuleiros[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim função: TLIS -Validar indice de lista */

/********** Fim do módulo de implementação: TLIS Teste lista de símbolos **********/
