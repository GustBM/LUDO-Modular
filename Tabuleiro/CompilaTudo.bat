@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err
del TesteSoma.exe

del *.obj
nmake /Ftestesoma.make 

copy  *.err  tudo.err

notepad tudo.err

popd
