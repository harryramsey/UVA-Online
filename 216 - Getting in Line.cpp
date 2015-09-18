#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

struct point{
    int x, y;
};

int N;
int path[8];
double dist[8][8];
bool used[8];
int soltn[8];
double smallest;

void initialize(point pts[])
{
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 16.0+sqrt(pow(pts[i].x-pts[j].x,2)+pow(pts[i].y-pts[j].y,2));
        }
    }

    for (int i = 0; i < 8; i++){
        path[i] = -1;
        soltn[i] = -1;
        used[i] = false;
    }
    smallest = 1000000000;
}

void backtrack(double pathSum, int v, int level)
{
    if (pathSum > smallest) return;
    if (level == N-1){
        if (pathSum < smallest){
            smallest = pathSum;
            for (int i = 0; i < N; i++){
                soltn[i] = path[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++){
        if (!used[i]){
            used[i] = true;
            path[level+1] = i;
            backtrack(pathSum+dist[v][i],i,level+1);
            used[i] = false;
            path[level+1] = -1;
        }
    }
}

int main(void)
{
    point pts[8];
    int caseNum = 1;
    while (scanf("%d",&N) == 1){
        if (N == 0) break;

        for (int i = 0; i < N; i++){
            point p;
            scanf("%d%d",&p.x,&p.y);
            pts[i] = p;
        }
        initialize(pts);

        for (int i = 0; i < N; i++){
            path[0] = i;
            used[i] = true;
            backtrack(0,i,0);
            used[i] = false;
        }

        printf("**********************************************************\n");
        printf("Network #%d\n",caseNum++);
        for (int i = 0; i < N-1; i++){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",pts[soltn[i]].x,pts[soltn[i]].y,pts[soltn[i+1]].x,pts[soltn[i+1]].y,
                   dist[soltn[i]][soltn[i+1]]);
        }
        printf("Number of feet of cable required is %.2lf.\n",smallest);

    }
    return 0;
}
