#include <stdio.h>
#include <math.h>

double f(double x) {
	double fun;
	fun = 0.2+25*x-200*pow(x,2)+657*pow(x,3)-900*pow(x,4)+400*pow(x,5);
	return fun;
}

double Tramp(double h, double f0, double f1)
{
	return h*(f(f0)+f(f1))/2.0;

	sum = f(f(0));
	for(i=1; i<n, i++);
	{
		x=h*i;
		sum=sum+2.0*f(x);
	}

	sum = sum+f(f1);
	return h*sum/2.0;
}


int main()
{
	double i,n,N=2, xi, xf, integral, h;
	double error, valor_exacto = 1.640533
	xi=0.0;
	xf=0.8;

	for(n=1;n<=N;n++)
	{
		h=xf-xi;
		integral = Tramp(h,xi,xf);
		printf("%d %lf \n",n, integral);
		error = 100*(abs(valor...falta aaaaaa)/abs(valor_exacto))
		printf("El valor de la integral es %lf\n",integral);
	}
}



