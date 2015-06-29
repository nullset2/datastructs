/*Programa para obtener términos de fibonacci e imprimir la serie de fibonacci hasta donde se desee. Usa métodos recursivos
José Alfredo Gallegos C., Abril 2011

TODO: agregar validación de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)

Queremos imprimir la serie fibonacci: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
Cada n-esimo elemento es el resultado de la suma de los dos anteriores
  Fn = F(n-1) + F(n-2)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

long int Fibonacci(long int x){                                                 //funcion recursiva para calcular los elementos de fibonacci
     
     if(x == 1 || x == 2)
          return 1;
     
     return (Fibonacci(x-1) + Fibonacci(x-2));
}

int main(){                                                                     //inicio de ejecución!
     
     long int n, i;                                                             //variables que usamos en el programa para manejar qué vamos a imprimir de la serie
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal
          printf("\n\nImprimamos la Serie de Fibonacci hasta n terminos!");
          printf("\n\nn >>> ");                                                 //muestra prompt para que el usuario entre datos
          scanf("%d", &n);                                                      //captura un entero del teclado y lo asigna a n
          
          if(n < 0)                                                             //validación de datos
               printf("\n\tDato no valido!\n");                                  //mensaje relacionado
          else{
               printf("\n");
               for(i=1; i<=n; i++)                                              //usamos un simple ciclo que
                    printf(" %d", Fibonacci(i));                                //imprime la serie de fibonacci hasta el término deseado
          }
     }
     return 0;
}
