REM Recompila peca

cls

call vsvars32
Call LimpaTudo.bat
Call GeraTudo.bat
Call Compila TestePeca
Call Testa TestePeca TestePeca

:sai