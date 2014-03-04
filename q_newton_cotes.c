
double qtrap(double (*func) (double, void *), double, double, int, void *);
double qsimp(double (*func) (double, void *), double, double, int, void *);


double qtrap(double (*func) (double, void *), double a, double b, int n, void * params)
{
	int i;
	double x;
	double h;
	double sum;
	sum=0.0;
	h=(b-a)/(double)(n-1);
	for(i=1;i<n-1;i++)
	{
		x=a+i*h;
		sum+= func(x,params);
	}
	sum+=((func(a,params)+func(b,params))*0.5);
	sum*=h;
	return sum;
}

double qsimp(double (*func) (double, void *), double a, double b, int n, void *params)
{
	int i;
	double x;
	double h;
	double sum;
	double w;
	sum=0.0;
	h=(b-a)/(double)(n-1);
	w=1.0;
	for(i=1;i<n-1;i++)
	{
		x=a+i*h;
		w=((i%2)==0)?2.0:4.0;
		sum+= w*func(x,params);
	}
	sum+=(func(a,params)+func(b,params));
	sum*=(h/3.0);
	return sum;
}
