#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test(int n)
{
	int i, sum = 0, lim = n/2;
	for (i = 1; i <= lim; i++){
		if (n % i == 0){
			sum += i;
		}
	}
	if (sum == n) printf("%5d  PERFECT\n", n);
	else if (sum < n) printf("%5d  DEFICIENT\n", n);
	else printf("%5d  ABUNDANT\n", n);
}

int main()
{
	int n;

	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n) == 1){
		if (n == 0) break;
		test(n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}

