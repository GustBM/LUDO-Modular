REM Compila o LUDO

cls

call vsvars32
Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\LUDODev /P..\COMPOSICAO\Gmake.parm 
Call Compila LUDODev
Call Testa LUDODev LUDODev

:sai