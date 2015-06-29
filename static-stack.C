/*Implementación de una pila estatica en C
José Alfredo Gallegos Chavarría (1383375), abril 2011*/

#include<stdio.h>                                                               //incluye lib. estándar I/O de C
#include<conio.h>                                                               //incluye lib. de esta crap
#define n 5

int top = 0, bottom = 0;                                                        //variables globales para manejar los extremos de la pila
int stack[n], aux[n];                                                           //la pila es de tamaño 5 estático, es accesible globalmente

//simple rutina para verificacion de vaciedad de pila
bool checkStackHasAvailableSpace()                   
{
     if((bottom == n && top == 0) || (bottom < top))                            //si el fin de la pila es pos. 5...o es el caso invalido (inicio antes del final por alguna maldita razón)
          return false;                                                         //retorna 'FALSO', NO es cierto que hay espacio
     else                                                                       //de otra manera, retorna 'VERDADERO'
          return true;                                                          
}

//rutina para agregar un elemento a la pila
void pushElement(int a)
{
     if(checkStackHasAvailableSpace()){                                         //valida si hay espacio disponible para poner el elem.
          if(bottom < n){                                                       //checa si se puede insertar para evitar overflow (no se están insertando > 5 elems.)                                  
	  	       stack[bottom] = a;                                               //asigna el valor de 'a' la posicion tope de la pila actual
		       bottom++;                                                        //aumenta bottom en 1
          }
          
          printf("\nAgregado: %d", a);
     }
     else
          printf("\nNo se puede agregar el elemento...!");                      //no debe imprimirse a menos que se haya intentado agregar cuando hay una pila llena
}

//rutina para quitar el elemento mas cercano al tope de la pila
void popElement()
{
     if(bottom < n + 1){                                                        //validacion para asegurarnos que no estamos saliendo de los 5 elems
          printf("\nQuitado: %d\n", stack[bottom - 1]);                         //muestra qué elemento se elimina
          stack[bottom - 1] = 0;                                                //zero-out yo!
          
          if(bottom > 0)                                                        //validación para evitar que bottom llegue a ser negativo
               bottom--;                                                        //decrecemos el bottom en 1 para compensar la perdida
     }
     else
          printf("\nNo se puede quitar el elemento...!");                       //nunca se debería de mostrar si todo está bien
}

//rutina para imprimir un mensaje adecuado dependiendo del estado de la pila
void printStackStatus(bool x)
{
     if(x){                                                                     //Si hay espacio en la pila...
          if(top == bottom)                                                     //...y no hay NINGUN ELEMENTO (unico caso en que st = bottom = 0)
               printf("\nPila vacia");
          else                                                                  //...y si hay otros elementos
               printf("\nHay espacio! Bien por ti!...\n");
     }
     else                                                                       //Si no hay espacio en la pila
          printf("\nPila llena...");
}

//Rutina para imprimir la pila en pantalla
void printStack()
{
     printf("\n");                                                              //para organización del espacio en pantalla
     for(int i = 0; i < n; i++){                                                //recorre todo el arreglo de stack
          printf(" %d ", stack[i]);                                             //...e imprimelo en pantalla
     }
     
     printf("\n\n");                                                            //para organización del espacio en pantalla
}

int main ()                                                                     //inicia ejecución del programa
{
     int b = 0, pick = 0;                                                       //variables locales para navegar y capturar datos
     
     while(bottom < n + 1)                                                      //nos permite poder seguir mostrando el menu principal
     {
          printf("\n[1] Agrega elemento\n");                                    //impresiones del menu principal
          printf("[2] Saca elemento\n");
          printf("[3] Verifica vaciedad\n");
          printf("[4] Imprime Elementos\n");
          printf("[5] Salir\n");
          printf("\n>>> ");                                                     //muestra prompt para que el usuario entre datos
          scanf("%d", &pick);                                                   //captura un entero del teclado y lo asigna a pick

          switch(pick)                                                          //decide qué hacer basado en el valor de pick
          {
               case 1: printf("\nElemento >>> ");                               //mensaje para capturar elemento
                       scanf("%d",&b);                                          //captura elemento y asigna su valor a var. aux. b
		               pushElement(b);                                          //llama pushElement con argumento b
                       printf("\n");
	                   break;                                                   //cierra el switch(), regresa al nivel anterior
			 
               case 2: popElement();                                            //llama a popElement con argumento b
                       printf("\n");
                       break;                                                   //cierra el switch(), regresa al nivel anterior
	 
               case 3: printStackStatus(checkStackHasAvailableSpace());         //llama a printStackStatus para mostrar el mensaje adecuado
                       printf("\n");                                            //dependiendo del estado de vaciedad de la pila
                       break;                                                   //cierra el switch(), regresa al nivel anterior
			 
               case 4: printStack();                                            //llama a printStack() para imprimir la pila
                       printf("\n");
                       break;                                                   //cierra el switch(), regresa al nivel anterior
   
               case 5: printf("\nHasta luego (: ...\n");                        //un mensajito
                       getch();                                                 //espera a que se presione una letra
                       return 0;                                                //regresa 0 (ejecucion satisfactoria y terminada)
                            
               default: printf("\n La opcion no correcta\n");                   //en caso que se entre algo incorrecto, luego regresa al while()
               break;
          }
     }
}
