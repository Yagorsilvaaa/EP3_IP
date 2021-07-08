/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   <94> - <Luciano Digiampiertri>                                **/
/**                                                                 **/
/**   Terceiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Yago Silva>                   <12543266>                     **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>

#define true 1
#define false 0

typedef int bool;


/*
	Jogo da Velha - programa para verificar o status de um jogo.

	Lista de Status calculado:
    0 - Jogo nao iniciado: o tabuleiro esta 'vazio', i.e., sem pecas X e O;
    1 - Jogo encerrado1: o primeiro jogador (que usa as pecas X) ganhou;
    2 - Jogo encerrado2: o segundo jogador (que usa as pecas O) ganhou;
    3 - Jogo encerrado3: empate - todas as casas do tabuleiro estao preenchidas com X e O, mas nenhum dos jogadores ganhou;
    4 - Jogo ja iniciado e em andamento: nenhuma das alternativas anteriores.	
 */

/*
	Determina o status de um partida de Jogo da Valha

	Entrada:
		tabuleiro - matriz 3x3 de caracteres representando uma partida valida de Jogo da Velha

	Saida:
		um inteiro contendo o status da partida (valores validos de zero a quatro)
*/

int verificaStatus(char tabuleiro[][3]) {
	int status = -1;

	int i, k;

	for (i = -1; i < 3; i++){

		if (i == -1) {

			for (k = 0; k < 3; k++) {

				if (tabuleiro[0][k] == ' ' && tabuleiro[1][k] == ' ' && tabuleiro[2][k] == ' '){
					status = 0;
					continue;

				} else{
					status = -1;
					break;
				} 

			}

		} else if (status == 0){
			break;
		} else{
		
			if (tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X'){
				status = 1;
				break;
			} else if (tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2] == 'X'){
				status = 1;
				break;
			} else if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
				status = 1;
				break;
			} else if (tabuleiro[2][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[0][2] == 'X'){
				status = 1;
				break;
			
			} else{
				
				if (tabuleiro[0][i] == 'O' && tabuleiro[1][i] == 'O' && tabuleiro[2][i] == 'O'){
					status = 2;
					break;
				} else if (tabuleiro[i][0] == 'O' && tabuleiro[i][1] == 'O' && tabuleiro[i][2] == 'O'){
					status = 2;
					break;
				} else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
					status = 2;
					break;
				} else if (tabuleiro[2][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[0][2] == 'O'){
					status = 2;
					break;
				
				} else {

					if (i == 0){
						
						for (k = 0; k < 3; k++){
							
							if (tabuleiro[0][k] != ' ' && tabuleiro[1][k] != ' ' && tabuleiro[2][k] != ' '){
								status = 3;
								continue;

							} else {
								status = -1;
								break;
							}

						}

					} else if (status == 3) {
						break;
					} else status = 4;			
				}
			}	
		}	
	}
	
	return status;
}

int main(){
	char tab0[][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	char tab1[][3] = {{' ',' ','X'},{'O','O','X'},{' ',' ','X'}};
	char tab2[][3] = {{' ',' ','X'},{'X','X',' '},{'O','O','O'}};
	char tab3[][3] = {{'X','O','X'},{'O','O','X'},{'X','X','O'}};
	char tab4[][3] = {{'O','X',' '},{'X','O','X'},{'O','X',' '}};

	printf("Status calculado: %i\n", verificaStatus(tab0));
	printf("Status esperado para o tabuleiro0: 0\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab1));
	printf("Status esperado para o tabuleiro1: 1\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab2));
	printf("Status esperado para o tabuleiro2: 2\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab3));
	printf("Status esperado para o tabuleiro3: 3\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab4));
	printf("Status esperado para o tabuleiro4: 4\n\n");
	
	return 0;
}