#include <stdio.h>

int main()
{
     int variable=10;          /*x set to 10*/
     int* ptr= *variable;       /*ptr points to my variable*/
     *ptr = 100;               /*x is now set to 100 by dereferencing ptr, that is, we access
                               the variable to which ptr is pointing to and we change the 
                               variable's value*/
     printf("value = %d, address = %d", variable, ptr); 
     getch();
     return 0;
}
