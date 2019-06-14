#if ! defined( LISTA_CIRCULAR_ )
#define LISTA_CIRCULAR_ 

/***************************************************************************
*
*  $MCD M�dulo de defini��o: LISC  Lista duplamente encadeada circular
*
*  Arquivo gerado:              lista_circular.h
*  Letras identificadoras:      LISC
*
*
*  Projeto: INF 1301 / TESTE 2 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Eduardo Motta
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       avs   01/mai/2019 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas circulares.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/

/***** Declara��es exportadas pelo m�dulo *****/
/* Tipo refer�ncia para uma lista */




/***********************************************************************
*
*  $TC Tipo de dados: LISC Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista circular
*
***********************************************************************/
typedef enum {

	LISC_CondRetOK,
	/* Concluiu corretamente */

	LISC_CondRetListaVazia,
	/* A lista n�o cont�m elementos */

	LISC_CondRetNaoAchou,
	/* N�o encontrou o valor procurado */

	LISC_CondRetFaltouMemoria
	/* Faltou mem�ria ao tentar criar um elemento de lista */

} LISC_tpCondRet;


typedef struct LISC_tagLista* LISC_tppListaC;

/***********************************************************************
*
*  $FC Funcao: LISC  &Criar lista circular
*
*  $ED Descricao da funcao
*     Cria uma lista generica circular.
*     Os possiveis tipos sao desconhecidos a priori.
*     A tipagem eh implicita.
*     Nao existe identificador de tipo associado a lista.
*
*  $EP Parametros
*     ExcluirValor  - Ponteiro para a funcao que processa a
*                     exclusao do valor referenciado pelo elemento
*                     a ser excluido.
*                     Ver descricao do modulo.
*
*     CompararValor - Ponteiro para a funcao que processa a
*                     comparacao de valores referenciados pelo elemento
*                     Ver descricao do modulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro sera utilizado pelas funcoes que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de memoria ou dados errados,
*     a funcao retornara NULL.
*     Nao sera dada mais informacao quanto ao problema ocorrido.
*
***********************************************************************/

LISC_tppListaC LISC_CriarLista(void( * ExcluirValor ) ( void * pDado ),
int(*CompararValor) (void * pValor1, void * pValor2));

/***********************************************************************
*
*  $FC Funcao: LISC  &Destruir lista circular
*
*  $ED Descricao da funcao
*     Destroi a lista circular fornecida.
*     O parametro ponteiro para a lista circular nao eh modificado.
*     Se ocorrer algum erro durante a destruicao, a lista resultara
*     estruturalmente incorreta.
*     OBS. nao existe previsao para possiveis falhas de execucao.
*
*  $FV Valor retornado
*     LISC_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void LISC_DestruirLista( LISC_tppListaC pLista ) ;

/***********************************************************************
*
*  $FC Funcao: LISC  &Esvaziar lista 
*
*  $ED Descricao da funcao
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Parametros
*     pLista - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

LISC_tpCondRet LISC_EsvaziarLista( LISC_tppListaC pLista ) ;

   /***********************************************************************
*
*  $FC Funcao: LISC  &Inserir elemento antes
*
*  $ED Descricao da funcao
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parametros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LISC_CondRetOK
*     LISC_CondRetFaltouMemoria
*     LISC_CondRetListaVazia
*
***********************************************************************/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppListaC pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC Funcao: LISC &Inserir elemento apos
*
*  $ED Descricao da funcao
*     Insere novo elemento apos o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parametros
*     Parametros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*     Valor retornado
*        LISC_CondRetOK
*        LISC_CondRetFaltouMemoria
*
***********************************************************************/

   LISC_tpCondRet LISC_InserirElementoApos( LISC_tppListaC pLista ,
                                          void * pValor        )
       ;


/***********************************************************************
*
*  $FC Funcao: LISC  &Excluir elemento
*
*  $ED Descricao da funcao
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente sera o novo corrente.
*     Se nao existir e existir o elemento a direita, este se tornara corrente.
*     Se este tambem nao existir a lista tornou-se vazia.
*
*  $EP Parametros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LISC_CondRetOK - elemento eliminado com sucesso
*     LISC_CondRetListaVazia - lista vazia 
*
***********************************************************************/

   LISC_tpCondRet LISC_ExcluirElemento( LISC_tppListaC pLista ) ;


   /***********************************************************************
*
*  $FC Funcao: LISC  &Obter referencia para o valor contido no elemento
*
*  $ED Descricao da funcao
*     Obtem a referencia para o valor contido no elemento corrente da lista
*
*  $EP Parametros
*     pLista - ponteiro para a lista de onde se quer o valor
*
*  $FV Valor retornado
*     LISC_CondRetOK - se o elemento corrente existe
*     LISC_CondRetListaVazia    - se a lista estiver vazia
*           
*
***********************************************************************/

    LISC_tpCondRet LISC_ObterValor( LISC_tppListaC pLista, void ** val );


   /***********************************************************************
*
*  $FC Funcao: LISC  &Procurar elemento contendo valor
*
*  $ED Descricao da funcao
*     Procura o elemento que referencia o valor dado.
*     a comparacao ocorre utilizando a funcao 'ComparaValor' fornecida
*
*  $EP Parametros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LISC_CondRetOK           - Se encontrou.
*                      a primeira instancia do elemento encontrada
*                      se torna o elemento corrente 
*
*     LISC_CondRetNaoEncontrou - Se o ponteiro nao foi encontrado
*                      O elemento corrente continua o mesmo
*     LISC_CondRetListaVazia   - Se a lista estiver vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppListaC pLista ,
                                    void * pValor        ) ;

/***********************************************************************
 *
 *  $FC Funcao: LISC  &Avancar elemento
 *
 *  $ED Descricao da funcao
 *    Avanca o elemento corrente 'num' elementos na lista.
 *     Se 'num' for positivo avanca em "direcao horaria".
 *     Se 'num' for negativo avança em "direcao anti-horaria".
 *     Se 'num' for zero nao avanca em nenhuma direcao.
 *
 *  $EP Paramentros
 *     pLista  - ponteiro para a lista a ser manipulada
 *     num    - o numero de elementos a andar
 *
 *  $FV Valor retornado
 *     LISC_CondRetOK      - se 'num' elementos tiverem sido andados
 *     LISC_CondRetVazia   - se a lista esta vazia
 *
 ***********************************************************************/


LISC_tpCondRet LISC_AvancarElementoCorrente(LISC_tppListaC pLista , 
									int num );




   /********** Fim do midulo de definicao: LISC  Lista circular duplamente encadeada **********/
  #else
#endif
