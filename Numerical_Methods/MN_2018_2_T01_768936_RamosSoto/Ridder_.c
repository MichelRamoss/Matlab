 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <math.h>
 #include <stdbool.h>
 
main(void) {
     int opcion=0;
     int sub=0;
     int load;
}
ridder ()
 {
 	float A,B,C,D,E;
 	float Xo,Xi,Xm;
 	float a2,a1,a0;
 	float Xr;
	system("cls");
	printf("Ridder\n\n");
 	printf("Usaremos la forma: Ax^B+Cx^D+E dentro de un rango [Xo,Xi]\nIngrese su valor de A:\n");
 	scanf("%f",&A);
 	printf("Ingrese el valor de B:\n");
 	scanf("%f",&B);
 	printf("Ingrese el valor de C:\n");
 	scanf("%f",&C);
 	printf("Ingrese el valor de D:\n");
 	scanf("%f",&D);
 	printf("Ingrese el valor de E:\n");
 	scanf("%f",&E);
 	printf("Ingrese su valor inicial de Xo:\n");
 	scanf("%f",&Xo);
 	printf("Ingrese su valor inicial de Xi:\n");
 	scanf("%f",&Xi);
 	Xm=(Xo+Xi)/2;
 	a2=-(funcionr(A,B,C,D,E,Xi)/(Xi*Xm+Xi*Xo-Xm*Xo-pow(Xi,2)))-(funcionr(A,B,C,D,E,Xm)/(Xi*Xm-Xi*Xo+Xm*Xo-pow(Xm,2)))+(funcionr(A,B,C,D,E,Xo)/(Xi*Xm-Xi*Xo-Xm*Xo+pow(Xo,2)));
 	a1=((funcionr(A,B,C,D,E,Xi)*(Xm+Xo))/(Xi*Xm+Xi*Xo-Xm*Xo-pow(Xi,2)))+((funcionr(A,B,C,D,E,Xm)*(Xi+Xo))/(Xi*Xm-Xi*Xo+Xm*Xo-pow(Xm,2)))-((funcionr(A,B,C,D,E,Xo)*(Xi+Xm))/(Xi*Xm-Xi*Xo-Xm*Xo+pow(Xo,2)));
 	a0=-((funcionr(A,B,C,D,E,Xi)*(Xm*Xo))/(Xi*Xm+Xi*Xo-Xm*Xo-pow(Xi,2)))-((funcionr(A,B,C,D,E,Xm)*(Xi*Xo))/(Xi*Xm-Xi*Xo+Xm*Xo-pow(Xm,2)))+((funcionr(A,B,C,D,E,Xo)*(Xi*Xm))/(Xi*Xm-Xi*Xo-Xm*Xo+pow(Xo,2)));
 	printf("\n\na2=%.3f\ta1=%.3f\ta0=%.3f\n\n",a2,a1,a0);
	
 	Xr=(-a1+sqrt(pow(a1,2)-(4*a2*a0)))/(2*a2);
 	if (Xr<0)
 	{
 		float Xr2;
		Xr2=(-a1-sqrt(pow(a1,2)-(4*a2*a0)))/(2*a2);
 		if (Xr<0)
 			printf("\nLa ecuaci%cn %.1fx^%.1f+%.1fx^%.1f+%.1f no tiene ra%cz.",162,A,B,C,D,E,161);
 		else
 			printf("\nLa ecuaci%cn %.1fx^%.1f+%.1fx^%.1f+%.1f tiene ra%cz: %5.4f",162,A,B,C,D,E,161,Xr2);
 	}
 	else 
 		printf("\nLa ecuaci%cn %.1fx^%.1f+%.1fx^%.1f+%.1f tiene ra%cz: %5.4f",162,A,B,C,D,E,161,Xr);
	return 0;
 }
double Funcionn(int B, double X)
{
	switch (B)
	{
		case 1:
			return cos(X);
			break;
		case 2:
			return 10*X+5;
			break;
		case 3:
			return 8*(pow(X,3))+5;
			break;
	}
return 0;
}
