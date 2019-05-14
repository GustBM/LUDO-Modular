@ECHO  OFF
REM  Gera todos os scripts de make

cls

pushd  .

cd ..\composicao

gmake  /b.. /cTesteCircular
gmake  /b..  /cTesteLista
gmake  /b.. /cTestePeca
gmake  /b.. /cTesteTabuleiro

popd
