REM Recompila e retesta tudo

if exist TestaTudo.bat goto faz
rem >>> esta' no diretorio ilegal
goto sai

:faz

cls

Call vsvars32.bat
Call LimpaTudo
Call GeraTudo
Call CompilaTudo
Call TestaTudo

:sai
