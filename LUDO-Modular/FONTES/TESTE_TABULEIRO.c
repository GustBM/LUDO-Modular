#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include	   "lista_circular.h"
#include	   "tabuleiro.h"

static const char RESET_TAB_CMD         [ ] = "=resetteste"       ;
static const char CRIAR_TABULEIRO       [ ] = "=criartabuleiro"   ;
static const char DESTRUIR_TABULEIRO    [ ] = "=destruirtabuleiro";

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_TAB   10
#define DIM_VALOR    100

TAB_tppTabuleiro  vttabuleiros[DIM_VT_TAB];


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TTAB &Testar lista
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 listas, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de mem�ria
*     =criartabuleiro               inxLista
*     =destruirtabuleiro            inxLista
*     
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxLista  = -1 ,
          numLidos   = -1,
          CondRetEsp = -1,
          CondRet_Tab = -1 ;
      
      int i ;

      /* Efetuar reset de teste de tabuleiro */

         if ( strcmp( ComandoTeste , RESET_TAB_CMD  ) == 0 )
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

            vttabuleiros[ inxLista ] =  TAB_CriaTabuleiro() ;

            return TST_CompararPonteiroNulo( 1 , vttabuleiros[ inxLista ] ,
               "Erro em ponteiro de nova lista."  ) ;

         } /* fim ativa: Testar Criar tabuleiro */


      /* Testar Destruir tabuleiro */

         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &inxLista, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet_Tab = TAB_DestruirTabuleiro( vttabuleiros[ inxLista ] ) ;
            vttabuleiros[ inxLista ] = NULL ;

            return TST_CompararInt( CondRetEsp , CondRet_Tab ,
                     "Condicao de retorno errada ao destruir tabuleiro." ) ;

         } /* fim ativa: Testar Destruir lista */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TAB&Testar Tabuleiro */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: TLIS -Validar indice de lista
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

   } /* Fim fun��o: TLIS -Validar indice de lista */

/********** Fim do m�dulo de implementa��o: TLIS Teste lista de s�mbolos **********/
