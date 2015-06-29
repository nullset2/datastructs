/*En este programa implementaremos ordenamiento de los datos de un arreglo de 10 enteros por ordenamiento de seleccion
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
     printf("\n[2] Ordenamiento por Seleccion");
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
void seleccion(int *array){                                                     //obtiene como parámetro un puntero a la primera posicion de nuestro arreglo
    
    int a, b, c, aux, contador = 0, intercambios = 0;                           //variables auxiliares para la rutina de ordenamiento
    bool change;                                                                //contadores e indicadores
    
    for(a = 0; a < n-1; ++a){                                                   //primero comparando desde el primer espacio del arreglo
                       
        change = false;                                                         //inicializa este booleano para decirle al programa si se hará swap o no
        c = a;                                                                  //c, la seleccion, es inicializada a a, dado que todavia no hemos comparado nada
        aux = array[a];                                                         //aux representa el valor mas bajo hasta ahora
        
        for(b = a+1; b < n; ++b){                                               //dentro del for anterior, tenemos otro ciclo
            contador++;                                                         //para llevar el registro de iteraciones realizadas
            if(array[b] < aux){                                                 //busca un dato menor en los restantes elementos que estamos comparando
                c = b;                                                          //si lo haya, la seleccion es actualizada
                aux = array[b];                                                 //el dato mas bajo tambien
                change = true;                                                  //y se actualiza el indicador de cambio

            }
        }
        
        if(change){                                                             //si se determinó que se hará swap de datos
                        
            array[c] = array[a];                                                //hace el swap
            array[a] = aux;                                                     //array[donde se encontró el mas bajo] = array[pos actual del ciclo], array[pos actual] = dato mas bajo encontrado hasta ahora
            intercambios++;                                                     //aumenta el contador de intercambios
            printArray();                                                       //y muestra el array actualizado
        }
    }

    printf("\n\nSeleccion Tarda %d Iteraciones, realizo %d intercambios", contador, intercambios);   //información
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
            case 2:  seleccion(array);                                          //...ordenar los elementos del arreglo
                     break;
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entró una opción inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
