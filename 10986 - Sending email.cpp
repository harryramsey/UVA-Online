#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

# define INF 1000000000

typedef pair<int,int> ii;

struct edge{
    int w, weight;
};

int dist[20005];
int parent[20005];
priority_queue<ii, vector<ii>, greater<ii> > pq;

void initialize(int s)
{
    for (int i = 0; i < 20005; i++){
    	dist[i] = INF;
    	parent[i] = -1;
    }
    dist[s] = 0;
    pq.push(ii(0,s));
}

void dijkstra(vector<vector<edge> > &g, int s)
{
    initialize(s);

    while (!pq.empty()){
        ii front = pq.top();
        pq.pop();
        int d = front.first;
        int u = front.second;

        if (d == dist[u]){
            for (int j = 0; j < g[u].size(); j++){
                int w = g[u][j].w;
                if (dist[w] > dist[u]+g[u][j].weight){
                    dist[w] = dist[u]+g[u][j].weight;
                    parent[w] = u;
                    pq.push(ii(dist[w],w));
                }
            }
        }
    }
}


int main(void)
{
    int N,n,m,s,t,v,w,weight;
    int caseNum = 1;
    scanf("%d",&N);

    for (int i = 0; i < N; i++){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        vector<vector<edge> > g(20005);

        for (int j = 0; j < m; j++){
        	scanf("%d%d%d",&v,&w,&weight);
        	edge e = {w,weight};
        	edge e1 = {v,weight};
        	g[v].push_back(e);
        	g[w].push_back(e1);
        }
        if (m == 0) initialize(s);
        if (m != 0) dijkstra(g,s);
        if (dist[t] == INF) printf("Case #%d: unreachable\n",caseNum++);
        else printf("Case #%d: %d\n",caseNum++, dist[t]);
    }
    return 0;
}
