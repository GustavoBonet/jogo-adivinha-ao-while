#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  
  printf("\nJOGO DA ADIVINHAÇÃO\n\n");
  
  // aqui ele usa o tempo para pegar um numero aleatorio   
  int tempo = time(0);
  // pega um numero aleatorio do tempo
  srand (tempo);
  // coloca em uma variavel
  int numeroaleatorio = rand();
  // limita o numero aleatorio entre 1 e 99
  int numero_secreto = numeroaleatorio % 100;
  //variavel para guardar a resposta do jogador
  int chute;
  // variavel para entrar no while
  int ganhou = 0;
  // variavel para contar quantas vezes o jogador tentou
  int tentativas = 1;
  double pontos = 1000.0;
  
  // while(1) significa que o loop roda infinitamente ate ser parado pelo break
  while(1){
    printf("Digite um número:");
    scanf("%d",&chute);
    
    // verifica se o chute do jogador foi menor ou igual a zero e volta pro começo do while se entrar nessa       funçao
    if (chute < 0){
      printf("O chute tem que ser maior que 0, tente novamente...\n");
      continue;
    }
    //mostra quantas vezes o loop ja rodou
    printf("%d tentativas\n\n", tentativas);
    
    if (numero_secreto == chute){
      printf("Parabéns você acertou!\n\n");
      // o break sai do loop
      break;
    }else if (numero_secreto < chute){
      printf("O número secreto é menor\n");
    }else if (numero_secreto > chute){
      printf("O número secreto é maior\n");
    }
    // toda vez que ele passa aqui a variavel tentativas aumenta mais 1
    tentativas++;
    // a funçao abs transforma todo negativo em positivo
    double pontosperdidos = abs(chute - numero_secreto) / 2.0;
    pontos = pontos - pontosperdidos;
  }
  printf("Pontuação %.2f\n",pontos);
  printf("\nFIM DE JOGO");
  
  return 0;
}