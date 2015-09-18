#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define INF 1000000000

typedef pair<int,int> ii;

double dp[1000+5][1000+5];
ii arr[100];

double getDist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double bitonic(int i, int j)
{
    if (i == 1 && j == 1){
        dp[i][j] = 0;
    }
    else if (dp[i][j] != -1){
        return dp[i][j];
    }
    else if (i < j-1){
        dp[i][j] = bitonic(i,j-1)+getDist(arr[j-1].first,arr[j-1].second,arr[j].first,arr[j].second);
    }
    else if (i > j){
        dp[i][j] = bitonic(j,i);
    }
    else {
        double q = INF;
        for (int k = 1; k < j; k++){
            q = min(q,bitonic(i,k) + getDist(arr[k].first,arr[k].second,arr[j].first,arr[j].second));
        }
        dp[i][j] = q;
    }
    return dp[i][j];
}

void initialize(int n)
{
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = -1;
        }
    }
}

int main(void)
{
    int a, b, n;
    double d = INF;

    scanf("%d",&n);

    for (int i = 1; i <= n; i++){
        scanf("%d%d",&a,&b);
        arr[i] = make_pair(a,b);
    }
    sort(arr+1,arr+n+1);
    initialize(n);

    for (int i = 1; i <= n; i++){
        printf("%d ",arr[i].first);
    }
    printf("\n");
    bitonic(n,n);
    return 0;
}
