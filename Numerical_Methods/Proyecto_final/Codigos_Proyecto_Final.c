//Proyecto Final
//Metodos numericos

 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <math.h>
 #include <stdbool.h>
 
 //Funciones que imprimen los diferentes menus en pantalla
 mostrar_menu()
 {
 	printf("Proyecto Final\nMetodos numericos\n\n");
 	printf("Seleccione el m%ctodo a usar:\n",130);
 	printf("1)Determinaci%cn de ra%cces algebraicas\n2)Soluci%cn de sistemas de ecuaciones algebraicas\n",162,161,162,162,161);
 	printf("3)Ajuste polinomial y funcional\n",162,162,130,162,130);
 	printf("4)Salir\n");
 	return 0;
 }
 mostrar_submenu1()
 {
 	printf("Determinaci%cn de ra%cces algebraicas\n\nSeleccione el subm%ctodo a usar:\n",162,161,130);
	printf("1)Bisecci%cn\n2)Falsa posici%cn\n3)Ridder\n4)Newton-Raphson",162,162,162);
 	printf("\n5)M%ctodo de la Secante\n6)Muller\n7)Bairstow\n",130,161,163,162,162,162);
 	return 0;
 }
 mostrar_submenu2()
 {
 	printf("Soluci%cn de sistemas de ecuaciones algebraicas\n\nSeleccione el subm%ctodo a usar:\n",162,130);
	printf("1)Eliminaci%cn de Gauss\n2)Descomposici%cn LU e inversi%cn de matrices\n3)Matrices y el m%ctodo de Gauss-Seidel\n",162,162,162,130);
	return 0;
 	
 }
 mostrar_submenu3()
 {
 	printf("Ajuste polinomial y funcional\n\nSeleccione el subm%ctodo a usar:\n",130);
	printf("1)Regresi%cn por m%cnimos cuadrados\n2)Interpolaci%cn\n",162,161,162,162);
	return 0;
 }
//Funciones que aplican los temas vistos en clase.
double Funcionb(int B, double X)
{
	switch (B)
	{
		case 1:
			return sin(X);
			break;
		case 2:
			return 5*(pow(X,2))+5*X-4;
			break;
		case 3:
			return 2*(pow(X,4))+5*X-4;
			break;
	}
}
 biseccion()
 {
 	int ec;
	system("cls");
	printf("Bisecci%cn\n\n",162);
 	printf("Qu%c ecuaci%cn desea aplicar?\n1)Sin(x)\n2)5x^2+5x-4\n3)2x^4+5x-4\n",130,162);
 	scanf("%d",&ec);
	double a, b, Error;
	int Max_Iter;
	double Error_Aprox, Prod;
	double Xr, Xn;
	int Ciclos = 0;
	printf("Dar el valor de Xi\n");
	scanf("%lf",&a);
	printf("\nDar el valor de Xf\n");
	scanf("%lf",&b);
	printf("\nCu%cl es el error permitido\n",160);
	scanf("%lf",&Error);
	printf("\nCu%cl es el m%cximo de ciclos\n",160,160);
	scanf("%d",&Max_Iter);
	if(Funcionb(ec,a)*Funcionb(ec,b)>0)
	{
		printf("\n No existe ra%cz en el intervalo\n",161);
	}
	else
	{
		Xr=(a+b)/2;
		Error_Aprox=((Xr-b)/Xr)*100;
		if (Error_Aprox<0)
		{
			Error_Aprox=Error_Aprox*(-1);	
		}
		printf("\n------------------------------------------------------------------------");
		Error_Aprox = 1;
		printf("\nCiclo\t\ta\t\tb\t\tXn\t\tError");
		printf("\n------------------------------------------------------------------------");
		printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
		while (Ciclos<=Max_Iter && Error<Error_Aprox)
		{
			Prod=Funcionb(ec,a)*Funcionb(ec,b);
			if (Prod==0)
				printf("La ra%cz es %lf",161,Xr);
			else
			{
				if(Prod<0)
					b=Xr;
				else
					a=Xr;
			}
			Xn=(a+b)/2;
			Ciclos+=1;
			Error_Aprox=((Xn-Xr)/Xn)*100;
			if (Error_Aprox<0)
			{
				Error_Aprox=Error_Aprox*(-1);	
			}
			printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
			Xr=Xn;
		}
		if(Ciclos<Max_Iter)
		{
			printf("\n------------------------------------------------------------------------");
			printf("\n\n La ra%cz de la ecuaci%cn es: %lf",161,162,Xn);
			printf("\n Se encontr%c en %d iteraciones",162,Ciclos);
		}
		else
			printf("\n No se encontr%c ra%cz en %d Iteraciones",162,161,Ciclos);
	}
	return 0;
}
 falsa_posicion ()
 {
 	int ec;
	system("cls");
	printf("Falsa posici%cn\n\n",162);
	printf("Qu%c ecuaci%cn desea aplicar?\n1)Sin(x)\n2)5x^2+5x-4\n3)2x^4+5x-4\n",130,162);
 	scanf("%d",&ec);
 	double a, b, Error;
	int Max_Iter;
	double Error_Aprox, Prod;
	double Xr, Xn;
	int Ciclos = 0;
	printf("Dar el valor de Xi\n");
	scanf("%lf",&a);
	printf("\nDar el valor de Xf\n");
	scanf("%lf",&b);
	printf("\nCu%cl es el error permitido\n",160);
	scanf("%lf",&Error);
	printf("\nCu%cl es el m%cximo de ciclos\n",160,160);
	scanf("%d",&Max_Iter);
	if(Funcionb(ec,a)*Funcionb(ec,b)>0)
	{
		printf("\n No existe ra%cz en el intervalo\n",161);
	}
	else
	{
		Xr=(a*Funcionb(ec,b)-b*Funcionb(ec,a))/(Funcionb(ec,b)-Funcionb(ec,a));
		Error_Aprox=((Xr-b)/Xr)*100;
		if (Error_Aprox<0)
		{
			Error_Aprox=Error_Aprox*(-1);	
		}
		printf("\n------------------------------------------------------------------------");
		Error_Aprox = 1;
		printf("\nCiclo\t\ta\t\tb\t\tXn\t\tError");
		printf("\n------------------------------------------------------------------------");
		printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
		while (Ciclos<=Max_Iter && Error<Error_Aprox)
		{
			Prod=Funcionb(ec,a)*Funcionb(ec,b);
			if (Prod==0)
				printf("La ra%cz es %lf",161,Xr);
			else
			{
				if(Prod<0)
					b=Xr;
				else
					a=Xr;
			}
			Xn=(a*Funcionb(ec,b)-b*Funcionb(ec,a))/(Funcionb(ec,b)-Funcionb(ec,a));
			Ciclos+=1;
			Error_Aprox=((Xn-Xr)/Xn)*100;
			if (Error_Aprox<0)
			{
				Error_Aprox=Error_Aprox*(-1);	
			}
			printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
			Xr=Xn;
		}
		if(Ciclos<Max_Iter)
		{
			printf("\n------------------------------------------------------------------------");
			printf("\n\n La ra%cz de la ecuaci%cn es: %lf",161,162,Xn);
			printf("\n Se encontr%c en %d iteraciones",162,Ciclos);
		}
		else
			printf("\n No se encontr%c ra%cz en %d Iteraciones",162,161,Ciclos);
	}
 	return 0;
 }
float funcionr(float a,float b,float c,float d,float e,float X)
 {
	return (a*pow(X,b))+(c*pow(X,d))+e;
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
}
 NR ()
 {
 	int ec;
	system("cls");
	printf("Newton-Raphson\n\n");
	printf("Qu%c ecuaci%cn desea aplicar?\n1)Sin(x)\n2)5x^2+5x-4\n3)2x^4+5x-4\n",130,162);
 	scanf("%d",&ec);
 	double a, Error;
	int Max_Iter;
	double Error_Aprox, Prod;
	double Xr, Xn;
	int Ciclos = 0;
	printf("Dar el valor de Xi\n");
	scanf("%lf",&a);
	printf("\nCu%cl es el error permitido\n",160);
	scanf("%lf",&Error);
	printf("\nCu%cl es el m%cximo de ciclos\n",160,160);
	scanf("%d",&Max_Iter);
		
	Xr=a-(Funcionb(ec,a)/Funcionn(ec,a));
	Error_Aprox=((Xr-a)/Xr)*100;
	if (Error_Aprox<0)
	{
		Error_Aprox=Error_Aprox*(-1);	
	}
	printf("\n------------------------------------------------------------------------");
	Error_Aprox = 1;
	printf("\nCiclo\t\ta\t\tXn\t\tError");
	printf("\n------------------------------------------------------------------------");
	printf("\n%3d\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,Error_Aprox);
	while (Ciclos<=Max_Iter && Error<Error_Aprox)
	{
		a=Xr;
		Xn=a-(Funcionb(ec,a)/Funcionn(ec,a));
		Ciclos+=1;
		Error_Aprox=((Xn-Xr)/Xn)*100;
		if (Error_Aprox<0)
		{
			Error_Aprox=Error_Aprox*(-1);	
		}
		printf("\n%3d\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,Error_Aprox);
		Xr=Xn;
	}
	if(Ciclos<Max_Iter)
	{
		printf("\n------------------------------------------------------------------------");
		printf("\n\n La ra%cz de la ecuaci%cn es: %lf",161,162,Xn);
		printf("\n Se encontr%c en %d iteraciones",162,Ciclos);
	}
	else
		printf("\n No se encontr%c ra%cz en %d Iteraciones",162,161,Ciclos);
 	return 0;
 }
 secante ()
 {
 	int ec;
	system("cls");
	printf("Secante\n\n");
	printf("Qu%c ecuaci%cn desea aplicar?\n1)Sin(x)\n2)5x^2+5x-4\n3)2x^4+5x-4\n",130,162);
 	scanf("%d",&ec);
 	double a, b, Error;
	int Max_Iter;
	double Error_Aprox, Prod;
	double Xr, Xn;
	int Ciclos = 0;
	printf("Dar el valor de Xi\n");
	scanf("%lf",&a);
	printf("\nDar el valor de Xf\n");
	scanf("%lf",&b);
	printf("\nCu%cl es el error permitido\n",160);
	scanf("%lf",&Error);
	printf("\nCu%cl es el m%cximo de ciclos\n",160,160);
	scanf("%d",&Max_Iter);
	Xr=a-(((b-a)/(Funcionb(ec,b)-Funcionb(ec,a)))*Funcionb(ec,a));
	Error_Aprox=((Xr-b)/Xr)*100;
	if (Error_Aprox<0)
	{
		Error_Aprox=Error_Aprox*(-1);	
	}
	printf("\n------------------------------------------------------------------------");
	printf("\nCiclo\t\ta\t\tb\t\tXn\t\tError");
	printf("\n------------------------------------------------------------------------");
	printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
	while (Ciclos<=Max_Iter && Error<Error_Aprox)
	{
		a=b;
		b=Xr;
		Xn=a-(((b-a)/(Funcionb(ec,b)-Funcionb(ec,a)))*Funcionb(ec,a));
		Ciclos+=1;
		Error_Aprox=((Xn-Xr)/Xn)*100;
		if (Error_Aprox<0)
		{
			Error_Aprox=Error_Aprox*(-1);	
		}
		printf("\n%3d\t%10.4f\t%10.4f\t%10.4f\t%10.4f",Ciclos,a,b,Xr,Error_Aprox);
		Xr=Xn;
	}
	if(Ciclos<Max_Iter)
	{
		printf("\n------------------------------------------------------------------------");
		printf("\n\n La ra%cz de la ecuaci%cn es: %lf",161,162,Xn);
		printf("\n Se encontr%c en %d iteraciones",162,Ciclos);
	}
	else
		printf("\n No se encontr%c ra%cz en %d Iteraciones",162,161,Ciclos);
 	return 0;
 }
 muller ()
 {
 	system("cls");
	printf("Muller\n\n");
	float A,B,C,D,E;
 	float Xo,X1,X2;
 	float a2,a1,a0;
 	float Xr,Xn;
 	int Max_Iter,Ciclos=0;
	double Error_Aprox,Error;
	system("cls");
	printf("Ridder\n\n");
 	printf("Usaremos la forma: Ax^B+Cx^D+E con valores iniciales Xo, X1 y X2.\nIngrese su valor de A:\n");
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
 	printf("Ingrese su valor inicial de X1:\n");
 	scanf("%f",&X1);
 	printf("Ingrese su valor inicial de X2:\n");
 	scanf("%f",&X2);
 	printf("\nCu%cl es el error permitido\n",160);
	scanf("%lf",&Error);
	printf("\nCu%cl es el m%cximo de ciclos\n",160,160);
	scanf("%d",&Max_Iter);
 	float d0,d1,h0,h1;
 	h0=X1-Xo;
 	h1=X2-X1;
 	d0=(funcionr(A,B,C,D,E,X1)-funcionr(A,B,C,D,E,Xo))/h0;
 	d1=(funcionr(A,B,C,D,E,X2)-funcionr(A,B,C,D,E,X1))/h1;
 	a0=(d1-d0)/(h1+h0);
 	a1=a0*h1+d1;
 	a2=funcionr(A,B,C,D,E,X2);
 	if (a1>=0)
 		Xr=X2+((-2*a2)/(a1+sqrt(pow(a1,2)-4*a0*a2)));
 	else
 	{
 		Xr=X2+((-2*a2)/(a1-sqrt(pow(a1,2)-4*a0*a2)));
 	}
 	Error_Aprox=((Xr-X2)/Xr)*100;
	if (Error_Aprox<0)
	{
		Error_Aprox=Error_Aprox*(-1);	
	}
 	printf("\n------------------------------------------------------------------------");
	printf("\nCiclo  Xo\t\tX1\t\tX2\t\tX3\tError");
	printf("\n------------------------------------------------------------------------");
	printf("\n%3d  %10.4f\t%10.4f\t%10.4f\t%10.4f\t%10.4lf",Ciclos,Xo,X1,X2,Xr,Error_Aprox);
	while (Ciclos<=Max_Iter&&Error<Error_Aprox)
	{
		Xo=X1;
		X1=X2;
		X2=Xr;
		h0=X1-Xo;
 		h1=X2-X1;
 		d0=(funcionr(A,B,C,D,E,X1)-funcionr(A,B,C,D,E,Xo))/h0;
 		d1=(funcionr(A,B,C,D,E,X2)-funcionr(A,B,C,D,E,X1))/h1;
 		a0=(d1-d0)/(h1+h0);
 		a1=a0*h1+d1;
 		a2=funcionr(A,B,C,D,E,X2);
		if (a1>=0)
 			Xn=X2+((-2*a2)/(a1+sqrt(pow(a1,2)-4*a0*a2)));
 		else
 		{
 			Xn=X2+((-2*a2)/(a1-sqrt(pow(a1,2)-4*a0*a2)));	
 		}
		Ciclos+=1;
		Error_Aprox=((Xn-X2)/Xn)*100;
		if (Error_Aprox<0)
		{
			Error_Aprox=Error_Aprox*(-1);	
		}
		Xr=Xn;
		printf("\n%3d  %10.4f\t%10.4f\t%10.4f\t%10.4f\t%10.4lf",Ciclos,Xo,X1,X2,Xr,Error_Aprox);
	}
	if(Ciclos<Max_Iter)
	{
		printf("\n------------------------------------------------------------------------");
		printf("\n\n La ra%cz de la ecuaci%cn es: %.4f",161,162,Xr);
		printf("\n Se encontr%c en %d iteraciones",162,Ciclos);
	}
	else
		printf("\n No se encontr%c ra%cz en %d Iteraciones",162,161,Ciclos);
 	return 0;
 }
 bairstow ()
 {
 	system("cls");
	printf("Bairstow\n\n");
	int n, m,w,np,contadorConver,k,z,nx,mx;
	float r,s,e,dr,ds,error,newsize,r0,s0;
	printf("Introduzca el grado del polinomo:\n");
	scanf("%d",&n);
	n++;
	w=contadorConver=z=0; //contador repeticiones proceso
	m=n-1;
	float C[n],Mr[n],Ms[n],Mat1[n],Mat2[m],raizReal[n],raizImaginaria[n];
	float raiz;
	int i,j;
	for (i=0;i<n;i++)
	{
		Mr[i]=Ms[i]=Mat1[i]=raizReal[i]=raizImaginaria[i]=0;
	}
	printf("Introduzca los coeficientes del polinomio (El primer coeficiente=1 autom%cticamente)\n",162,160);
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			C[i]=1;
		}
		else
		{
			printf("Introduzca el coeficiente de x^%d:\n",-i+(n-1));
			scanf("%f",&C[i]);	
		}
	}
	printf("Introduzca el valor inicial de r:\n");
	scanf("%f",&r0);
	printf("Introduzca el valor inicial de s:\n");
	scanf("%f",&s0);
	printf("Introduzca el valor del error de convergencia:\n");
	scanf("%f",&error);
	printf("Introduzca numero maximo de iteraciones:\n");
	scanf("%d",&k);
	dr=ds=1;
	printf("\nSu polinomio es: ");
	for(i=0;i<n;i++)
	{
		int aux;
		aux=n-i;
		printf("%.3fX^%d",C[i],aux);
	}
	for(j=0;j<2*(n-1);j=j+2) //Se suman 2 al contador porque se guardan 2 valores en las raices (j y j+1)
	{	
		dr=ds=1;
		np=(n-1)-2*w; //np es el grado del polinomio a dividir
		nx=n-1-2*w;
		mx=nx-1;
		if(np<=2)
		{
			if(np==2)
			{
				raiz=(C[1]*C[1])-(4*C[2]);
				if(raiz < 0)
				{
					raiz=abs(raiz);
					raizReal[j]=(-C[1])/2;
					raizReal[j+1]=(-C[1])/2;
					raizImaginaria[j]=sqrt(raiz)/2;
					raizImaginaria[j+1]=-sqrt(raiz)/2;
				}
				else 
				{
					raizReal[j]=((-C[1])+(sqrt(raiz)))/2;
					raizReal[j+1]=((-C[1])-(sqrt(raiz)))/2;
					raizImaginaria[j]=0;
					raizImaginaria[j+1]=0;	
				}
			}
			else
			{
				raizReal[j]=-C[1];
			}
			break;
		}
		else
		{
			contadorConver=0;
			r=r0;
			s=s0;
			for(i=0;i<=np;i++)
			{
				Mr[i]=Ms[i]=Mat1[i]=Mat2[i]=0; //regresa a 0 Mr y Ms
			}
			while(abs(dr)>error||abs(ds)>error)
			{ 
				for (i=0;i<=np;i++)
				{
					Mat1[i]=C[i]+Mr[i]+Ms[i]; //hace la primera division sintetica
					Mr[i+1]=(-r)*(Mat1[i]);
					Ms[i+2]=(-s)*(Mat1[i]);
				}
				for (i=0;i<=np;i++)
				{
					Mr[i]=Ms[i]=0; //regresa a 0 Mr y Ms
				}
				for (i=0;i<np;i++) //segunda division sintetica
				{
					Mat2[i]=-Mat1[i]+Mr[i]+Ms[i];
					Mr[i+1]=(-r)*(Mat2[i]);
					Ms[i+2]=(-s)*(Mat2[i]);
				}	
				dr=(((Mat2[mx-1])*(-Mat1[nx-1]))-((-Mat1[nx])*(Mat2[mx-2])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2]))); //cramer
				ds = (((-Mat1[nx])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(-Mat1[nx-1])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2])));
				r=r+dr;
				s=s+ds;
				contadorConver++;
				if(contadorConver>k)
				{
					printf("\nFallo en la convergencia\n");
					break;
				}	
				z++;
			}
			raiz=(r*r)-(4*s);
			if(raiz<0)
			{
				raiz=abs(raiz);
				raizReal[j]=-r/2;
				raizReal[j+1]=-r/2;
				raizImaginaria[j]=sqrt(raiz)/2;
				raizImaginaria[j+1]=-sqrt(raiz)/2;
			}
			else 
			{
				raizReal[j]=((-r)+(sqrt(raiz)))/2;
				raizReal[j+1]=((-r)-(sqrt(raiz)))/2;
				raizImaginaria[j]=0;
				raizImaginaria[j+1]=0;	
			}
			w++;
			newsize=(n-1)-(2*w);
			for(i=0;i<=newsize;i++)
				C[i]=Mat1[i];
		}
	}
	printf("Raices:\n");
	for(i=0;i<n-1;i++)
	{
		if(raizImaginaria[i]==0)
			printf("X%d=%f\n",i,raizReal[i]);
		else
			printf("X%d=%.4f %.4fi",i,raizReal[i],raizImaginaria[i]);
	}

 	return 0;
}
 EG ()
 {
 	system("cls");
	printf("Elimincaci%cn de Gauss\n\n",162);
	int i,j,k,n;
	double m[20][20],aux;
	printf("N%cmero de ecuaciones N=\n",163);
	scanf("%d",&n);
	printf("\nDigite los elementos de la matriz en la posici%cn:",162);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nM[%d,%d]=",i,j);
			scanf("%lf",&m[i][j]);
		}
		printf("\nTermino independiente de X%d\n",i);
		scanf("%lf",&m[i][n+1]);
	}
	printf("\nSu sistema de ecuaciones ingresado es:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3lfX%d+",m[i][j],(n+1)-j);
		}
		printf("=%5.3lf\n",m[i][n+1]);
	}
	printf("\nLa matriz ingresada es:\n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3lf\t",m[i][j]);
		}
		printf("\n\n");
	}
	for(i=1;i<=n;i++)
	{
		if(m[i][i]!=0)
		{
			aux=1/m[i][i];
			for(j=1;j<=n+1;j++)
			{
				m[i][j]=aux*m[i][j];
			}
			for(j=1;j<=n;j++)
			{
				if(j!=i)
				{
					aux=-m[j][i];
					for(k=1;k<=n+1;k++)
					{
						m[j][k]=m[j][k]+aux*m[i][k];
					}
				}
			}
		}
	}
	printf("\nLa matriz identidad es:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3lf\t",m[i][j]);
		}
		printf("\n\n");
	}
	printf("El valor de las incognitas es :");
	for(i=1;i<=n;i++)
	{
		printf("\nX%d=%5.3lf\n",i,m[i][n+1]);
	}
 	return 0;
 }
 LU ()
 {
 	system("cls");
	printf("Descomposici%cn LU e inversi%cn de matrices\n\n",162,162);
	int n,m,i,j,k;
	double a[20][20],b[20][20],apoyo;
	printf("\nIngrese el n%cmero de Ecuaciones N=\n",163);
	scanf("%d",&n);
	printf("\nDigite los elementos de la matriz en la posici%cn:",162);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nM[%d,%d]=",i,j);
			scanf("%lf",&a[i][j]);
		}
		printf("\nTermino independiente de X%d\n",i);
		scanf("%lf",&a[i][n+1]);
	}
	printf("\nSu sistema de ecuaciones ingresado es:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3lfX%d+",a[i][j],(n+1)-j);
		}
		printf("=%5.3lf\n",a[i][n+1]);
	}
	printf("\nLa matriz ingresada es:\n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3lf\t",a[i][j]);
		}
		printf("\n\n");
	}
	m=n+1;
	do
	{
		if(a[1][1]==0)
		{
			k=m-1;
			for(i=2;i<=k;i++)
			{
				if(a[i][1]!=0)
				{
					for(j=1;j<=m;j++)
					{
						apoyo=a[i][j];               
						a[i][j]=a[1][j];
						a[1][j]=apoyo;
					}
				}				
			}
		}
		else
		{
			for(j=2;j<=m;j++)
			{
				for(i=2;i<=n;i++)
				{
					b[i-1][j-1]=a[i][j]-a[1][j]*a[i][1]/a[1][1];
				}
			}
			for(j=2;j<=m;j++)
			{
				b[n][j-1]=a[1][j]/a[1][1];
			}
			m=m-1;
			for(j=1;j<=m;j++)
			{
				for(i=1;i<=n;i++)
				{
					a[i][j]=b[i][j];
				}
			}
		}
	}
	while(m>1);
	printf("El valor de las incognitas es :");
	for(i=1;i<=n;i++)
	{
		printf("\nX%d=%5.3lf",i,a[i][1]);
	}
 	return 0;
 }
 MGS ()
 {
 	int n,i,j;
	float A[20][20],B[20];
	float Error,S[20],OS[20],E[20];
	system("cls");
	printf("Matrices y el m%ctodo de Gauss-Seidel\n\n",130);
	printf("N%cmero de ecuaciones N=\n",163);
	scanf("%d",&n);
	printf("\nCu%cl es el error permitido\n",160);
	scanf("%f",&Error);
	printf("\nDigite los elementos de la matriz en la posici%cn:",162);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nM[%d,%d]=",i,j);
			scanf("%f",&A[i][j]);
		}
		printf("\nTermino independiente de X%d\n",i);
		scanf("%f",&B[i]);
	}
	printf("\nSu sistema de ecuaciones ingresado es:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5.3fX%d+",A[i][j],(n+1)-j);
		}
		printf("=%5.3f\n",B[i]);
	}
	for (i=0;i<n;++i)
	{
		S[i]=0;
		OS[i]=0;
		E[i] = (S[i]-OS[i]);
	}
	bool errorCheck=false;
	int cont=0;
	printf("\n------------------------------------------------------------------------");
	while(!errorCheck)
	{
		printf("\nIteraci%cn %d:\n",162,cont);
		for (i=0;i<n;++i)
		{
			double sum=0;
			for (j=0;j<n;++j)
			{
				if (j!=i)
				{
					sum+=A[i][j]*S[j];
				}
			}
			OS[i]=S[i];
			S[i]=(B[i]-sum)/A[i][i];
			E[i]=(S[i]-OS[i]);
			printf("(%5.4f,%5.4f)",S[i],abs(E[i]));
		}
		for (i=0;i<n;++i)
		{
			if(abs(E[i])>Error)
			{
				break;
			}
			errorCheck=true;
		}
		cont++;
	}
	printf("\nResultados:\n");
	for (i=0;i<n;++i)
	{
		printf("X%d=%5.4f\n",i,S[i]);
	}
	printf("\nSe realiz%c en %d iteraciones.\n",162,cont);
 	return 0;
 }
 RMC ()
 {
 	system("cls");
	printf("Regresi%cn por m%cnimos cuadrados\n\n",162,161);
	int n,i;
	float x[20],y[20];
	float k,t,w,k2,m,b;
	do
	{
		printf("Cu%cntos puntos tiene? (m%cnimo 2,m%cximo 20).\n",160,161,160);
		scanf("%d",&n);
		if(n<2||n>20)
			printf("Ingrese un n%cmero entre 2 y 20.\n");
	}
	while(n<2||n>20);
	for(i=0;i<n;i++)
	{
		printf("Ingrese el valor de X%d:\n",i+1);
		scanf("%f",&x[i]);
		printf("Ingrese el valor de Y%d:\n",i+1);
		scanf("%f",&y[i]);
	}
	printf("\nUsted ingres%c los siguientes pares de n%cmeros:\n",162,163);
	for(i=1;i<=n;i++)
	{
		printf("\n%d) [%5.3f,%5.3f]\t",i,x[i],y[i]);
			
	}
  	for(i=0;i<n;i++)
	{
		k+=x[i];
		t+=y[i];
		w+=(x[i])*(y[i]);
		k2+=(x[i])*(x[i]);
	}
	m=(n*w-k*t)/(n*k2-k*k);
	printf("La pendiente ajustada por m%cnimos cuadrados es m=%f\n",161,m);
	k=0;
	t=0;
	w=0;
	k2=0;
	for(i=0;i<n;i++)
	{
		k+=x[i];
		t+=y[i];
		w+=(x[i])*(y[i]);
  		k2+=(x[i])*(x[i]);
	}
	b=(t*k2-k*w)/(n*k2-k*k);
	printf("\nEl punto de corte por m%cnimos cuadrados es b=%f\n",161,b);
 	return 0;
 }
 interpolacion ()
 {
 	float A,B,C,D,E,r,X;
	int e;
	float Xo,X1,X2,X3;
	float bo,b1,b2,b3;
	system("cls");
	printf("Interpolaci%cn\n\n",162);
	printf("Usaremos la forma: Ax^B+Cx^D+E\nIngrese su valor de A:\n");
 	scanf("%f",&A);
 	printf("Ingrese el valor de B:\n");
 	scanf("%f",&B);
 	printf("Ingrese el valor de C:\n");
 	scanf("%f",&C);
 	printf("Ingrese el valor de D:\n");
 	scanf("%f",&D);
 	printf("Ingrese el valor de E:\n");
 	scanf("%f",&E);
 	printf("Ingrese la X a encontrar:\n");
 	scanf("%f",&X);
 	printf("\nEl polinomio ingresado es:\n%.3fx^%.3f+%.3fx^%.3f+%.3f\nCon el punto X=%.3f a encontrar.\n",A,B,C,D,E,X);
	printf("\nDesea hacer la interpolaci%cn\n1)Lineal\n2)Cuadr%ctica\n3)C%cbica\n",162,160,163);
	scanf("%d",&e);
	switch (e)
	{
		case 1:
			system("cls");
			printf("\nInterpolaci%cn lineal\nSe usar%cn dos puntos iniciales:\n",162,160);
			printf("Ingrese su valor inicial de Xo:\n");
 			scanf("%f",&Xo);
 			printf("Ingrese su valor inicial de X1:\n");
 			scanf("%f",&X1);
 			bo=funcionr(A,B,C,D,E,Xo);
 			b1=(funcionr(A,B,C,D,E,X1)-funcionr(A,B,C,D,E,Xo))/(X1-Xo);
			r=bo+(b1*(X-Xo));
			printf("\nEl polinomio ingresado es:\n%.3fx^%.3f+%.3fx^%.3f+%.3f\n",A,B,C,D,E,X);
			printf("\nLa funci%cn evaluada en X=%f es:\nf(%f)=%f\n",162,X,X,r);
			break;
		case 2:
			system("cls");
			printf("\nInterpolaci%cn cuadr%ctica\nSe usar%cn tres puntos iniciales:\n",162,160,160);
			printf("Ingrese su valor inicial de Xo:\n");
 			scanf("%f",&Xo);
 			printf("Ingrese su valor inicial de X1:\n");
 			scanf("%f",&X1);
 			printf("Ingrese su valor inicial de X2:\n");
 			scanf("%f",&X2);
 			bo=funcionr(A,B,C,D,E,Xo);
 			b1=(funcionr(A,B,C,D,E,X1)-funcionr(A,B,C,D,E,Xo))/(X1-Xo);
 			b2=(((funcionr(A,B,C,D,E,X2)-funcionr(A,B,C,D,E,X1))/(X2-X1))-b1)/(X2-Xo);
			r=bo+(b1*(X-Xo))+(b2*(X-Xo)*(X-X1));
			printf("\nEl polinomio ingresado es:\n%.3fx^%.3f+%.3fx^%.3f+%.3f\n",A,B,C,D,E,X);
			printf("\nLa funci%cn evaluada en X=%f es:\nf(%f)=%f\n",162,X,X,r);
			break;
		case 3:
			system("cls");
			printf("\nInterpolaci%cn c%cbica\nSe usar%cn cuatro puntos iniciales:\n",162,163,160);
			printf("Ingrese su valor inicial de Xo:\n");
 			scanf("%f",&Xo);
 			printf("Ingrese su valor inicial de X1:\n");
 			scanf("%f",&X1);
 			printf("Ingrese su valor inicial de X2:\n");
 			scanf("%f",&X2);
 			printf("Ingrese su valor inicial de X2:\n");
 			scanf("%f",&X3);
 			bo=funcionr(A,B,C,D,E,Xo);
 			b1=(funcionr(A,B,C,D,E,X1)-funcionr(A,B,C,D,E,Xo))/(X1-Xo);
 			b2=(((funcionr(A,B,C,D,E,X2)-funcionr(A,B,C,D,E,X1))/(X2-X1))-b1)/(X2-Xo);
 			b3=(((funcionr(A,B,C,D,E,X3)-funcionr(A,B,C,D,E,X2))/(X3-X2))-((funcionr(A,B,C,D,E,X2)-funcionr(A,B,C,D,E,X1))/(X2-X1))-b1)/(X3-Xo);
 			r=bo+(b1*(X-Xo))+(b2*(X-Xo)*(X-X1))+(b3*(X-Xo)*(X-X1)*(X-X2));
 			printf("\nEl polinomio ingresado es:\n%.3fx^%.3f+%.3fx^%.3f+%.3f\n",A,B,C,D,E,X);
			printf("\nLa funci%cn evaluada en X=%f es:\nf(%f)=%f\n",162,X,X,r);
			break;
	}
 	return 0;
 }
 //Función para el reinicio del programa y abrir el menu principal.
 regresar ()
 {
	int x=0;
	printf("\n\nDesea regresar al menu principal?");
	printf("\nS%c, presione '1'\tNo presione '2'\n",161);
	scanf("%d",&x);
	 if (x==1)
	 	return 0;
	else
	{
		printf("\n\nGracias por usar este programa\n");
		exit(1);
	}
 }
 //Función principal del programa
 main(void) 
 {
     int opcion=0;
     int sub=0;
     int load;
 
     //Se muestran los menu y submenus.
	 do 
	 {
         system("cls");
		 mostrar_menu();
         scanf("%d",&opcion);
             //en cada Switch se llamará la función que aplique el método especificado.
			 switch (opcion) 
			 {
                case 1:
                	system("cls");
					mostrar_submenu1();
					scanf("%d",&sub);
					switch (sub)
					{
						case 1:
							biseccion();
							break;
						case 2:
							falsa_posicion ();
							break;
						case 3:
							ridder ();
							break;
						case 4:
							NR ();
							break;
						case 5:
							secante ();
							break;
						case 6:
							muller ();
							break;
						case 7:
							bairstow ();
							break;
						case 8: 
							default: printf( "Opci%cn no v%clida\n",162,160 );
                         	break;	
					}
                       break;
                case 2:
                	system("cls");
					mostrar_submenu2();
					scanf("%d",&sub);
					switch (sub)
					{
						case 1:
							EG ();
							break;
						case 2:
							LU ();
							break;
						case 3:
							MGS ();
							break;
						case 4:
							default: printf( "Opci%cn no v%clida\n",162,160 );
							break;
					}
                        break;
                case 3:
					system("cls");
					mostrar_submenu3();
					scanf("%d",&sub);
					switch (sub)
					{
						case 1:
							RMC ();
							break;
						case 2:
							interpolacion ();
							break;
						case 3:
							default: printf( "Opci%cn no v%clida\n",162,160 );
							break;
					}
                        break;
                case 4:
                	printf("\n\nGracias por usar este programa\n");
					return 0;
                        break;
                case 5:
				default: printf( "Opci%cn no v%clida\n",162,160 );
                         break;
     		 } 
			regresar ();
	}
	while (opcion!=5);
 }
