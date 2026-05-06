#include <stdio.h>

int main() {
    char nombre[20];
    printf("¿Como te llamas, ingeniero? ");
    scanf("%s", nombre);
    printf("¡Perfecto, %s! Tu entorno de C esta al 100%%.\n", nombre);
    return 0;
}