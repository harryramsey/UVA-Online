#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int m[15][15];
int s[15][15];
int p[25];

int lookup_chain(int i, int j)
{
    if (m[i][j] < 2147000000){
        return m[i][j];
    }
    if (i == j){
        m[i][j] = 0;
    }
    else {
        for (int k = i; k < j; k++){
            int q = lookup_chain(i,k)+lookup_chain(k+1,j)+p[i*2]*p[(k*2)+1]*p[(j*2)+1];
            if (q < m[i][j]){
                m[i][j] = q;
                s[i][j] = k;
            }
        }
    }
    return m[i][j];
}

void path(int a, int b)
{
    if ( a == b ) printf("A%d",a+1);
    else
    {
        printf("(");
        path( a, s[ a ][ b ] );
        printf(" x ");
        path( s[ a ][ b ]+1, b );
        printf(")");
    }
}

int main(void)
{
    int N;
    int caseNum = 1;

    while (scanf("%d",&N) == 1){
        if (N == 0) break;

        int n = N*2;
        for (int i = 0; i < n; i++){
            scanf("%d",&p[i]);
        }
        for (int i = 0; i <= N; i++){
            for (int j = 0; j <= N; j++){
                m[i][j] = 2147000000;
            }
        }
        int ans = lookup_chain(0, N-1);
        printf("Case %d: ",caseNum++);
        path(0, n/2 -1);
        printf("\n");
    }
    return 0;
}
