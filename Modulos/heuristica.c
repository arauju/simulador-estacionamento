#include "registro.h"
#include "tempo.h"

int main (int argc, char **argv){

  FILE *entrada, *manobras;
  entrada = fopen (argv[1], "r");
  manobras = fopen (argv[2], "w");
  int i = 0, j, gi, gj, zi, zj, ci = 0, cj = 0, k = 0, s = 0, m, retorno;
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

  //leitura das entradas
  while (fscanf(entrada, "%c %d %c %c%d%c%d\n", &v.nome, &v.tamanho, &v.direcao, &v.p1, &v.p2, &v.p3, &v.p4) != EOF){
    if (v.direcao == 'X'){
      //verificacao de entrada invalida
      if (v.p2 < 1 || v.p2 > 5 || v.p4 < 1 || v.p2 > 6 || ((v.tamanho == 3) && (v.p2 > 4))){
      printf("Seguinte veículo inválido: %c %d %c %c%d%c%d\n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
      } else insereDX (matriz, v);
    }
    if (v.direcao == 'Y'){
      //verificacao de entrada invalida
      if (v.p4 < 1 || v.p4 > 5 || v.p2 < 1 || v.p2 > 6|| (v.tamanho == 3 && v.p4 > 4)){
        printf("Seguinte veículo inválido: %c %d %c %c%d%c%d\n", v.nome, v.tamanho, v.direcao, v.p1, v.p2, v.p3, v.p4);
      }
      else insereDY(matriz, v);
     }
   }

  /*            EXECUCAO DOS MOVIMENTOS           */

  for (i = 1; i <= 5; i++){
    if (matriz[2][4].nome != 'Z' && matriz[2][5].nome != 'Z'){
      retorno = encontraZ (matriz, &v);
      fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
      if (retorno != 0){
        if (v.direcao == 'X'){
          eixoXmovX (matriz, v, &ci, &cj);
        } else eixoXmovY (matriz, v, &ci, &cj);

        //movimenta a colisao em X positivamente, e depois verifica se Z pode movimentar à saída
        v.nome = matriz[ci][cj].nome;
        v.direcao = 'X';
        v.mov = i;

        //colisao está no eixo X
        if (matriz[ci][cj].direcao == 'X'){
          eixoXmovX(matriz, v, &ci, &cj);
          fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
          retorno = encontraZ(matriz, &v);
          fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
          if (retorno != 0){
            if (v.direcao == 'X'){
              eixoXmovX (matriz, v, &ci, &cj);
            } else eixoYmovX (matriz, v, &ci, &cj);
          }
        }

        //colisao está no eixo Y
        if (matriz[ci][cj].direcao == 'Y'){
          eixoYmovX(matriz, v, &ci, &cj);
          fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
          retorno = encontraZ(matriz, &v);
          fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
          if (retorno != 0){
            if (v.direcao == 'X'){
              eixoXmovX (matriz, v, &ci, &cj);
            } else eixoXmovY (matriz, v, &ci, &cj);
          }
        }

        //movimenta a colisao em Y positivamente, e depois verifica se Z pode movimentar à saída
        if (matriz[2][4].nome != 'Z' && matriz[2][5].nome != 'Z'){
          v.nome = matriz[ci][cj].nome;
          v.direcao = 'Y';
          v.mov = i;

          //colisao está em X
          if (matriz[ci][cj].direcao == 'X'){
            eixoXmovY(matriz, v, &ci, &cj);
            fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
            retorno = encontraZ(matriz, &v);
            fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
            if (retorno != 0){
              if (v.direcao == 'X'){
                eixoXmovX (matriz, v, &ci, &cj);
              } else eixoXmovY(matriz, v, &ci, &cj);
            }
          }

          //colisao está em Y
          if (matriz[ci][cj].direcao == 'Y'){
            eixoYmovY(matriz, v, &ci, &cj);
            fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
            retorno = encontraZ(matriz, &v);
            fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
            if (retorno != 0){
              if (v.direcao == 'X'){
                eixoXmovX (matriz, v, &ci, &cj);
              } else eixoXmovY(matriz, v, &ci, &cj);
            }
          }
        }

        //movimenta a colisao em X negativamente, e depois tenta movimentar Z á saída
        if (matriz[2][4].nome != 'Z' && matriz[2][5].nome != 'Z'){
            v.nome = matriz[ci][cj].nome;
            v.direcao = 'X';
            v.mov = -i;

            //colisão está no eixo X
            if (matriz[ci][cj].direcao == 'X'){
              eixoXmovX(matriz, v, &ci, &cj);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              retorno = encontraZ(matriz, &v);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              if (retorno != 0){
                if (v.direcao == 'X'){
                  eixoXmovX (matriz, v, &ci, &cj);
                } else eixoXmovY(matriz, v, &ci, &cj);
              }
            }

            //colisão está no eixo Y
            if (matriz[ci][cj].direcao == 'Y'){
              eixoYmovX(matriz, v, &ci, &cj);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              retorno = encontraZ(matriz, &v);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              if (retorno != 0){
                if (v.direcao == 'X'){
                  eixoXmovX (matriz, v, &ci, &cj);
                } else eixoXmovY(matriz, v, &ci, &cj);
              }
            }
          }

        //movimenta a colisao em Y negativamente, e depois tenta movimentar Z á saída
        if (matriz[2][4].nome != 'Z' && matriz[2][5].nome != 'Z'){
            v.nome = matriz[ci][cj].nome;
            v.direcao = 'Y';
            v.mov = -i;

            //colisão está no eixo X
            if (matriz[ci][cj].direcao == 'X'){
              eixoXmovY(matriz, v, &ci, &cj);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              retorno = encontraZ(matriz, &v);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              if (retorno != 0){
                if (v.direcao == 'X'){
                  eixoXmovX (matriz, v, &ci, &cj);
                } else eixoXmovY(matriz, v, &ci, &cj);
              }
            }

            //colisão está no eixo Y
            if (matriz[ci][cj].direcao == 'Y'){
              eixoYmovY(matriz, v, &ci, &cj);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              retorno = encontraZ(matriz, &v);
              fprintf (manobras, "%c %c %d\n", v.nome, v.direcao, v.mov);
              if (retorno != 0){
                if (v.direcao == 'X'){
                  eixoXmovX (matriz, v, &ci, &cj);
                } else eixoXmovY(matriz, v, &ci, &cj);
              }
            }
        }
      }
    }
  }
  finalizaTempo(&t, &tempoU, &tempoS);
  //printf ("Tempo usuario: %f, tempo de sistema: %f", tempoU, tempoS);
}
