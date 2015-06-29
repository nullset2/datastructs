/*Como una gran conclusión de todo lo visto, en este programa manejaremos un árbol binario de datos
José Alfredo Gallegos C., Abril 2011*/

#include <stdio.h>                                                              //usando lib. estandar IO de E/S de C
#include <conio.h>                                                              //usando lib. de entrada del teclado
#include <stdlib.h>                                                             //usando lib. estandar de C (funcion malloc())

//Definición del nodo
struct TreeElement{                                                             //definimos la estructura del nodo del arbol
     int data;                                                                  //dato del nodo, un entero
     struct ListElement* left;                                                  //puntero al siguiente nodo del arbol despues de este
     struct ListElement* right;
};

typedef struct TreeElement Node;                                                //Node debe ser definido como tipo de dato para uso en el programa
Node* head = NULL,* tail = NULL;                                                //puntero al primer y ultimo nodo del arbol, inicializa el arbol al hacer head = null (no hay elementos)

//Rutina para mostrar las opciones del menu principal
void printMenu(){
    printf("\n[1] Agrega elemento\n");                                          //impresiones del menu principal
    printf("[2] Borra elemento\n");
    printf("[3] Salir\n");
    printf("\n>>> ");                                                           //muestra prompt para que el usuario entre datos
}

//Rutina para agregar un nuevo nodo al arbol
void addNode(int x){

     Node* newnode = (Node*)malloc(sizeof(Node));                               //crea el nodo a agregar (reservamos memoria)
     
     if (head == NULL){                                                         //si es el primer nodo del arbol...
          head = newnode;                                                       //indicamos que es el primer nodo del arbol, es decir
          tail = newnode;                                                       //head y tail deben apuntar a nuestro primer nodo
          newnode->next = NULL;                                                 //y obviamente como también es el ultimo, su campo next debe apuntar a NULL
     }
     else{                                                                      //si no es el primer nodo del arbol...
          tail->next = newnode;                                                 //el que hasta ahora era el último tiene que apuntar al nuevo
          tail = newnode;                                                       //hacemos que el nuevo sea ahora el último
          newnode->next = NULL;                                                 //y hacemos que el que ahora es ultimo apunte a NULL, para indicar el fin de arbol
     }
                                                                                //después de haber jugado con los punteros para ver donde pertenece nuestro nuevo nodo
     newnode->data = x;                                                         //asignamos la info requerida al campo de datos "data" del nuevo nodo
     
     printf("\nAgregado: %d...\n", x);                                          //hemos terminado: se muestra un mensaje de confirmación
     getch();                                                                   //espera a que el usuario presione una tecla
}

//Rutina para eliminar un nodo del arbol
void deleteNode(int x){
     
     Node* seek = head;                                                         //usamos un nodo auxiliar para poder recorrer el arbol y encontrar donde vamos a borrar
     Node* prev;                                                                //también otro nodo auxiliar para conservar una referencia del nodo anterior al borrando
     
     while(seek->data != x){                                                    //recorremos mientras el valor de "data" en el nodo que está viendo no sea "x" (lo que queremos borrar)...
          prev = seek;                                                          //guarda la locacion del nodo anterior al de recorrido
          seek = seek->next;                                                    //adquiere el valor de "next" en el nodo que ve y sigue recorriendo, no debe salirse de este while hasta encontrar el nodo que quiere
          
          if(seek == NULL){                                                     //si no encontró el dato...
               printf("\nDato no presente en el arbol!...\n");                  //muestra mensaje relacionado
               getch();                                                         //espera a que se presione una tecla
               return;                                                          //retorna a nivel anterior
          }
     }
     
     if(seek == head){                                                          //caso especial si encontró el dato al inicio del arbol (seek = head), es decir, no recorrió en el while
          head = seek->next;                                                    //hace que head apunte al nodo después del primero
          free(seek);                                                           //libera el primer nodo
          printf("\nEliminado: %d...\n", x);                                    //muestra confirmación
          getch();                                                              //espera a presionar una tecla
          return;                                                               //retorna al nivel anterior
     }
     
     if(seek == tail){                                                          //caso especial si encontró el dato al final del arbol
          tail = prev;                                                          //tail apunta al anterior
          prev->next = NULL;                                                    //hace que dicho nodo ahora apunte a NULL dado que ahora es el final del arbol
          free(seek);                                                           //libera el nodo que antes era el ultimo
          printf("\nEliminado: %d...\n", x);                                    //muestra mensaje de confirmación
          getch();                                                              //espera a presionar una tecla
          return;                                                               //retorna al nivel anterior
     }
                                                                                //si encontró el dato en cualquier otro lugar
     prev->next = seek->next;                                                   //unimos el nodo anterior con el siguiente del eliminando...
     free(seek);                                                                //bye-bye motherfucker!
     
     printf("\nEliminado: %d...\n", x);                                         //mensaje de confirmación
     getch();                                                                   //espera a que el usuario presione una tecla
}

//Rutina para imprimir todos los elementos del arbol
void printTree()
{
     int i = 0;                                                                 //usamos un entero para contar los nodos del arbol
     Node* seek = head;                                                         //usamos un puntero auxiliar a un nodo para recorrer el arbol
     
     if(head == NULL){                                                          //caso especial en que no hay nodos en el arbol todavía
          printf("\nel arbol esta vacia!\n");                                   //un mensaje relacionado...
          return;                                                               //y de vuelta a donde estábamos
     }
     
     while(seek){                                                               //mientras no hayamos llegado al fin del arbol
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
          printTree();                                                          //llama a printTree() para imprimir el arbol
          printMenu();                                                          //llama a printMenu() para imprimir la lista principal de opciones
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
                            
               default: printf("\nOpcion invalida\n\n");                        //en caso que se entre algo incorrecto, luego regresa al while()
                        break;
          }
     }
}
