#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int numSoltns, m, n;
vector<int> soltn;

void findPath(vector<vector<int> > &vec, int i, int j, int target, int it)
{
    if (i == m-1){
        soltn.push_back(j);
        numSoltns++;
        return;
    }
    if (i+1 < m && vec[i+1][j] == target){
        if (target == it){
            findPath(vec,i+1,j,1,it+1);
        }
        else findPath(vec,i+1,j,target+1,it);
    }
    if (j-1 >= 0 && vec[i][j-1] == target){
        if (target == it){
            findPath(vec,i,j-1,1,it+1);
        }
        else findPath(vec,i,j-1,target+1,it);
    }
    if (j+1 < n && vec[i][j+1] == target){
        if (target == it){
            findPath(vec,i,j+1,1,it+1);
        }
        else findPath(vec,i,j+1,target+1,it);
    }
    if (i-1 >= 0 && vec[i-1][j] == target){
        if (target == it){
            findPath(vec,i-1,j,1,it+1);
        }
        else findPath(vec,i-1,j,target+1,it);
    }

}

int main(void)
{
    int N,num, j;
    bool printed = false;
    scanf("%d",&N);

    for (int i = 0; i < N; i++){
        scanf("%d%d",&m,&n);
        vector<vector<int> > vec(m,vector<int>(n));
        soltn.clear();

        if (!printed) printed = true;
        else printf("\n");

        for (j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
            	scanf("%d",&num);
            	vec[j][k] = num;
            }
        }
        numSoltns = 0;
        for (j = 0; j < n; j++){
            if (vec[0][j] == 1){
                findPath(vec,0,j,1,2);
                if (numSoltns > 0) break;
            }
       }
		sort(soltn.begin(),soltn.end());
		printf("1 %d\n",j+1);
		printf("%d %d\n",m,soltn[0]+1);
    }
    return 0;
}

