#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int dp[105][51000];
int weights[105];
int values[105];

void initialize()
{
    memset(dp,-1,sizeof dp);
}

int knapsack(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || j == 0) return dp[i][j] = 0;
    else{
    	if (j-weights[i] >= 0){
            dp[i][j] = max(knapsack(i-1,j), values[i]+knapsack(i-1,j-weights[i]));
    	}
    	else dp[i][j] = knapsack(i-1,j);
    }
    return dp[i][j];
}

int main(void)
{
    int N, numCoins, coin;
    weights[0] = 0;
    values[0] = 0;

    scanf("%d",&N);
    for (int i = 0; i < N; i++){
    	scanf("%d",&numCoins);
    	int sum = 0;
    	for (int j = 1; j <= numCoins; j++){
            scanf("%d",&coin);
            sum += coin;
            values[j] = coin;
            weights[j] = coin;
    	}
    	initialize();
    	int closest = knapsack(numCoins,sum/2);
    	int partner = sum-closest;
    	printf("%d\n",partner-closest);
    }
    return 0;
}
