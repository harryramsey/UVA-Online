#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXTOTAL 30000
double nway[MAXTOTAL+10];
int coin[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};


void count_ways(int n)
{
	int i,j,v,c;
	v = 11;
	nway[0] = 1;
	for (i = 0; i < v; i++){
		c = coin[i];
		for (j = c; j <= n; j++){
			nway[j] += nway[j-c];
		}
	}
}

int main()
{
	double d;
	count_ways(MAXTOTAL);
	while (scanf("%lf", &d) == 1){
		if (d == 0.00){
			break;
		}
		int n = 100*d + 0.5;
		printf ("%6.2lf%17.lf\n", d, nway [n]);
	}
	return 0;
}
