#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

char board[105][105];
int ld[8] = {1,1,0,-1,-1,-1,0,1};
int rd[8] = {0,1,1,1,0,-1,-1,-1};

void floodFill(int x, int y, char old, char newChar)
{
    if (x >= 105 || x < 0 || y >= 105 || y < 0){
        return;
    }
    if (board[x][y] != old) return;
    if (board[x][y] == old){
        board[x][y] = newChar;
        for (int i = 0; i < 8; i++){
            floodFill(x+ld[i],y+rd[i],old,newChar);
        }
    }
}

int main(void)
{
    int x,y;

    while (scanf("%d%d",&x,&y)){
        if (x == 0 && y == 0) break;
        memset(board,NULL,sizeof board);

        for (int i = 0; i < x; i++){
            scanf("%s",board[i]);
        }

        int c = 0;
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if (board[i][j] == '@'){
                    c++;
                    floodFill(i,j,'@','*');
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
