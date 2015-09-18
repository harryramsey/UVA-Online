#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int dp[101][101];
int height[101][101];
int row, col;

int findLength(int i, int j)
{
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    else{
        int arr[4];
        for (int k = 0; k < 4; k++){
            arr[k] = 1;
        }
        if (i+1 < row && height[i][j] > height[i+1][j]){
            arr[0] = 1+findLength(i+1,j);
        }
        if (i-1 >= 0 && height[i][j] > height[i-1][j]){
            arr[1] = 1+findLength(i-1,j);
        }
        if (j+1 < col && height[i][j] > height[i][j+1]){
            arr[2] = 1+findLength(i,j+1);
        }
        if (j-1 >= 0 && height[i][j] > height[i][j-1]){
            arr[3] = 1+findLength(i,j-1);
        }
        for (int k = 0; k < 4; k++){
            if (arr[k] > dp[i][j]){
                dp[i][j] = arr[k];
            }
        }
    }
    return dp[i][j];
}

int main(void)
{
    int N;
    string str;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> str >> row >> col;
        for (int j = 0; j < row; j++){
            for (int k = 0; k < col; k++){
                scanf("%d",&height[j][k]);
                dp[j][k] = -1;
            }
        }
        int longest = 0;
        for (int j = 0; j < row; j++){
            for (int k = 0; k < col; k++){
                int length = findLength(j,k);
                if (length > longest){
                    longest = length;
                }
            }
        }
        printf("%s: %d\n",str.c_str(),longest);
    }
    return 0;
}
