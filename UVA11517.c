#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 2147483647

int coins[10001];
int dp[30001];

void solve(int N, int total)
{
	int i, j, c;

	dp[0] = 0;
	for (i=1; i<=30000; i++){
	    dp[i] = INF;
	}

	for (i = 0; i < N; i++){
		c = coins[i];
	    for (j = 30001 - c - 1; j >= 0; j--){
	        if (dp[j] < INF){
	            dp[j+c] = min(dp[j+c], dp[j]+1);
	        }
	    }
	}

	for (i = total; i < 30000; i++){
		if (dp[i] != INF){
			printf("%d %d\n", i, dp[i]);
			break;
		}
	}

}

int min (int a, int b)
{
   if (a < b){
	   return a;
   }
   return b;
}

int main()
{
	int cases, total, N, coin, i, j;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++){
		scanf("%d", &total);
		scanf("%d", &N);
		for (j = 0; j < N; j++){
			scanf("%d", &coin);
			coins[j] = coin;
		}
		solve(N, total);
	}

	return 0;
}

