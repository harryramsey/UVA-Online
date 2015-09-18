#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

bool originalFound[105];
bool found[105];
bool dominated[105][105];
int color[105];

void bfs(vector<vector<int> > &g, int start, int ignore)
{
    for (int i = 0; i < g.size(); i++){
    	found[i] = false;
    	color[i] = 1;
    }
    int v;
    queue<int> q;


    if (ignore >= 0){
    	color[ignore] = -1;
    	found[ignore] = false;
    }
    if (start != ignore){
    	 q.push(start);
    	 found[start] = true;
    }

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

void findDominated(vector<vector<int> > &g)
{
	for (int i = 0; i < g.size(); i++){
		originalFound[i] = found[i];
		/*if (originalFound[i]){
			dominated[0][i] = true;
			dominated[i][i] = true;
		}*/
	}
	for (int i = 0; i < g.size(); i++){
		bfs(g,0,i);
		for (int j = 0; j < g.size(); j++){
			if (originalFound[j] && !found[j]){
				dominated[i][j] = true;
			}
		}
	}
}

void printSoltn(int caseNum, int size)
{
	int length = 2*size +1;
	string str = "";
	for (int i = 0; i < length; i++){
		if (i == 0 || i == length-1){
			str += "+";
		}
		else str += "-";
	}

	printf("Case %d:\n",caseNum);
	for (int i = 0; i < size; i++){
		printf("%s\n",str.c_str());
		for (int j = 0; j < size; j++){
			if (dominated[i][j]) printf("|Y");
			else printf("|N");
		}
		printf("|\n");
	}
	printf("%s\n",str.c_str());
}

int main(void)
{
	int N, n, num;
	int caseNum = 1;
	scanf("%d",&N);

	for (int i = 0; i < N; i++){
		scanf("%d",&n);
		vector<vector<int> > g(n);
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				scanf("%d",&num);
				if (num == 1){
					g[j].push_back(k);
				}
			}
		}
		memset(dominated,false,sizeof dominated);
		bfs(g,0,-1);
		findDominated(g);
		printSoltn(caseNum,g.size());
		caseNum++;
	}
    return 0;
}
