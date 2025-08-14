//Michel Abraham Ramos Soto
//768936
//Programa del metodo de biseccion.
//16/08/18

# include <stdio.h>
# include <math.h>
# include<conio.h>
# include<string.h>
# include<process.h>
#define TOL 0.000005
#define f(x) sin(3*x-2)

void falsaposicion();

int main() {
	printf("\n Solucion por Falsa posicion \n");
	printf("\n La Ecuacion a resolver es: ");
	printf("\n\t\t\t sin(3x-2) \n\n");
falsaposicion();	
}

void falsaposicion(){
	float f0,f1,f2;
	float x0,x1,x2;
	int itr;
	int i;
	printf("Numero de iteracciones: ");
	scanf("%d",&itr);
	for(x1=0.0;;){
		f1=f(x1);
		if (f1>0){
			break;
		}
		 else {
		 	x1 = x1+0.1;
		 }
	}
			
	x0= x1-0.1;
	f0 = f(x0);
	printf("\n\t");
	printf("\n\t\t Iteraccion\t x\t\t F(X) \n");
	printf("\n\t");
	  for(i=0;i<itr;i++){
	  	x2 = x0-((x1-x0)/(f1-f0))*f0;
	  	f2=f(x2);
	  	 if(f0*f2>0){
	  	 	x1=x2;
	  	 	f1=f2;
	  	 }
	  	   else {
	  	    	x0=x2;
	  	    	f0=f2;
	  	   }
	  	     if (fabs(f(2))>TOL){
	  	     	printf("\n\t\t%d\t%f\t%f\n",i+1,x2,f2);
	  	     }
	  }
	  printf("\t");
	  printf("\n\t\t\t Raiz= %f\n",x2);
	  printf("\t");
	  getch();
			}
