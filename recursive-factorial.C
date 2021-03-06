/*Programa para calcular el factorial de un numero entero positivo. Usa m�todos recursivos
Jos� Alfredo Gallegos C., Abril 2011

TODO: agregar validaci�n de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)

Queremos lograr el calculo del factorial de un entero: 
  n! = n * (n-1)!
     = n * (n-1) * (n-2)!
     ...
     = n * (n-1) * (n-2) * ... * 3 * 2 * 1 * 0!
  y como tenemos la condicion de parada 0! = 1, ahi es donde nos devuelve el dato y para la recursi�n*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

long int Factorial(long int n){                                                 //funcion recursiva para calcular el factorial de un entero
    
    if(n == 0)                                                                  //caso especial de 0!
         return 1;                                                              //matematicamente 0! = 1, as� que debe devolver ese valor!
    
    return n * Factorial(n-1);                                                  //retorna n * el valor retornado por la misma funci�n en que estamos (fn se llama a si misma) pero con un argumento menor por 1
}

int main(){                                                                     //inicio de ejecuci�n!
    
     long int x;                                                                //variables para operar el men� principal
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal                                                                          //TODO: buscar como mostrarlo m�s bonito (limpiar pantalla siempre en esta posici�n)
          
          printf("\nCalcula el factorial de (entero positivo)... >>> ");        //muestra prompt para que el usuario entre datos
          scanf("%d", &x);                                                      //captura un entero del teclado y lo asigna a x
               
          if(x < 0)                                                             //validaci�n de datos
               printf("\n\tDato no valido!\n");                                 //mensaje relacionado a la validaci�n de datos
          else
               printf("\n\t%d! = %d \n", x, Factorial(x));                      //si el dato es adecuado muestra su factorial
     }
     return 0;
}
