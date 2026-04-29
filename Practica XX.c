/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 29/04/2026
Programa de Manipulacion cadenas
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    char copia[100];
    int i;

    printf("Introduce una frase: ");
    
    // fgets lee la frase incluyendo espacios hasta presionar Enter
    fgets(frase, sizeof(frase), stdin);

    // Eliminar el salto de línea (\n) que fgets captura al final
    frase[strcspn(frase, "\n")] = '\0';

    // --- 1. Longitud de la cadena ---
    int longitud = strlen(frase);
    printf("\n1. Longitud de la cadena: %d", longitud);

    // --- 2. Primeros 3 caracteres ---
    printf("\n2. Primeros 3 caracteres: ");
    for(i = 0; i < 3 && i < longitud; i++) {
        printf("%c", frase[i]);
    }

    // --- 3. Ultimos 3 caracteres ---
    printf("\n3. Ultimos 3 caracteres: ");
    if (longitud >= 3) {
        // Apuntamos a la posición: longitud total menos 3
        printf("%s", &frase[longitud - 3]);
    } else {
        printf("%s", frase); // Si es muy corta, se muestra completa
    }

    // Copiamos la frase original a 'copia' para manipularla sin perder la original
    strcpy(copia, frase);

    // --- 4. Cadena en mayusculas ---
    printf("\n4. Cadena en mayusculas: ");
    for(i = 0; copia[i]; i++) {
        printf("%c", toupper(copia[i]));
    }

    // --- 5. Cadena en minusculas ---
    printf("\n5. Cadena en minusculas: ");
    for(i = 0; copia[i]; i++) {
        printf("%c", tolower(copia[i]));
    }

    // --- 6. Reemplazar vocales 'a' por '@' ---
    printf("\n6. Reemplazo de 'a' por '@': ");
    for(i = 0; frase[i]; i++) {
        if(frase[i] == 'a') { 
            printf("@");
        } else {
            printf("%c", frase[i]);
        }
    }

    printf("\n"); // Salto de línea final para limpiar la consola
    return 0;
}