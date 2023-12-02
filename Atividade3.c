#include <stdio.h>
#include <string.h>
#include <ctype.h>

void converterParaMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char placa[10];
    char diaDaSemana[20];

    scanf("%s", placa);
    scanf("%s", diaDaSemana);

    int tamanhoPlaca = strlen(placa);

    if ((tamanhoPlaca == 7 || tamanhoPlaca == 8) &&
        isupper(placa[0]) && isupper(placa[1]) && isupper(placa[2]) &&
        ((tamanhoPlaca == 7 && isdigit(placa[3])) ||
         (tamanhoPlaca == 8 && placa[3] == '-' && isdigit(placa[4]))) &&
        isdigit(placa[tamanhoPlaca - 1])) {

        if (strcmp(diaDaSemana, "SEGUNDA-FEIRA") && strcmp(diaDaSemana, "TERCA-FEIRA") &&
            strcmp(diaDaSemana, "QUARTA-FEIRA") && strcmp(diaDaSemana, "QUINTA-FEIRA") &&
            strcmp(diaDaSemana, "SEXTA-FEIRA") && strcmp(diaDaSemana, "SABADO") &&
            strcmp(diaDaSemana, "DOMINGO")) {
            printf("Dia da semana invalido\n");
        } else {
            if (!strcmp(diaDaSemana, "SABADO") || !strcmp(diaDaSemana, "DOMINGO")) {
                printf("Nao ha proibicao no fim de semana\n");
            } else {
                int ultimoDigito = placa[tamanhoPlaca - 1] - '0';
                int podeCircular = 1;

                if ((ultimoDigito == 0 || ultimoDigito == 1) && !strcmp(diaDaSemana, "SEGUNDA-FEIRA")) podeCircular = 0;
                else if ((ultimoDigito == 2 || ultimoDigito == 3) && !strcmp(diaDaSemana, "TERCA-FEIRA")) podeCircular = 0;
                else if ((ultimoDigito == 4 || ultimoDigito == 5) && !strcmp(diaDaSemana, "QUARTA-FEIRA")) podeCircular = 0;
                else if ((ultimoDigito == 6 || ultimoDigito == 7) && !strcmp(diaDaSemana, "QUINTA-FEIRA")) podeCircular = 0;
                else if ((ultimoDigito == 8 || ultimoDigito == 9) && !strcmp(diaDaSemana, "SEXTA-FEIRA")) podeCircular = 0;

                converterParaMinusculas(diaDaSemana);

                if (podeCircular) {
                    printf("%s pode circular %s\n", placa, diaDaSemana);
                } else {
                    printf("%s nao pode circular %s\n", placa, diaDaSemana);
                }
            }
        }
    } else {
        printf("Placa invalida\n");

        if (strcmp(diaDaSemana, "SEGUNDA-FEIRA") && strcmp(diaDaSemana, "TERCA-FEIRA") &&
            strcmp(diaDaSemana, "QUARTA-FEIRA") && strcmp(diaDaSemana, "QUINTA-FEIRA") &&
            strcmp(diaDaSemana, "SEXTA-FEIRA") && strcmp(diaDaSemana, "SABADO") &&
            strcmp(diaDaSemana, "DOMINGO")) {
            printf("Dia da semana invalido\n");
        }
    }

    return 0;
}
