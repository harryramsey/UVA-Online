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
vector<int> vertices;

vector<vector<int> > transposeGraph(vector<vector<int> > &g)
{
    int size = g.size();
    vector<vector<int> > t(size);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < g[i].size(); j++){
            int v = g[i][j];
            t[v].push_back(i);
        }
    }
    return t;
}

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
    vertices.push_back(u);
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

void strong_dfs(vector<vector<int> > &g, int u)
{
    printf(" %d",u);
    start[u] = depth;
    color[u] = GRAY;

    for (int i = 0; i < g[u].size(); i++){
    	int v = g[u][i];
    	if (color[v] == WHITE){
            parent[v] = u;
            strong_dfs(g,v);
    	}
    }
    color[u] = BLACK;
    depth++;
    finish[u] = depth;
}

void strongly_connected(vector<vector<int> > &g)
{
    vertices.resize(0);
    DFS(g);
    vector<vector<int> > t = transposeGraph(g);
    reverse(vertices.begin(),vertices.end());
    vector<int> copy(g.size());

    for (int i = 0; i < g.size(); i++){
        copy[i] = vertices[i];
    }

    for (int i = 0; i < g.size(); i++){
        color[i] = WHITE;
        parent[i] = -1;
        start[i] = finish[i] = -1;
    }

    int c = 1;
    for (int i = 0; i < g.size(); i++){
        if (color[copy[i]] == WHITE){
            printf("Tree %d:",c++);
            strong_dfs(t,i);
            printf("\n");
        }
    }
}

int main(void)
{
    int x,y,n;
    scanf("%d",&n);
    vector<vector<int> > g(n);

    while (scanf("%d%d",&x,&y) == 2){
        if (x < 0 && y < 0) break;
        g[x].push_back(y);
    }
    strongly_connected(g);
    return 0;
}
