@ECHO  OFF
REM  Gera todos os scripts de make

cls

pushd  .

gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TesteCircular  /P..\COMPOSICAO\Gmake.parm
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TesteContador /P..\COMPOSICAO\Gmake.parm 
gmake  /B..\PRODUTOS\  /c..\COMPOSICAO\TesteLista    /P..\COMPOSICAO\Gmake.parm
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TestePeca      /P..\COMPOSICAO\Gmake.parm
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TesteTabuleiro /P..\COMPOSICAO\Gmake.parm
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TestePartida  /P..\COMPOSICAO\Gmake.parm

popd
