#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void max_interval_sum(int arr[], int N)
{
	int i,j = 0;
	int curr_max = arr[0];
	int sum_arr[N];

	sum_arr[0] = arr[0];

	for (i = 1; i < N; i++){
		if (sum_arr[i-1] < 0){
			sum_arr[i] = arr[i];
		}
		else{
			sum_arr[i] = arr[i] + sum_arr[i-1];
		}
		if (sum_arr[i] > curr_max){
			curr_max = sum_arr[i];
		}
	}
	if (curr_max <= 0){
		printf("Losing streak.\n");
	}
	else printf("The maximum winning streak is %d.\n", curr_max);
}

int main()
{
	int N, num, i;

	while (scanf("%d", &N) == 1){
		if (N == 0) break;
		int arr[N];
		for (i = 0; i < N; i++){
			scanf("%d", &num);
			arr[i] = num;
		}
		max_interval_sum(arr,N);
	}
	return 0;
}

