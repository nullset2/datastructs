/*Lista enlazada, base de las pilas y colas dinamicas
José Alfredo Gallegos C., Abril 2011*/

/*EL PROGRAMA YA FUNCIONA PERFECTAMENTE, pero tenemos
TODO: agregar validación de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado
#include <stdlib.h>                                                             //usando lib. estandar de C (funcion malloc())

//Definición del nodo
struct ListElement{                                                             //definimos la estructura del nodo de la lista
     int data;                                                                  //dato del nodo, un entero
     struct ListElement* next;                                                  //puntero al siguiente nodo de la lista despues de este
};                                                                              //por alguna razón aquí debe ir un ;

typedef struct ListElement Node;                                                //Node debe ser definido como tipo de dato para uso en el programa
Node* head = NULL,* tail = NULL;                                                //puntero al primer y ultimo nodo de la lista, inicializa la lista al hacer head = null (no hay elementos)

//Rutina para agregar un nuevo nodo a la lista
void addNode(int x){

     Node* newnode = (Node*)malloc(sizeof(Node));                               //crea el nodo a agregar (reservamos memoria)

     if (head == NULL){                                                         //si es el primer nodo de la lista...
          head = newnode;                                                       //indicamos que es el primer nodo de la lista, es decir
          tail = newnode;                                                       //head y tail deben apuntar a nuestro primer nodo
          newnode->next = NULL;                                                 //y obviamente como también es el ultimo, su campo next debe apuntar a NULL
     }
     else{                                                                      //si no es el primer nodo de la lista...
          tail->next = newnode;                                                 //el que hasta ahora era el último tiene que apuntar al nuevo
          tail = newnode;                                                       //hacemos que el nuevo sea ahora el último
          newnode->next = NULL;                                                 //y hacemos que el que ahora es ultimo apunte a NULL, para indicar el fin de lista
     }
                                                                                //después de haber jugado con los punteros para ver donde pertenece nuestro nuevo nodo
     newnode->data = x;                                                         //asignamos la info requerida al campo de datos "data" del nuevo nodo

     printf("\nAgregado: %d...\n", x);                                          //hemos terminado: se muestra un mensaje de confirmación
     getch();                                                                   //espera a que el usuario presione una tecla
}
//Rutina para eliminar un nodo de la lista
void deleteNode(int x){

     Node* seek = head;                                                         //usamos un nodo auxiliar para poder recorrer la lista y encontrar donde vamos a borrar
     Node* prev;                                                                //también otro nodo auxiliar para conservar una referencia del nodo anterior al borrando

     while(seek->data != x){                                                    //recorremos mientras el valor de "data" en el nodo que está viendo no sea "x" (lo que queremos borrar)...
          prev = seek;                                                          //guarda la locacion del nodo anterior al de recorrido
          seek = seek->next;                                                    //adquiere el valor de "next" en el nodo que ve y sigue recorriendo, no debe salirse de este while hasta encontrar el nodo que quiere

          if(seek == NULL){                                                     //si no encontró el dato...
               printf("\nDato no presente en la lista!...\n");                  //muestra mensaje relacionado
               getch();                                                         //espera a que se presione una tecla
               return;                                                          //retorna a nivel anterior una tecla
               return;                                                          //retorna a nivel anterior
          }
     }

     if(seek == head){                                                          //caso especial si encontró el dato al inicio de la lista (seek = head), es decir, no recorrió en el while
          head = seek->next;                                                    //hace que head apunte al nodo después del primero
          free(seek);                                                           //libera el primer nodo
          printf("\nEliminado: %d...\n", x);                                    //muestra confirmación
          getch();                                                              //espera a presionar una tecla
          return;                                                               //retorna al nivel anterior
     }

     if(seek == tail){                                                          //caso especial si encontró el dato al final de la lista
          tail = prev;                                                          //tail apunta al anterior
          prev->next = NULL;                                                    //hace que dicho nodo ahora apunte a NULL dado que ahora es el final de la lista
          free(seek);                                                           //libera el nodo que antes era el ultimo
          printf("\nEliminado: %d...\n", x);                                    //muestra mensaje de confirmación
          getch();                                                              //espera a presionar una tecla
          return;                                                               //retorna al nivel anterior
     }
                                                                                //si encontró el dato en cualquier otro lugar
     prev->next = seek->next;                                                   //unimos el nodo anterior con el siguiente del eliminando...
     free(seek);                                                                //bye-bye mofo

     printf("\nEliminado: %d...\n", x);                                         //mensaje de confirmación
     getch();                                                                   //espera a que el usuario presione una tecla
}
//Rutina para imprimir todos los elementos de la lista
void printList(){
     int i = 0;                                                                 //usamos un entero para contar los nodos de la lista
     Node* seek = head;                                                         //usamos un puntero auxiliar a un nodo para recorrer la lista

     system("cls");
     if(head == NULL){                                                          //caso especial en que no hay nodos en la lista todavía
          printf("\nLa lista esta vacia!\n");                                   //un mensaje relacionado...
          return;                                                               //y de vuelta a donde estábamos
     }

     while(seek){                                                               //mientras no hayamos llegado al fin de la lista
          printf(" %d", seek->data);                                            //accesa al campo "data" asociado con el nodo actual e imprimelo
          seek = seek->next;                                                    //adquiere la dirección del siguiente elemento...
          i++;                                                                  //para contar cuantos nodos tenemos
     }

     printf("\n %d nodo(s) hasta ahora...\n", i);                               //organización en pantalla y muestra el contador
}

int main(){
     int pick, b;                                                               //variables para operar el menú principal

     while(true)                                                                //nos permite poder seguir mostrando el menu principal
     {
          //TODO: buscar como mostrarlo más bonito (limpiar pantalla siempre en esta posición)

          printList();                                                          //llama a printList() para imprimir la lista

          printf("\n[1] Agrega elemento\n");                                    //impresiones del menu principal
          printf("[2] Borra elemento\n");
          printf("[3] Salir\n");
          printf("\n>>> ");                                                     //muestra prompt para que el usuario entre datos
          scanf("%d", &pick);                                                   //captura un entero del teclado y lo asigna a pick

          switch(pick)                                                          //decide qué hacer basado en el valor de pick
          {
               case 1: printf("\nElemento >>> ");                               //mensaje para capturar elemento
                       scanf("%d",&b);                                          //captura elemento y asigna su valor a var. aux. b
		               addNode(b);                                              //llama pushElement con argumento b
                       printf("\n");                                            //organización!
	                   break;                                                   //cierra el switch(), regresa al nivel anterior

               case 2: printf("\nElemento >>> ");
                       scanf("%d",&b);                                          //captura elemento y asigna su valor a var. aux. b
                       deleteNode(b);                                           //llama a deleteNode con argumento b
                       printf("\n");                                            //organización!
                       break;                                                   //cierra el switch(), regresa al nivel anterior

               case 3: printf("\nHasta luego (: ...\n");                        //un mensajito
                       getch();                                                 //espera a que se presione una letra
                       return 0;                                                //regresa 0 (ejecucion satisfactoria y terminada)

               default: printf("\nOpcion invalida\n\n");                       //en caso que se entre algo incorrecto, luego regresa al while()
                        break;
          }
     }
}
