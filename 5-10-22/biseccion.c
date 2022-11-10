# include <stdio.h>
# include <math.h>

int ni;
double a,b,r,rold, es, ea;

float f (float x)
{
	return log(x-2);
}

int main()
{
	es=0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001; ea=1; ni=0;
	a=2.5 ; b=4; rold=a;
	while(es<ea)
	{
		r=(a+b)/2;
		ni=ni+1;
		if(f(a)*f(r)<0) b=r;
		else if (f(r)*f(b)<0) a=r; 
		ea=fabs((r-rold)/r)*100;
		rold=r;
		printf("El valor de la a=%f b=%f r=%f el ea=%f \n",a,b,r,ea);
	}
	printf("El valor de la raiz es=%.10f\n",r);
}
