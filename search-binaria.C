/*En este programa implementaremos un algoritmo de busqueda binaria sobre una colecci�n de datos. Usamos m�todos recursivos y ordenamiento
Jos� Alfredo Gallegos C. Abril 2011*/

#include <stdio.h>
#include <conio.h>
#define n 15                                                                    //este ejercicio usa una cantidad de 15 elementos, si bien puede ser cualquier cantidad deseada

int array[n];                                                                   //declaramos este arreglo de enteros como global para poderlo accesar en todos los modulos

//rutina simple para imprimir los elementos del arreglo en pantalla
void printArray(){
    
    printf("\n");                                                               //organizaci�n en pantalla
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
    
    printf("\n");                                                               //organizaci�n en pantalla
    for(int k = 0; k < n; k++){                                                 //usa un simple ciclo para accesar al arreglo
        printf("Arreglo[%d]: ", k+1);                                           //y poblar todos los elementos del arreglo
        scanf("%d", &array[k]);
    }
}

//rutina para ordenar por m�todo de inserci�n
void insercion(int* array)                                                      //obtiene como par�metro un puntero a la primera posicion de nuestro arreglo
{
    int a, b, aux, contador = 0, intercambios = 0;                              //variables auxiliares para la rutina de ordenamiento
    
    for(a = 1; a < n; ++a){                                                     //para un ciclo que recorrer� todo el arreglo
          
        aux = array[a];                                                         //captura el valor de la posici�n actual el arreglo
        
        for(b = a-1; b >= 0 && aux < array[b]; b--)                             //abrimos otro ciclo con condici�n de entrada b cte no puede ser negativa y este ciclo solo aplica para cuando los valores del arreglo en b son mayores al valor del aux anterior
            array[b+1] = array[b];                                              //desplaza el valor anterior al lugar siguiente
    
        array[b+1] = aux;                                                       //arregla el ultimo elemento por arreglar
    }
}

//rutina para buscar un dato en el arreglo por busqueda binaria
void busqueda(int primero, int query, int ultimo){

    int mid, loc = 0;                                                           //variables auxiliares para movernos por el arreglo y almacenar los datos importantes de la busqueda
    bool found;                                                                 //para marcar cuando se ha encontrado el elemento coincidente con la clave (query) entrada

    if(primero > ultimo){                                                       //Condici�n de parada del m�todo recursivo: en caso que no se encontr� el query... Tambi�n es el primer paso del algoritmo
        found = false;                                                          //En este caso se han realizado todas las comparaciones posibles y no se ha encontrado el query
        printSearchResults(found, query, loc);                                  //ya se lleg� a la condici�n de parada, as� que a regresar para evitar recursion infinita!
    }                                                                           //s�lo debe de llegar a este m�todo despu�s de un paso recursivo, lo cual todav�a le permite mostrar el mensaje de conclusion adecuadamente
                                                                                //y agregar el return es seguro    
    else{
     
        mid = obtainArrayMidPointIndex(primero, ultimo);                        //llama a obtainArrayMidPointIndex para obtener el punto medio del arreglo con que estamos trabajando
    
        if(query == array[mid]){                                                //Condici�n de parada del m�todo recursivo: en caso que s� se encontr� el query...
            found = true;                                                       //Esta condici�n es a la que se llega cuando ya encontr� el dato buscado despues de pasos recursivos
            loc = mid;                                                          //guarda la locaci�n de donde est� el elemento buscado
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

int main(){                                                                     //main() - inicio de ejecuci�n!
    
    int pick = 0, query = 0;                                                    //ints para poder manejar el menu principal
    
    while(true){                                                                //usamos este ciclo para poder mostrar continuamente el menu principal
        
        printf("\n");                                                           //con prop�sito est�tico
        printArray();                                                           //llama a printArray() para mostrar el estado actual del arreglo
        printMenu();                                                            //llama a printMenu() para mostrar las opciones del menu principal
        scanf("%d", &pick);                                                     //captura la opci�n deseada por el usuario y

        switch (pick){                                                          //dependiendo de dicha opci�n toma la decisi�n de
               
            case 1:  populateArray();                                           //...empezar a pedir los elementos del arreglo
                     insercion(array);                                          //en este caso tambien los ordena porque los datos deben estar ordenados para implementar busqueda binaria
                     break;
            case 2:  printf("\n Dato >>> ");                                    //pide entrar el dato a buscar
                     scanf("%d", &query);                                       //captura qu� dato se quiere buscar
                     busqueda(0, query, n-1);                                   //llama a b�squeda para buscar el dato
                     break;                                                     
            case 3:  printf("\n Hasta luego (:");                               //...o terminar el programa
                     getch();
                     return 0;
            default: printf("Opcion no valida\n\n");                            //...si entr� una opci�n inadecuada, muestra un mensaje adecuado
                     break;
        }
    }
}
