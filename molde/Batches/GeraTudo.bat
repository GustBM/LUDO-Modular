@ECHO  OFF
REM  Gera todos os scripts de make

cls

pushd  .

cd ..\composicao\Gmake

gmake  /b../TesteCircular
gmake  /b.. /TesteLista
gmake  /b../TestePeca
gmake  /b../TesteTabuleiro

popd
