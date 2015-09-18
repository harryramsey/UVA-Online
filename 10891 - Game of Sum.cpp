#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int vals[105];
int best[105][105];

void reset()
{
    for (int i = 0; i < 105; i++){
        for (int j = 0; j < 105; j++){
            best[i][j] = -1000000000;
        }
    }
}

int sum(int i, int j)
{
    int val = 0;
    for (int k = i; k <= j; k++){
        val += vals[k];
    }
    return val;
}

int solve(int i, int j)

{
    if (i > j) return 0;
    if (best[i][j] > -1000000000){
        return best[i][j];
    }
    else{
        int q = -1000000000;

        for (int k = i; k <= j; k++){
            q = max(q,sum(i,k)-solve(k+1,j));
        }
        for (int k = j; k >= i; k--){
            q = max(q,sum(k,j)-solve(i,k-1));
        }
        best[i][j] = q;
    }
    return best[i][j];
}


int main(void)
{
    int N;
    while (scanf("%d",&N) == 1){
    	if (N == 0) break;
    	for (int i = 0; i < N; i++){
            scanf("%d",&vals[i]);
    	}
    	reset();
    	printf("%d\n",solve(0,N-1));
    }
    return 0;
}
