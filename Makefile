all: blackjack

blackjack: baralho.o jogador.o blackjack.c
	gcc blackjack.c -o blackjack baralho.o jogador.o

baralho.o: baralho.c
	gcc -c baralho.c

jogador.o: jogador.c
	gcc -c jogador.c

clean:
	rm *.o
