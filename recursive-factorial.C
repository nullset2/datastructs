/*Programa para calcular el factorial de un numero entero positivo. Usa métodos recursivos
José Alfredo Gallegos C., Abril 2011

TODO: agregar validación de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)

Queremos lograr el calculo del factorial de un entero: 
  n! = n * (n-1)!
     = n * (n-1) * (n-2)!
     ...
     = n * (n-1) * (n-2) * ... * 3 * 2 * 1 * 0!
  y como tenemos la condicion de parada 0! = 1, ahi es donde nos devuelve el dato y para la recursión*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

long int Factorial(long int n){                                                 //funcion recursiva para calcular el factorial de un entero
    
    if(n == 0)                                                                  //caso especial de 0!
         return 1;                                                              //matematicamente 0! = 1, así que debe devolver ese valor!
    
    return n * Factorial(n-1);                                                  //retorna n * el valor retornado por la misma función en que estamos (fn se llama a si misma) pero con un argumento menor por 1
}

int main(){                                                                     //inicio de ejecución!
    
     long int x;                                                                //variables para operar el menú principal
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal                                                                          //TODO: buscar como mostrarlo más bonito (limpiar pantalla siempre en esta posición)
          
          printf("\nCalcula el factorial de (entero positivo)... >>> ");        //muestra prompt para que el usuario entre datos
          scanf("%d", &x);                                                      //captura un entero del teclado y lo asigna a x
               
          if(x < 0)                                                             //validación de datos
               printf("\n\tDato no valido!\n");                                 //mensaje relacionado a la validación de datos
          else
               printf("\n\t%d! = %d \n", x, Factorial(x));                      //si el dato es adecuado muestra su factorial
     }
     return 0;
}
