/*Basado en mi trabajo anterior de listas dinámicas, implementaré una cola con asignación dinámica de memoria
José Alfredo Gallegos C., Abril 2011*/

/*cola: estructura FIFO... First-In, First-Out, esa es la clave para hacer fácil la implementación... solo tendré que tweakear un poco mis módulos!*/

/*EL PROGRAMA YA FUNCIONA PERFECTAMENTE, pero tenemos
TODO: agregar validación de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado
#include <stdlib.h>                                                             //usando lib. estandar de C (funcion malloc())

//Definición del nodo
struct QueueElement{                                                            //definimos la estructura del nodo de la cola
     int data;                                                                  //dato del nodo, un entero
     struct QueueElement* next;                                                 //puntero al siguiente nodo de la cola despues de este
};                                                                              //por alguna razón aquí debe ir un ;

typedef struct QueueElement Node;                                               //Node debe ser definido como tipo de dato para uso en el programa
Node* head = NULL,* tail = NULL;                                                //puntero al primer y ultimo nodo de la cola, inicializa la cola al hacer head = null (no hay elementos)

//Rutina para agregar un nuevo nodo a la cola
//La única diferencia comparado con la lista: solo entra datos por el final!
void addNode(int x){

     Node* newnode = (Node*)malloc(sizeof(Node));                               //crea el nodo a agregar (reservamos memoria)
     
     if (head == NULL){                                                         //si es el primer nodo de la cola...
          head = newnode;                                                       //indicamos que es el primer nodo de la cola, es decir
          tail = newnode;                                                       //head y tail deben apuntar a nuestro primer nodo
          newnode->next = NULL;                                                 //y obviamente como también es el ultimo, su campo next debe apuntar a NULL
     }
     else{                                                                      //si no es el primer nodo de la cola...
          tail->next = newnode;                                                 //el que hasta ahora era el último tiene que apuntar al nuevo
          tail = newnode;                                                       //hacemos que el nuevo sea ahora el último
          newnode->next = NULL;                                                 //y hacemos que el que ahora es ultimo apunte a NULL, para indicar el fin de cola
     }
                                                                                //después de haber jugado con los punteros para ver donde pertenece nuestro nuevo nodo
     newnode->data = x;                                                         //asignamos la info requerida al campo de datos "data" del nuevo nodo
     
     printf("\nAgregado: %d...\n", x);                                          //hemos terminado: se muestra un mensaje de confirmación
     getch();                                                                   //espera a que el usuario presione una tecla
}

//Rutina para eliminar un nodo de la cola
//La única diferencia comparado al de la lista: no toma un data para buscar el nodo que lo tiene y eliminarlo, sino que solo elimina el primero!
void deleteNode(){
     
     Node* aux = head;                                                          //usamos un nodo auxiliar para poder recorrer la cola y encontrar donde vamos a borrar
     
     head = aux->next;                                                          //hace que head apunte al nodo después del primero
     printf("\nEliminado: %d...\n", aux->data);                                 //muestra confirmación     
     free(aux);                                                                 //libera el primer nodo
     getch();                                                                   //espera a presionar una tecla
     return;                                                                    //retorna al nivel anterior
}

//Rutina para imprimir todos los elementos de la cola
void printList()
{
     int i = 0;                                                                 //usamos un entero para contar los nodos de la cola
     Node* seek = head;                                                         //usamos un puntero auxiliar a un nodo para recorrer la cola
     
     if(head == NULL){                                                          //caso especial en que no hay nodos en la cola todavía
          printf("\nLa cola esta vacia!\n");                                   //un mensaje relacionado...
          return;                                                               //y de vuelta a donde estábamos
     }
     
     while(seek){                                                               //mientras no hayamos llegado al fin de la cola
          printf(" %d", seek->data);                                            //accesa al campo "data" asociado con el nodo actual e imprimelo
          seek = seek->next;                                                    //adquiere la dirección del siguiente elemento...
          i++;                                                                  //para contar cuantos nodos tenemos
     }
     
     printf("\n %d nodo(s) hasta ahora...\n", i);                               //organización en pantalla y muestra el contador
}
 
int main()
{    
     int pick, b;                                                               //variables para operar el menú principal
     
     while(true)                                                                //nos permite poder seguir mostrando el menu principal
     {
          //TODO: buscar como mostrarlo más bonito (limpiar pantalla siempre en esta posición)
          
          printList();                                                          //llama a printList() para imprimir la cola
          
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
			 
               case 2: deleteNode();                                            //llama a deleteNode
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
