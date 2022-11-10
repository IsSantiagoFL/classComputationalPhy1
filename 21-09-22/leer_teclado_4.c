#include <stdio.h>
#include <math.h>
int main()
{
	float Ax, Ay, Az, mod_A; 
	float Bx, By, Bz, mod_B; 
	float prod_esc;
	//Escaneando los valores del vector A
	printf("Ingrese las componentes escalares rectangulares del vector A\n");
	printf("Ingrese el valor de Ax: ");
	scanf("%f", &Ax);
	printf("Ingrese el valor de Ay: ");
	scanf("%f", &Ay);
	printf("Ingrese el valor de Az: ");
	scanf("%f", &Az);

	//Escaneando los valores del vector B
	printf("\nIngrese las componentes escalares rectangulares del vector B\n");
	printf("Ingrese el valor de Bx: ");
	scanf("%f", &Bx);
	printf("Ingrese el valor de By: ");
	scanf("%f", &By);
	printf("Ingrese el valor de Bz: ");
	scanf("%f", &Bz);
	
	//Calculando el modulo del vector A
	mod_A=sqrt(pow(Ax,2)+pow(Ay,2)+pow(Az,2));
	printf("\nEl modulo del vector A es: %.2f\n\n",mod_A);
	printf("Los valores ingresados para el vector A fueron:\n");
	printf("El valor de Ax es %.2f\n",Ax);
	printf("El valor de Ay es %.2f\n",Ay);
	printf("El valor de Az es %.2f\n",Az);
	
	//Calculando el modulo del vector A
	mod_B=sqrt(pow(Bx,2)+pow(By,2)+pow(Bz,2));
	printf("\nEl modulo del vector B es: %.2f\n\n",mod_B);
	printf("Los valores ingresados para el vector B fueron:\n");
	printf("El valor de Bx es %.2f\n",Bx);
	printf("El valor de By es %.2f\n",By);
	printf("El valor de Bz es %.2f\n",Bz);

	//Calculando el producto escalar
	prod_esc=Ax*Bx+Ay*By+Az*Bz;
	printf("El producto escalar del vector A con el vector B es: %.2f\n",prod_esc);
}
