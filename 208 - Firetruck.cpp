#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

bool used[25];
int soltns;
vector<vector<int> > allPaths;
bool found[25];
int color[25];

void bfs(int start, vector<vector<int> > &g)
{
    for (int i = 0; i < 25; i++){
    	found[i] = false;
    	color[i] = 1;
    }
    int v;
    found[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
    	int u = q.front();
    	q.pop();

    	for (int i = 0; i < g[u].size(); i++){
            v = g[u][i];
            if (color[v] == 1){
                color[v] = 0;
                found[v] = true;
                q.push(v);
            }
    	}
    	color[u] = -1;
    }
}


void findPath(vector<vector<int> >& vec, vector<int> &path, int v, int target)
{
    if (v == target){
    	allPaths.push_back(path);
        soltns++;
        return;
    }

    for (int i = 0; i < vec[v].size(); i++){
        int w = vec[v][i];
        if (!used[w] && found[w]){
            used[w] = true;
            path.push_back(w);
            findPath(vec,path,w,target);
            used[w] = false;
            path.pop_back();
        }
    }
}

int main(void)
{
    int N, v, w;
    int caseNum = 1;
    while (scanf("%d",&N) == 1){
        printf("CASE %d:\n",caseNum++);
        vector<vector<int> > vec(25);
        vector<int> path;

        while (scanf("%d%d",&v,&w)){
            if (v == 0 && w == 0) break;

            vec[v-1].push_back(w-1);
            vec[w-1].push_back(v-1);
        }

        for (int i = 0; i < 25; i++){
            used[i] = false;
        }
        bfs(N-1,vec);
        allPaths.resize(0);
        soltns = 0;
        used[0] = true;
        path.push_back(0);
        findPath(vec,path,0,N-1);

        sort(allPaths.begin(), allPaths.end());
        for (int i = 0; i < allPaths.size(); i++){
            for (int j = 0; j < allPaths[i].size(); j++){
                if (j== 0) printf("%d",allPaths[i][j]+1);
                else printf(" %d",allPaths[i][j]+1);
            }
            printf("\n");
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",soltns,N);
    }

    return 0;
}
