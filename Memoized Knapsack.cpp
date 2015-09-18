#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int dp[105][105];
int weights[50] = {0,5,4,6,3};
int values[50] = {0,10,40,30,50};
int W = 10;

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
    initialize();
    printf("%d\n",knapsack(4,10));
    printf("\n");
    for (int i = 0; i <= 4; i++){
    	for (int j = 0; j <= 10; j++){
            printf("%d ",dp[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}
