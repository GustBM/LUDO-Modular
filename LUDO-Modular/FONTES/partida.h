#if ! defined( PARTIDA_ )
#define PARTIDA_

/***************************************************************************
*
*  $MCD Módulo de definição: PAR  Módulo da partida para LUDO
*
*  Arquivo gerado:              partida.h
*  Letras identificadoras:      PAR
*
*
*  Projeto: INF 1301 / TESTE 4 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: GBM - Gustavo Barros Marchesan
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       GBM   11/jun/2019 início desenvolvimento
*
*  $ED Descrição do módulo
*     Módulo responsável pelo inicio e fim da partida, com contagem de pontos,
*	  supervisão das rodadas e definição do vencedor. 
*
***************************************************************************/

#if defined( PARTIDA_OWN )
#define PARTIDA_EXT
#else
#define PARTIDA_EXT extern
#endif

#include "peca.h"
#include "tabuleiro.h"

/***** Declarações exportadas pelo módulo *****/

typedef struct PAR_tagPartida * PAR_tppPartida;


/***********************************************************************
*
*  $TC Tipo de dados: GT Códigos de retorno de funções
*
*
***********************************************************************/

typedef enum {

	PAR_CondRetOK,
	/* Concluiu corretamente */   

	PAR_CondRetFaltouMemoria, 
	/* Faltou Memoria */
			   
	PAR_CondRetNumeroDeJogadoresInvalido,
	/* Número de jogadores inválido */

	PAR_CondRetCorJaEscolhida,
	/* Cor já foi escolhida por outro jogador */

	PAR_CondRetCorInvalida
	/* Cor inválida */
   
   } PAR_CondRet ;

/***********************************************************************
 *
 *  $FC Função: JOGO  &Inicializa Jogo
 *
 *  $ED Descrição da função
 *     Inicializa um jogo de Ludo.
 *
 *  $EP Parâmetros
 *     pJogo     - ponteiro para jogo.
 *      num      - numero referente a quantidade de jogadores.
 *      cor      - cor da peça referente ao jogador.
 *
 *  $FV Valor retornado
 *     PAR_CondRetOK - Caso a inicialização foi correta.  
 *     PAR_CondRetFaltouMemoria - Caso tenha faltado memória.
 *     PAR_CondRetCorJaEscolhida - Caso a cor já tenha sido escolhida.
 *     PAR_CondRetCorInvalida - Caso a cor indicada seja inválida.
 *     PAR_CondRetNumeroDeJogadoresInvalido - Caso o numero de jogadores indicado
 *                                               é incorreto (menor que 2 ou maior que 4).
 *
 ***********************************************************************/

/* Assertivas de Entrada PAR_InicializaJogo
 *  Ter memoria suficiente para criacao da estrutura.
 *  A quantidade de jogadores a jogar devem estar corretas.
 *  Os ponteiros recebidos como parâmetros devem fazer referência correta
 *
 *  Fim Assertivas de Entrada PAR_InicializaJogo */

PAR_CondRet PAR_InicializaJogo ( PAR_tppPartida * pJogo , int num , int *cor ) ;


/* Assertivas de Saida PAR_InicializaJogo
 *  A memoria referente a estrutura tem que ser alocada.
 *  O jogo deverá ter sido corretamente inicializado.
 *  A funcao retornara um PAR_CondRet
 *
 *  Fim Assertiva de Saida PAR_InicializaJogo */

/***********************************************************************
 *
 *  $FC Função: PAR  &Realiza Jogada
 *
 *  $ED Descrição da função
 *     Realiza uma jogada no Jogo de Ludo.
 *
 *  $EP Parâmetros
 *     pJogo     - ponteiro para jogo.
 *      cor      - cor da peça referente ao jogador. 
 *
 ***********************************************************************/

/* Assertivas de Entrada PAR_RealizaJogada
 *  O ponteiro recebido como parâmetro deve fazer referência correta.
 *  A cor indicada deverá estar correta.
 *
 *  Fim Assertivas de Entrada PAR_RealizaJogada */

int PAR_RealizaJogada ( PAR_Ludo *pJogo , int cor ) ;


/***********************************************************************
 *
 *  $FC Função: PAR  &Verifica Vencedor
 *  $ED Descrição da função
 *     Verifica se há vencedores na partida
 *
 *  $EP Parâmetros
 *     pJogo     - ponteiro para jogo.
 *   vencedores  - Vetor que guarda os jogadores que já venceram, em nenhuma ordem particular.
 *
 *  $FV Valor retornado
 *	  1 - Caso haja vencedores suficientes para acabar a partida, i.e. 3
 *    0 - Caso haja vencedores, mas ainda 
 *   -1 - Caso a lista de vencedores esteja vazia
 ***********************************************************************/

/* Assertivas de Entrada PAR_VerificaVencedor
 *  O ponteiro recebido como parâmetro deve fazer referência correta.
 *  O vetor vencedores não precisa estar vazio nem ter sido inicializado, pois ele será na função
 *
 *  Fim Assertivas de Entrada PAR_VerificaVencedor */

int PAR_VerificaVencedor( PAR_Ludo *pJogo, int * vencedores ) ;

/* Assertivas de Saida PAR_VerificaVencedor
 *  A memoria referente a estrutura tem que ser alocada.
 *  O jogo deverá ter sido corretamente inicializado.
 *  A funcao retornara um valor inteiro 0 ou -1
 *
 *  Fim Assertiva de Saida PAR_VerificaVencedor */


#undef PARTIDA_EXT


/*********** Fim do módulo de definição: TAB Modulo Partida **********/


#else
#endif