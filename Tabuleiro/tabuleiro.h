/***************************************************************************
*
*  $MCD Módulo de definição: TAB  Módulo do tabuleiro para LUDO
*
*  Arquivo gerado:              tabuleiro.h
*  Letras identificadoras:      TAB
*
*
*  Projeto: INF 1301 / TESTE 2 2019.1
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Gustavo Barros Marchesan
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       GBM   07/mai/2019 início desenvolvimento
*	  2		  GBM	12/mai/2019 Junção dos módulos tabuleiro e peca
*
*  $ED Descrição do módulo
*     Módulo para criação e manipulação do tabuleiro e pecas para o jogo LUDO
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

typedef struct TAB_tagTabuleiro * TAB_tppTabuleiro;

typedef struct TAB_tagCasaInfo * TAB_tppCasaInfo;

typedef struct peca* PECA;

/***********************************************************************
*
*  $TC Tipo de dados: GT Códigos de retorno de funções
*
*
***********************************************************************/

   typedef enum {

         CondRetOK ,
               /* Função executou correto */

         CondRetErro ,
               /* Erro de leitura de arquivo */

         CondRetMem
               /* Erro de espaço na memória */

   } tpCondRet ;

/***********************************************************************
*
*  $FC Função: TAB  &Criar Tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro para o LUDO, composto por uma lista circular
*	  composta por 56 posições e 4 listas comuns composta por 5 casas cada
*	  A função não precisa de parâmetros para fazer as listas porque ela já
*	  será uma lista de casas.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a tabela.
*     Este ponteiro será utilizado pelas funções que manipulem a tabela.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*	  Caso haja um erro na criação da tabela inicial a função retornará NULL
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

TAB_tppTabuleiro TAB_CriaTabuleiro ();

/***********************************************************************
*
*  $FC Função: TAB  &Destruir Tabuleiro
*
*  $ED Descrição da função
*     Elemina o conteudo da de todas as listas do tabuleiro e depois 
*	  destroi ele
*
*  $EP Parâmetros
*     pTab - ponteiro para a o tabuleiro a ser destruido
*
***********************************************************************/

void TAB_DestruirTabuleiro( TAB_tppTabuleiro pTab);

/***********************************************************************
*
*  $FC Função: TAB  &Limpa Casa Tab
*
*  $ED Descrição da função
*     Elemina o elemento do tabuleiro dado como parâmetro
*
*  $EP Parâmetros
*     casa - ponteiro para a casa a ser esvaziada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a função ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informações adicionais
*
***********************************************************************/

tpCondRet TAB_LimpaCasaTab (TAB_tpCasaInfo casa);

/***********************************************************************
*
*  $FC Função: TAB  &Cria Peca
*
*  $ED Descrição da função
*     Cria uma peça para o jogo de ludo.
*
*  $EP Parâmetros
*     jogador - inteiro representando o jogador a qual a peça pertence
*	  ret - ponteiro de referência para a peca criada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a função ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informações adicionais
*
***********************************************************************/

tpCondRet TAB_CriaPeca (int jogador, PECA* ret);


/***********************************************************************
*
*  $FC Função: TAB  &Destroi Peca
*
*  $ED Descrição da função
*     Elemina a peca do tabuleiro dado como parâmetro
*
*  $EP Parâmetros
*     p - ponteiro para a peca a ser eliminada
*
*  $FV Valor retornado
*	  CondRetOK  - Se a função ocorreu sem problemas
*	  CondRetErro - caso tenha algum problema. Sem informações adicionais
*
***********************************************************************/

tpCondRet TAB_DestroiPeca (PECA* p);