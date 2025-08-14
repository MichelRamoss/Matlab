//Michel Abraham Ramos Soto
//768936
//Programa del metodo de biseccion.
//16/08/18


#include <stdio.h>
#include <math.h>

typedef struct eca {
	float xi, fxi, xs, fxs, xr[2], fxr;
	float ea, ea_max;
	int n, n_max;
	float (*f)(float x);
}eca;

eca biseccion(float xi, float xs, float ea_max, int n_max, float(*f)(float x))
	{
	eca bs;
	bs.xi = xi;
	bs.xs = xs;
	bs.ea_max = ea_max;
	bs.n_max = n_max;
	bs.f = f;
	bs.fxi = bs.f(bs.xi);
	bs.fxs = bs.f(bs.xs);
	bs.ea = FP_INFINITE;
	bs.n = 0;
	bs.xr[0] = bs.xi;
	bs.xr[1] = bs.xs;
	while ((bs.n<bs.n_max)&&(bs.ea>bs.ea_max))	
		{
		bs.xr[bs.n%2] = (bs.xi + bs.xs) / 2;
		bs.fxr = bs.f(bs.xr[bs.n % 2]);
		if((bs.fxi*bs.fxr)<0)	
		{
			bs.xs = bs.xr[bs.n % 2];
			bs.fxi = bs.fxr;
		}
		bs.ea = fabs(bs.xr[bs.n%2]-bs.xr[(bs.n+1)%2]) / bs.xr[bs.n % 2];
		bs.n++;				
		}
		return bs;
	}
	float f1(float x)
	{
		return sin(3*x-2);
	}
	
	int main(int argc, const char* argv[]){
		eca e1;
		e1 = biseccion(0, 1, 1e-6, 100, f1);
		printf("xr = %f\tea = %f\tn = %d\n", e1.xr[(e1.n+1)%2], e1.ea, e1.n);
		return 0;
		
	}
