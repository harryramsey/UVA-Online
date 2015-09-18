#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int C, R, nCases;
    scanf("%d",&nCases);
    for (int i = 0; i < nCases; i++){
        scanf("%d%d",&C,&R);

        if (C == R){
            printf("Case #%d: 0\n",i+1);
        }
        else{
            int target  = C-R;
            int root = sqrt(target);
            vector <int> soltns;

            for (int j = 1; j <= root; j++){
                if (target%j == 0){
                    int factor = target/j;
                    if (j > R){
                        soltns.push_back(j);
                    }
                    if (factor > R && factor != j){
                        soltns.push_back(factor);
                    }
                }
            }

            std::sort(soltns.begin(),soltns.end());
            printf("Case #%d:", i+1);
            for (int j = 0; j < soltns.size(); j++){
               printf(" %d",soltns[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
