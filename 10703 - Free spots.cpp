#include <iostream>
#include <cstdio>
#include <vector>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int min(int a, int b){
    if (a < b) return a;
    return b;
}

int main(void)
{
    bool board[505][505];
    for (int i = 0; i < 505; i++){
        for (int j = 0; j < 505; j++){
            board[i][j] = false;
        }
    }

    int W,H,N,X1,X2,Y1,Y2;
    while (std::scanf("%d%d%d",&W,&H,&N) == 3){
        if (W == 0 && H == 0 && N == 0) break;
        if (N == 0){
        	std::scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
        }
        for (int i = 0; i < N; i++){
            std::scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
            if (X1 > W){
                int temp = X1;
                X1 = Y1;
                Y1 = temp;
            }
            if (X2 > W){
                int temp = X2;
                X2 = Y2;
                Y2 = temp;
            }
            if (Y1 > H){
                int temp = Y1;
                Y1 = X1;
                X1 = temp;
            }
            if (Y2 > H){
                int temp = Y2;
                Y2 = X2;
                X2 = temp;
            }
            int A = max(X1,X2);
            int B = min(X1, X2);
            int C = max(Y1,Y2);
            int D = min(Y1,Y2);
            for (int j = B; j <= A; j++){
                for (int k = D; k <= C; k++){
                    board[j][k] = true;
                }
            }
        }
        int count = 0;
        for (int i = 1; i <= W; i++){
            for (int j = 1; j <= H; j++){
                if (board[i][j] == false){
                    count++;
                }
                else board[i][j] = false;
            }
        }
        if (count == 0) std::printf("There is no empty spots.\n");
        else if (count == 1) std::printf("There is one empty spot.\n");
        else std::printf("There are %d empty spots.\n",count);

    }
    return 0;
}
