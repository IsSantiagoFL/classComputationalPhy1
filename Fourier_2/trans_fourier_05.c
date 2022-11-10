#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "gnuplot_i.h"
#include "Tras_Fourier.h"

#define PI	M_PI	/* pi to machine precision, defined in math.h */
#define TWO_PI (2.0*PI)

int graficar_tiempo(double xx[], double yy[],int tam)
{
	int i;
	
    	gnuplot_ctrl    *h1;
    	h1 = gnuplot_init() ; 
    	gnuplot_resetplot(h1) ;
    	gnuplot_setstyle(h1, "lines") ;
	gnuplot_set_xlabel (h1,"Tiempo S");
	gnuplot_set_ylabel (h1,"Amplitud");

	gnuplot_plot_xy(h1,xx,yy,tam,"grafico") ;
	printf("presione ENTER para continuar\n");
	while (getchar()!='\n') {}
	
    	gnuplot_close(h1) ;
	return (tam);
}

int graficar_frecuencia(double xx[], double yy[],int tam)
{
	int i;
	
    	gnuplot_ctrl    *h1;
    	h1 = gnuplot_init() ; 
    	gnuplot_resetplot(h1) ;
    	gnuplot_setstyle(h1, "impulses") ;
	gnuplot_set_xlabel (h1,"Frecuencia Hz");
	gnuplot_set_ylabel (h1,"Potencia Espectral A^2");	

	gnuplot_plot_xy(h1,xx,yy,tam,"grafico") ;
	printf("presione ENTER para continuar\n");
	while (getchar()!='\n') {}
	
    	gnuplot_close(h1) ;
	return (tam);
}

int main()
{
	FILE *Leer,*Grabar;
	char *nombre=NULL;
	char nombre1[20],CC,buff1,buff2;
	int i,j,kk,k,l,num_h,cont=0,sos,tam,N;
	double *x, *y, *sum, suma, muestreo,cte;
	double(*x1)[2];           /* pointer to time-domain samples */
	double(*X)[2];           /* pointer to frequency-domain samples */
	double *frec;           /* puntero para la frecuencia  */
	double *pot;           /*puntero para la potencia */

	srand(time(NULL));
	tam=pow(2,14); if((Leer=fopen("guri.dat","r"))==NULL)
//	tam=pow(2,12); if((Leer=fopen("henon.dat","r"))==NULL)
//	tam=pow(2,11); if((Leer=fopen("kobe.dat","r"))==NULL)
//	tam=pow(2,12); if((Leer=fopen("logis.dat","r"))==NULL)
//	tam=pow(2,12); if((Leer=fopen("lorentz.dat","r"))==NULL)		
//	tam=pow(2,13); if((Leer=fopen("dato_5_r.dat","r"))==NULL)
	{
		printf("Error en archivo de entrada\n");
		exit(0);
	}
			
//	tam=pow(2,10);

	/* Memoria Dimanica Malloc. */
	x = (double *) malloc( (tam+1) * sizeof(double));
	y = (double *) malloc( (tam+1) * sizeof(double));
	sum = (double *) malloc( (tam+1) * sizeof(double));
	x1 = malloc(2 * (tam+1) * sizeof(double));
	X = malloc(2 * (tam+1) * sizeof(double));
	frec = (double *) malloc( (tam+1) * sizeof(double));
	pot = (double *) malloc( (tam+1) * sizeof(double));
	
	for(i=0;i<tam;i++)
	{
		fscanf(Leer,"%lf\n",&y[i]);
//		printf("%lf\n",y[i]);
	}	
	
	muestreo=1.0/tam;

	printf("muestreo %lf\n",muestreo);

	for(i=0;i<tam;i++)
	{
		x[i]=i*muestreo;
	}

	cte=2.0*PI;
	
	for(i=0;i<tam;i++)
		if(i<20) printf("%d %.1lf %.2lf\n",i,x[i],sum[i]);		
	
	sos=graficar_tiempo(x,y,tam);
	
	for(i=0;i<tam;i++)
	{
		x1[i][0]=y[i];
		x1[i][1]=0.0;
	}
		
	fft(tam, x1, X);
//	dft(tam, x1, X);	

	for (j=0; j<tam/2; j++)
	{
		pot[j]=2.0*sqrt(X[j][0]*X[j][0]+X[j][1]*X[j][1])/(double) (tam);
		frec[j]=(double)j*(double)(1.0)/(double)(muestreo*tam);
		if(j<20) printf("%d %.2lf %.2lf\n",j,frec[j],pot[j]);	
	}
	
	sos=graficar_frecuencia(frec,pot,tam/2);
	
	
	free(x);
	free(y);
	free(sum);
	free(x1);
	free(X);
	free(frec);
	free(pot);
	fclose(Leer);
}
