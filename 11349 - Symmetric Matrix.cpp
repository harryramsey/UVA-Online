#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>

int main(void)
{
    int nCases,N;
    long num;
    char fluff[10],fluffy[10];
    std::scanf("%d",&nCases);

    for (int i = 0; i < nCases; i++){
        std::scanf("%s%s%d",fluff,fluffy,&N);
        int length = N*N;
        long elements[length];
        bool symmetric = true;

        for (int j = 0; j < length; j++){
            std::scanf("%ld",&num);
            elements[j] = num;
            if (num < 0){
                symmetric = false;
            }
        }


        for (int j = 0; j <= length/2; j++){
            if (elements[j] != elements[length-j-1]){
                symmetric = false;
                break;
            }
        }
        if (symmetric) std::printf("Test #%d: Symmetric.\n",i+1);
        else std::printf("Test #%d: Non-symmetric.\n",i+1);
    }
    return 0;
}
