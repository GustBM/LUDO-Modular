REM Recompila lista circular

cls

call vsvars32
Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TesteCircular /P..\COMPOSICAO\Gmake.parm 
Call Compila TesteCircular
Call Testa TesteCircular TesteCircular

:sai