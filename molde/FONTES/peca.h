#if ! defined ( PECA_ )
#define PECA_

/***************************************************************************
*
*  $MCD Módulo de definição: Modulo peca
*
*  Arquivo gerado:              peca.h
*  Letras identificadoras:      PECA
*
*  Projeto: Jogo de Ludo
*  Gestor:  Professor Alessandro Garcia
*  Autores: Luiz Fellipe Augusto, Eduardo Motta e Gustavo Barros
*
*
*  $ED Descrição do módulo
*     Cria uma Peça a partir de um índice dado no vetor.
*     Destroi uma Peça a partir de um índice dado no vetor.
*     Obtem informações sobre a Peça dado um indice no vetor.
*     Atualiza status e final de uma Peça dado um indice no vetor.
*
*     OBS IMPORTANTE: As 4 primeiras posições do vetor de peças destinam-se
*                     a cor vermelha, as próximas 4 destinam-se a cor azul,
*                     e analogamente para a cor verde e amarelo.
*
**************************************************************************/

/*****************INFORMAÇÃO DA COR*********************
*
*  A COR DE CADA PEÇA É CLASSIFICADA COMO:
*
*       0 - VERMELHO
*       1 - AZUL
*       2 - VERDE
*       3 - AMARELO

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma peça */

typedef struct Peca * PECA_tpPeca; 
/***********************************************************************
*
*  $TC Tipo de dados: PECA condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da peça
*
***********************************************************************/
typedef enum {

	PECA_CondRetOK ,
		/* Condição de retorno correto */

	PECA_CondRetFaltaMemoria , 
		/* Condição de retorno por Falta de memória na alocação */

	PECA_CondRetCorInvalida ,
		/*Condição de retorno devido a Cor inválida */

	PECA_CondRetFimErrado ,
		/* Condição de retorno devido a Fim Errado */						

	PECA_CondRetExiste ,
		/* Condição de retorno que indica que Peca existe */

	PECA_CondRetNaoExiste
		/* Condição de retorno que indica que Peca nao existe */

	PECA_CondRetStatusErrado ,
		/* Condição de retorno que indica Status Errado */

} PECA_CondRet;

/***********************************************************************
*
*  $FC Função: PECA &Criar PECA
*
*  $ED Descrição da função
*     Cria uma peça, dado um indice, no vetor.
*
*  $EP Parametros
*  * peca - ponteiro para peça a ser criada
*    i    - indice da peça no vetor
* 	 cor  - cor da peça
*
***********************************************************************/
/* Assertivas de Entrada PECA_CriaPeca
*  Existir mémoria suficiente para criacao da peça
*  Só pode criar uma peça que não exista até o momento de criação (peca[i] = NULL)
*  A cor dada (int) tem que ser entre 0 e 3
*  Para todo peca[i], peca = NULL.
*/

PECA_CondRet PECA_CriaPeca ( PECA_tpeca * peca, int i, int cor ) ;

/* Assertivas de Saida PECA_CriaPeca
*  A memoria referente a estrutura da peca tem que ser alocada
*  Para todo peca[i] criado, peca[i] != NULL
*  Para todo peca criado, peca->cor deve estar entre 0 e 3
*  A funcao retornara um PECA_CondRet
*/
/***********************************************************************
*
*  $FC função: PECA &Destruir peça
*
*  $ED Descrição da função
*     Destroi uma peça dado um indice, dentro do vetor.
*
*  $EP Parametros
*   *peca  -  peca a ser destruida.
*     i   -  indice no vetor

***********************************************************************/
/* Assertivas de Entrada PECA_DestroiPeca
*  Existir peça ja criada (para toda peca , peca != NULL)
*
*  Fim Assertiva de Entrada PECA_DestroiPeca */

PECA_CondRet PECA_DestroiPeca ( PECA_tpPeca peca ) ;
 
/* Assertiva de Saida PECA_DestroiPeca
*  A peca deve ser destruida (para todo peca , peca = NULL)
*  A memoria alocada para peca deve ser liberada 
*  A funcao retorna um PECA_CondRet
*
*  Fim Assertiva de Saida PECA_DestroiPeca */
/***********************************************************************
*
*  $FC Função: PECA  &Obtem cor
*
*  $ED Descrição da função
*    informa a cor de uma peça dada no vetor.
*
*  $EP Parametros
*   peca - peça que procura saber a cor
*  * cor - ponteiro passado para receber a cor
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemCor
*  Deve existir uma cor valida na peca (para todo peca, peca->cor entre 0 e 3)
*
*  Fim Assertiva de Entrada PECA_ObtemCor */

PECA_CondRet PECA_ObtemCor ( PECA_tpPeca peca , int * cor ) ;

/*  Assertiva de Saida PECA_ObtemCor
*   Deverá ser retornado uma cor válida (inteiro entre 0 e 3)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemCor */

/***********************************************************************
*
*  $FC Função: PECA  &Obtem fim
*
*  $ED Descrição da função
*     Dada uma peça no vetor, informa se está na casa final.
*
*  $EP Parametros
*   peca - peça que procura saber o final
*  * final - ponteiro passado para receber o final
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemFinal
*  Deve existir um valor final valido na peca
*
*  Fim Assertiva de Entrada PECA_ObtemFinal */

PECA_CondRet PECA_ObtemFinal ( PECA_tpPeca peca , int * final ) ;

/*  Assertiva de Saida PECA_ObtemFinal
*   Deverá ser retornado um final válido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemFinal */

/***********************************************************************
*
*  $FC Função: PECA  &Obtem status
*
*  $ED Descrição da função
*     Dada uma peça no vetor, informa seu status.
*
*  $EP Parametros
*   peca - peça que procura saber o status
*  * status - ponteiro passado para receber o status
*
***********************************************************************/

/* Assertivas de Entrada PECA_ObtemStatus
*  Deve existir um status valido na peca
*
*  Fim Assertiva de Entrada PECA_ObtemStatus */

PECA_CondRet PECA_ObtemStatus ( PECA_tpPeca peca , char * status ) ;

/*  Assertiva de Saida PECA_ObtemStatus
*   Deverá ser retornado um status válido (caracter 'D' ou 'F')
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_ObtemStatus */

/***********************************************************************
*
*  $FC Função: PECA  &Atualiza peça
*
*  $ED Descrição da função
*     Dado uma peça, atualiza o status e a condição final da peça.
*
*  $EP Parametros
*   peca - peça que procura saber a cor
*   final - atualizar se peça está no estágio final
*   status - atualizar se se peça está em jogo
*
***********************************************************************/

/* Assertivas de Entrada PECA_AtualizaPeca
*  Deve existir um status valido na peca
*  Deve existir um valor final valido na peca
*  A peça deve existi antes de chamar a função.
*
*  Fim Assertiva de Entrada PECA_AtualizaPeca */

PECA_CondRet PECA_AtualizaPeca ( PECA_tpPeca peca , int final, char status ) ;

/*  Assertiva de Saida PECA_AtualizaPeca
*   Deverá ser atualizado um status válido (caracter 'D' ou 'F')
*   Deverá ser atualizado um final válido (inteiro 1 ou 0)
*   A funcao retorna um PECA_CondRet
*
*   Fim Assertiva de Saida PECA_AtualizaPeca */

/********** Fim do módulo de definição: PECA Módulo Peças **********/
 