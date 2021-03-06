/*En este programa implementaremos ordenamiento de los datos de un arreglo de 10 enteros por ordenamiento de insercion
Jos� Alfredo Gallegos C. Abril 2011*/

#include <stdio.h>
#include <conio.h>
#define n 10

int array[n];                                                                   //declaramos este arreglo de enteros como global para poderlo accesar en todos los modulos

//rutina simple para imprimir los elementos del arreglo en pantalla
void printArray(){
    
    printf("\n");                                                               //organizaci�n en pantalla
    for(int t = 0; t < n; t++){                                                 //y usa un simple ciclo para accesar a los elementos del arreglo
        printf(" %d ", array[t]);                                               //y mostrarlos
    }
}

//rutina simple para imprimir las opciones del menu principal
void printMenu(){
     
     printf("\n\n[1] Llenar Arreglo");                                          //impresiones del menu principal
     printf("\n[2] Ordenamiento por Insercion");
     printf("\n[3] Salir");
     printf("\n\n>>> ");                                                        //un prompt para pedir entrada de datos del usuario
}

//rutina simple para llenar el arreglo de datos
void populateArray(){
    
    printf("\n");                                                               //organizaci�n en pantalla
    for(int k = 0; k < n; k++){                                                 //usa un simple ciclo para accesar al arreglo
        printf("Arreglo[%d]: ", k+1);                                           //y poblar todos los elementos del arreglo
        scanf("%d", &array[k]);
    }
}

//rutina para ordenar por m�todo de agitaci�n
void insercion(int* array)                                                      //obtiene como par�metro un puntero a la primera posicion de nuestro arreglo
{
    int a, b, aux, contador = 0, intercambios = 0;                              //variables auxiliares para la rutina de ordenamiento
    
    for(a = 1; a < n; ++a){                                                     //para un ciclo que recorrer� todo el arreglo
          
        aux = array[a];                                                         //captura el valor de la posici�n actual el arreglo
        
        for(b = a-1; b >= 0 && aux < array[b]; b--){                            //abrimos otro ciclo con condici�n de entrada b cte no puede ser negativa y este ciclo solo aplica para cuando los valores del arreglo en b son mayores al valor del aux anterior
            array[b+1] = array[b];                                              //desplaza el valor anterior al lugar siguiente
            intercambios++;                                                     //se realiz� un intercambio y llevamos el registro
        }
    
        array[b+1] = aux;                                                       //arregla el ultimo elemento por arreglar
        printArray();                                                           //imprime el arreglo actualizado
        contador++;                                                             //aumenta la cuenta de iteraciones del metodo
    }
    
    printf("\n\nInsercion Tarda %d Iteraciones, realizo %d intercambios", contador, intercambios);   //informaci�n
}

int main(){                                                                     //main() - inicio de ejecuci�n!
    
    int pick = 0;                                                               //int para poder manejar el menu principal
    
    while(true){                                                                //usamos este ciclo para poder mostrar continuamente el menu principal
        
        printf("\n");                                                           //con prop�sito est�tico
        printArray();                                                           //llama a printArray() para mostrar el estado actual del arreglo
        printMenu();                                                            //llama a printMenu() para mostrar las opciones del menu principal
        scanf("%d", &pick);                                                     //captura la opci�n deseada por el usuario y

        switch (pick){                                                          //dependiendo de dicha opci�n toma la decisi�n de
               
            case 1:  populateArray();                                           //...empezar a pedir los elementos del arreglo
                     break;
            case 2:  insercion(array);                                          //...ordenar los elementos del arreglo
                     break;
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entr� una opci�n inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
