#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int p, target, soltns;
int arr[105];
char used[105];
bool dp[65000][101];

void print_soltn()
{
    for (int i = 0; i < p-1; i++){
        printf("%d%c",arr[i],used[i]);
    }
    printf("%d=%d\n",arr[p-1],target);
}

void reset(){
    memset(dp,false,sizeof(dp));
}

void solve(int curr, int level)
{
    if (soltns > 0) return;
    if (curr > 32000 || curr < -32000) return;
    if (dp[curr+32000][level] == true) return;
    if (level == p-1){
        if (curr == target){
            print_soltn();
            soltns++;
        }
        return;
    }
    dp[curr+32000][level] = true;

    if (curr % arr[level+1] == 0){
    	used[level] = '/';
    	solve(curr/arr[level+1],level+1);
    }

    used[level] = '*';
    solve(curr*arr[level+1],level+1);

    used[level] = '+';
    solve(curr+arr[level+1],level+1);

    used[level] = '-';
    solve(curr-arr[level+1],level+1);
}

int main(void)
{
    int N;
    scanf("%d",&N);

    for (int i = 0; i < N; i++){
        scanf("%d",&p);
        for (int j = 0; j < p; j++){
            scanf("%d",&arr[j]);
        }
        scanf("%d",&target);
        soltns = 0;
        reset();
        solve(arr[0],0);
        if (soltns == 0) printf("NO EXPRESSION\n");
    }
    return 0;
}

