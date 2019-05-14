##################################################
###
### Diretivas de MAKE para o construto: TesteCircular
### Gerado a partir de: ..\COMPOSICAO\TesteCircular.comp
###
### ----- Arquivo gerado, N�O EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteCircular


### Nomes de paths

Pinc                 = ..\Tabelas
Ptab                 = ..\Tabelas
Pdef                 = ..\Tabelas
Ph                   = ..\Fontes
Pobj                 = ..\Objetos
Perr                 = ..\Produtos
PDEFAULT             = ..\Fontes
Pc                   = ..\Fontes

### Nomes de diret�rios para gera��o

Finc                 = ..\Tabelas
Ftab                 = ..\Tabelas
Fdef                 = ..\Tabelas
Fh                   = ..\Fontes
Fobj                 = ..\Objetos
Ferr                 = ..\Produtos
FDEFAULT             = ..\Fontes
Fc                   = ..\Fontes

### Macros da plataforma


O       =
OD      = /Zi /Od
L       =
LD      = /DEBUG /DEBUGTYPE:CV

!IFDEF PRD
O       = /Ox
!ENDIF

OPT     = /c /J /W4 /nologo
INCLUDE = $(INCLUDE);$(PDEFAULT)


### Regras de gera��o

all : limpa \
   $(Fobj)\testelistacircular.obj   $(Fobj)\lista_circular.obj \
   Construto

### Limpar arquivos

limpa :
   CompileBanner /c$(NOME)
   CompileBanner /c$(NOME) >$(Ferr)\$(NOME).err


### Depend�ncias de m�dulos objeto a compilar

$(Fobj)\testelistacircular.obj :  {$(Pc)}\testelistacircular.c \
    {$(Ph)}generico.h           {$(Ph)}lerparm.h            {$(Ph)}lista_circular.h     \
    {$(Ph)}tst_espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\lista_circular.obj :  {$(Pc)}\lista_circular.c \
    {$(Ph)}lista_circular.h    
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Termina��o

Construto : \
   $(Fobj)\testelistacircular.obj   $(Fobj)\lista_circular.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteCircular
###
##################################################

