#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

std::string concat(std::string &str, int n)
{
    std::string copy = "";
    for (int i = 0; i < n; i++){
        copy += str;
    }
    return copy;
}

int main(void)
{
    int cases;
    std::string str;
    std::cin >> cases;

    for (int i = 0; i < cases; i++){
    	std::cin >> str;
        for (int j = 0; j < str.size(); j++){
            if (str.size()%(j+1) == 0){
                std::string subseq = str.substr(0, j+1);
                std::string possiblePeriod = concat(subseq,str.size()/subseq.size());
                if (possiblePeriod == str){
                    std::printf("%d\n",j+1);
                    if (i != cases-1) std::printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}

