#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


int main()
{
    int nCases,N,H;
    std::string str;
    std::cin >> nCases;

    for (int i = 0; i < nCases; i++){
        std::cin >> N >> H;
        std::string s1(N-H,'0');
        std::string s2(H,'1');
        str = s1+s2;

        do{
            std::printf("%s\n",str.c_str());
        }while (std::next_permutation(str.begin(),str.end()));

        if (i != nCases-1) std::printf("\n");
    }
    return 0;
}

