#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int route = 1;

void max_interval_sum(int arr[], int N)
{
	int i,j = 0, loc1 = 0, loc2 = 0,max_length = 0, start_path,end_path;
	int curr_max = arr[0];
	int sum_arr[N];

	sum_arr[0] = arr[0];

	for (i = 1; i < N; i++){ //get maximum interval array
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

	while (j < N){ //find longest subinterval that ends on the maximum sum value
		if (sum_arr[j] >= 0){
			loc2++;
			if (sum_arr[j] == curr_max && loc2-loc1 > max_length){
				max_length = loc2-loc1;
				start_path = loc1+1;
				end_path = loc2+1;
			}
		}
		else{
			loc1 = j+1; loc2 = j+1;
		}
		j++;
	}
	if (curr_max <= 0){
		printf("Route %d has no nice parts\n", route);
	}
	else printf("The nicest part of route %d is between stops %d and %d\n", route, start_path,end_path);
	route++;
}



int main()
{
	int cases, i, N, j, r;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++){
		scanf("%d", &N);
		int arr[N-1];
		for (j = 0; j < N-1; j++){
			scanf("%d",&r);
			arr[j] = r;
		}
		max_interval_sum(arr,N-1);
	}

	return 0;
}
