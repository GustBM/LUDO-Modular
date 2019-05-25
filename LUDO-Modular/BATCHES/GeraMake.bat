@ECHO  OFF
REM  Gera script de make
REM    Sintaxe   GeraMake <NomeArquivoComposicao>

pushd  .

if ""=="%1" goto erro

gmake /c..\COMPOSICAO\%1 /B..\PRODUTOS\ /P..\COMPOSICAO\Gmake.parm 
goto sai

:erro
echo Falta nome do arquivo de diretivas de composicao

:sai
popd
