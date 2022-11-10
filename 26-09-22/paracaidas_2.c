#include <stdio.h>
#include <math.h>
#include "gnuplot_i.h"

int main()
{
	int i,N=30, t;
	float m=68.1, g=9.8, c=12.5;
	float v, v0, v1=0.0;

	gnuplot_ctrl *h1;
	double x[N],V_ana[N],V_aprox[N];
	
	v0=0; t=0.0;
	for(t=0;t<N;t+=2)
	{
		v= (g*m/c)*(1.0-exp((-c/m)*t));
		v1=v0+(g-c*v0/m)*2.0;
		
		x[t]=t;
		V_ana[t]=v;
		V_aprox[t]=v0;

		printf("%d\t %.5f\t %.5f\n",t,v,v1);
		v1=v0+(g-c*v0/m)*2.0;

		v0=v1;
	}	

	h1 = gnuplot_init();
	gnuplot_setstyle(h1, "points") ;
// gnuplot_setstyle(h1, "lines") ;
	gnuplot_plot_xy(h1, x, V_ana, N, "Velocidad Analitica del paracaidas") ;
	gnuplot_plot_xy(h1, x, V_aprox, N, "Velocidad Aproximada del paracaidas") ;

	sleep(1000);
	gnuplot_resetplot(h1) ;
	gnuplot_close(h1) ;

}
