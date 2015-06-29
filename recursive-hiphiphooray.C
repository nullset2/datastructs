/*Programa para imprimir... tantas veces como sea deseado Hip Hip Hip... Hip (n-esima vez) Hurra!
... ejercicio de recursividad
José Alfredo Gallegos C., Abril 2011

TODO: agregar validación de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado

void hooray(int x){                                                             //funcion recursiva para imprimir los hips

     if(x == 1){                                                                //paso de parada
          printf("\n\t Hurra!!!\n");                                            //imprime la ultima parte de la frase
          return;
     }
          
     printf("\n\t Hip,");
     hooray(x-1);
}

int main(){                                                                     //inicio de ejecución!
     
     int n, i;                                                                  //variables que usamos en el programa para manejar qué vamos a imprimir de la serie
     
     while(true){                                                               //nos permite poder seguir mostrando el menu principal
          printf("\nEcha una porra!");
          printf("\n\nn >>> ");                                                 //muestra prompt para que el usuario entre datos
          scanf("%d", &n);                                                      //captura un entero del teclado y lo asigna a n
          
          if(n < 0)                                                             //validación de datos
               printf("\n\tDato no valido!\n");                                 //mensaje relacionado
          else{
               hooray(n);                                                       //let's do thisssss
          }
     }
     return 0;
}
