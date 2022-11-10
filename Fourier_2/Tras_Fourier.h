#define max 16252			/* max number of input data */
#define PI	M_PI	/* pi to machine precision, defined in math.h */
#define TWO_PI (2.0*PI)

void dft(int N, double(*x)[2], double(*X)[2]);
void fft(int N, double(*x)[2], double(*X)[2]);
void fft_rec(int N, int offset, int delta,
			 double(*x)[2], double(*X)[2], double(*XX)[2]);

void fft(int N, double(*x)[2], double(*X)[2])
{
	/* Declare a pointer to scratch space. */
	double(*XX)[2] = malloc(2 * N * sizeof(double));
	
	/* Calculate FFT by a recursion. */
	fft_rec(N, 0, 1, x, X, XX);
	
	/* Free memory. */
	free(XX);
}

void fft_rec(int N, int offset, int delta,
			 double(*x)[2], double(*X)[2], double(*XX)[2])
{
	int N2 = N / 2;            /* half the number of points in FFT */
	int k;                   /* generic index */
	double cs, sn;           /* cosine and sine */
	int k00, k01, k10, k11;  /* indices for butterflies */
	double tmp0, tmp1;       /* temporary storage */
	
	if (N != 2)  /* Perform recursive step. */
	{
		/* Calculate two (N/2)-point DFT's. */
		fft_rec(N2, offset, 2 * delta, x, XX, X);
		fft_rec(N2, offset + delta, 2 * delta, x, XX, X);
		
		/* Combine the two (N/2)-point DFT's into one N-point DFT. */
		for (k = 0; k<N2; k++)
		{
			k00 = offset + k*delta;    k01 = k00 + N2*delta;
			k10 = offset + 2 * k*delta;  k11 = k10 + delta;
			cs = cos(TWO_PI*k / (double)N); sn = sin(TWO_PI*k / (double)N);
			tmp0 = cs * XX[k11][0] + sn * XX[k11][1];
			tmp1 = cs * XX[k11][1] - sn * XX[k11][0];
			X[k01][0] = XX[k10][0] - tmp0;
			X[k01][1] = XX[k10][1] - tmp1;
			X[k00][0] = XX[k10][0] + tmp0;
			X[k00][1] = XX[k10][1] + tmp1;
		}
	}
	else  /* Perform 2-point DFT. */
	{
		k00 = offset; k01 = k00 + delta;
		X[k01][0] = x[k00][0] - x[k01][0];
		X[k01][1] = x[k00][1] - x[k01][1];
		X[k00][0] = x[k00][0] + x[k01][0];
		X[k00][1] = x[k00][1] + x[k01][1];
	}
	
}

void dft(int N, double(*x)[2], double(*X)[2])
{
	double imag, real,input[N+1],real1[N+1],imag1[N+1],sum=0.0,mues;
	int i=0,j,k;
	
	for (j=0; j<N; j++) input[j]=x[j][0];
	i=N;
	mues=1.0/(i*1.0);
	for (j=0; j<i; j++)			/* loop for frequency index */
	{
		real=imag=0.0;			/* clear variables */
		for (k=0; k<i; k++)		/* loop for sums */
		{
			real+=input[k]*cos((2*PI*k*j)/i);
			imag+=input[k]*sin((2*PI*k*j)/i);
		}
		X[j][0]=real;
		X[j][1]=imag;
	}
	
}
