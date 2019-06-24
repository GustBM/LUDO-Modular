rem testa todos os scripts

cls

..\produtos\testeCircular	/s..\scripts\testeCircular    	/l..\produtos\testeCircular   	 /a..\scripts\estatisticas
if errorlevel 4 goto sai

..\produtos\testeCircular	/s..\scripts\testeContador    	/l..\produtos\testeCircular   	 /a..\scripts\estatisticas
if errorlevel 4 goto sai

..\produtos\testePeca  		/s..\scripts\testePeca          /l..\produtos\testePeca      	/a..\scripts\estatisticas
if errorlevel 4 goto sai

..\produtos\testeLista		/s..\scripts\testeLista         /l..\produtos\testeLista        /a..\scripts\estatisticas
if errorlevel 4 goto sai

..\produtos\testeTabuleiro	/s..\scripts\testeTabuleiro	    /l..\produtos\testeTabuleiro	/a..\scripts\estatisticas
if errorlevel 4 goto sai

..\produtos\testePartido	/s..\scripts\testePartido	    /l..\produtos\testePartido	    /a..\scripts\estatisticas
if errorlevel 4 goto sai


..\..\ferramnt\exbestat /e..\scripts\estatisticas

:sai

