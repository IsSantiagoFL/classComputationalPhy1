#include <stdio.h>
#include <math.h>

int main()
{
	int i,N=98, t;
	float m=68.1, g=9.8, c=12.5;
	float v,a;
	for(t=0;t<N;t+=2)
	{
		v = (g*m/c)*(1.0-exp((-c/m)*t));
		a=g-c*v/m;
		printf("t=%d v=%.18f a=%.18f \n",t,v,a);
	}

}
