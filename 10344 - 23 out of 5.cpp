#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int S[5];

bool backtrack(int i, long currSum)
{
    if (i == 5 && currSum == 23){
        return true;
    }
    if (i == 5 && currSum != 23){
        return false;
    }
    if (backtrack(i+1,currSum+S[i])){
        return true;
    }
    if (backtrack(i+1,currSum-S[i])){
        return true;
    }
    if (backtrack(i+1,currSum*S[i])){
        return true;
    }
}

int main(void)
{
    while (std::scanf("%d%d%d%d%d",&S[0],&S[1],&S[2],&S[3],&S[4]) == 5){
    	if (S[0] == 0 && S[1] == 0 && S[2] == 0 && S[3] == 0 && S[4] == 0) break;

    	std::sort(S,S+5);
        bool possible = false;
        do{
            if (backtrack(1,S[0])){
       		possible = true;
       		break;
            }
        }while (std::next_permutation(S,S+5));

        if (possible) std::printf("Possible\n");
        else std::printf("Impossible\n");
    }
    return 0;
}
