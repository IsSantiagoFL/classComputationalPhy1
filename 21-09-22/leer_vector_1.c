#include <stdio.h>
#include <math.h>
int main()
{
	float Ax, Ay, Az, mod; 
	printf("Ingrese el valor de Ax:\n");
	scanf("%f", &Ax);
	printf("El valor de Ax es %.2f\n\n",Ax);

	printf("Ingrese el valor de Ay:\n\n");
	scanf("%f", &Ay);
	printf("El valor de Ay es %.2f\n\n",Ay);

	printf("Ingrese el valor de Az:\n");
	scanf("%f", &Az);
	printf("El valor de Az es %.2f\n\n",Az);

	mod=sqrt(Ax*Ax+Ay*Ay+Az*Az);
	printf("El modulo del vector A es: %.2f\n",mod);
}
