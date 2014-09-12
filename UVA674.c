#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVAL 7490
int coins[5] = {1,5,10,25,50};
int num_ways[MAXVAL+1];

void generate_num_ways()
{
	int i,j,c;
	num_ways[0] = 1;

	for (i = 0; i < 5; i++){
		c = coins[i];
		for (j = c; j <= MAXVAL; j++){
			num_ways[j] += num_ways[j-c];
		}
	}
}



int main()
{
	int val;
	generate_num_ways();
	while (scanf("%d", &val) == 1){
		printf("%d\n",num_ways[val]);
	}
	return 0;
}
