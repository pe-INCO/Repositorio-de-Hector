/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 13/04/2026
Programa de Ordenamiento Quick Sort
*/

#include <stdio.h>

// 1. La función que intercambia dos números

void intercambiar(int *a, int *b) {
    int temp = *a; // Guardamos el valor de 'a' en una variable temporal
    *a = *b;       // Ponemos el valor de 'b' en donde estaba 'a'
    *b = temp;     // Ponemos el valor guardado en 'temp' dentro de 'b'
}

// 2. La función que organiza el arreglo alrededor del pivote
int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; // Elegimos el último elemento como pivote
    int i = (bajo - 1);    // Índice para mover los elementos menores

    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1); // Esta es la posición donde quedó el pivote
}

// 3. La función que divide y llama a sí misma (recursividad)
void ordenar(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int indicePivote = particion(arr, bajo, alto);
        
        // Ordenamos la parte izquierda del pivote
        ordenar(arr, bajo, indicePivote - 1);
        // Ordenamos la parte derecha del pivote
        ordenar(arr, indicePivote + 1, alto);
    }
}

int main() {
    int miArreglo[] = {10, 3, 7, 1, 9}; // Arreglo cualquiera
    int n = 5; // Tamaño del arreglo

    printf("Arreglo antes de ordenar: ");
    for(int i=0; i<n; i++) printf("%d ", miArreglo[i]);

    // Llamamos a la función pasándole el inicio (0) y el final (n-1)
    ordenar(miArreglo, 0, n - 1);

    printf("\nArreglo ordenado: ");
    for(int i=0; i<n; i++) printf("%d ", miArreglo[i]);
    
    return 0;
}