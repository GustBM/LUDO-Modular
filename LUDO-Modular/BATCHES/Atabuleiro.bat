REM Recompila tabuleiro

cls

Call LimpaTudo.bat
gmake  /B..\PRODUTOS\ /c..\COMPOSICAO\TesteTabuleiro /P..\COMPOSICAO\Gmake.parm
Call Compila TesteTabuleiro
Call Testa TesteTabuleiro TesteTabuleiro

:sai