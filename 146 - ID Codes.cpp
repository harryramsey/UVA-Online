#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int main(void)
{
    char str[100];
    while (std::scanf("%s",str) == 1){
        if (str[0] == '#') break;

        if (std::next_permutation(str,str+strlen(str))){
            std::printf("%s\n",str);
        }
        else std::printf("No Successor\n");
    }
    return 0;
}
