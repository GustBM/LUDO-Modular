#include <stdio.h>

/*uma casa pode ter no maximo 4 pecas, todas da mesma cor

	cores sao R - Vermelho     B - Azul
	
			  Y - Amarelo      G - Verde
			  
			     
	casas com apenas a inicial da cor possuem apenas uma peca daquela cor na casa
	
	casa com cor x n  indicam que há N pecas de uma mesma cor presentes na casa 
	
	setas apontam para casa inicial de cada cor. 

 */
void interface(){
	
int i, j;

	char tabuleiro[31][61]=	{   "    __________          v---v---v---v         __________     " ,
                                "   |          |         |   |   |   |        |          |    " ,
                                "   |  R    R  |         |---+---+---|        |  B       |    " ,
                                "   |          |         |Rx2|   < B | <==    |          |    " ,
                                "   |          |         |---+---+---|        |          |    " ,
                                "   |__________|         |   |   |   |        |__________|    " ,
                                "                        |---+---+---|                        " ,
                                "                        |   |   |   |                        " ,
                                "                        |---+---+---|                        " ,
                                "                        |   |   |   |                        " ,
                                "     ||                 |---+---+---|                        " ,
                                "     vv                 |   |   |   |                        " ,
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,
                                "|   |   |   |   |   |   |   |   |   |   | B |   |   |   |   |" ,
                                "|---+vvv+---+---+---+---+---+---+---+---+---+---+---+---+---|" ,
                                "|   |   |   |   |   |   |   | X | B |   |   |   |   |   |   |" ,
                                "|---+---+---+---+---+---+---+---+---+---+---+---+---+^^^+---|" ,
                                "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |" ,
                                ">---.---.---.---.---.---+---+---+---+---.---.---.---.---.---<" ,
                                "                        |   |   |   |                ^^      " ,
                                "                        |---+---+---|                ||      " ,
                                "                        |   |   |   |                        " ,
                                "                        |---+---+---|                        " ,
                                "                        | Y |   |   |                        " ,
                                "    __________          |---+---+---|         __________     " ,
                                "   |          |         |   |   |   |        |          |    " ,
                                "   |  Y   Y   |         |---+---+---|        |  G    G  |    " ,
                                "   |          |     ==> |   >   |   |        |          |    " ,
                                "   |  Y       |         |---+---+---|        |  G    G  |    " ,
                                "   |__________|         |   |   |   |        |__________|    " ,
                                "                        ^---^---^---^                        " };

	for(i=0;i<31;i++){
		for(j=0;j<61;j++){
			
			if()
			
			printf("%c", tabuleiro[i][j]);
		}
		printf("\n");
	}
	
}


int main(void){
	
	interface();
	
	return 0;
}
