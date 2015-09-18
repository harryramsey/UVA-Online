#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

void DFS (std::string dict[], int dictSize, std::string pattern, std::string str, int level)
{
    int N = pattern.size();

    if (level == N){
        std::printf("%s\n",str.c_str());
    	return;
    }

    if (pattern[level] == '#'){
        for (int i = 0; i < dictSize; i++){
            DFS(dict,dictSize,pattern,str + dict[i],level+1);
        }
    }
    else{
        for (int i = 0; i < 10; i++){
            char c = '0' + i;
            DFS(dict,dictSize,pattern,str+c,level+1);
        }
    }
}


int main()
{
    int dictSize,numPatterns;
    std::string words,pattern;
    std::string dict[101];

    while (std::cin >> dictSize){
        for (int i = 0; i < dictSize; i++){
            std::cin >> dict[i];
        }
        std::cin >> numPatterns;
        for (int i = 0; i < numPatterns; i++){
            std::cin >> pattern;
            if (i == 0)std::printf("--\n");
            DFS(dict,dictSize,pattern,"",0);
        }
    }
    return 0;
}

