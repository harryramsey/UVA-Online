#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

#define INF 1000000000

int dist[105][105];

void maximin(int N)
{
    for (int i = 0; i <= N; i++){
        dist[i][i] = 0;
    }

    for (int k = 0; k <= N; k++){
        for (int i = 0; i <= N; i++){
            for (int j = 0; j <= N; j++){
                dist[i][j] = max(dist[i][j],min(dist[i][k],dist[k][j]));
            }
        }
    }
}

int main(void)
{
    int v,e,a,b,weight,s,f,ppl;
    int caseNum = 1;

    while (scanf("%d%d",&v,&e) == 2){
        if (v == 0 & e == 0) break;

        memset(dist,INF,sizeof dist);
        for (int i = 0; i < e; i++){
            scanf("%d%d%d",&a,&b,&weight);
            dist[a-1][b-1] = weight;
            dist[b-1][a-1] = weight;
        }
        maximin(v);
        scanf("%d%d%d",&s,&f,&ppl);

        s--;f--;
        printf("Scenario #%d\n",caseNum++);
        if (s == f) printf("Minimum Number of Trips = 0\n");
        else printf("Minimum Number of Trips = %d\n",(ppl+dist[s][f]-2)/(dist[s][f]-1));
        printf("\n");
    }
    return 0;
}

