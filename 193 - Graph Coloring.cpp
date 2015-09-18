#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int color[101];
vector<int> soltn;
int maxVal;

void initialize()
{
    for (int i = 0; i < 101; i++){
        color[i] = -1;
    }
    maxVal = 0;
}


void maxBlack(vector<vector<int> > &vec, int node, int numBlack, int level)
{
    if (level == vec.size()){
        if (numBlack > maxVal){
            maxVal = numBlack;
            soltn.resize(0);
            for (int i = 0; i < vec.size(); i++){
                if (color[i] == 1){
                    soltn.push_back(i);
                }
            }
        }
        return;
    }

    bool possible_black = true;
    int v;

    if (vec[node].size() == 0){
    	color[node] = 1;
    	maxBlack(vec,node+1,numBlack+1,level+1);
    }
    else {
        for (int i = 0; i < vec[node].size(); i++){
            v = vec[node][i];
            if (color[v] == 1){
                possible_black =  false;
                break;
            }
        }
        if (possible_black){
            color[node] = 1;
            maxBlack(vec,node+1,numBlack+1,level+1);
        }
        color[node] = -1;
        maxBlack(vec,node+1,numBlack,level+1);
    }
}

int main(void)
{
    int N, vertices, edges, v, w;
    scanf("%d",&N);

    for (int i = 0; i < N; i++){
        scanf("%d%d",&vertices,&edges);
        vector<vector<int> > vec(vertices);
        for (int j = 0; j < edges; j++){
            scanf("%d%d",&v,&w);
            vec[v-1].push_back(w-1);
            vec[w-1].push_back(v-1);
        }
        initialize();
        maxBlack(vec,0,0,0);

        printf("%d\n",maxVal);
        for (int j = 0; j < soltn.size(); j++){
            if (j == 0) printf("%d",soltn[j]+1);
            else printf(" %d",soltn[j]+1);
        }
        printf("\n");
    }
    return 0;
}
