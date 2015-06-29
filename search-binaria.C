/*En este programa implementaremos un algoritmo de busqueda binaria sobre una colección de datos. Usamos métodos recursivos y ordenamiento
José Alfredo Gallegos C. Abril 2011*/

#include <stdio.h>
#include <conio.h>
#define n 15                                                                    //este ejercicio usa una cantidad de 15 elementos, si bien puede ser cualquier cantidad deseada

int array[n];                                                                   //declaramos este arreglo de enteros como global para poderlo accesar en todos los modulos

//rutina simple para imprimir los elementos del arreglo en pantalla
void printArray(){
    
    printf("\n");                                                               //organización en pantalla
    for(int t = 0; t < n; t++){                                                 //y usa un simple ciclo para accesar a los elementos del arreglo
        printf(" %d ", array[t]);                                               //y mostrarlos
    }
}

//funcion simple para determinar el punto medio del arreglo que se esta trabajando
int obtainArrayMidPointIndex(int primero, int ultimo){
    
    if((primero + ultimo)%2 == 0)                                               //si el arreglo tiene cantidad impar de elementos
        return (primero+ultimo)/2;                                              //el punto medio es simplemente la mitad de la suma de los indices inf. y superior (va de 0 a n)
    else                                                                        //si el arreglo tiene cantidad par de elementos
        return ((primero+ultimo)-1)/2;                                          //consideraremos al punto medio como el anterior a la mitad de la suma de los extremos
}

//rutina simple para mostrar el resultado de la busqueda realizada
void printSearchResults(bool found, int query, int loc){

    if(found)
        printf("\n Elemento %d encontrado en posicion %d!!!", query, loc+1);    //muestra memsaje relacionado a que si se encontro el dato
    else                                                                        //loc+1 es para mayor legibilidad a la hora de ejecutarse dado que es como lo percibe el usuario que cuenta posiciones de 1 a n
        printf("\n Elemento %d no encontrado en el arreglo ):", query);         //muestra mensaje relacionado
}

//rutina simple para imprimir las opciones del menu principal
void printMenu(){
     
     printf("\n\n[1] Llenar Arreglo");                                          //impresiones del menu principal
     printf("\n[2] Busqueda de un dato");
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

//rutina para ordenar por método de inserción
void insercion(int* array)                                                      //obtiene como parámetro un puntero a la primera posicion de nuestro arreglo
{
    int a, b, aux, contador = 0, intercambios = 0;                              //variables auxiliares para la rutina de ordenamiento
    
    for(a = 1; a < n; ++a){                                                     //para un ciclo que recorrerá todo el arreglo
          
        aux = array[a];                                                         //captura el valor de la posición actual el arreglo
        
        for(b = a-1; b >= 0 && aux < array[b]; b--)                             //abrimos otro ciclo con condición de entrada b cte no puede ser negativa y este ciclo solo aplica para cuando los valores del arreglo en b son mayores al valor del aux anterior
            array[b+1] = array[b];                                              //desplaza el valor anterior al lugar siguiente
    
        array[b+1] = aux;                                                       //arregla el ultimo elemento por arreglar
    }
}

//rutina para buscar un dato en el arreglo por busqueda binaria
void busqueda(int primero, int query, int ultimo){

    int mid, loc = 0;                                                           //variables auxiliares para movernos por el arreglo y almacenar los datos importantes de la busqueda
    bool found;                                                                 //para marcar cuando se ha encontrado el elemento coincidente con la clave (query) entrada

    if(primero > ultimo){                                                       //Condición de parada del método recursivo: en caso que no se encontró el query... También es el primer paso del algoritmo
        found = false;                                                          //En este caso se han realizado todas las comparaciones posibles y no se ha encontrado el query
        printSearchResults(found, query, loc);                                  //ya se llegó a la condición de parada, así que a regresar para evitar recursion infinita!
    }                                                                           //sólo debe de llegar a este método después de un paso recursivo, lo cual todavía le permite mostrar el mensaje de conclusion adecuadamente
                                                                                //y agregar el return es seguro    
    else{
     
        mid = obtainArrayMidPointIndex(primero, ultimo);                        //llama a obtainArrayMidPointIndex para obtener el punto medio del arreglo con que estamos trabajando
    
        if(query == array[mid]){                                                //Condición de parada del método recursivo: en caso que sí se encontró el query...
            found = true;                                                       //Esta condición es a la que se llega cuando ya encontró el dato buscado despues de pasos recursivos
            loc = mid;                                                          //guarda la locación de donde está el elemento buscado
            printSearchResults(found, query, loc);                              //retorna al nivel anterior
        }
        else{
            if(query < array[mid])                                              //Caso recursivo
                busqueda(primero, query, mid-1);                                //busca desde el primero del arreglo hasta el anterior al punto medio
            else
                if(query > array[mid])                                          //Caso recursivo
                    busqueda(mid+1, query, ultimo);                             //busca desde el siguiente punto al punto medio hasta el final del arreglo
        }
    }
}

int main(){                                                                     //main() - inicio de ejecución!
    
    int pick = 0, query = 0;                                                    //ints para poder manejar el menu principal
    
    while(true){                                                                //usamos este ciclo para poder mostrar continuamente el menu principal
        
        printf("\n");                                                           //con propósito estético
        printArray();                                                           //llama a printArray() para mostrar el estado actual del arreglo
        printMenu();                                                            //llama a printMenu() para mostrar las opciones del menu principal
        scanf("%d", &pick);                                                     //captura la opción deseada por el usuario y

        switch (pick){                                                          //dependiendo de dicha opción toma la decisión de
               
            case 1:  populateArray();                                           //...empezar a pedir los elementos del arreglo
                     insercion(array);                                          //en este caso tambien los ordena porque los datos deben estar ordenados para implementar busqueda binaria
                     break;
            case 2:  printf("\n Dato >>> ");                                    //pide entrar el dato a buscar
                     scanf("%d", &query);                                       //captura qué dato se quiere buscar
                     busqueda(0, query, n-1);                                   //llama a búsqueda para buscar el dato
                     break;                                                     
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entró una opción inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
