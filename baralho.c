#include <stdio.h>
#include "baralho.h"

// le os valores das 52 cartas dados pela entrada padrão, alimenta o baralho e retorna
Baralho leituraBaralho(){

	char lixo, naipe, digito;
	int valor;
	Baralho baralho;
	Carta carta;

	baralho.posicao = 0;
	for(int i=0; i < TAM_BARALHO; i++)
	{
		scanf(" %c%c%c", &digito, &carta.naipe, &lixo);
		if(digito == 'A')
		{
			carta.valor = 1;
		}
		else if(digito == '0' || digito =='J' || digito =='Q' || digito =='K')
		{
			carta.valor = 10;
		}
		else
		{
			carta.valor = (int)digito-(int)'0'; 
		}
		baralho.cartas[i] = carta;
	}
	return baralho;
}

// retorna o valor da proxima carta do deck
int sorteiaCarta(Baralho *b){
	int valor = b->cartas[b->posicao].valor;
	printf("Carta: %d-%c\n", valor, b->cartas[b->posicao].naipe);
	b->posicao++;
	return valor;
}