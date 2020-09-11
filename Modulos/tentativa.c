#include "registro.h"
#include "tempo.h"

int main (int argc, char **argv){

  FILE *entrada, *manobras;
  entrada = fopen (argv[1], "r");
  manobras = fopen (argv[2], "w");
  int i = 0, j, gi, gj, zi, zj, k = 0, l;

  veiculos v;
  veiculos matriz[6][6];
  char dado[18];

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

  while (fscanf(entrada, "%c %d %c %c%d%c%d\n", &v.nome, &v.tamanho, &v.direcao, &v.p1, &v.p2, &v.p3, &v.p4) != EOF){
    //  printf ("%c %d %c %c%d%c%d \n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
    if (v.nome != 'Z'){
      dado[k] = v.nome;
      k++;
    }

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
      if (v.p4 < 1 || v.p4 > 5 || v.p2 < 1 || v.p2 > 6|| (v.tamanho == 3 && v.p4 > 4)){
        printf("Seguinte veículo inválido: %c %d %c %c%d%c%d\n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
      }
      else
    insereDY(matriz, v);
     }
    }

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

    for (l = 0; l < k; l++){
      for (i = 1; i <= 5; i++){
        fprintf (manobras,"%c X %d\n", dado[l], i);
        fprintf (manobras, "Z Y %d\n", zi - 2);
        fprintf (manobras, "Z X %d\n", 4 - zj);

        fprintf (manobras,"%c Y %d\n", dado[l], i);
        fprintf (manobras, "Z Y %d\n", zi - 2);
        fprintf (manobras, "Z X %d\n", 4 - zj);

        fprintf (manobras,"%c X %d\n", dado[l], -i);
        fprintf (manobras, "Z Y %d\n", zi - 2);
        fprintf (manobras, "Z X %d\n", 4 - zj);

        fprintf (manobras,"%c Y %d\n", dado[l], -i);
        fprintf (manobras, "Z Y %d\n", zi - 2);
        fprintf (manobras, "Z X %d\n", 4 - zj);
      }
    }
    finalizaTempo(&t, &tempoU, &tempoS);
    printf ("Tempo usuario: %f, tempo de sistema: %f", tempoU, tempoS);
  }
