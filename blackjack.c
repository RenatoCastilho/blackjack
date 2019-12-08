#include <stdio.h>
#include "baralho.h"
#include "jogador.h"

int main(int argc, char const *argv[])
{
	// Iniciando variaveis do programa
	char nome[100], resposta;
	int aposta;
	Jogador dealer, jogador;
	Baralho baralho;

	// lendo e atribuindo baralho
	baralho = leituraBaralho();
	
	// atribuindo valores de jogadores
	dealer = initJogador("Dealer");
	printf("Digite seu nome:\n");
	scanf("%s", nome);
	jogador = initJogador(nome);

	//Loop de Partida
	do
	{
		int pontos_jogador, pontos_dealer;	// inicializando variaveis de escopo da partida

		// Turno do jogador
		printf("Digite sua aposta:\n");	// lendo valor da aposta e
		scanf("%d", &aposta);
		initPartida(&jogador, aposta);	// iniciando turno do jogador
		imprimeJogador(jogador);
		do
		{
			somaPonto(&jogador, sorteiaCarta(&baralho));	// comprando uma carta e atribuindo pontos ao jogador

			pontos_jogador = retornaPonto(jogador);	// armazenando pontuacao do jogador
			if(pontos_jogador < 21)	// caso os pontos não sejam iguais ou maiores que 21,
			{
				printf("Deseja continuar (S/N):\n");	// perguntar se o jogador quer comprar mais cartas
				scanf(" %c", &resposta);
			}			
		}while(pontos_jogador < 21 && resposta == 'S');
		
		// caso a pontuacao do jogador seja maior ou igual a 21, o jogo nao precisa continuar
		if (pontos_jogador >= 21)
		{
			if (pontos_jogador == 21) vitoria(&jogador); // caso a pontuacao seja 21, o jogador venceu
			else derrota(&jogador); // caso contrario, excedeu 21 e ele perdeu
		}
		// caso contrario, o Dealer tem a oportunidade de vencer
		else
		{
			//Turno do dealer
			initPartida(&dealer,aposta);
			imprimeJogador(dealer);
			do
			{
				somaPonto(&dealer, sorteiaCarta(&baralho));	// comprando uma carta e atribuindo pontos ao dealer
				pontos_dealer = retornaPonto(dealer);	// armazenando pontuacao do dealer
			}while(pontos_dealer < 17);

			// caso a pontuacao do dealer seja maior ou igual a 21, nao precisa haver comparacao de pontos
			if (pontos_dealer >= 21)
			{
				if (pontos_dealer == 21) derrota(&jogador); // caso a pontuacao seja 21, o dealer venceu
				else vitoria(&jogador);	// caso contrario, excedeu 21 e ele perdeu
			}
			// caso contrario, as pontuacoes precisam ser comparadas para que seja definido o vencedor
			else
			{
				if (pontos_jogador < pontos_dealer) derrota(&jogador); // o jogador perde caso seus pontos sejam menores
				else vitoria(&jogador); // caso contrario, ele vence
			}
		}
		printf("Deseja fazer nova aposta (S/N):\n"); // perguntando se o jogador quer continuar apostando
		scanf(" %c", &resposta);
	}while(resposta == 'S');

	imprimeResultado(jogador); // imprimindo resultado final do jogo
	
	return 0;
}
