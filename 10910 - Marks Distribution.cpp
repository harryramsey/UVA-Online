#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int N, T, P, hi;
int dp[100][100];

void initialize()
{
    memset(dp,-1,sizeof dp);
    hi = (N-1)*(T-P);
}

bool isPromising(int curr, int level)
{
	if ((N-level)*P + curr > T){
		return false;
	}
	return true;
}
int solve(int curr, int level)
{
    if (level == N){
        if (curr == T){
            return 1;
        }
        return 0;
    }
    if (dp[curr][level] != -1){
        return dp[curr][level];
    }

    else{
        dp[curr][level] = 0;

        for (int i = P; i <= T; i++){
            if (isPromising(curr+i,level+1)){
            	dp[curr][level] += solve(curr+i,level+1);
            }
            else break;
        }
    }
    return dp[curr][level];
}

int main(void)
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d%d%d",&N,&T,&P);
        initialize();
        printf("%d\n",solve(0,0));
    }
    return 0;
}
