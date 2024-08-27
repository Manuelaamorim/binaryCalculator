/*
 * Nome: Manuela Cavalcanti
 * Turma: CC 3A - 2024.2
 * Email: mca2@cesar.school
 * Data de Criação: 24/08/2024
 * 
 * Revisões/Atualizações:
 *  - 24/08/2024 11:00: Criado o arquivo e repositório git
 *  - 24/08/2024 13:30: Implementação da Questão 01 finalizada e commit no github
 * '- 24/08/2024 19;40: Implementação da Questão 02 e commit no github
 *  - 26/08/2024 14:30 - 17:10: Implementação da Questão 03 e commit no github
 * -  26/08/2024 22:00: Ajustes finais da didática para manter o padrão entre funções.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void complementoADois(double numero, int *bin, int *i){
  int conversao[16];
    int soma = 1;

    for (int j = 0; j < 16 - *i; j++) {
        conversao[j] = 0;
    }
    
    for (int j = 0; j < *i; j++) {
        conversao[16 - *i + j] = bin[j];
    }

    printf("\nPasso 3: Inverter os bits para obter o complemento a um.\n");
    for (int j = 0; j < 16; j++) {
        conversao[j] = conversao[j] == 0 ? 1 : 0;
    }

    printf("\nPasso 4: Adicionar 1 para obter o complemento a dois.\n");
    for (int l = 15; l >= 0; l--) {
        if (conversao[l] == 1 && soma == 1) {
            conversao[l] = 0;
            soma = 1; 
        } else {
            conversao[l] += soma;
            soma = 0;
        }
    }

    printf("%.1f em complemento a dois =  ", numero);
    for (int k = 0; k < 16; k++) {
        printf("%d", conversao[k]);
    }
    printf("\n");
}

void baseDois(double numero, int *i, int *bin, int resultado) {
    printf("Passo 1: Converter a parte inteira do numero para binario.\n\n");
    
    while (resultado != 0) {
        printf("Dividindo %d por 2:\n", resultado);
        bin[*i] = resultado % 2;
        printf("Resto = %d\n", bin[*i]);
        resultado = resultado / 2;
        printf("Quociente = %d\n\n", resultado);
        (*i)++;
    }

    printf("Parte inteira em binario (antes de inverter): ");
    if (numero < 0){
        for (int j = 0; j < *i; j++) {
            printf("%d", bin[j] * -1);
        }
    }
    else{
        for (int j = 0; j < *i; j++) {
            printf("%d", bin[j]);
        }
    } 
    printf("\n\n");

    printf("Passo 2: Inverter a parte inteira para obter a representacao correta.\n");
    for (int j = 0; j < (*i) / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }

    printf("%.1f em base 2 = ", numero);
    if (numero == 0) {
        printf("0");
    }
    else if(numero < 0){
        for (int k = 0; k < *i; k++) {
            printf("%d", bin[k] * (-1));
        }
    } else {
        for (int k = 0; k < *i; k++) {
            printf("%d", bin[k]);
        }
    }
    printf("\n\n");
}

void Octal(double numero,int i, int *bin, int resultado){

    printf("Passo 1: Converter a parte inteira do numero para base 8.\n");

    while (resultado != 0) {
        printf("Dividindo %d por 8:\n", resultado);
        bin[i] = resultado % 8;
        printf("Resto = %d\n", bin[i]);
        resultado = resultado / 8;
        printf("Quociente = %d\n\n", resultado);
        i++;
    }

    printf("Parte inteira em base 8 (antes de inverter): ");
    for (int j = 0; j < i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n\n");

    printf("Passo 2: Inverter a parte inteira para obter a representacao correta.\n");
    for (int j = 0; j < i / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    printf("%.1f em base 8 = ", numero);
    if (numero == 0) {
        printf("0");
    } else {
        for (int k = 0; k < i; k++) {
            printf("%d", bin[k]);
        }
    }
    printf("\n");
}

void Hexa(double numero, int i, int *bin, int resultado) {
    printf("Passo 1: Converter a parte inteira do numero para base 16.\n");

    while (resultado != 0) {
        printf("Dividindo %d por 16:\n", resultado);
        bin[i] = resultado % 16;
        printf("Resto = %d\n", bin[i]);
        resultado = resultado / 16;
        printf("Quociente = %d\n\n", resultado);
        i++;
    }

    printf("Parte inteira em base 16 (antes de inverter): ");
    for (int j = 0; j < i; j++) {
        printf("%d", bin[j]); 
    }
    printf("\n\n");

    printf("Passo 2: Inverter a parte inteira para obter a representacao correta.\n");
    for (int j = 0; j < i / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    printf("%.1f em base 16 = ", numero);
    if (numero == 0) {
        printf("0");
    } else {
        for (int k = 0; k < i; k++) {
            printf("%X", bin[k]);
        }
    }
    printf("\n");
}

void codigoBcd(double numero){
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
    printf("Passo 1: Separar cada digito do numero.\n");
    int split[10];
    int digito = numero;
    int i = 0;
    while (digito > 0){
        split[i] = digito % 10;
        digito = digito / 10;
        i++;
    }

    printf("Digitos separados: ");
    for (int j = 0; j < i; j++) {
        printf("%d\n", split[j]);
    }
    printf("\n");
    printf("Passo 2: Inverter os digitos para obter a representacao correta.\n");
    for (int j = 0; j < i / 2; j++){
        int temp = split[j];
        split[j] = split[i - j - 1];
        split[i - j - 1] = temp;
    }
    
    printf("%.1f em codigo BCD = ", numero);
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

void conversaoFloat(double numero, int *i, int *bin, int resultado) {
    int parte_inteira;
    double parte_fracionaria;
    int armazena_fracao[24] = {0};
    int k = 0, cont = 1, expoente = 0, sinal;

    if (numero > 0){
        sinal = 0;
    }
    else{
        sinal = 1;
    }
    
    printf("Passo 1: Determinar o sinal do numero.\n");
    printf("Numero original: %lf\n", numero);
    printf("Sinal: %d (0 para positivo, 1 para negativo)\n", sinal);

    if (sinal) {
        numero = -numero;
    }

    parte_inteira = (int)numero;
    parte_fracionaria = numero - parte_inteira;

    printf("\nPasso 2: Separar a parte inteira da parte fracionaria.\n");
    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte fracionaria: %lf\n", parte_fracionaria);

    printf("\nPasso 3: Converter a parte fracionaria para binario.\n");

    while (parte_fracionaria != 0 && cont <= 23) {
        printf("Multiplicacao: %lf x 2 = ", parte_fracionaria);
        parte_fracionaria = parte_fracionaria * 2;

        printf("%lf, ", parte_fracionaria);
        armazena_fracao[k] = (int)parte_fracionaria;

        printf("Parte inteira extraida: %d, ", armazena_fracao[k]);
        parte_fracionaria = parte_fracionaria - armazena_fracao[k];
        printf("Nova parte fracionaria: %lf\n", parte_fracionaria);

        k++;
        cont++;
    }

    printf("\nPasso 4: Converter a parte inteira do numero para binario.\n");

    while (resultado != 0) {
        printf("Dividindo %d por 2:\n", resultado);
        bin[*i] = resultado % 2;
        printf("Resto = %d\n", bin[*i]);
        resultado = resultado / 2;
        printf("Quociente = %d\n\n", resultado);
        (*i)++;
    }

    for (int j = 0; j < (*i) / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }

    printf("Parte inteira em binario (invertida): ");

    for (int j = 0; j < *i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n");

    if (*i > 0) {
        expoente = (*i) - 1; 
    } else {
        printf("\nPasso 5: Calculo de expoente:\n");
        while (parte_fracionaria < 1 && parte_fracionaria > 0) {
            parte_fracionaria *= 2;
            expoente--;
            printf("Multiplicando a parte fracionaria por 2: %lf, novo expoente: %d\n", parte_fracionaria, expoente);
        }
    }
    printf("Expoente calculado: %d\n", expoente);
    int expoente_com_vies = expoente + 127;
    printf("Expoente com vies: %d\n", expoente_com_vies);
    
    printf("Mantissa: ");
    int mantissa_index = 0;
    
    for (int j = 1; j < *i; j++) {
        printf("%d", bin[j]);
        mantissa_index++;
    }
    
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    
    while (mantissa_index < 23) {
        printf("0");
        mantissa_index++;
    }
    
    printf("\n");

    printf("Representacao binaria final (IEEE 754 float) = ");
    printf("%d ", sinal); 
    for (int j = 7; j >= 0; j--) {
        printf("%d", (expoente_com_vies >> j) & 1); 
    }
    printf(" ");
    mantissa_index = 0;  
    for (int j = 1; j < *i; j++) {  
        printf("%d", bin[j]);
        mantissa_index++;
    }
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    while (mantissa_index < 23) {
        printf("0");
        mantissa_index++;
    }
    printf("\n");
}

void conversaoDouble(double numero, int *i, int *bin, int resultado) {
    int parte_inteira;
    double parte_fracionaria;
    int armazena_fracao[53] = {0};
    int k = 0, cont = 1, expoente = 0, sinal;

    if (numero > 0){
        sinal = 0;
    }
    else{
        sinal = 1;
    }

    if (sinal) {
        numero = -numero;
    }

    printf("Passo 1: Determinar o sinal do numero.\n");
    printf("Numero original: %lf\n", numero);
    printf("Sinal: %d (0 para positivo, 1 para negativo)\n", sinal);

    parte_inteira = (int)numero;
    parte_fracionaria = numero - parte_inteira;

    printf("\nPasso 2: Separar a parte inteira da parte fracionaria.\n");
    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte fracionaria: %lf\n", parte_fracionaria);

    printf("\nPasso 3: Converter a parte fracionaria para binario.\n");
    while (parte_fracionaria != 0 && cont <= 52) {
        printf("Multiplicacao: %lf x 2 = ", parte_fracionaria);
        parte_fracionaria = parte_fracionaria * 2;

        printf("%lf, ", parte_fracionaria);
        armazena_fracao[k] = (int)parte_fracionaria;

        printf("Parte inteira extraida: %d, ", armazena_fracao[k]);
        parte_fracionaria = parte_fracionaria - armazena_fracao[k];
        printf("Nova parte fracionaria: %lf\n", parte_fracionaria);
        k++;
        cont++;
    }

    printf("\nPasso 4: Converter a parte inteira do numero para binario.\n");

    while (resultado != 0) {
        printf("Dividindo %d por 2:\n", resultado);
        bin[*i] = resultado % 2;
        printf("Resto = %d\n", bin[*i]);
        resultado = resultado / 2;
        printf("Quociente = %d\n\n", resultado);
        (*i)++;
    }

    for (int j = 0; j < (*i) / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[(*i) - j - 1];
        bin[(*i) - j - 1] = temp;
    }

    printf("Parte inteira em binario (invertida): ");

    for (int j = 0; j < *i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n");

    if (*i > 0) {
        expoente = (*i) - 1; 
    } else {
        printf("\nPasso 5: Calculo de expoente:\n");
        while (parte_fracionaria < 1 && parte_fracionaria > 0) {
            parte_fracionaria *= 2;
            expoente--;
            printf("Multiplicando a parte fracionaria por 2: %lf, novo expoente: %d\n", parte_fracionaria, expoente);
        }
    }
    printf("Expoente calculado: %d\n", expoente);

    int expoente_com_vies = expoente + 1023;
    printf("Expoente com vies: %d\n", expoente_com_vies);


    printf("Mantissa: ");
    int mantissa_index = 0;

    for (int j = 1; j < *i; j++) {
        printf("%d", bin[j]);
        mantissa_index++;
    }

    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }

    while (mantissa_index < 52) {
        printf("0");
        mantissa_index++;
    }
    
    printf("\n");

    printf("Representacao binaria final (IEEE 754 double):\n");
    printf("%d ", sinal); 
    for (int j = 10; j >= 0; j--) {
        printf("%d", (expoente_com_vies >> j) & 1);  
    }
    printf(" ");
    mantissa_index = 0;  
    for (int j = 1; j < *i; j++) { 
        printf("%d", bin[j]);
        mantissa_index++;
    }
    for (int j = 0; j < k; j++) {
        printf("%d", armazena_fracao[j]);
        mantissa_index++;
    }
    while (mantissa_index < 52) {
        printf("0");
        mantissa_index++;
    }
    printf("\n");
}

int main() {

    double numero;
    int bin[30];
    int i = 0;
    int opcao = 0;

    printf("======CALCULADORA DE CONVERSAO======\n\n\n");
    printf("Digite o decimal:\n");

    scanf("%lf", &numero);
    int resultado = numero;

    printf("1 - Converter decimal para base 2\n");
    printf("2 - Converter decimal para base 8\n");
    printf("3 - Converter decimal para base 16\n");
    printf("4 - Converter decimal para codigo BCD\n");
    printf("5 - Complemento a dois com 16 bits\n");
    printf("6 - Converter para float\n");
    printf("7 - Converter para double\n");
    printf("\n\nDigite a opcao de conversao: ");
    scanf("%d", &opcao);
    system("cls");
    

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
    else if(opcao == 6){
        conversaoFloat(numero, &i, bin, resultado);
    }
    else if(opcao == 7){
        conversaoDouble(numero, &i, bin, resultado);
    }
    else{
        printf("Opção invalida.");
    }
}