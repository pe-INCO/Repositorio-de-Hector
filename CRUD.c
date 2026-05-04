/*
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 04/05/2026
Programa de CRUD
*/

#include <stdio.h>   // Librería estándar para entrada y salida (printf, scanf, etc.)
#include <stdlib.h>  // Librería para funciones de sistema (como remove)

int main() {
    // --- DECLARACIÓN DE VARIABLES ---
    FILE *archivo;       // El "puntero" que representará nuestro archivo en el programa
    int opcion;          // Para guardar la elección del menú
    char linea[100];     // Buffer (espacio) para leer frases completas
    char texto[100];     // Buffer para escribir texto nuevo
    int numero;          // Para probar la lectura de datos numéricos

    // El bucle do-while permite que el menú se repita hasta que elijas 'Salir'
    do {
        printf("\n======= MENU CRUD DE ARCHIVOS =======");
        printf("\n1. Crear/Sobrescribir (Modo 'w')");
        printf("\n2. Leer todo el contenido (Modo 'r')");
        printf("\n3. Añadir informacion (Modo 'a')");
        printf("\n4. Leer dato especifico (fscanf)");
        printf("\n5. Eliminar el archivo (remove)");
        printf("\n6. Salir");
        printf("\nSelecciona una opcion: ");
        
        scanf("%d", &opcion); // Captura la opción numérica
        getchar();            // Limpia el 'Enter' sobrante del teclado para que no afecte a los fgets

        switch (opcion) {
            
            case 1: // --- CREATE / UPDATE (Sobrescribir) ---
                // fopen abre el archivo. "w" (write) crea el archivo si no existe,
                // pero CUIDADO: si ya existe, borra todo su contenido previo.
                archivo = fopen("datos.txt", "w");
                
                if (archivo == NULL) {
                    printf("Error: No se pudo crear el archivo.\n");
                } else {
                    // fprintf escribe texto con formato, similar a printf pero al archivo
                    fprintf(archivo, "Encabezado_Sistema 1\n");
                    fprintf(archivo, "Registro_Base 100\n");
                    fclose(archivo); // Cerramos para asegurar que los datos se guarden en el disco
                    printf("Archivo 'datos.txt' creado exitosamente.\n");
                }
                break;

            case 2: // --- READ (Lectura completa) ---
                // "r" (read) abre el archivo solo para leerlo.
                archivo = fopen("datos.txt", "r");
                
                if (archivo == NULL) {
                    printf("Error: El archivo no existe. Primero crealo con la opcion 1.\n");
                } else {
                    printf("\n--- Mostrando contenido del archivo ---\n");
                    // fgets lee una línea completa hasta encontrar un salto de línea (\n)
                    // Se repite mientras no lleguemos al final del archivo (NULL)
                    while (fgets(linea, sizeof(linea), archivo) != NULL) {
                        printf("%s", linea); // Imprime en pantalla lo que leyó del archivo
                    }
                    fclose(archivo); // Siempre cerrar al terminar
                }
                break;

            case 3: // --- UPDATE (Añadir sin borrar lo anterior) ---
                // "a" (append) abre el archivo y coloca el cursor al final de todo.
                // Lo que escribas se agregará después del último carácter existente.
                archivo = fopen("datos.txt", "a");
                
                if (archivo == NULL) {
                    printf("Error al abrir.\n");
                } else {
                    printf("Escribe el texto que quieres añadir: ");
                    fgets(texto, sizeof(texto), stdin); // Captura texto del usuario
                    fprintf(archivo, "%s", texto);       // Lo escribe en el archivo
                    fclose(archivo);
                    printf("Dato añadido correctamente.\n");
                }
                break;

            case 4: // --- READ (Lectura con formato específico) ---
                archivo = fopen("datos.txt", "r");
                if (archivo != NULL) {
                    // fscanf busca patrones. Aquí busca una palabra (%s) y un entero (%d)
                    // Es muy útil para bases de datos simples
                    if (fscanf(archivo, "%s %d", texto, &numero) == 2) {
                        printf("Dato extraido: Texto [%s] y Numero [%d]\n", texto, numero);
                    } else {
                        printf("El formato de la primera linea no coincide con 'Palabra Numero'.\n");
                    }
                    fclose(archivo);
                }
                break;

            case 5: // --- DELETE (Borrar archivo del sistema) ---
                // remove() es una función de sistema. No necesita abrir el archivo.
                // Devuelve 0 si la eliminación fue exitosa.
                if (remove("datos.txt") == 0) {
                    printf("Archivo 'datos.txt' eliminado del disco duro.\n");
                } else {
                    printf("No se pudo eliminar (quiza el archivo no existe).\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6); // Se repite hasta que el usuario elija 6

    return 0;
}