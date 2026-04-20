/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 20/04/2026
Programa de Matriz de Calificaciones - Versión Final
*/
#include <stdio.h>

int main() {
    int opcion;
    float calificaciones[3][4];
    int i, j;
    char nombres[3][50];
    
    float suma, promedio;
    float notaMax;

    do {
        printf("\n=============================================\n");
        printf("           MENU DE CALIFICACIONES            \n");
        printf("=============================================\n");
        printf("1. Ingresar Notas\n");
        printf("2. Mostrar matriz completa\n");
        printf("3. Calcular y mostrar promedio por estudiante\n");
        printf("4. Calcular y mostrar promedio por materia\n");
        printf("5. Encontrar la nota mas alta y su posicion\n");
        printf("6. Salir\n");
        printf("---------------------------------------------\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                for(i = 0; i < 3; i++) {
                    printf("\nNombre del estudiante %d: ", i + 1);
                    // El " %[^\n]" permite leer nombres con espacios (ej. Juan Pablo)
                    scanf(" %[^\n]", nombres[i]); 
                    
                    for (j = 0; j < 4; j++) {
                        printf("  Nota materia %d: ", j + 1);
                        scanf("%f", &calificaciones[i][j]);
                    }
                }
                printf("\n¡Datos guardados correctamente!\n");
                break;

            case 2:
                printf("\n%-20s\tM1\tM2\tM3\tM4\n", "Estudiante");
                printf("-------------------------------------------------------------\n");
                for (i = 0; i < 3; i++) {
                    printf("%-20s\t", nombres[i]);
                    for (j = 0; j < 4; j++) {
                        printf("%.1f\t", calificaciones[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\n--- PROMEDIOS POR ESTUDIANTE ---\n");
                for (i = 0; i < 3; i++) {
                    suma = 0;
                    for (j = 0; j < 4; j++) {
                        suma += calificaciones[i][j];
                    }
                    promedio = suma / 4;
                    printf("%-20s | Promedio: %.2f\n", nombres[i], promedio);
                }
                break;

            case 4: 
                printf("\n--- PROMEDIOS POR MATERIA ---\n");
                for (j = 0; j < 4; j++) {
                    suma = 0;
                    for (i = 0; i < 3; i++) {
                        suma += calificaciones[i][j];
                    }
                    promedio = suma / 3;
                    printf("Materia %d: %.2f\n", j + 1, promedio);
                }
                break;

            case 5: 
                // Buscamos el valor máximo global
                notaMax = calificaciones[0][0];
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        if (calificaciones[i][j] > notaMax) {
                            notaMax = calificaciones[i][j];
                        }
                    }
                }

                printf("\n>>> LA NOTA MAS ALTA ES: %.1f <<<\n", notaMax);
                printf("Localizada en:\n");
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        if (calificaciones[i][j] == notaMax) {
                            printf("- %s (Materia %d)\n", nombres[i], j + 1);
                        }
                    }
                }
                break;

            case 6: 
                printf("Cerrando el sistema...\n"); 
                break;

            default: 
                printf("Error: Opcion no valida.\n");
        }

        if(opcion != 6) {
            printf("\nPresiona Enter para continuar...");
            while(getchar() != '\n'); 
            getchar();               
        }
        
    } while(opcion != 6);

    return 0;
}