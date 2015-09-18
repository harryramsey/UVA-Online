#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

char board[35][85];
int ld[4] = {0,1,-1,0};
int rd[4] = {-1,0,0,1};

void floodFill(int x, int y, char old, char newChar)
{
    if (x >= 35 || x < 0 || y >= 85 || y < 0){
        return;
    }
    if (board[x][y] != old) return;
    if (board[x][y] == old){
        board[x][y] = newChar;
        for (int i = 0; i < 4; i++){
            floodFill(x+ld[i],y+rd[i],old,newChar);
        }
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
    string str;
    getline(cin,str);

    for (int i = 0; i < N; i++){
        int line = 0;
        memset(board,NULL,sizeof board);
        while (getline(cin,str)){
            if (str[0] == '_') break;
            for (int j = 0; j < str.size(); j++){
            	board[line][j] = str[j];
            }
            line++;
        }
        for (int j = 0; j < line; j++){
            for (int k = 0; board[j][k] != NULL; k++){
                if (board[j][k] == '*'){
                    board[j][k] = ' ';
                    floodFill(j,k,' ','#');
                }
            }
        }
        for (int j = 0; j < line; j++){
            for (int k = 0; board[j][k] != NULL; k++){
                printf("%c",board[j][k]);
            }
            printf("\n");
        }
        printf("%s\n",str.c_str());
    }
    return 0;
}
