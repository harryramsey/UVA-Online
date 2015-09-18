#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>
#include <map>

using namespace std;

# define INF 1000000000

struct edge{
    int w, weight;
};

int dist[1100000];
bool intree[1100000];
int parent[1100000];
int board[1005][1005];
int N,M;

int initialize(vector<vector<edge> > &g, int s)
{
    for (int i = 0; i < g.size(); i++){
        dist[i] = INF;
        intree[i] = false;
        parent[i] = -1;
    }
    dist[s] = board[0][0];
}

int findMin(vector<vector<edge> > &g)
{
    int min = INF;
    for (int i = 0; i < g.size(); i++){
        if (dist[i] < min  && !intree[i]){
            min = i;
        }
    }
    return min;
}

void dijkstra(vector<vector<edge> > &g, int s)
{
    initialize(g,s);
    int v = s;

    while (!intree[v]){
        intree[v] = true;

        for (int i = 0; i < g[v].size(); i++){
            int w = g[v][i].w;
            if (dist[w] > dist[v]+g[v][i].weight){
                dist[w] = dist[v]+g[v][i].weight;
                parent[w] = v;
            }
        }

        v = s;
        int min = INF;
        for (int i = 0; i < g.size(); i++){
        	if (!intree[i] && dist[i] < min){
        		min = dist[i];
        		v = i;
        	}
        }

    }
}

void addEdge(vector<vector<edge> > &g, int i, int j)
{
	int v = i*M + j;

	if (i+1 < N){
		edge e = {(i+1)*M + j, board[i+1][j]};
		g[v].push_back(e);
	}
	if (i-1 >= 0){
		edge e = {(i-1)*M + j, board[i-1][j]};
		g[v].push_back(e);
	}
	if (j+1 < M){
		edge e = {i*M + (j+1), board[i][j+1]};
		g[v].push_back(e);
	}
	if (j-1 >= 0){
		edge e = {i*M + (j-1), board[i][j-1]};
		g[v].push_back(e);
	}
}

int main(void)
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d%d",&N,&M);
        for (int j = 0; j < N; j++){
        	for (int k = 0; k < M; k++){
        		scanf("%d",&board[j][k]);
        	}
        }

        vector<vector<edge> > g(N*M);
        for (int j = 0; j < N; j++){
        	for (int k = 0; k < M; k++){
                addEdge(g,j,k);
            }
        }
        dijkstra(g,0);
        printf("%d\n",dist[(N*M)-1]);
    }
    return 0;
}
