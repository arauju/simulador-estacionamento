#include "registro.h"


void limpa (veiculos matriz[][6], int i, int j){
	  matriz[i][j].nome = '0';
    matriz[i][j].tamanho = 0;
    matriz[i][j].direcao = '0';
    matriz[i][j].p1 = '0';
    matriz[i][j].p2 = 0;
    matriz[i][j].p3 = '0';
    matriz[i][j].p4 = 0;
}

void imprimeM (veiculos matriz[][6]){
	int i, j;
	printf ("\n");
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			printf("%c  ", matriz[i][j].nome);
		}
		printf ("\n");
	}
}

/*							INSERINDO NA MATRIZ							*/
//na direcao X
void insereDX (veiculos matriz[][6], veiculos v){
	//carro
	if (v.tamanho == 2){
		if (matriz[6 - v.p4][v.p2 - 1].nome == '0' && matriz[6 - v.p4][v.p2].nome == '0'){
		//parte 1
		matriz[6 - v.p4][v.p2 - 1].nome = v.nome;
		matriz[6 - v.p4][v.p2 - 1].tamanho = v.tamanho;
		matriz[6 - v.p4][v.p2 - 1].direcao = v.direcao;
		matriz[6 - v.p4][v.p2 - 1].p1 = v.p1;
		matriz[6 - v.p4][v.p2 - 1].p2 = v.p2;
		matriz[6 - v.p4][v.p2 - 1].p3 = v.p3;
		matriz[6 - v.p4][v.p2 - 1].p4 = v.p4;

		//parte 2
		matriz[6 - v.p4][v.p2].nome = v.nome;
		matriz[6 - v.p4][v.p2].tamanho = v.tamanho;
		matriz[6 - v.p4][v.p2].direcao = v.direcao;
		matriz[6 - v.p4][v.p2].p1 = v.p1;
		matriz[6 - v.p4][v.p2].p2 = v.p2;
		matriz[6 - v.p4][v.p2].p3 = v.p3;
		matriz[6 - v.p4][v.p2].p4 = v.p4;
		}
	}

	//caminhao
	if (v.tamanho == 3){
		if (matriz[6 - v.p4][v.p2 - 1].nome == '0' && matriz[6 - v.p4][v.p2].nome == '0' && matriz[6 - v.p4][v.p2 + 1].nome == '0'){
			//parte 1
			matriz[6 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[6 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[6 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[6 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[6 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[6 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[6 - v.p4][v.p2 - 1].p4 = v.p4;

			//parte 2
			matriz[6 - v.p4][v.p2].nome = v.nome;
			matriz[6 - v.p4][v.p2].tamanho = v.tamanho;
			matriz[6 - v.p4][v.p2].direcao = v.direcao;
			matriz[6 - v.p4][v.p2].p1 = v.p1;
			matriz[6 - v.p4][v.p2].p2 = v.p2;
			matriz[6 - v.p4][v.p2].p3 = v.p3;
			matriz[6 - v.p4][v.p2].p4 = v.p4;

			//parte 3
			matriz[6 - v.p4][v.p2 + 1].nome = v.nome;
			matriz[6 - v.p4][v.p2 + 1].tamanho = v.tamanho;
			matriz[6 - v.p4][v.p2 + 1].direcao = v.direcao;
			matriz[6 - v.p4][v.p2 + 1].p1 = v.p1;
			matriz[6 - v.p4][v.p2 + 1].p2 = v.p2;
			matriz[6 - v.p4][v.p2 + 1].p3 = v.p3;
			matriz[6 - v.p4][v.p2 + 1].p4 = v.p4;
		}
	}
}

//na direcao Y
void  insereDY (veiculos matriz[][6], veiculos v){
	//carro
	if (v.tamanho == 2){
		if (matriz[6 - v.p4][v.p2 - 1].nome == '0' && matriz[5 - v.p4][v.p2 - 1].nome == '0'){
			//parte 1
			matriz[6 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[6 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[6 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[6 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[6 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[6 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[6 - v.p4][v.p2 - 1].p4 = v.p4;

			//parte 2
			matriz[5 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[5 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[5 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[5 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[5 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[5 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[5 - v.p4][v.p2 - 1].p4 = v.p4;
		}
	}

	//caminhao
	if (v.tamanho == 3){
		if (matriz[6 - v.p4][v.p2 - 1].nome == '0' && matriz[5 - v.p4][v.p2 - 1].nome == '0' && matriz[4 - v.p4][v.p2 - 1].nome == '0'){
			//parte 1
			matriz[6 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[6 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[6 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[6 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[6 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[6 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[6 - v.p4][v.p2 - 1].p4 = v.p4;

			//parte 2
			matriz[5 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[5 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[5 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[5 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[5 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[5 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[5 - v.p4][v.p2 - 1].p4 = v.p4;

			//parte 3
			matriz[4 - v.p4][v.p2 - 1].nome = v.nome;
			matriz[4 - v.p4][v.p2 - 1].tamanho = v.tamanho;
			matriz[4 - v.p4][v.p2 - 1].direcao = v.direcao;
			matriz[4 - v.p4][v.p2 - 1].p1 = v.p1;
			matriz[4 - v.p4][v.p2 - 1].p2 = v.p2;
			matriz[4 - v.p4][v.p2 - 1].p3 = v.p3;
			matriz[4 - v.p4][v.p2 - 1].p4 = v.p4;
		}
	}
}

void imenosv(veiculos matriz[][6], veiculos v, int i, int j){
	matriz[i - v.mov][j].nome = matriz[i][j].nome;
	matriz[i - v.mov][j].tamanho = matriz[i][j].tamanho;
	matriz[i - v.mov][j].direcao = matriz[i][j].direcao;
	matriz[i - v.mov][j].p1 = matriz[i][j].p1;
	matriz[i - v.mov][j].p2 = matriz[i][j].p2;
	matriz[i - v.mov][j].p3 = matriz[i][j].p3;
	matriz[i - v.mov][j].p4 = matriz[i][j].p4;
}

void jmaisv(veiculos matriz[][6], veiculos v, int i, int j){
	matriz[i][j + v.mov].nome = matriz[i][j].nome;
	matriz[i][j + v.mov].tamanho = matriz[i][j].tamanho;
	matriz[i][j + v.mov].direcao = matriz[i][j].direcao;
	matriz[i][j + v.mov].p1 = matriz[i][j].p1;
	matriz[i][j + v.mov].p2 = matriz[i][j].p2;
	matriz[i][j + v.mov].p3 = matriz[i][j].p3;
	matriz[i][j + v.mov].p4 = matriz[i][j].p4;
}

int encontraZ(veiculos matriz[][6], veiculos *v){
	int zi, zj, i, j;
	//encontra a posicao de Z
	for (i = 5; i >= 0; i--){
		for (j = 0; j < 6; j++){
			if (matriz[i][j].nome == 'Z'){
						zi = i;
						zj = j;
				break;
			}
		}
	}
	if (4 - zj != 0){
		v->nome = 'Z';
		v->direcao = 'X';
		v->mov = 4 - zj;
		return 1;
	} else {
		if (zi - 2 != 0){
			v->nome = 'Z';
			v->direcao = 'Y';
			v->mov = zi - 2;
			return 1;
		}else {
			return 0;
		}
	}
}

/*             REALIZA OS MOVIMENTOS          */

//veiculo no eixo X se movimentando em Y
int eixoXmovY (veiculos matriz[][6], veiculos v, int *ci, int *cj){
	int i, j, gi, gj, k;

	//movimento positivo
	if (v.mov > 0){
		//verificacao de movimento invalido
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (i - v.mov < 0) {
						return 2;
					}
					for (k = i - 1; k >= i - v.mov; k--){
						if (matriz[k][j].nome != '0'){
							*ci = k;
							*cj = j;
							return 1;
						}
					}
				}
			}
		}

		//realiza o movimento
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					gi = i;
					gj = j;
					imenosv (matriz, v, i, j);

					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}

	if (v.mov < 0){
		//verificacao de movimento invalido
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (i - v.mov > 5){
						return 2;
					}
					for (k = i + 1; k <= i - v.mov; k++){
						if (matriz[i - v.mov][j].nome != '0'){
							*ci = k;
							*cj = j;
							return 1;
						}
					}
				}
			}
		}

		//realiza o movimento
		for (i = 5; i > 0; i--){
			for (j = 5; j > 0; j--){
				if (matriz[i][j].nome == v.nome){
					gi = i;
					gj = j;
					imenosv (matriz, v, i, j);
					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}
}

//veiculo no eixo X se movimentando no eixo X
int eixoXmovX (veiculos matriz[][6], veiculos v, int *ci, int *cj){
	int i, j, gi, gj, k;

	//movimento positivo
	if (v.mov > 0){
		//verificacao de movimento valido
		for (i = 5; i >= 0; i--){
			for (j = 5; j >= 0; j--){
				if (matriz[i][j].nome == v.nome){
					if (j + v.mov > 5) {
						return 2;
					}
					for (k = j + 1; k <= j + v.mov; k++){
						if (matriz[i][k].nome != '0'){
							*ci = i;
							*cj = k;
							return 1;
						}
					}

					//realiza o movimento
					gi = i;
					gj = j;
					jmaisv(matriz, v, i, j);

		      //limpa a posicao
		      limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}

	//movimento negativo
	if (v.mov < 0){
		//verificacao de movimento valido
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (j + v.mov < 0){
						return 2;
					}
					for (k = j - 1; k >= j + v.mov; k--){
						if (matriz[i][k].nome != '0'){
							*ci = i;
							*cj = k;
							return 1;
						}
					}
					//realiza o movimento
					gi = i;
					gj = j;
					jmaisv(matriz, v, i, j);

		      //limpa a posicao
		      limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}
}

//veiculo no eixo Y se movimentando em Y
int eixoYmovY (veiculos matriz[][6], veiculos v, int *ci, int *cj){
	int i, j, gi, gj, k;

	//movimento positivo
	if (v.mov > 0){
		//verificacao de movimento valido
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (i - v.mov < 0 || matriz[i - v.mov][j].nome != '0'){
						return 2;
					}
					for (k = i - 1; k >= i - v.mov; k--){
						if (matriz[k][j].nome != '0'){
							*ci = k;
							*cj = j;
							return 1;
						}
					}

					//realiza o movimento
					gi = i;
					gj = j;
					imenosv (matriz, v, i, j);

					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}

	if (v.mov < 0){
		for (i = 5; i >= 0; i--){
			for (j = 5; j >= 0; j--){
				if (matriz[i][j].nome == v.nome){
					if (i - v.mov > 5){
						return 2;
					}
					for (k = i + 1; k <= i - v.mov; k++){
						if (matriz[k][j].nome != '0'){
							*ci = k;
							*cj = j;
							return 1;
						}
					}

					//realiza o movimento
					gi = i;
					gj = j;
					imenosv (matriz, v, i, j);

					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}
}

int eixoYmovX (veiculos matriz[][6], veiculos v, int *ci, int *cj){
	int i, j, gi, gj, k;
	//movimento positivo
	if (v.mov > 0){
		//verificacao de movimento valido
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (j + v.mov > 5){
						return 2;
					}
					for (k = j + 1; k <= j + v.mov; k++){
						if (matriz[i][k].nome != '0'){
							*ci = i;
							*cj = k;
							return 1;
						}
					}
				}
			}
		}

		//realiza o movimento
		for (i = 5; i > 0; i--){
			for (j = 5; j > 0; j--){
				if (matriz[i][j].nome == v.nome){
					gi = i;
					gj = j;
					jmaisv(matriz, v, i, j);

					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}

	//movimento negativo
	if (v.mov < 0){
		//verifica se é valido
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					if (j + v.mov < 0){
						return 2;
					}
					for (k = j - 1; k >= j + v.mov; k--){
						if (matriz[i][k].nome != '0'){
							*ci = i;
							*cj = k;
							return 1;
						}
					}
				}
			}
		}

		//realiza o movimento
		for (i = 0; i < 6; i++){
			for (j = 0; j < 6; j++){
				if (matriz[i][j].nome == v.nome){
					gi = i;
					gj = j;
					jmaisv(matriz, v, i, j);

					//limpa a posicao
					limpa(matriz, gi, gj);
				}
			}
		}
		return 0;
	}
}
