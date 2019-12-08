#include <stdio.h>
#include <string.h>
#include "jogador.h"


// incializa um jogador, dado o seu nome
Jogador initJogador(char *nome)
{
	Jogador jogador;

	jogador.pont = 0;
	jogador.aposta = 0;
	jogador.total = 0;
	strcpy(jogador.nome, nome); 

	return jogador;
}

// atualiza o valor da aposta no inicio de uma partida
void initPartida(Jogador *j, int aposta)
{
	j->aposta = aposta;
	j->pont = 0;
}

// impreme na tela no nome de um jogador
void imprimeJogador(Jogador j)
{
	printf("%s\n", j.nome);
}

// adiciona o valor de uma carta à pontuacao do jogador
void somaPonto(Jogador *j, int valor)
{
	j->pont += valor;
}

// retorna o valor da pontuacao do jogador
int retornaPonto(Jogador j)
{
	return j.pont;
}

// imprime na tela o valor ganho ou perdido pelo jogador
void imprimeResultado(Jogador j)
{
	if(j.total < 0)
	{
		printf("%s, voce perdeu %d reais.\n", j.nome, (-1)*j.total);
	}
	else
	{
		printf("%s, voce ganhou %d reais.\n", j.nome, j.total);
	}
	
}

// atualiza o total de dinheiro do jogador e imprime na tela que ele ganhou
void vitoria(Jogador *j)
{
	j->total += j->aposta;
	printf("Voce ganhou!\n");
}

// atualiza o total de dinheiro do jogador e imprime na tela que ele perdeu
void derrota(Jogador *j)
{
	j->total -= j->aposta;
	printf("Voce perdeu!\n");
}