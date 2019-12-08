#include <stdio.h>
#define TAM_BARALHO 52

typedef struct carta {
	char naipe;
	int valor;
} Carta;

typedef struct baralho {
	Carta cartas[TAM_BARALHO];
	int posicao;
} Baralho;

// le os valores das 52 cartas dados pela entrada padrão
Baralho leituraBaralho();

// retorna a proxima carta do deck
int sorteiaCarta(Baralho *b);