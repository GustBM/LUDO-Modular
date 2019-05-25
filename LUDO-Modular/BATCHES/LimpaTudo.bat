REM   Limpa tudo que sera' regerado


if exist TestaTudo.bat goto faz
rem >>> esta' no diretorio ilegal
goto sai

:faz

pushd .

cd ..\Batches
del *.bak

cd ..\Composicao
del *.bak


cd ..\Fontes
del *.bak
del *.err

cd ..\Objetos
del *.bak
del *.obj
del *.lib
del *.build

cd ..\Produtos
del *.bak
del *.log
del *.exe
del *.err
del *.list
del *.make

cd ..\Scripts
del *.bak
del *.estat

popd

:sai
