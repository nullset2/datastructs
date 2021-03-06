/*Programa para calcular el numero de combinaciones de un conjunto de n elementos tomado de r en r. Usa m�todos recursivos
Jos� Alfredo Gallegos C., Abril 2011

TODO: agregar validaci�n de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)

Queremos lograr el calculo de combinaciones: 
  C(n, r) = n! / [r! * (n-r)!]*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

long int Factorial(long int x){                                                 //funcion recursiva para calcular el factorial de un entero
    
    if(x == 0)                                                                  //caso especial de 0!
         return 1;                                                              //matematicamente 0! = 1, as� que debe devolver ese valor!
    
    return x * Factorial(x-1);                                                  //retorna n * el valor retornado por la misma funci�n en que estamos (fn se llama a si misma) pero con un argumento menor por 1
}

int main(){                                                                     //inicio de ejecuci�n!
    
     long int n, r;                                                             //variables para operar el men� principal
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal                                                                          //TODO: buscar como mostrarlo m�s bonito (limpiar pantalla siempre en esta posici�n)
          
          printf("\nCalcula tus combinaciones de n tomados de r en r!");
          printf("\n\nn >>> ");                                                 //muestra prompt para que el usuario entre datos
          scanf("%d", &n);                                                      //captura un entero del teclado y lo asigna a n
          printf("r >>> ");                                                     //muestra prompt para que el usuario entre datos
          scanf("%d", &r);                                                      //captura un entero del teclado y lo asigna a n
               
          if(n < 0 || r < 0 || r > n)                                           //validaci�n de datos
               printf("\n\tDatos no validos!\n");                               //mensaje relacionado a la validaci�n de datos
          else                                                                  //si todo est� bien muestra combinaciones
               printf("\n\tC(%d, %d) = %d \n", n, r, Factorial(n)/(Factorial(r)*Factorial(n-r)));
     }
     
     return 0;
}
