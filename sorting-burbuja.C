/*En este programa implementaremos ordenamiento de los datos de un arreglo de 10 enteros por ordenamiento de burbuja
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
     printf("\n[2] Bubblesort");
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

//rutina para ordenar por método de burbuja
//responde al algoritmo de bubblesorting visto en clase
void bubblesort(int *array){                                                    //obtiene como parámetro un puntero a la primera posicion de nuestro arreglo
    
    int aux = 0, contador = 0, intercambios = 0;                                //usa una variable auxiliar para implementar metodo de burbuja variable para contar el numero de pasos realizados por el ordenamiento
    
    for(int i = 1; i < n; ++i){                                                 //el metodo de burbuja usa dos ciclos anidados para recorrer el arreglo
        for(int j = n-1; j >= i; --j){                                          //1/2 (n2-n) veces
            
            contador++;                                                         //aumenta el contador en 1 para llevar el registro
            
            if(array[j-1] > array[j]){                                          //hace la comparación del elemento actual
                aux = array[j-1];                                               //si el elemento anterior es mayor al elemento actual
                array[j-1] = array[j];                                          //captura el valor del anterior en el auxiliar, recorre el valor del anterior al actual
                array[j] = aux;                                                 //y hace que el valor del auxiliar, el cual es mayor que el actual, ahora quede DELANTE del actual
                intercambios++;                                                 //aumenta el contador de intercambios en 1
                printArray();                                                   //y muestra el estado actual del arreglo
            }
        }
    }

    printf("\n\nBubblesort Tarda %d Iteraciones, realizo %d intercambios", contador, intercambios);   //información
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
            case 2:  bubblesort(array);                                         //...ordenar los elementos del arreglo
                     break;
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entró una opción inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
