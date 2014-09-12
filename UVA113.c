#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findK(int n, double p)
{
	double k = exp(log(p)/n);
	printf("%0.lf\n", k);
}

int main()
{
	int n;
	double p;

	while (scanf("%d %lf", &n, &p) == 2){
		findK(n,p);
	}
	return 0;
}

