#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>

int main(void)
{
    int nCases, nKeys, nLines;;
    char key[10], val[10];
    std::scanf("%d",&nCases);

    for (int i = 0; i < nCases; i++){
        std::map <char,int> map;
        std::scanf("%d",&nKeys);
        for (int j = 0; j < nKeys; j++){
            std::scanf("%s%s",key,val);
            map.insert(std::pair<char,int>(key[0],atoi(val)));
        }

        std::scanf("%d",&nLines);
        std::string line;
        std::getline(std::cin, line);
        long long sum = 0;
        for (int j = 0; j < nLines; j++){
            std::getline(std::cin,line);
            int length = line.size();
            for (int k = 0; k < length; k++){
            	sum += map.find(line[k])->second;
            }
        }
        if (sum == 0) std::printf("0.00$\n");
        else if (sum%100 == 0) std::printf("%lld.00$\n",sum/100);
        else if (sum%100 < 10) std::printf("%lld.0%lld$\n",sum/100,sum%100);
        else std::printf("%lld.%lld$\n",sum/100,sum%100);
    }

    return 0;
}

