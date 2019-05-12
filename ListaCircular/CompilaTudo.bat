@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err
del TesteCircular.exe

del *.obj
nmake /Ftestecircular.make 

copy  *.err  tudo.err

notepad tudo.err

popd
