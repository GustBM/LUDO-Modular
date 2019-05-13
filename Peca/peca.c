#include <stdio.h>
#include "peca.h"
#include <malloc.h>

struct peca
{
	int time;
};

PECA_CondRet cria_peca(int jogador, PECA* ret)
{
	PECA* p = (PECA*) malloc(sizeof(PECA));
	if(p == NULL)
	{
		printf("Erro ao criar peca \n");
		return PECA_FaltouMemoria;
	}
	p->time = jogador;
	*ret = *p;
	return PECA_ok;
}

int destroi_peca(PECA* p)
{
	free(p);
	return PECA_ok;
}