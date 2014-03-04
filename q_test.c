#include<stdio.h>
#include<math.h>

double qtrap(double (*func)(double, void *), double, double, int, void *);
double qsimp(double (*func)(double, void *), double, double, int, void *);
double my_func(double, void *);

int main()
{
	FILE *fptr;
	int N=2;
	int N_max=5000;
	int i;
	double out_trap;
	double out_simp;
	double err_trap;
	double err_simp;
	double exact;
	double a;
	double b;
	void *params;
	
	fptr = fopen("quadratures.dat","w");

	a=0.0;
	b=3.0;
	params = NULL;
	exact = exp(b) - exp(a);
	fprintf(fptr,"#N\texact\ttrap\tsimp\terr_trap\terr_simp\n");
	for(i=3;i<N_max;i+=2)
	{
		out_trap=qtrap(&my_func, a, b, i, params);
		out_simp=qsimp(&my_func, a, b, i, params);
		err_trap=(out_trap-exact)/exact;
		err_simp=(out_simp-exact)/exact;

		fprintf(fptr,"%d\t%e\t%e\t%e\t%e\t%e\n",i,exact,out_trap,out_simp,err_trap,err_simp);
	}		
	fclose(fptr);
	return 0;
}

double my_func(double x, void *params)
{
	return exp(x);
}
