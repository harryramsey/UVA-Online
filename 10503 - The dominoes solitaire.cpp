#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

struct domino{
    int left;
    int right;
};

bool used[20];
int spaces, numDominoes, soltns;

void placeDomino(domino board[],domino dominoes[], int level)
{
    if (level == spaces+1){
        if (board[level].left == board[level-1].right){
            soltns++;
        }
        return;
    }

    for (int i = 0; i < numDominoes; i++){
        if (!used[i]){
            used[i] = true;
            if (dominoes[i].left == board[level-1].right){
                board[level] = dominoes[i];
                placeDomino(board,dominoes,level+1);
            }
            if (dominoes[i].right == board[level-1].right){
                domino d;
                d.left = dominoes[i].right;
                d.right = dominoes[i].left;
                board[level] = d;
                placeDomino(board,dominoes,level+1);
            }
            used[i] = false;
        }
    }
}


int main(void)
{
    while(scanf("%d",&spaces) == 1){
          if (spaces == 0) break;
          domino first, last;
          scanf("%d%d%d%d%d",&numDominoes,&first.left,&first.right,&last.left,&last.right);

          domino place[numDominoes];
          for (int i = 0; i < numDominoes; i++){
              domino d;
              scanf("%d%d",&d.left,&d.right);
              place[i] = d;
          }

          for (int i = 0; i < 20; i++){
              used[i] = false;
          }
          domino board[2+spaces];
          board[0] = first;
          board[spaces+1] = last;
          soltns = 0;

          placeDomino(board,place,1);
          if (soltns > 0){
              std::printf("YES\n");
          }
          else{
              std::printf("NO\n");
          }
    }
    return 0;
}
