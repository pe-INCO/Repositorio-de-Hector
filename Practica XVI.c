/*
Nombre: Hector Leonardo  Torres Campos
Codigo: 222621939
Fecha: 26/03/2026
Programa de Ordenamiento
*/
#include <stdio.h>

int main()
{
    int i, j, temp, n;
    int arreglo[] = { 50, 26 , 7, 9, 15, 27};
    n = sizeof(arreglo)/sizeof(arreglo[0]);
    
    for(i = 0; i < n -1; i++){
        for( j = i+1; j < n; j++){
            
            if(arreglo[i] > arreglo[j]){
            
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            }   
        }
    }
    
    printf("Arreglo ordenado: ");
    for(i = 0; i < n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    
    return 0;
}
