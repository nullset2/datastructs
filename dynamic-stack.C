/*Basado en mi trabajo anterior de listas din�micas, implementar� una pila con asignaci�n din�mica de memoria
Jos� Alfredo Gallegos C., Abril 2011*/

/*pila: estructura LIFO... Last-In, First-Out, esa es la clave para hacer f�cil la implementaci�n... solo tendr� que tweakear un poco mis m�dulos!*/

/*EL PROGRAMA YA FUNCIONA PERFECTAMENTE, pero tenemos
TODO: agregar validaci�n de entrada de datos para cuando se entran datos (que no se pueda entrar texto en lugar de numeros)*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado
#include <stdlib.h>                                                             //usando lib. estandar de C (funcion malloc())

//Definici�n del nodo
struct StackElement{                                                            //definimos la estructura del nodo de la pila
     int data;                                                                  //dato del nodo, un entero
     struct StackElement* next;                                                 //puntero al siguiente nodo de la pila despues de este
};                                                                              //por alguna raz�n aqu� debe ir un ;

typedef struct StackElement Node;                                               //Node debe ser definido como tipo de dato para uso en el programa
Node* head = NULL,* tail = NULL;                                                //puntero al primer y ultimo nodo de la pila, inicializa la pila al hacer head = null (no hay elementos)

//Rutina para agregar un nuevo nodo a la pila
//La �nica diferencia comparado con la lista: solo entra datos por el final!
void addNode(int x){

     Node* newnode = (Node*)malloc(sizeof(Node));                               //crea el nodo a agregar (reservamos memoria)
     
     if(head == NULL){                                                          //si es el primer nodo de la pila...
          head = newnode;                                                       //indicamos que es el primer nodo de la pila, es decir
          tail = newnode;                                                       //head y tail deben apuntar a nuestro primer nodo
          newnode->next = NULL;                                                 //y obviamente como tambi�n es el ultimo, su campo next debe apuntar a NULL
     }
     else{                                                                      //si no es el primer nodo de la pila...
          tail->next = newnode;                                                 //el que hasta ahora era el �ltimo tiene que apuntar al nuevo
          tail = newnode;                                                       //hacemos que el nuevo sea ahora el �ltimo
          newnode->next = NULL;                                                 //y hacemos que el que ahora es ultimo apunte a NULL, para indicar el fin de pila
     }
                                                                                //despu�s de haber jugado con los punteros para ver donde pertenece nuestro nuevo nodo
     newnode->data = x;                                                         //asignamos la info requerida al campo de datos "data" del nuevo nodo
     
     printf("\nAgregado: %d...\n", x);                                          //hemos terminado: se muestra un mensaje de confirmaci�n
     getch();                                                                   //espera a que el usuario presione una tecla
}

//Rutina para eliminar un nodo de la pila
//La �nica diferencia comparado al de la lista: no toma un data para buscar el nodo que lo tiene y eliminarlo, sino que solo elimina el final!
void deleteNode(){
     
     Node* seek = head;                                                         //usamos un nodo auxiliar para poder recorrer la lista y encontrar donde vamos a borrar
     Node* prev;                                                                //tambi�n otro nodo auxiliar para conservar una referencia del nodo anterior al borrando
     
     while(seek->next != NULL){                                                 //recorremos la pila hasta el final
          prev = seek;                                                          //guarda la locacion del nodo anterior
          seek = seek->next;                                                    //adquiere el valor de "next" en el nodo que ve y sigue recorriendo, no debe salirse de este while hasta encontrar el nodo que quiere
     }
     
     if(seek == head){                                                          //caso especial si va a borrar el inicio de la pila, es decir, no recorri� en el while
          head = NULL;                                                          //hace que head apunte al nodo despu�s del primero
          printf("\nEliminado: %d...\n", seek->data);                           //muestra confirmaci�n
          free(seek);                                                           //libera el primer nodo
          getch();                                                              //espera a presionar una tecla
          return;                                                               //retorna al nivel anterior
     }
     
     tail = prev;                                                               //tail apunta al anterior
     prev->next = NULL;                                                         //hace que dicho nodo ahora apunte a NULL dado que ahora es el final de la lista
     printf("\nEliminado: %d...\n", seek->data);                                //muestra mensaje de confirmaci�n
     free(seek);                                                                //libera el nodo que antes era el ultimo
     getch();                                                                   //espera a presionar una tecla
     return;                                                                    //retorna al nivel anterior
}

//Rutina para imprimir todos los elementos de la pila
void printList()
{
     int i = 0;                                                                 //usamos un entero para contar los nodos de la pila
     Node* seek = head;                                                         //usamos un puntero auxiliar a un nodo para recorrer la pila
     
     if(head == NULL){                                                          //caso especial en que no hay nodos en la pila todav�a
          printf("\nLa pila esta vacia!\n");                                    //un mensaje relacionado...
          return;                                                               //y de vuelta a donde est�bamos
     }
     
     while(seek){                                                               //mientras no hayamos llegado al fin de la pila
          printf(" %d", seek->data);                                            //accesa al campo "data" asociado con el nodo actual e imprimelo
          seek = seek->next;                                                    //adquiere la direcci�n del siguiente elemento...
          i++;                                                                  //para contar cuantos nodos tenemos
     }
     
     printf("\n %d nodo(s) hasta ahora...\n", i);                               //organizaci�n en pantalla y muestra el contador
}
 
int main()
{    
     int pick, b;                                                               //variables para operar el men� principal
     
     while(true)                                                                //nos permite poder seguir mostrando el menu principal
     {
          //TODO: buscar como mostrarlo m�s bonito (limpiar pantalla siempre en esta posici�n)
          
          printList();                                                          //llama a printList() para imprimir la pila
          
          printf("\n[1] Agrega elemento\n");                                    //impresiones del menu principal
          printf("[2] Borra elemento\n");
          printf("[3] Salir\n");
          printf("\n>>> ");                                                     //muestra prompt para que el usuario entre datos
          scanf("%d", &pick);                                                   //captura un entero del teclado y lo asigna a pick

          switch(pick)                                                          //decide qu� hacer basado en el valor de pick
          {
               case 1: printf("\nElemento >>> ");                               //mensaje para capturar elemento
                       scanf("%d",&b);                                          //captura elemento y asigna su valor a var. aux. b
		               addNode(b);                                              //llama pushElement con argumento b
                       printf("\n");                                            //organizaci�n!
	                   break;                                                   //cierra el switch(), regresa al nivel anterior
			 
               case 2: deleteNode();                                            //llama a deleteNode
                       printf("\n");                                            //organizaci�n!
                       break;                                                   //cierra el switch(), regresa al nivel anterior
                               
               case 3: printf("\nHasta luego (: ...\n");                        //un mensajito
                       getch();                                                 //espera a que se presione una letra
                       return 0;                                                //regresa 0 (ejecucion satisfactoria y terminada)
                            
               default: printf("\nOpcion invalida\n\n");                        //en caso que se entre algo incorrecto, luego regresa al while()
                        break;
          }
     }
}
