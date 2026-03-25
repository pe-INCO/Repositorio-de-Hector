/*   
Nombre: Hector Leonardo Torres Campos
Codigo: 222621939
Fecha: 25/03/2026
Programa de Busqueda Secuencial
*/

#include<stdio.h>

int main (){
    int arreglo[10] = { 12, 45, 7, 89, 23, 56, 90, 34, 11, 67};
    int numeroABuscar;
    int encontrado = 0;
    int posicion = -1;
    
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &numeroABuscar);
    
    for(int i = 0; i < 10; i++){
        if(arreglo[i] == numeroABuscar){
            encontrado = 1;
            posicion = i;
            break;
        }
        
    }
    if(encontrado == 1){
        printf("El numero %d fue encontrado en la posicion %d\n",numeroABuscar, posicion);
    }
    else{
    printf("El numero %d no fue encontrado en el arreglo\n",numeroABuscar);
    }
        
    return 0;
}