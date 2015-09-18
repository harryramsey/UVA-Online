#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

int ld[6] = {-1,0,1,-1,0,1};
int rd[6] = {-1,-1,0,0,1,1};
char board[205][205];
bool visited[205][205];
int N;

bool checkAns(int x, int y)
{
    if (x < 0 || x >= N || y >= N || y < 0){
        return false;
    }
    if (board[x][y] == 'w') return false;
    if (x == N-1 && board[x][y] == 'b'){
        return true;
    }
    if (visited[x][y]) return false;
    if (!visited[x][y]){
    	visited[x][y] = true;
    }

    bool soltn = false;
    for (int i = 0; i < 6; i++){
        if (checkAns(x+ld[i],y+rd[i])){
            return soltn = true;
        }
    }

}


int main(void)
{
    int caseNum = 1;
    while (scanf("%d",&N)){
        if (N == 0) break;
        for (int i = 0; i < N; i++){
            scanf("%s",board[i]);
        }
        memset(visited,false,sizeof visited);
        bool blkSoltn = false;
        for (int j = 0; j < N; j++){
            if (board[0][j] == 'b'){
                blkSoltn = checkAns(0,j);
                if (blkSoltn) break;
            }
        }
        if (blkSoltn) printf("%d %c\n",caseNum++,'B');
        else printf("%d %c\n",caseNum++,'W');
    }
    return 0;
}
