##################################################
###
### Diretivas de MAKE para o construto: TesteCircular
### Gerado a partir de: TesteCircular.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteCircular


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
   $(Fobj)\testelistacircular.obj   $(Fobj)\lista_circular.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\testelistacircular.obj :  {$(Pc)}\testelistacircular.c \
    {$(PDEFAULT)}GENERICO.h           {$(PDEFAULT)}LERPARM.h            {$(PDEFAULT)}TST_ESPC.h           \
    {$(PDEFAULT)}TST_Espc.h           {$(PDEFAULT)}lista_circular.h    
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\lista_circular.obj :  {$(Pc)}\lista_circular.c \
    {$(PDEFAULT)}lista_circular.h    
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\testelistacircular.obj   $(Fobj)\lista_circular.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteCircular
###
##################################################

