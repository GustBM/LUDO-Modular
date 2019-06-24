REM Recompila partida

cls

Call vsvars32.bat
Call LimpaTudo.bat
Call Geratudo.bat
Call Compila TestePartida
Call Testa TestePartida TestePartida

:sai