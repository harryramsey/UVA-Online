#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

int N;
bool used[17];
int pos[17];

bool isPrime(int n)
{
    int root = sqrt(n);
    for (int i = 2; i <= root; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void DFS(int level)
{
    if (level == N){
        for (int i = 0; i < N; i++){
            if (i == N-1){
                std::printf("%d\n",pos[i]);
            }
            else std::printf("%d ",pos[i]);
        }
        return;
    }
    else{
       	for (int i = 2; i <= N; i++){
            if (level == N-1 && !used[i]){
                if (isPrime(i+1) && isPrime(i+pos[level-1])){
                    used[i] = true;
                    pos[level] = i;
                    DFS(level+1);
                    used[i] = false;
                }
            }
            else if (!used[i] && isPrime(i+pos[level-1])){
                used[i] = true;
                pos[level] = i;
                DFS(level+1);
                used[i] = false;
            }
        }
    }
}

int main(void)
{
    int cases = 0;
    while (scanf("%d", &N) == 1) {
        cases++;
        if(cases > 1) printf("\n");

        for (int i = 0; i <= N; i++){
            used[i] = false;
        }
        for (int i = 0; i <= N; i++){
            pos[i] = 0;
        }
        used[1] = true;
        pos[0] = 1;
        printf("Case %d:\n", cases);
        DFS(1);
    }
    return 0;
}
