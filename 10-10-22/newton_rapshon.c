#include <stdio.h>
#include <math.h>

int ni;
float x2,x1,es,ea;

float f(float x) {return log(x-2);}
float df(float x) {return 1/(x-2);}

int main()
{
	es=0.1; ea=1; ni=0; x1=4;


	while(es<ea)
	{
		x2=x1-f(x1)/df(x1);
		ni=ni+1;

		ea=fabs((x2-x1)/x2)*100;
		x1=x2;
		printf("El valor de x2=%f ea=%f\n",x2,ea);
	}
	printf("El valor de la raiz es =%f\n las interacciones son %d\n",x2,ni);
}
