#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct veiculo{
  char nome;
  int tamanho;
  char direcao;
  char p1, p3;
  int p2, p4;
  int mov;
}veiculos;

void limpa(veiculos matriz[][6], int i, int j);
void insereDX (veiculos matriz[][6], veiculos v);
void insereDY (veiculos matriz[][6], veiculos v);
void imprimeM (veiculos matriz[][6]);
int eixoXmovY (veiculos matriz[][6], veiculos v, int *ci, int *cj);
int eixoXmovX (veiculos matriz[][6], veiculos v, int *ci, int *cj);
int eixoYmovY (veiculos matriz[][6], veiculos v, int *ci, int *cj);
int eixoYmovX (veiculos matriz[][6], veiculos v, int *ci, int *cj);
void imenosv(veiculos matriz[][6], veiculos v, int i, int j);
void jmaisv(veiculos matriz[][6], veiculos v, int i, int j);
int encontraZ(veiculos matriz[][6], veiculos *v);

#endif
