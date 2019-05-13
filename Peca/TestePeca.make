##################################################
###
### Diretivas de MAKE para o construto: TestePeca
### Gerado a partir de: TestePeca.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TestePeca


### Nomes de paths

Pobj                 = ../Objetos
Perr                 = .
PDEFAULT             = .
Pc                   = .

### Nomes de diretórios para geração

Fobj                 = ../Objetos
Ferr                 = .
FDEFAULT             = .
Fc                   = .

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


### Regras de geração

all : limpa \
   $(Fobj)\TestePeca.obj   $(Fobj)\Peca.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\TestePeca.obj :  {$(Pc)}\TestePeca.c \
    {$(PDEFAULT)}GENERICO.h           {$(PDEFAULT)}LerParm.h            {$(PDEFAULT)}TST_Espc.h           \
    {$(PDEFAULT)}peca.h              
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\Peca.obj :  {$(Pc)}\Peca.c \
    {$(PDEFAULT)}peca.h              
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\TestePeca.obj   $(Fobj)\Peca.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TestePeca
###
##################################################

