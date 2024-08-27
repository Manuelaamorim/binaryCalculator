/*
 * Nome: Manuela Cavalcanti
 * Email: mca2@cesar.school
 * Data de Criação: 24/08/2024
 * 
 * Revisões/Atualizações:
 *  - 24/08/2024 11:00: Criado o arquivo e repositório git
 *  - 24/08/2024 13:30: Implementação da Questão 01 finalizada e commit no github
 * '- 24/08/2024 19;40: Implementação da Questão 02 e commit no github
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void complementoADois(int numero, int *bin, int *i){
    int aux = 16 - ((*i) + 1);
    int conversao[16];
    int soma = 1;

    for (int j = 0; j < 16 - *i; j++){
        conversao[j] = 0;
    }
    for (int j = 0; j < *i; j++){
        conversao[16 - *i + j] = bin[j];
    }

    printf("\n%d em complemento a dois = ", numero);    

    if (((*i) + 1) == 16){
        for (int k = 0; k < (*i); k++){
            printf("%d", bin[k]);
        }   
    }
    else{
        for (int j = 0; j < 16; j++){
            if (conversao[j] == 0){
                conversao[j] = 1;
            }
            else{
                conversao[j] = 0;
            }
        }

        for (int l = 0; l < 16; l++){
            if ((conversao[16 - l - 1] + soma) == 2){
                conversao[16 - l - 1] = 0;
                soma = 1;
            }
            else if ((conversao[16 - l - 1] + soma) == 1){
                conversao[16 - l - 1] = 1;
                soma = 0;
            }
            else{
                break;
            }
        }

        for (int k = 0; k < 16; k++){
            printf("%d", conversao[k]);
        }      
    }
}
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
    printf("5 - complemento a dois com 16 bits\n\n");

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
    else if(opcao == 5){
        baseDois(numero, &i, bin, resultado);
        complementoADois(numero, bin, &i);
    }
}