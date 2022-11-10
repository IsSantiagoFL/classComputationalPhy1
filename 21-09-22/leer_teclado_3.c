#include <stdio.h>
int main()
{
	float a,b,c,d,e;
	printf("Ingrese el valor de a:\n");
	scanf("%f", &a);
	printf("El valor de a es %f\n\n",a);

	printf("Ingrese el valor de b:\n\n");
	scanf("%f", &b);
	printf("El valor de b es %f\n\n",b);

	printf("Ingrese el valor de c:\n");
	scanf("%f", &c);
	printf("El valor de c es %f\n\n",c);

	printf("Ingrese el valor de d:\n");
	scanf("%f", &d);
	printf("El valor de d es %f\n\n",d);

	e=a+b+c+d;
	printf("El valor de a + b + c + d es: %f\n", e);
}
