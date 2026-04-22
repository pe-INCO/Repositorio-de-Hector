/*
-----------------------------------------------------------
Nombre: Héctor Leonardo Torres Campos
Codigo:222621939
Fecha:
Programa de 
------------------------------------------------------------
*/
#include <stdio.h>

int main() {
    int prod1, prod2;
    float total, promedio, precio1, precio2;

    printf("Cantidad de articulos del producto 1: ");
    scanf("%d", &prod1);

    printf("Cantidad de articulos del producto 2: ");
    scanf("%d", &prod2);

    printf("Ingresa el precio del producto 1: ");
    scanf("%f", &precio1);

    printf("Ingresa el precio del producto 2: ");
    scanf("%f", &precio2);

    total = (prod1 * precio1) + (prod2 * precio2);
    promedio = total / (prod1 + prod2);

    printf("\nEl total de la compra es: %.2f\n", total);
    printf("El promedio por articulo es: %.2f\n", promedio);

    getch();

    return 0;
}
    
   






