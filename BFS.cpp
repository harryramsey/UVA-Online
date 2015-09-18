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
int dist[105];
int parent[105];

void bfs(vector<vector<int> > &g, int start, int ignore)
{
    for (int i = 0; i < g.size(); i++){
    	color[i] = WHITE;
    	dist[i] = 1000000000;
    	parent[i] = -1;
    }
    queue<int> q;
    color[start] = GRAY;
    dist[start] = 0;
    parent[start] = -1;

    while(!q.empty()){
    	int u = q.front();
    	q.pop();

    	for (int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if (color[v] == WHITE){
                color[v] = GRAY;
                dist[v] = dist[u]+1;
                parent[v] = u;
                q.push(v);
            }
    	}
    	color[u] = BLACK;
    }
}


int main(void)
{
    return 0;
}

