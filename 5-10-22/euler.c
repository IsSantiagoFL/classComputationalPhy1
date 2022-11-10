# include <stdio.h>
# include <math.h>

int funcion (int n)
{
	int i, fac=1;
	for(i=1;i<n+1;i++)
	{	
		fac=fac*i;
	}
	return fac;
}

int main ()
{
	int nu, factorial, N;
	float x, sum, et, va, vt, vaa, ea=0;
	vt = exp(0.5);
	N=6;
	x = 0.5;
	sum = 1.0;
	for(nu=1;nu<N+1;nu++)
	{
		factorial=funcion(nu);
		sum=sum+pow(x,nu)/factorial;
		va=sum;
		et=100.0*(vt-va)/vt;
		
		if (nu>1) ea=va-vaa;
		printf("El valor de la serie con %d es %f el et es %f\n",nu+1,sum, et);
		vaa=va;
	}
}
