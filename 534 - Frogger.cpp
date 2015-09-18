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

double dist[205][205];

struct point{
    int x,y;
};

void minimax(int N)
{
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
}

double getDist(int a, int b, int c, int d)
{
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main(void)
{
    int n, x, y;
    int caseNum = 1;
    point arr[205];
    while(scanf("%d",&n) == 1){
        if (n == 0) break;

        memset(dist,INF,sizeof dist);
        for (int i = 0; i < n; i++){
            scanf("%d%d",&x,&y);
            point p;
            p.x = x;
            p.y = y;
            arr[i] = p;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                double d = getDist(arr[i].x,arr[i].y,arr[j].x,arr[j].y);
                dist[i][j] = d;
            }
        }
        minimax(n);
        printf("Scenario #%d\n",caseNum++);
        printf("Frog Distance = %.3lf\n\n",dist[0][1]);
    }
  return 0;
}
