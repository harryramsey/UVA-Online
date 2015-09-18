#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

int peg[55];
int N;

bool isSquare(int n){
    int root = sqrt(n);
    return (root*root == n);
}

int DFS(int num, int p) {
    if (p == N) return 0;
    if (peg[p] == 0){
    	peg[p] = num;
    	return 1+DFS(num+1,p);
    }

    for (int i = 0; i <= p; i++){
    	if (isSquare(peg[i]+num)){
            peg[i] = num;
            return 1+DFS(num+1,p);
    	}
    }
    DFS(num,p+1);
}

int main()
{
    int n;
    std::scanf("%d",&n);

    for (int i = 0; i < n; i++){
        std::scanf("%d",&N);

        for (int j = 0; j < n; j++){
            peg[j] = 0;
        }

        int length = DFS(1,0);
        std::printf("%d\n",length);
    }
    return 0;
}
