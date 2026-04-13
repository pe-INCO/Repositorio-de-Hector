/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 13/04/2026
Programa de Ordenamiento insertionSort
*/

#include <stdio.h>

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función principal de Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i]; // El elemento que vamos a insertar
        int j = i - 1;

        /* Mientras j sea mayor o igual a 0 y el elemento en j
           sea mayor que la clave, movemos el elemento una posición a la derecha */
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insertamos la clave en su posición correcta
        arr[j + 1] = clave;
    }
}

int main() {
    int miArreglo[] = {10, 3, 7, 1, 9};
    int n = 5;

    printf("Arreglo original: ");
    imprimirArreglo(miArreglo, n);

    insertionSort(miArreglo, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(miArreglo, n);

    return 0;
}
