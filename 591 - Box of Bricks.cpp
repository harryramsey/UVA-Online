#include <iostream>
#include <cstdio>

int main(void)
{
    int height;
    int n;
    int setNumber = 1;

    while (std::scanf("%d",&n) == 1){
    	if (n == 0) break;

        int blockHeights[n];
        int totalBlocks = 0;
        for (int i = 0; i < n; i++){
            std::scanf("%d",&height);
            blockHeights[i] = height;
            totalBlocks += height;
        }
        int average = totalBlocks/n;
        int moves = 0;
        for (int i = 0; i < n; i++){
            if (blockHeights[i] < average){
                moves += average-blockHeights[i];
            }
        }
        std::printf("Set #%d\n",setNumber);
        std::printf("The minimum number of moves is %d.\n",moves);
        std::printf("\n");
        setNumber++;
    }
    return 0;
}

