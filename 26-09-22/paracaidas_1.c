#include <stdio.h>
#include <math.h>

int main()
{
	int i,N=20, t;
	float m=68.1, g=9.8, c=12.5;
	float v, v0, v1=0.0;

	
	v0=0; t=0.0;
	for(t=0;t<N;t+=2)
	{
		v= (g*m/c)*(1.0-exp((-c/m)*t));
		v1=v0+(g-c*v0/m)*2.0;

		printf("%d\t %.5f\t %.5f\n",t,v,v1);
		v1=v0+(g-c*v0/m)*2.0;

		v0=v1;
	}	


}
