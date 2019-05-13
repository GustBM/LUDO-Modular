/***************************************************************************
*  $MCI Módulo de implementação: TPeca Teste Peca
*
*  Arquivo gerado:              TestPeca.c
*  Letras identificadoras:      TPECA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Luiz Fellipe Augusto, Eduardo Motta, Gustavo Barros
*****************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include  <string.h>
#include "peca.h"
#include "GENERICO.h"
#include "LerParm.h"
#include "TST_Espc.h"


static const char CRIAR_PECA_CMD         [ ] = "=criarpeca"     ;
static const char DESTRUIR_PECA_CMD      [ ] = "=destruirpeca"  ;


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int numLidos   = -1 ;

      int ValEsp = -1 ;

	  int jogador;

	  PECA* p;

	  int time;


      /* Testar CriarPeca */

          if ( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,&jogador,&time,&ValEsp ) ;

            if ( ( numLidos != 3 ) )
            {
               return TST_CondRetParm ;
            } /* if */

            TST_CompararInt( ValEsp , cria_peca(jogador,p),"Valor Diferente");
			return TST_CondRetOK;

         } /* fim ativa: Testar CriarPeca */


      /* Testar Destruir Peca */

         else if ( strcmp( ComandoTeste , DESTRUIR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &time,TST_CondRetOK ) ;

            if ( ( numLidos != 2 ) )
            {
               return TST_CondRetParm ;
            } /* if */
			TST_CompararInt(TST_CondRetOK,destroi_peca(p),"Não Destruiu");
            return TST_CondRetOK ;

         } /* fim ativa: Testar Destruir Peca */
   }