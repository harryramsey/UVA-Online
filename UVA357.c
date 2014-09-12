#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVALUE 30000
long long int num_ways[MAXVALUE+1];
int coins[5] = {1, 5, 10, 25, 50};

void generate_ways(){
	int c, i,j;

	num_ways[0] = 1;
	for (i = 0; i < 5; i++){
		c = coins[i];
		for (j = c; j <= MAXVALUE; j++){
			num_ways[j] += num_ways[j-c];
		}
	}
}

int main()
{
	int cents;
	long long int ways;

	generate_ways();
	while (scanf("%d", &cents) == 1){
		ways = num_ways[cents];
		if (ways == 1){
			printf("There is only 1 way to produce %d cents change.\n", cents);
		}
		else printf("There are %lld ways to produce %d cents change.\n", ways, cents);
	}
	return 0;
}

