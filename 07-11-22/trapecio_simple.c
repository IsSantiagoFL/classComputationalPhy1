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
}


int main()
{
	double xi,xf, integral, h;
	xi=0.0;
	xf=0.8;
	h=xf-xi;
	integral = Tramp(h,xi,xf);
	printf("El valor de la integral es %lf\n",integral);
}



