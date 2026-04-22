/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 16/04/2026
Programa de Fifo-Lifo
*/
#include <stdio.h>

int main() {
    int ArregloPila[5], ArregloCola[5];
    int tope = -1; // Para Pila
    int frente = 0, final = 0; // Para Cola
    int opcion;

    do {
        printf("\n=================================\n");
        printf("      MENU: PILA Y COLA          \n");
        printf("=================================\n");
        printf("1. Pila: Encolar (Push)\n");
        printf("2. Pila: Desencolar (Pop)\n");
        printf("3. Cola: Encolar\n");
        printf("4. Cola: Desencolar\n");
        printf("5. Mostrar Estado\n");
        printf("6. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            // --- OPERACIONES PILA (LIFO) ---
            case 1: // Pila Push
                if(tope < 4) {
                    tope++;
                    printf("Ingrese numero para Pila: ");
                    scanf("%d", &ArregloPila[tope]);
                } else printf("Pila llena.\n");
                break;
            case 2: // Pila Pop
                if(tope >= 0) printf("Pila, sacado: %d\n", ArregloPila[tope--]);
                else printf("Pila vacia.\n");
                break;

            // --- OPERACIONES COLA (FIFO) ---
            case 3: // Cola Encolar
                if(final < 5) {
                    printf("Ingrese numero para Cola: ");
                    scanf("%d", &ArregloCola[final++]);
                } else printf("Cola llena.\n");
                break;
            case 4: // Cola Desencolar
                if(frente < final) printf("Cola, sacado: %d\n", ArregloCola[frente++]);
                else printf("Cola vacia.\n");
                break;

            case 5: // Mostrar ambos
                printf("\nPila: ");
                for(int i=0; i<=tope; i++) printf("%d ", ArregloPila[i]);
                printf("\nCola: ");
                for(int i=frente; i<final; i++) printf("%d ", ArregloCola[i]);
                printf("\n");
                break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida.\n");
        }

        if(opcion != 6) {
            printf("\nPresiona Enter para continuar...");
            while(getchar() != '\n'); getchar();
        }
    } while (opcion != 6);

    return 0;
}