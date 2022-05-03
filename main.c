#include <stdio.h>
#include <stdlib.h>
#include "calcnum.h"

int main () {

    char comando = 0;

    do {
        printf("\n==== MENU ====\n");
        printf("'C' - Conversao\n'S' - Sistema Linear\n'E' - Equacao Algebrica\n'F' - Finalizar\n");
        printf("Digite a opcao desejada: ");
        scanf(" %c%*[^\n]", &comando); //limpa o buffer

        switch (comando)
        {
        case 'C':
            printf("vc escolheu conversao");
            conversao();
            break;
        
        case 'S':
            printf("vc escolheu sistema linear");
            sistemaLinear();
            break;

        case 'E':
            printf("vc escolheu equacao algebrica");
            eqAlgebrica();
            break;

        case 'F':
            printf("vc escolheu finalizar a aplicacao");
            break;

        default:
            printf("Opcao invalida, tente novamente.");
            break;
        }
    }
    while (comando != 'F');
    
}