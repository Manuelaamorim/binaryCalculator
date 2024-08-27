/*
 * Nome: Manuela Cavalcanti
 * Email: mca2@cesar.school
 * Data de Criação: 24/08/2024
 * 
 * Revisões/Atualizações:
 *  - 24/08/2024 11:00: Criado o arquivo e repositório git
 *  - 24/08/2024 13:30: Implementação da Questão 01 finalizada e commit no github
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void baseDois(int numero, int *i, int *bin, int resultado){

    while (resultado != 0){   
        bin[*i] = resultado % 2;
        resultado = resultado / 2;
        (*i)++;
    }

    for (int j = 0; j < (*i) / 2; j++){
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }
    printf("%d em base 2 = ", numero);
    if (numero == 0){
        printf("0");
    }

    for (int k = 0; k < (*i); k++){
        printf("%d", bin[k]);
    }
}

void Octal(int numero,int i, int *bin, int resultado){

    while (resultado != 0){   
        bin[i] = resultado % 8;
        resultado = resultado / 8;
        i++;
    }

    for (int j = 0; j < i / 2; j++){
        int temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }
    printf("%d em base 8 = ", numero);
    if (numero == 0){
        printf("0");
    }

    for (int k = 0; k < i; k++){
        printf("%d", bin[k]);
    }
}

void Hexa(int numero, int i, int *bin, int resultado){

    while (resultado != 0){   
        bin[i] = resultado % 16;
        resultado = resultado / 16;
        i++;
    }

    for (int j = 0; j < i / 2; j++){
        int temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }
    printf("%d em base 16 = ", numero);
    if (numero == 0){
        printf("0");
    }

    for (int k = 0; k < i; k++){
        printf("%d", bin[k]);
    }
}

void codigoBcd(int numero){
    const char bin[10][4] = {
        "0000",
        "0001",
        "0010",
        "0011",
        "0100",
        "0101",
        "0110",
        "0111",
        "1000",
        "1001"
    };

    int split[10];
    int digito = numero;
    int i = 0;
    while (digito > 0){
        split[i] = digito % 10;
        digito = digito / 10;
        i++;
    }

    for (int j = 0; j < i / 2; j++){
        int temp = split[j];
        split[j] = split[i - j - 1];
        split[i - j - 1] = temp;
    }

    printf("%d em codigo BCD = ", numero);
    if (numero == 0){
        printf("0");
    }

    for (int k = 0; k < i; k++){
        for (int l = 0; l < 10; l++){
            for (int p = 0; p < 4; p++){
                if (split[k] == l){
                    printf("%c", bin[l][p]);
                }     
            }  
        }  
    }    
}
int main() {

    int numero;
    int bin[30];
    int i = 0;
    int opcao = 0;

    printf("======CALCULADORA DE CONVERSAO======\n\n\n");
    printf("Digite o numero a ser convertido:\n");

    scanf("%d", &numero);
    int resultado = numero;

    printf("\n1 - converter decimal para base 2\n");
    printf("2 - converter decimal para base 8\n");
    printf("3 - converter decimal para base 16\n");
    printf("4 - converter decimal para codigo BCD\n");

    printf("Digite a opcao de conversao:\n");
    scanf("%d", &opcao);

    if (opcao == 1){
        baseDois(numero, &i, bin, resultado);
    }
    else if (opcao == 2){
        Octal(numero, i, bin, resultado);
    }
    else if (opcao == 3){
        Hexa(numero, i, bin, resultado);
    }
    else if (opcao == 4){
        codigoBcd(numero);   
    }
}