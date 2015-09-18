#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

vector<int> pset;

void initSet(int N)
{
    pset.assign(N,0);
    for (int i = 0; i < N; i++){
        pset[i] = i;
    }
}

int findSet(int i)
{
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}

int main(void)
{
    int n,v,e,a,b,weight;

    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d%d",&v,&e);

        vector<pair<int,ii> > EdgeList(e);
        for (int j = 0; j < e; j++){
            scanf("%d%d%d",&a,&b,&weight);
            EdgeList[j] = make_pair(weight,ii(a-1,b-1));
        }
        sort(EdgeList.begin(),EdgeList.end());

        int mst_cost = 0;
        initSet(v);
        vector<int> MST;
        for (int j = 0; j < e; j++){
            pair<int,ii> front = EdgeList[j];
            if (!isSameSet(front.second.first,front.second.second)){
                mst_cost += front.first;
                unionSet(front.second.first,front.second.second);
                MST.push_back(j);
            }
        }

        int next_best = 2147383647;
        for (int k = 0; k < MST.size(); k++){
           initSet(v);
           int ignore = MST[k];
           int cost = 0;
           int count = 0;

           for (int j = 0; j < e; j++){
        	   pair<int,ii> front = EdgeList[j];
        	   if (j != ignore){
				   if (!isSameSet(front.second.first,front.second.second)){
					   cost += front.first;
					   unionSet(front.second.first,front.second.second);
					   count++;
				   }
        	   }
           }
           if (cost < next_best && count == MST.size()) next_best = cost;
        }
        printf("%d %d\n",mst_cost,next_best);
    }
    return 0;
}
