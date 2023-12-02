#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numero_romano_decimal(char roman[]) {
    int i, decimal = 0, prev_value = 0;
    int len = strlen(roman);

    int numeros_romanos[26];
    numeros_romanos['I' - 'A'] = 1;
    numeros_romanos['V' - 'A'] = 5;
    numeros_romanos['X' - 'A'] = 10;
    numeros_romanos['L' - 'A'] = 50;
    numeros_romanos['C' - 'A'] = 100;
    numeros_romanos['D' - 'A'] = 500;
    numeros_romanos['M' - 'A'] = 1000;

    for (i = len - 1; i >= 0; i--) {
        int value = numeros_romanos[roman[i] - 'A'];
        if (value < prev_value) {
            decimal -= value;
        } else {
            decimal += value;
        }
        prev_value = value;
    }

    return decimal;
}

void decimal_binario(int decimal, char binario[]) {
    itoa(decimal, binario, 2);
}

void decimal_hexadecimal(int decimal, char hexadecimal[]) {
    char temp[5];
    sprintf(temp, "%X", decimal);

    for (int i = 0; temp[i]; i++) {
        if (temp[i] >= 'A' && temp[i] <= 'F') {
            temp[i] += 32;
        }
    }

    strcpy(hexadecimal, temp);

}

int main() {

    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int numeroDecimal = numero_romano_decimal(numeroRomano);

    char numeroBinario[33];
    char numeroHexadecimal[5];

    decimal_binario(numeroDecimal, numeroBinario);
    decimal_hexadecimal(numeroDecimal, numeroHexadecimal);

    printf("%s na base 2: %s\n", numeroRomano, numeroBinario);
    printf("%s na base 10: %d\n", numeroRomano, numeroDecimal);
    printf("%s na base 16: %s\n", numeroRomano, numeroHexadecimal);

    return 0;
}