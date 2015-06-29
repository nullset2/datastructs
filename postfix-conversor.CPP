#include<stdio.h>
#include<conio.h>
 
int main(){

    int top = 0, apu = 0, tope = 0, tpos = 0, opera;
    char Ei[50], Pos[50], Pila[50];

    for(top=0;top<50;top++)
        Ei[top]=Pos[top]=Pila[top]='\0';

    printf("Conversor a Posfija\n");
   
    for(top=0;(Ei[top]=getchar()) != '\n';top++);
		do{           
			if('('==Ei[apu]){
				tope++;
				Pila[tope]=Ei[apu];
			}
       
			else{
             
				if(')'==Ei[apu]){           
					while(Pila[tope]!='('){
						Pos[tpos]=Pila[tope];
						tpos++; tope--;
					}
					Pila[tope]='\0';
					tope--;
				}
	   
				else{
					if(Ei[apu]!='^' && Ei[apu]!='/' && Ei[apu]!='*' && Ei[apu]!='+' && Ei[apu]!='-'){
						Pos[tpos]=Ei[apu];
						tpos++;
					}
	           
					else{
	               
						opera=1;
	               
						switch(Pila[tope]){
							case'^': if(Ei[apu]=='+'||Ei[apu]=='-'||Ei[apu]=='*'||Ei[apu]=='/'||Ei[apu]=='^')
										opera=0;
										break;
							case'/': if(Ei[apu]=='+'||Ei[apu]=='-'||Ei[apu]=='*'||Ei[apu]=='/')
										opera=0;
										break;
							case'*': if(Ei[apu]=='+'||Ei[apu]=='-'||Ei[apu]=='*')
										opera=0;
										break;
							case'+': if(Ei[apu]=='+'||Ei[apu]=='-')
										opera=0;
										break;
							case'-': if(Ei[apu]=='-')
										opera=0;
										break;
						}
               
						while(tope>0 && opera==0){
							Pos[tpos]=Pila[tope];
							tpos++; tope--;
						}
		       
						tope++;
						Pila[tope]=Ei[apu];
					}
				}
			}
			apu++;
		}

		while(top!=apu);
		while(tope>0){
			Pos[tpos]=Pila[tope];
			tpos++; tope--;
		}
	
	for(top=0;top!=tpos;top++) printf("%c",Pos[top]);
		getche();
   
	return 0;
}
