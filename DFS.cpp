#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

#define WHITE 1
#define GRAY 0
#define BLACK -1

int color[105];
int start[105];
int finish[105];
int parent[105];
int depth;

void DFS_Visit(vector<vector<int> > &g, int u)
{
    depth++;
    start[u] = depth;
    color[u] = GRAY;

    for (int i = 0; i < g[u].size(); i++){
    	int v = g[u][i];
    	if (color[v] == WHITE){
            parent[v] = u;
            DFS_Visit(g,v);
    	}
    }
    color[u] = BLACK;
    depth++;
    finish[u] = depth;
}

void DFS(vector<vector<int> > &g)
{
    for (int i = 0; i < g.size(); i++){
        color[i] = WHITE;
        parent[i] = -1;
        start[i] = finish[i] = -1;
    }
    depth = 0;
    for (int i = 0; i < g.size(); i++){
        if (color[i] == WHITE){
            DFS_Visit(g,i);
        }
    }
}


int main(void)
{
    return 0;
}
