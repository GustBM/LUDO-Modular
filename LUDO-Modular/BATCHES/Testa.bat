@ECHO  OFF
REM  Testa um programa Formato  Testa  <NomePrograma> <NomeScript> [l]

if ""=="%1" goto erro
if ""=="%2" goto erro
if ""=="%3" goto console

..\produtos\%1 /s..\scripts\%2 /l..\produto\%2 /a..\scripts\estatisticas
goto sai

:console
..\produtos\%1 /s..\scripts\%2 /a..\scripts\estatisticas
goto sai

:erro
@ECHO  ON
REM >>> Comando errado deveria ser
REM
REM  Testa <NomePrograma> <NomeScript> [*]
REM     se * existe e' gerado em /produto um log com o mesmo nome do script
REM

:sai