/*En este programa implementaremos ordenamiento de los datos de un arreglo de 10 enteros por ordenamiento de agitación
José Alfredo Gallegos C. Abril 2011*/

#include <stdio.h>
#include <conio.h>
#define n 10

int array[n];                                                                   //declaramos este arreglo de enteros como global para poderlo accesar en todos los modulos

//rutina simple para imprimir los elementos del arreglo en pantalla
void printArray(){
    
    printf("\n");                                                               //organización en pantalla
    for(int t = 0; t < n; t++){                                                 //y usa un simple ciclo para accesar a los elementos del arreglo
        printf(" %d ", array[t]);                                               //y mostrarlos
    }
}

//rutina simple para imprimir las opciones del menu principal
void printMenu(){
     
     printf("\n\n[1] Llenar Arreglo");                                          //impresiones del menu principal
     printf("\n[2] Ordenamiento por Agitacion");
     printf("\n[3] Salir");
     printf("\n\n>>> ");                                                        //un prompt para pedir entrada de datos del usuario
}

//rutina simple para llenar el arreglo de datos
void populateArray(){
    
    printf("\n");                                                               //organización en pantalla
    for(int k = 0; k < n; k++){                                                 //usa un simple ciclo para accesar al arreglo
        printf("Arreglo[%d]: ", k+1);                                           //y poblar todos los elementos del arreglo
        scanf("%d", &array[k]);
    }
}

//rutina para ordenar por método de agitación
void agitacion(int *array){                                                     //obtiene como parámetro un puntero a la primera posicion de nuestro arreglo
    
    int aux = 0, contador = 0, intercambios = 0;                                //usa una variable auxiliar para implementar metodo de burbuja variable para contar el numero de pasos realizados por el ordenamiento
    bool change = false;                                                        //para controlar si se deben de estar haciendo intercambios
    
    do{
        change = false;                                                         //marca change como falso: hasta ahora no cambios
        for(int i = n-1; i > 0; --i){                                           //ciclo para chequeo de burbuja...
            
            if(array[i-1] > array[i]){                                          //si el lugar anterior del arreglo tiene un mayor dato que el actual
                aux = array[i-1];                                               //haz ordenamiento estilo burbuja (recordemos que agitacion es mejoramiento del bubblesort)
                array[i-1] = array[i];                                      
                array[i] = aux;
                                                             
                intercambios++;                                                 //aumenta en 1 el contador de intercambios para reflejar el intercambio hecho
                change = true;                                                  //marca change como true para seguir ciclando
            }
            contador++;                                                         //aumenta en 1 el contador de iteraciones --ya terminamos 1 iteracion
            printArray();                                                       //imprime el estado actual del arreglo
        }
            
        for(int j = 1; j < n; ++j){                                             //segunda rutina de ordenamiento
                                                                                //también funciona bajo el mismo principio del bubblesort pero en orden inverso
            if(array[j-1] > array[j]){
                aux = array[j-1];                                           
                array[j-1] = array[j];                                      
                array[j] = aux;                                     
                
                intercambios++;
                change = true;                                           
            }
            contador++;
            printArray(); 
        }
         
    }while(change);

    printf("\n\nAgitacion Tarda %d Iteraciones, realizo %d intercambios", contador, intercambios);   //información
}

int main(){                                                                     //main() - inicio de ejecución!
    
    int pick = 0;                                                               //int para poder manejar el menu principal
    
    while(true){                                                                //usamos este ciclo para poder mostrar continuamente el menu principal
        
        printf("\n");                                                           //con propósito estético
        printArray();                                                           //llama a printArray() para mostrar el estado actual del arreglo
        printMenu();                                                            //llama a printMenu() para mostrar las opciones del menu principal
        scanf("%d", &pick);                                                     //captura la opción deseada por el usuario y

        switch (pick){                                                          //dependiendo de dicha opción toma la decisión de
               
            case 1:  populateArray();                                           //...empezar a pedir los elementos del arreglo
                     break;
            case 2:  agitacion(array);                                          //...ordenar los elementos del arreglo
                     break;
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entró una opción inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
