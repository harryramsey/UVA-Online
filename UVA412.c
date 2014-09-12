#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findPi(int arr[],int N)
{
	int i, j, count = 0;
	double pi, pairs = N*(N-1)/2;

	for (i = 0; i < N; i++){
		for (j = i+1; j < N; j++){
			if (gcd(arr[i],arr[j]) == 1){
				count++;
			}
		}
	}
	if (count == 0){
		printf("No estimate for this data set.\n");
	}
	else{
		pi = sqrt((6*pairs)/count);
		printf("%.6lf\n",pi);
	}
}

int gcd(int a, int b)
{
	int x = max(a,b);
	int y = min(a,b);
	while (y != 0){
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int min(int a, int b)
{
	if (a < b){
		return a;
	}
	return b;
}

int max(int a, int b)
{
	if (a > b){
		return a;
	}
	return b;
}

int main()
{
	int size, i, n;
	int arr[60];

	while (scanf("%d", &size) == 1){
		if (size == 0) break;
		for (i = 0; i < size; i++){
			scanf("%d",&n);
			arr[i] = n;
		}
		findPi(arr,size);
	}
	return 0;
}



