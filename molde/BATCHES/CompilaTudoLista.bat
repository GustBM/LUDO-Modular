@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

cd ..\produtos
del *.err
del TesteLista.exe

cd ..\objetos
del *.obj
nmake /Ftestelista.make 

cd  ..\produtos
copy  *.err  tudo.err

notepad tudo.err

popd
