#include <stdio.h>

typedef enum {
	PECA_ok = 0,
	PECA_FaltouMemoria = 1 
} PECA_CondRet;

typedef struct peca PECA;

PECA_CondRet cria_peca(int jogador, PECA* ret);
	
PECA_CondRet destroi_peca(PECA* p);