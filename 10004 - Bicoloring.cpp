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

int color[205];
bool discovered[205];

bool bfs(vector<vector<int> > &g, int start)
{
    for (int i = 0; i < g.size(); i++){
    	color[i] = GRAY;
    	discovered[i] = false;
    }
    queue<int> q;
    color[start] = WHITE;
    discovered[start] = true;
    q.push(start);

    while(!q.empty()){
    	int u = q.front();
    	q.pop();

    	for (int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if (!discovered[v]){
            	discovered[v] = true;
            	int numBlack = 0;
            	int numWhite = 0;
                for (int j = 0; j < g[v].size(); j++){
                	if (color[g[v][j]] == WHITE) numWhite++;
                	else if (color[g[v][j]] == BLACK) numBlack++;
                }
                if (numWhite > 0 && numBlack > 0) return false;
                else if (numWhite > 0){
                	color[v] = BLACK;
                }
                else color[v] = WHITE;
                q.push(v);
            }
    	}
    }
    return true;
}


int main(void)
{
	int x,y,v,e;

	while(scanf("%d",&v) == 1){
		if (v == 0) break;
		scanf("%d",&e);
		vector<vector<int> > g(v);

		for (int i = 0; i < e; i++){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (bfs(g,0)) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
    return 0;
}
