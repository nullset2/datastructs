/*Este programa recuerdo que lo bajé de internet... es un ejemplo de una lista
encadenada y aparentemente crea una lista con asignación dinámica de memoria
de los numeros del 1 al 10...*/

#include<stdlib.h>                                       //stdlib para malloc()
#include<stdio.h>                                        //lib. estandar IO de C

struct list_el {                                         //define el struct del elemento de la lista
   int val;                                              //campo del dato que contiene
   struct list_el * next;                                //puntero al siguiente nodo de la lista, es parte de la misma definicion del nodo
};                                                       //es decir, por unica ocasion el bloque puede hacer referencia a un elemento de sí mismo sin actualmente
                                                         //terminar de definirse!
typedef struct list_el item;                             //define tipo de dato "item" para usarlo en el programa, este es el elemento de la lista

int main() {                                             //inicio de ejecución del programa
   item * curr, * head;                                  //define punteros a items, curr y head
   int i;

   head = NULL;                                          //inicializa la lista con head = null (no hay elementos)

   for(i=1;i<=10;i++) {                                  //realiza un ciclo 10 ocasiones
                                                         //(puedo cambiar el limite del for y el programa hace la lista tan grande como sea necesario)
      curr = (item *)malloc(sizeof(item));               //alocamiento de memoria dinámico para el elemento a agregar

      curr->val = i;                                     //accesa al campo "val" del elemento al que apunta curr y le asigna el valor de i
      curr->next = head;                                 //hace que el campo "next" del elemento al que apunta curr ahora apunte a head (null por ahora, para volverse el primer elemento de la lista
      head = curr;                                       //hace que el puntero de head tome el valor de curr porque ahora el nodo de curr es el primero, head
   }

   curr = head;                                          //hace que el curr vuelva a apuntar al puntero de head, para imprimir la lista

   while(curr) {                                         //mientras curr no sea NULL
      printf("%d\n", curr->val);                         //accesa al campo "val" asociado con dicho curr e imprimelo
      curr = curr->next ;                                //asigna el valor del siguiente nodo de la lista a curr para seguir recorriendo
   }
   getch();                                              //espera a que se presione una tecla
   return 0;
}
