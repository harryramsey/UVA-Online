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
    int m,n,a,b,weight;

    while (scanf("%d%d",&m,&n) == 2){
        if (m == 0 && n == 0) break;

        vector<pair<int,ii> > EdgeList(n);
        int totalWeight = 0;
        for (int i = 0; i < n; i++){
            scanf("%d%d%d",&a,&b,&weight);
            EdgeList[i] = (make_pair(weight,ii(a,b)));
            totalWeight += weight;
        }
        sort(EdgeList.begin(),EdgeList.end());

        int mst_cost = 0;
        int tree_size = 1;
        initSet(m);
        for (int i = 0; i < n; i++){
            pair<int,ii> front = EdgeList[i];
            if (!isSameSet(front.second.first,front.second.second)){
                mst_cost += front.first;
                unionSet(front.second.first,front.second.second);
                tree_size++;
                if (tree_size == m) break;
            }
        }
        printf("%d\n", totalWeight-mst_cost);
    }
    return 0;
}

