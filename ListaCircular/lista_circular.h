#if ! defined( LISTA_CIRCULAR_ )
#define LISTA_CIRCULAR_ 

/***************************************************************************
*
*  $MCD Módulo de definição: LISC  Lista duplamente encadeada circular
*
*  Arquivo gerado:              lista_circular.h
*  Letras identificadoras:      LISC
*
*
*  Projeto: INF 1301 / TESTE 2 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Eduardo Motta
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       avs   01/mai/2019 início desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa listas genéricas duplamente encadeadas circulares.
*     Podem existir n listas em operação simultaneamente.
*     As listas possuem uma cabeça encapsulando o seu estado.
*
*     Cada lista é homogênea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que contém.
*
*     Os ponteiros para os dados são copiados para elementos da lista.
*        Não é copiado o valor apontado por estes ponteiros.
*
*     O controle da destruição do valor de um elemento a ser excluído
*        é realizado por uma função fornecida pelo usuário.
*
*     Cada lista referencia uma função que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A função de liberação dos valores contidos nos elementos deve
*        assegurar a liberação de todos os espaços referênciados pelo
*        valor contido em um elemento.
*        Esta função é chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso não seja necessário desalocar o valor referenciado pelo
*        elemento, o ponteiro para a função de liberação poderá ser NULL .
*        Caso o elemento da lista seja a única âncora do valor referenciado,
*        esta função deve promover a destruição (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/
/* Tipo referência para uma lista */




/***********************************************************************
*
*  $TC Tipo de dados: LISC Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista circular
*
***********************************************************************/
typedef enum {

	LISC_CondRetOK,
	/* Concluiu corretamente */

	LISC_CondRetListaVazia,
	/* A lista não contém elementos */

	LISC_CondRetNaoAchou,
	/* Não encontrou o valor procurado */

	LISC_CondRetFaltouMemoria
	/* Faltou memória ao tentar criar um elemento de lista */

} LISC_tpCondRet;


typedef struct LISC_tagLista* LISC_tppListaC;

/***********************************************************************
*
*  $FC Função: LISC  &Criar lista circular
*
*  $ED Descrição da função
*     Cria uma lista genérica circular.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     ExcluirValor  - ponteiro para a função que processa a
*                     exclusão do valor referenciado pelo elemento
*                     a ser excluído.
*                     Ver descrição do módulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro será utilizado pelas funções que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

LISC_tppListaC LISC_CriarLista(
	void(*ExcluirValor) (void * pDado));

/***********************************************************************
*
*  $FC Função: LISC  &Destruir lista circular
*
*  $ED Descrição da função
*     Destrói a lista circular fornecida.
*     O parâmetro ponteiro para a lista circular não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     LISC_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void LISC_DestruirLista( LISC_tppListaC pLista ) ;

/***********************************************************************
*
*  $FC Função: LISC  &Esvaziar lista 
*
*  $ED Descrição da função
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

   void LISC_EsvaziarLista( LISC_tppListaC pLista ) ;

   /***********************************************************************
*
*  $FC Função: LISC  &Inserir elemento antes
*
*  $ED Descrição da função
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LISC_CondRetOK
*     LISC_CondRetFaltouMemoria
*
***********************************************************************/

   LISC_tpCondRet LISC_InserirElementoAntes( LISC_tppListaC pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC Função: LISC &Inserir elemento após
*
*  $ED Descrição da função
*     Insere novo elemento após o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâmetros
*     Parâmetros
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
*  $FC Função: LISC  &Excluir elemento
*
*  $ED Descrição da função
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente será o novo corrente.
*     Se não existir e existir o elemento à direita, este se tornará corrente.
*     Se este também não existir a lista tornou-se vazia.
*
*  $EP Parâmetros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LISC_CondRetOK
*     LISC_CondRetListaVazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ExcluirElemento( LISC_tppListaC pLista ) ;


   /***********************************************************************
*
*  $FC Função: LISC  &Obter referência para o valor contido no elemento
*
*  $ED Descrição da função
*     Obtem a referência para o valor contido no elemento corrente da lista
*
*  $EP Parâmetros
*     pLista - ponteiro para a lista de onde se quer o valor
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

   void * LISC_ObterValor( LISC_tppListaC pLista ) ;


   /***********************************************************************
*
*  $FC Função: LISC  &Procurar elemento contendo valor
*
*  $ED Descrição da função
*     Procura o elemento que referencia o valor dado.
*     A função compara ponteiro e não conteúdo apontado.
*
*  $EP Parâmetros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LISC_CondRetOK  - se encontrou.
*                      O elemento corrente é o primeiro elemento do
*                      elemento corrente inclusive para o fim da lista
*                      e que contém o ponteiro procurado
*
*     LISC_CondRetNaoEncontrou - se o ponteiro não foi encontrado
*                      O elemento corrente continua o mesmo
*     LISC_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

   LISC_tpCondRet LISC_ProcurarValor( LISC_tppListaC pLista ,
                                    void * pValor        ) ;

   /********** Fim do módulo de definição: LISC  Lista circular duplamente encadeada **********/
  #else
#endif