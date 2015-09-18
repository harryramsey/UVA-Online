#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int square[101];
int dp[10001];

void initialize()
{
    for (int i = 0; i <= 100; i++){
        square[i] = i*i;
    }
    for (int i = 0; i <= 10000; i++){
        dp[i] = 1000000000;
    }
    for(int i = 0; i <= 100; i++){
        dp[square[i]] = 1;
    }
}

int solve(int i)
{
    if (dp[i] != 1000000000){
        return dp[i];
    }
    else{
        for (int j = 1; square[j] < i; j++){
            dp[i] = min(dp[i],1+solve(i-square[j]));
        }
    }
    return dp[i];
}

int main(void)
{
    int N, num;
    scanf("%d",&N);
    initialize();

    for (int i = 0; i < N; i++){
        scanf("%d",&num);
        printf("%d\n",solve(num));
    }
    return 0;
}

