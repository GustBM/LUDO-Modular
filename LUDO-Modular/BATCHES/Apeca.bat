REM Recompila peca

cls

call vsvars32
Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TestePeca /P..\COMPOSICAO\Gmake.parm
Call Compila TestePeca
Call Testa TestePeca TestePeca

:sai