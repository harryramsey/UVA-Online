#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

int main(void)
{
    std::string str;
    while (getline(std::cin, str)){
        int count = 0;
        std::map<std::string,int> map;
        for (int i = 0; i < str.size(); i++){
            for (int j = 1; j <= str.size()-i; j++){
                std::string subsequence = str.substr(i, j);
                std::string subseqCopy = subsequence;
                std::reverse(subseqCopy.begin(), subseqCopy.end());

                if (subsequence == subseqCopy && map.count(subsequence) == 0){
                    count++;
                    map.insert(std::pair<std::string,int>(subsequence,1));
                }
            }
        }
        std::printf("The string '%s' contains %d palindromes.\n",str.c_str(),count);
    }
    return 0;
}
