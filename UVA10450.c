#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int fibs[53];
int scenario = 1;

fib_gen()
{
	int i;
	fibs[0] = 2;
	fibs[1] = 3;

	for(i = 2; i < 53; i++){
		fibs[i] = fibs[i-1]+fibs[i-2];
	}
}

void lookup_fib(int n)
{
	printf("Scenario #%d:\n", scenario++);
	printf("%lld\n",fibs[n-1]);
	printf("\n");
}

int main()
{
	int i, n, cases;

	fib_gen();
	scanf("%d",&cases);
	for (i = 0; i < cases; i++){
		scanf("%d", &n);
		lookup_fib(n);
	}

	return 0;
}
