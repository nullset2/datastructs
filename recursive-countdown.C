/*Programa para imprimir todos los enteros positivos antes de un determinado entero. Ejercicio de recursividad...
si bien hay una soluci�n iterativa m�s adecuada para ello...
Jos� Alfredo Gallegos C., Abril 2011

TODO: agregar validaci�n de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

void Countdown(int x){                                                          //funcion recursiva para imprimir los enteros positivos antes del numero
     
     if(x == 0)
          return;
     
     if (x == 1){
          printf(" %d", x);
          return;
     }
     
     printf(" %d,", x);
     Countdown(x-1);
}

int main(){                                                                     //inicio de ejecuci�n!
     
     long int n, i;                                                             //variables que usamos en el programa para manejar qu� vamos a imprimir de la serie
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal
          printf("\n\nContemos hacia atras!");
          printf("\n\nn >>> ");                                                 //muestra prompt para que el usuario entre datos
          scanf("%d", &n);                                                      //captura un entero del teclado y lo asigna a n
          
          if(n < 0)                                                             //validaci�n de datos
               printf("\n\tDato no valido!");                                 //mensaje relacionado
          else{
               printf("\n");                                                    //preparaci�n...
               Countdown(n);                                                    //let's DO IT!!!
          }
     }
     return 0;
}
