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
    int encontrado = 0; //Inicia en 0 y cambia a 1 si encuentra el numero 
    int posicion = -1;  // lo hace para que ponga bien la posicion
    
    printf("Ingrese el numero que desea buscar: "); //Aqui ingresas el numero que deseas buscar
    scanf("%d", &numeroABuscar);
    
    for(int i = 0; i < 10; i++){          //Aqui va recorriendo uno por uno para revisar si el numero esta en el arreglo
        if(arreglo[i] == numeroABuscar){
            encontrado = 1;
            posicion = i;
            break;
        }
        
    }
    if(encontrado == 1){
        printf("El numero %d fue encontrado en la posicion %d\n",numeroABuscar, posicion);//Aqui te dice si el numero esta y en posicion
    }
    else{
    printf("El numero %d no fue encontrado en el arreglo\n",numeroABuscar);//Aqui te dice si el numero no esta en el arreglo
    }
        
    return 0;
}
