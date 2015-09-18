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

void DFS_Visit(vector<vector<int> > &g, int u)
{
    color[u] = GRAY;

    for (int i = 0; i < g[u].size(); i++){
    	int v = g[u][i];
    	if (color[v] == WHITE){
            DFS_Visit(g,v);
    	}
    }
    color[u] = BLACK;
}

void DFS(vector<vector<int> > &g)
{
    for (int i = 0; i < g.size(); i++){
        color[i] = WHITE;
    }
    int c = 0;
    for (int i = 0; i < g.size(); i++){
        if (color[i] == WHITE){
            c++;
            DFS_Visit(g,i);
        }
    }
    printf("%d\n",c);
}


int main(void)
{
    int N;
    char largest;
    string edge;
    bool printed = false;

    cin >> N;

    for (int i = 0; i < N; i++){
    	if (printed) printf("\n");
    	else printed = true;

        cin >> largest;
        getline(cin,edge);
        vector<vector<int> > g(1+largest-'A');

        while (getline(cin,edge)){
            if (edge == "") break;
            int v = edge[0]-'A';
            int w = edge[1]-'A';
            g[v].push_back(w);
            g[w].push_back(v);
        }
        DFS(g);
    }
    return 0;
}
