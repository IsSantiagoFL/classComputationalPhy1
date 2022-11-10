#include <stdio.h>
int main()
{
	float a,b,c,d,e;
	printf("Ingrese el valor de a\n");
	scanf("%d", &a);
	printf("El valor de a es %d\n\n",a);

	printf("Ingrese el valor de b\n\n");
	scanf("%d", &b);
	printf("El valor de b es %d\n\n",b);

	printf("Ingrese el valor de c\n");
	scanf("%d", &c);
	printf("El valor de c es %d\n\n",c);

	printf("Ingrese el valor de d\n");
	scanf("%d", &d);
	printf("El valor de d es %d\n\n",d);

	e=a+b+c+d;
	printf("La suma de a, b, c y d es: %d\n\n",e);

}
