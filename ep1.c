/*
INTEGRANTES DA EQUIPE:

ANA LIDIA LISBOA
GABRIEL FELICIANO
LETICIA SAMPAIO
MARINA BRASIL
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void conversao(double num);
void sistemaLinear();
void eqAlgebrica();

int main () {

    char comando = 0;
    double num_conv = 0.0;

    do {
        printf("\n\n==== MENU ====\n");
        printf("'C' - Conversao\n'S' - Sistema Linear\n'E' - Equacao Algebrica\n'F' - Finalizar\n");
        printf("Digite a opcao desejada: ");
        scanf(" %c%*[^\n]", &comando); // recebe o comando e limpa o buffer

        switch (comando)
        {
        case 'C':
            printf("insira o numero decimal para conversao: ");
            scanf("%lf", &num_conv);
            // printf("%lf\n", num_conv);
            conversao(num_conv);

            /*
            !!!ATENCAO!!!
            PRECISA MELHORAR A PRECISAO DO SCANF
            NÃO ESTA PEGANDO CASAS DECIMAIS DEPOIS DA 6ª
            */
            
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

void conversao(double num) {

    // --------------------------- CONVERSAO BINARIA --------------------------------//

    // vetor para salvar o numero binario
    int numBinarioInt[32]; // parte inteira do numero binario
    int numBinarioFrac[32]; // parte fracionaria do numero binario

    char isSigned = 0;

    if(num < 0.0) {
        isSigned = 1; 
        num = -num;
    }

    int n = (int)num;
    // printf("%d", n);
    double m = num - n;
    // printf("%lf", m);

    // conversao da parte inteira
    int i = 0; // armazena qtd de casas da parte inteira
    while (n > 0) {
        numBinarioInt[i] = n % 2; // salva resto da divisao por 2
        n = n / 2; // salva o resultado inteiro da divisao por 2
        i++; // aumenta contador para impressao ao final
    };
 
    // imprime a parte inteira em ordem inversa
    printf("Binario: ");
    if(isSigned) printf("-");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", numBinarioInt[j]);

    // testa se existe parte fracionaria antes de fazer a conversao
    int k = 0; // armazena qtd de casas da parte fracionaria
    if (m) {
        // conversao da parte fracionaria
        while (m > 0) {
            numBinarioFrac[k] = (int)(m *= 2); // salva a parte inteira da multiplicacao
            m = m - (int)m; // salva somente a parte fracionaria apos multiplicacao
            k++; // aumenta contador para impressao ao final 
        };
        printf(".");
        // imprime a parte fracionaria em ordem direta
        for (int l = 0; l < k && l < 20; l++)
            printf("%d", numBinarioFrac[l]);
    };


    // -------------------------- CONVERSAO OCTAL -----------------------------------//

    // vetor para salvar o numero octal
    int numOctalInt[32]; // parte inteira do numero octal
    int numOctalFrac[32]; // parte fracionaria do numero octal

    double div_int  = ceil(i/3.0); // encontra quantos conjuntos de 3 existem no inteiro
    double div_frac = ceil(k/3.0); // encontra quantos conjuntos de 3 existem na fracao

    n = (int)num;
    m = num - n;

    int j = 0;
    while(n) {
        numOctalInt[j++] = (n & 0b111);
        n >>= 3;
    }
    printf("\nOctal: ");
    if(isSigned) printf("-");
    for (j = div_int - 1; j >= 0; j--)
        printf("%d", numOctalInt[j]);

    j = 0;
    while(m && j < 20) {
        m *= 8;
        numOctalFrac[j++] = (int)m;
        m = m - (int)m;
    } 
    printf(".");

    for (j = 0; j < div_frac; j++)
        printf("%d", numOctalFrac[j]);


    // ----------------------- CONVERSAO HEXADECIMAL --------------------------------//

    // vetor para salvar o numero octal
    int numHexaInt[32]; // parte inteira do numero hexadecimal
    int numHexaFrac[32]; // parte fracionaria do numero hexadecimal

    div_int  = ceil(i/4.0); // encontra quantos conjuntos de 4 existem no inteiro
    div_frac = ceil(k/4.0); // encontra quantos conjuntos de 4 existem na fracao

    n = (int)num;
    m = num - n;

    int q = 0;
    while(n) {
        numHexaInt[q++] = (n & 0b1111);
        n >>= 4;
    }
    printf("\nHexadecimal: ");
    if(isSigned) printf("-");
    for (q = div_int - 1; q >= 0; q--)
        printf("%X", numHexaInt[q]);

    q = 0;
    while(m && q < 20) {
        m *= 16;
        numHexaFrac[q++] = (int)m;
        m = m - (int)m;
    } 
    printf(".");

    for (q = 0; q < div_frac; q++)
        printf("%X", numHexaFrac[q]);
    
};

void sistemaLinear() {
    printf("teste2");
};

void eqAlgebrica() {
    printf("teste3");
};