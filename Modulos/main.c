#include "registro.h"
#include "tempo.h"

int main (int argc, char **argv){

  FILE *entrada, *manobras;
  entrada = fopen (argv[1], "r");
  manobras = fopen (argv[2], "r");
  int i = 0, j, gi, gj, zi, zj, retorno = 0, k = 0, l, ci, cj, totalmov = 0;

  veiculos v;
  veiculos matriz[6][6];
  veiculos v2[500];

  //Variaveis para calcular tempo
  Tempo t;
	double tempoU,tempoS;
	struct rusage resources;
	struct timeval inicioU, inicioS, fimU, fimS;

  iniciaTempo(&t);

  //inicia a matriz com 0
  for (i = 0; i < 6; i++){
    for (j = 0; j < 6; j++){
		limpa(matriz, i, j);
    }
  }

  //leitura da entrada a preenchimento da matriz
  while (fscanf(entrada, "%c %d %c %c%d%c%d\n", &v.nome, &v.tamanho, &v.direcao, &v.p1, &v.p2, &v.p3, &v.p4) != EOF){

    //veiculo na direcao X
    if (v.direcao == 'X'){
        ////verificacao de entrada invalida
        if (v.p2 < 1 || v.p2 > 5 || v.p4 < 1 || v.p2 > 6 || ((v.tamanho == 3) && (v.p2 > 4))){
			printf("Seguinte veículo inválido: %c %d %c %c%d%c%d\n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
        } else
		    insereDX (matriz, v);
    }

    //veiculo na direcao Y
    if (v.direcao == 'Y'){
      //verificacao de entrada invalida
      if (v.p4 < 1 || v.p4 > 5 || v.p2 < 1 || v.p2  > 6|| (v.tamanho == 3 && v.p4 > 4)){
        printf("Seguinte veículo inválido: %c %d %c %c%d%c%d\n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
      }
      else insereDY(matriz, v);
    }
  }
  imprimeM (matriz);

  //leitura das manobras
  k = 0;
  while (fscanf(manobras, "%c %c %d\n", &v2[k].nome,  &v2[k].direcao, &v2[k].mov) != EOF ){
    k++;
  }

  /*        EXECUCAO DAS MANOBRAS          */
  l = 0;
 while (matriz[2][4].nome != 'Z' && matriz[2][4].nome != 'Z'){
    if (v2[l].nome == 'Z'){
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
      if (v2[l].mov == 'Y' && (2 - zi == 0)){
        l ++;
      } else {
        if (v2[l].mov == 'X' && (4 - zj == 0)){
          l++;
        }
      }
    }
    if (l >= k){
      l = 0;
    }

    //encontra o veiculo a ser movimentado
    for (i = 5; i > 0; i--){
      for (j = 0; j < 6; j++){
        if (matriz[i][j].nome == v2[l].nome){
              gi = i;
              gj = j;
          break;
        }
      }
    }

    //realiza os movimentos
    if (matriz[gi][gj].direcao == 'X'){
      if (v2[l].direcao == 'X'){
        retorno = eixoXmovX(matriz, v2[l], &ci, &cj);
        if (retorno == 0){
          totalmov ++;
        }
      }
      if (v2[l].direcao == 'Y'){
        retorno = eixoXmovY(matriz, v2[l], &ci, &cj);
        if (retorno == 0){
          totalmov ++;
        }
      }
    }
    if (matriz[gi][gj].direcao == 'Y'){
      if (v2[l].direcao == 'X'){
        retorno = eixoYmovX(matriz, v2[l], &ci, &cj);
        if (retorno == 0){
          totalmov ++;
        }
      }
      if (v2[l].direcao == 'Y'){
        retorno = eixoYmovY(matriz, v2[l], &ci, &cj);
        if (retorno == 0){
          totalmov ++;
        }
      }
    }
    l++;
    if (l == k){
      l = 0;
    }
  }

  //resultados
  imprimeM(matriz);
  finalizaTempo(&t, &tempoU, &tempoS);
  printf ("\nCarro Z movimentado à saída com sucesso.\n");
  printf ("Numero de movimentos executados: %d\n", totalmov);
  printf ("Tempo usuario: %f, tempo de sistema: %f", tempoU, tempoS);

}
