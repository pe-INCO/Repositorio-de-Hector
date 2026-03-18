/*
Nombre: Hector
Codigo: 222621939
Fecha: 18/03/2026
Programa de Gestión de Arreglos 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrarMenu();

int main() {
    int opcion;
    int arreglo[10]; 
    int tam = 0; // 'tam' lleva el conteo REAL de cuántos números hay guardados

    do {
        mostrarMenu();
        
        // Validación de entrada para el menú
        if (scanf("%d", &opcion) != 1) {
            printf("\n>>> Error: Ingresa un numero valido (1-6).\n");
            while (getchar() != '\n'); 
            opcion = 0;
            continue; 
        }

        switch (opcion) {
            case 1: // Inicializar con aleatorios
                srand(time(NULL)); 
                for (int i = 0; i < 5; i++) {
                    arreglo[i] = rand() % 100;
                }
                tam = 5; 
                printf("\n[OK] Arreglo inicializado con 5 valores aleatorios.\n");
                break;

            case 2: // Mostrar arreglo
                if (tam == 0) {
                    printf("\n[!] El arreglo esta vacio actualmente.\n");
                } else {
                    printf("\n--- Contenido del Arreglo (Total: %d) ---\n", tam);
                    for (int i = 0; i < tam; i++) {
                        printf("Indice [%d]: %d\n", i, arreglo[i]);
                    }
                }
                break;

            case 3: // Agregar al final
                if (tam < 10) {
                    printf("\nIngrese el valor a agregar: ");
                    scanf("%d", &arreglo[tam]);
                    tam++; // El nuevo elemento ocupa el índice que antes era el 'tam'
                    printf("[OK] Elemento guardado al final.\n");
                } else {
                    printf("\n[!] Error: El arreglo esta lleno (Max 10).\n");
                }
                break;

            case 4: // Insertar en posición específica
                if (tam < 10) {
                    int pos, valor;
                    printf("\n¿En que indice quieres insertar? (0 a %d): ", tam);
                    scanf("%d", &pos);

                    if (pos >= 0 && pos <= tam) {
                        printf("Ingresa el valor: ");
                        scanf("%d", &valor);

                        // RECORRIDO A LA DERECHA: Empezamos desde el final
                        for (int i = tam; i > pos; i--) {
                            arreglo[i] = arreglo[i - 1];
                        }
                        
                        arreglo[pos] = valor; // Ahora sí, insertamos en el hueco
                        tam++; // Aumentamos el conteo total
                        printf("[OK] Elemento insertado en el indice %d.\n", pos);
                    } else {
                        printf("\n[!] Error: Posicion fuera de rango.\n");
                    }
                } else {
                    printf("\n[!] Error: Arreglo lleno.\n");
                }
                break;

            case 5: // Eliminar por posición
                if (tam > 0) {
                    int pos;
                    printf("\n¿Indice del elemento a eliminar? (0 a %d): ", tam - 1);
                    scanf("%d", &pos);

                    if (pos >= 0 && pos < tam) {
                        // RECORRIDO A LA IZQUIERDA: Tapamos el hueco
                        for (int i = pos; i < tam - 1; i++) {
                            arreglo[i] = arreglo[i + 1];
                        }
                        tam--; // Reducimos el conteo total
                        printf("[OK] Elemento eliminado correctamente.\n");
                    } else {
                        printf("\n[!] Error: Indice no existe.\n");
                    }
                } else {
                    printf("\n[!] El arreglo ya esta vacio.\n");
                }
                break;

            case 6:
                printf("\nSaliendo del programa. ¡Hasta pronto, Hector!\n");
                break;

            default:
                printf("\n[!] Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    printf("\n==============================");
    printf("\n      GESTOR DE ARREGLOS      ");
    printf("\n==============================");
    printf("\n1. Inicializar (5 aleatorios)");
    printf("\n2. Mostrar arreglo actual");
    printf("\n3. Agregar al final");
    printf("\n4. Insertar en posicion");
    printf("\n5. Eliminar posicion");
    printf("\n6. Salir");
    printf("\nOpcion: ");
}