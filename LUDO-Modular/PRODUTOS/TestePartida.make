##################################################
###
### Diretivas de MAKE para o construto: TestePartida
### Gerado a partir de: ..\COMPOSICAO\TestePartida.comp
###
### ----- Arquivo gerado, N�O EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TestePartida


### Nomes de paths

Pdef                 = ..\Fontes
Ph                   = ..\Fontes
Pobj                 = ..\Objetos
Perr                 = ..\Produtos
PDEFAULT             = ..\Fontes
Pc                   = ..\Fontes

### Nomes de diret�rios para gera��o

Fdef                 = ..\Fontes
Fh                   = ..\Fontes
Fobj                 = ..\Objetos
Ferr                 = ..\Produtos
FDEFAULT             = ..\Fontes
Fc                   = ..\Fontes

### Macros da plataforma


O       = /D_CRT_SECURE_NO_DEPRECATE
OD      = /Zi /Od /D_CRT_SECURE_NO_DEPRECATE
L       =
LD      = /DEBUG /DEBUGTYPE:CV

!IFDEF PRD
O       = /Ox /D_CRT_SECURE_NO_DEPRECATE
!ENDIF

OPT     = /c /J /W4 /nologo
INCLUDE = $(INCLUDE);$(PDEFAULT)


### Regras de gera��o

all : limpa \
   $(Fobj)\partida.obj   $(Fobj)\teste_tabuleiro.obj   $(Fobj)\testepartida.obj \
   $(Fobj)\tabuleiro.obj   $(Fobj)\peca.obj   $(Fobj)\lista.obj \
   $(Fobj)\lista_circular.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Depend�ncias de m�dulos objeto a compilar

$(Fobj)\partida.obj :  {$(Pc)}\partida.c \
    {$(Ph)}lista.h              {$(Ph)}lista_circular.h     {$(Ph)}partida.h            \
    {$(Ph)}peca.h               {$(Ph)}tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\teste_tabuleiro.obj :  {$(Pc)}\teste_tabuleiro.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}lista.h              \
    {$(Ph)}tst_espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\testepartida.obj :  {$(Pc)}\testepartida.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}lista.h              \
    {$(Ph)}lista_circular.h     {$(Ph)}partida.h            {$(Ph)}peca.h               \
    {$(Ph)}tabuleiro.h          {$(Ph)}tst_espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\tabuleiro.obj :  {$(Pc)}\tabuleiro.c \
    {$(Ph)}lista.h              {$(Ph)}lista_circular.h     {$(Ph)}peca.h               \
    {$(Ph)}tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\peca.obj :  {$(Pc)}\peca.c \
    {$(Ph)}peca.h              
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\lista.obj :  {$(Pc)}\lista.c \
    {$(Ph)}lista.h             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\lista_circular.obj :  {$(Pc)}\lista_circular.c \
    {$(Ph)}cespdin.h            {$(Ph)}conta.h              {$(Ph)}lista_circular.h    
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Termina��o

Construto : \
   $(Fobj)\partida.obj   $(Fobj)\teste_tabuleiro.obj   $(Fobj)\testepartida.obj \
   $(Fobj)\tabuleiro.obj   $(Fobj)\peca.obj   $(Fobj)\lista.obj \
   $(Fobj)\lista_circular.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TestePartida
###
##################################################

