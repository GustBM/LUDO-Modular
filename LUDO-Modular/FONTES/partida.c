/***************************************************************************
*  $MCI Módulo de implementação: PAR  Módulo da partida para LUDO
*
*  Arquivo gerado:              partida.c
*  Letras identificadoras:      PAR
*
*  Projeto: INF 1301 / Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
*  $HA Histórico de evolução:
*     Versão |  Autores   |      Data     |    Observações
*       1    |    GB      |   11/06/2019  | Início desenvolvimento
*       2    |    GB      |   12/06/2019  |      Ajustes
*       3    |    GB      |   23/06/2019  |      Ajustes    
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "tabuleiro.h"
#include "peca.h"

#define PAR_OWN
#include "partida.h"
#undef PAR_OWN

#define EVER ;;

#define TRUE 1
#define FALSE 0


#define NUM_PECA_PLAYER 4
#define MAX_PECAS 16 
#define MAX_PLAYERS 4
#define MIN_PLAYERS 2

#define VERMELHO 0
#define AMARELO 3

#define ROLA_DADO ((rand() % 6) + 1)

#define NENHUM 0

#define NUM_JOGADORES_MENOS1 ((pJogo ->num_jogadores) - 1)

#define TERMINOU 1

#define NAO_TERMINOU 1

#define NO_FIM 1
#define MAX_DADO 6
#define MIN_DADO 1
#define FORA_DO_JOGO 'F'
#define DENTRO_DO_JOGO 'D'
#define NAO_EXISTE 0

#define FORA_DO_FIM 0

#define INTERVALO_CASAS_INI 13

#define MIN_PECAS_PER_PLAYER 1
#define MAX_PECAS_PER_PLAYER 4


#define CASA_NORMAL 'N'
#define CASA_FINAL 'F'

#define SIM 'Y'
#define NAO 'N' 

#define MAIOR_CASA_NORMAL 52
#define MAIOR_CASA_FINAL 6
#define MENOR_CASA 1

#define AVANCO_UNICO 1
#define RETROCESSO_UNICO -1



/***********************************************************************
 *
 *  $TC Tipo de dados: PAR Partida de Ludo
 *
 ***********************************************************************/

typedef struct PAR_tagPartida
{
	TAB_tppTabuleiro pTabuleiro ;
	/* Ponteiro para Tabuleiro */
	
	PECA_tpPeca pecas[MAX_PECAS] ;
	/* Vetor de Peças */
	
	int num_jogadores ;
	/* Numero de jogadores */
	
} PAR_Ludo ;

/***** Protótipo das funções encapsuladas no módulo *****/

static void LimpaCabeca ( PAR_Ludo *pJogo ) ;

static void LancaDado ( int * pValor ) ;

static int ProcuraPeca ( TAB_tppTabuleiro pTabuleiro , PECA_tpPeca pPeca ) ;

PAR_CondRet PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) ;


/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
 *
 *  $FC Função: PAR  -Inicializa Jogo
 *
 ***********************************************************************/

PAR_CondRet PAR_InicializaJogo ( PAR_tppPartida pJogo , int num ) 
{
	int i;

	TAB_tppTabuleiro pTabuleiro ;
	PECA_CondRet retorno_pec 	;
	
	if ( num < MIN_PLAYERS || num > MAX_PLAYERS )
	{
		return PAR_CondRetNumeroDeJogadoresInvalido ;
	}

	pJogo = ( PAR_Ludo * ) malloc ( sizeof ( PAR_Ludo ) ) ;
	if ( pJogo == NULL )
	{
		return PAR_CondRetFaltouMemoria ;
	}
	
	LimpaCabeca ( pJogo ) ;

	pTabuleiro = TAB_CriaTabuleiro() ;
	if(pTabuleiro == NULL)
		return PAR_CondRetFaltouMemoria ;

	for ( i = 0 ; i < MAX_PECAS ; i++ ) 
	{
		retorno_pec = PECA_CriaPeca (pJogo ->pecas , i , i/MAX_PECAS_PER_PLAYER) ;
			switch ( retorno_pec ) 
			{
				case PECA_CondRetFaltaMemoria :
					return PAR_CondRetFaltouMemoria ;
				case PECA_CondRetExiste :
					return PAR_CondRetCorJaEscolhida ;
				case PECA_CondRetOK :
					break;
				default :
					printf("Erro inesperado\n");
					exit(0);
			}
	}

	pJogo->pTabuleiro    = pTabuleiro ;
	pJogo->num_jogadores = num        ;
	
	return PAR_CondRetOK ;
	
}  /* Fim função: PAR &Inicializa Jogo */


/***********************************************************************
 *
 *  $FC Função: PAR  -Limpa cabeça
 *
 ***********************************************************************/

static void LimpaCabeca ( PAR_Ludo *pJogo )
{
	int i ;
	pJogo->pTabuleiro = NULL ;

	for ( i = 0 ; i < MAX_PECAS ; i++ )
		pJogo->pecas[i] = NULL ;

	pJogo->num_jogadores = NENHUM ;
}

/***********************************************************************
 *
 *  $FC Função: PAR  -Lanca Dado
 *
 ***********************************************************************/


static void LancaDado ( int * pValor )
{
    int ValorAleatorio ;
  
    srand ( time ( NULL ) ) ;
    ValorAleatorio = ROLA_DADO;
      
    * pValor = ValorAleatorio ;
  
} /* Fim função: PAR  &Lanca Dado */



/***********************************************************************
 *
 *  $FC Função: PAR  -Verifica Ganhador
 *
 ***********************************************************************/
int PAR_VerificaVencedor( PAR_Ludo *pJogo, int * vencedores) {
	int final, i;
	int cor, terminaram = NENHUM;
	int jogadores[MAX_PLAYERS] = {0, 0, 0, 0};

	int * vencedoresTemp = (int*) malloc(sizeof(int) * (pJogo->num_jogadores));
	if(vencedoresTemp == NULL)
	{
		return PAR_CondRetFaltouMemoria;
	}

	for (i = 0; i < (pJogo->num_jogadores); i++)
	{
		vencedoresTemp[i] = FALSE;
	}

	for (i = 0; i < MAX_PECAS; i++)
	{
		PECA_ObtemFim (pJogo->pecas[i], &final );
		if (final == NO_FIM)
		{
			PECA_ObtemCor(pJogo->pecas[i], &cor);
			jogadores[cor]++;
		}
	}

	for (i = 0; i < MAX_PLAYERS; i++)
	{
		if(jogadores[i] == MAX_PECAS_PER_PLAYER) 
		{
			vencedoresTemp[terminaram] = TRUE;
			terminaram++;
		}
	}

	vencedores = vencedoresTemp;

	if (terminaram == NENHUM)
	{
		return PAR_CondRetNenhumVencedor;
	} 
	else if (terminaram == NUM_JOGADORES_MENOS1 || terminaram == MAX_PLAYERS){
		return PAR_CondRetAcabou;
	} 
	else 
	{
		return PAR_CondRetAlgunsVenceram;
	}

}/* Fim função: PAR  &Verifica Vencedor */

/***********************************************************************
 *
 *  $FC Função: PAR  -Realiza as rodadas do jogo
 *
 ***********************************************************************/

PAR_CondRet PAR_RealizarRodadas(PAR_tppPartida pJogo,int *ordem, int* vencedores_final)
{
	int cor_atu = 0;
	int CondRetPAR;
	int*vencedores = vencedores_final;
	CondRetPAR = PAR_VerificaVencedor( pJogo , vencedores );
	if(vencedores == NULL)
	{
		return PAR_CondRetFaltouMemoria ;
	}

	for(EVER)
	{
		cor_atu = cor_atu % MAX_PLAYERS;
		if(vencedores[cor_atu] == FALSE)
		{
			PAR_RealizaJogada (pJogo , ordem[cor_atu]);
			CondRetPAR = PAR_VerificaVencedor( pJogo , vencedores );
			
			switch ( CondRetPAR ) 
			{
				case PAR_CondRetFaltouMemoria :
					return PAR_CondRetFaltouMemoria ;
				case PAR_CondRetAcabou :
					break;
				case PAR_CondRetAlgunsVenceram :
					break;
				default :
					printf("Erro inesperado\n");
					exit(0);
			}
			cor_atu++;
		}

		if(CondRetPAR == PAR_CondRetAcabou)
			break;
		
	}
	vencedores_final = vencedores;
	return PAR_CondRetAcabou;
}/* Fim função: PAR  &realiza rodadas */



/***********************************************************************
 *
 *  $FC Função: PAR  -Realiza Jogada
 *
 ***********************************************************************/
PAR_CondRet PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) 
{
	int dado, i, auxCor  = 0;
	char status;
	int numerocasaMexer = 0;
	char tipoCasaMexer;

	int pecas_fora;
	int numPeca;
	int peca_valida = 0;

	CAS_CondRet CondRetCasa;

	char acao;
	int tomada_de_decisao = FALSE;
	char cores[4][9] = {"VERMELHO","AZUL","VERDE","AMARELO"};

	LISC_tppListaC casasNormais = NULL;
	TAB_tppCasaInfo casaIni = NULL;
	LIS_tppLista *casasFinais = NULL;

	TAB_tppCasaInfo casa_atu = NULL;
	TAB_tppCasaInfo casa_final_atu = NULL;

	LIS_tpCondRet LISCondRet;

	if (cor < VERMELHO || cor > AMARELO)
	{
		return PAR_CondRetCorInvalida;
	}

	while(!tomada_de_decisao)
	{
		printf("eh a vez do %s , aperte G para rolar o dado ou Q para encerrar o jogo: ", cores[cor]);
		scanf("%c", &acao);

		if(acao == 'Q')
		{
			printf("tem certeza que deseja encerrar o jogo (S/N)? ");
			scanf("%c", &acao);
			if(acao == 'S')
			{
				printf("partida encerrada\n");
				exit(0);
			}
		}
		else if(acao == 'G')
		{
			tomada_de_decisao = TRUE;
		}
		else
		{
			printf("comando desconhecido\n");
		}
	}	

	TAB_AcessaCasas(pJogo->pTabuleiro, casasNormais, casaIni, casasFinais);

	LancaDado ( &dado ) ;

	TAB_imprime(pJogo->pecas, pJogo->pTabuleiro);

	pecas_fora = 0;
	for(i= MAX_PECAS_PER_PLAYER * cor ;i<MAX_PECAS;i++)
	{
		PECA_ObtemStatus(pJogo->pecas[i],&status);
		if ( status == FORA_DO_JOGO )
    	{
        	pecas_fora++;
    	}
	}

	tomada_de_decisao = FALSE;
	
		if(pecas_fora > NENHUM && (dado == MIN_DADO || dado == MAX_DADO))
		{
			while(!tomada_de_decisao)
			{
				printf("deseja tirar alguma peca do campo inicial (Y/N): ");
				scanf("%c", &acao);
				if(acao == SIM)
				{
					while(!peca_valida)
					{
						printf("escolha qual peca deseja mexer: ");
						scanf("%d", &numPeca);
						PECA_ObtemStatus(pJogo->pecas[numPeca],&status);
						if(numPeca < MIN_PECAS_PER_PLAYER || numPeca > MAX_PECAS_PER_PLAYER)
						{
							printf("valor invalido. deve ser entre 1 e 4.\n");
						}
						else if(status == DENTRO_DO_JOGO)
						{
							printf("peca invalida. deve ser uma peca dentro do jogo\n");
						}
						else
						{
							peca_valida = TRUE;
							numPeca--;
							numPeca = MAX_PECAS_PER_PLAYER * cor + numPeca;
							PECA_AtualizaPeca(pJogo->pecas[numPeca],FORA_DO_FIM,DENTRO_DO_JOGO);
							LISC_ProcurarValor(casasNormais,casaIni);
							auxCor = cor;
							while(auxCor > VERMELHO){
								LISC_AvancarElementoCorrente(casasNormais,INTERVALO_CASAS_INI);
								auxCor--;
							}
							LISC_ObterValor(casasNormais, (void**)casa_atu);
							CondRetCasa = TAB_AlteraCasa(casa_atu,pJogo->pecas[numPeca]);
							if(CondRetCasa == CAS_CondRetBarreira)
							{
								printf("ha uma barreira na saida da peca.\n");
								if(pecas_fora  == MAX_PECAS_PER_PLAYER)
								{
									printf("aguarde o jogador inimigo desmontar a barreira da saida\n");
									acao = NAO;
								}
								break;
							}
							else
							{
								tomada_de_decisao = TRUE;
							}
						}
						
					}
						
				}
				if(acao == NAO)
				{
						tomada_de_decisao = TRUE;
				}
				else
				{
						printf("comando invalido. tente novamente.\n");
				}
			}	
		}
		if (pecas_fora < MAX_PECAS_PER_PLAYER)
		{
			int validar_tipo = FALSE;
			while(!validar_tipo)
			{
				
				printf("Vc tirou %d no dado, escolha o tipo da casa em que a peca que voce quer mexer esta presente: (N: Normal /F: Final ) ", dado);
				scanf("%c", &tipoCasaMexer);
				if(tipoCasaMexer != CASA_NORMAL && tipoCasaMexer != CASA_FINAL)
				{
					printf("tipo inexistente. Tente Novamente.\n");
				}
				else
				{
					PECA_tpPeca  pecaMexer;
					printf("Agora escolha  o numero da casa em que a peca que voce quer mexer esta presente: ", tipoCasaMexer);
					scanf("%d", &numerocasaMexer);

					if(tipoCasaMexer == CASA_NORMAL && (numerocasaMexer < MENOR_CASA  || numerocasaMexer > MAIOR_CASA_NORMAL))
					{
						printf("casa inexistente. Tente Novamente.\n");
					}
					else if(tipoCasaMexer == CASA_FINAL && (numerocasaMexer < MENOR_CASA  || numerocasaMexer > MAIOR_CASA_FINAL))
					{
						printf("casa inexistente. Tente Novamente.\n");
					}
					else 
					{
						if(tipoCasaMexer == CASA_NORMAL )
						{
							LISC_ProcurarValor(casasNormais , casaIni ) ;//tornar casa inicial vermelha como elemento corrente
							LISC_AvancarElementoCorrente( casasNormais , numerocasaMexer ); 
							LISC_ObterValor(casasNormais,(void**)casa_atu);

						}
						else if(tipoCasaMexer == CASA_FINAL)
						{
							IrInicioLista(casasFinais[cor]);
							LIS_AvancarElementoCorrente( casasFinais[cor] , numerocasaMexer) ;
							casa_atu = (void*) LIS_ObterValor( casasFinais[cor] ) ;
						}

						CondRetCasa = TAB_ObtemCasa(casa_atu,pecaMexer);

						if(CondRetCasa == CAS_CondRetCasaVazia)
						{
							printf("a casa nao tem ninguem. tente novamente\n");
						}
						else if(CondRetCasa == CAS_CondRetCasaInimiga)
						{
							printf("a casa eh inimiga. tente novamente\n");
						}
						else if (CondRetCasa == CAS_CondRetOK)
						{
							printf("vamos rolar o dado\n");
							validar_tipo = TRUE;
						}			
					}	
				}		
			}

			if(tipoCasaMexer == CASA_NORMAL )
			{
				while(dado > 0)
				{
					LISC_AvancarElementoCorrente( casasNormais , AVANCO_UNICO);
					LISC_ObterValor(casasNormais,(void**)casa_atu);
					if(TAB_verificaDesvio(casasFinais,casa_atu,cor))
					{
						IrInicioLista(casasFinais[cor]);
						while(dado > 0)
						{
							LIS_AvancarElementoCorrente( casasFinais[cor] , AVANCO_UNICO);
							dado--;
						}
					}
					if(dado == 0)
					{
						break;
					}
					dado--; 
				}
				if(TAB_verificaDesvio(casasFinais,casa_atu,cor))
				{
					casa_final_atu = LIS_ObterValor(casasFinais[cor]);
					CondRetCasa = TAB_AlteraCasa(casa_final_atu,pecaMexer);
				}
				
				
			}	

			
			else if(tipoCasaMexer == CASA_FINAL)
			{
				while(dado > 0)
				{
					LISCondRet = LIS_AvancarElementoCorrente( casasFinais[cor] , AVANCO_UNICO);
					if(LISCondRet == CondRetFimLista)
					{
						PECA_AtualizaPeca(pecaMexer,NO_FIM,DENTRO_DO_JOGO);
						break;
					}
					dado--;
				}

				casa_final_atu = LIS_ObterValor(casasFinais[cor]);
				CondRetCasa = TAB_AlteraCasa(casa_final_atu,pecaMexer);

			}
			
		}

	printf("movimento encerrado\n");
	return PAR_CondRetOK;
}   /* Fim função: PAR  &Realiza Jogada */
