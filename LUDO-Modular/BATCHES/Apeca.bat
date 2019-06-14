REM Recompila peca

cls

Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TestePeca     /P..\COMPOSICAO\Gmake.parm
Call Compila TestePeca
Call Testa TestePeca TestePeca

:sai