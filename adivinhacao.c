#include <stdio.h> //Entrada e saida;
#include <stdlib.h>
#include <time.h>

int main(){
    printf("*********************************\n");
    printf(" Bem vindo ao jogo de adivinha? \n");
    printf("*********************************\n");

    int seg = time(0);
    srand(seg);
    int  numeroAleatorio = rand();

    int numeroSecreto = numeroAleatorio% 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) FÁCIL (2) MÉDIO (3) DIFÍCIL\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numTentativas;
    switch (nivel) {
        case 1 :
            numTentativas = 20;
            break;
        case 2:
            numTentativas = 15;
            break;
        default:
            numTentativas = 5;
            break;
    }
    for(int i = 1; i <= numTentativas; i++ ) {

        printf("\nTentativa %d\n", i);
        printf("Qual seu chute?");

        scanf("%d", &chute);
        printf("\nSeu chute foi : %d\n", chute);

        if(chute<0){
            printf("\nVocê nao pode chutar número negativos\n\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        int menor = chute < numeroSecreto;

        if(acertou) {
            printf("\n!Parabéns! você acertou!\n");
            printf("%d Tentativa(s) para acertar\n", tentativas);
            printf("Total de ponto: %.1f \n",pontos );
            printf("Fim de Jogo!\n");

            break;
        }

        else if(maior){
            printf("Foi maior que número secreto!\n");
        }
        else if(menor){
            printf("Foi menor que número secreto!\n");
        }

        tentativas ++;
        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;

        if(i == numTentativas){
            printf("\n\n       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");
            printf("Você perdeu! Tente de novo.\n");
        }
    }

}