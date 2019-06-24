REM Recompila Partida

cls

call vsvars32
Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TestePartida /P..\COMPOSICAO\Gmake.parm 
Call Compila TestePartida
Call Testa TestePartida TestePartida

:sai