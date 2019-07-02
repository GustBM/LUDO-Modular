REM Compila o LUDO

cls

call vsvars32
Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\LUDO /P..\COMPOSICAO\Gmake.parm 
Call Compila LUDO
Call Testa LUDO LUDO

:sai